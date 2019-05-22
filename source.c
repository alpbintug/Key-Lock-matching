#include <stdio.h>

#include <time.h>
#define MAX 50
//Seperating our Array into two, one having bigger values than the value of random, the other having lesser values.
int partition(int a[],int left, int right, int random, int n){
    if(left<right){
        while(left<right){
            while(random<a[right]) //We're finding the first number which is smaller than the value of random from the right
                right--;
            while(random>a[left]) //We're finding the first number which is greater than the value of random from the left
                left++;
            int tmp = a[left]; //We're exchanging two valuse so bigger one goes to the right, smaller one goes to the left
            a[left] = a[right];
            a[right] = tmp;
        } //At the end of this while, our random value will find its place in the Array
        printf("\nArray partially sorted for integer %d: ",random);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
    return left; //Returning the left value to remember the division point of the array.
}

void sort(int Key[],int Lock[], int left, int right, int n){
        srand(time(NULL)); //Setting up to generate random numbers
        int pivot,random;
        if(right>left){
            random = Key[(rand()%(right-left))+left]; //Generating random index value on Key array (which is between left value and right value)
                                                      //Then returning the random key we generated
            printf("\n---------------------------------------------------");
            printf("\n\tRandomly selected key: %d",random);
            printf("\nLock Array: ");
            for(int i=0;i<n;i++){
                printf("%d ",Lock[i]);
            }
            pivot=partition(Lock,left,right,random,n); //Partly sorting and dividing our array, Randomly generated value will find its place in the array
            printf("\nKey Array: ");
            for(int i=0;i<n;i++){
                printf("%d ",Key[i]);
            }
            partition(Key,left,right,Lock[pivot],n); //Sending the value of Lock[Pivot] which equals the random value We generated
                                                     //We're sending this value to the function via Lock[pivot] as mentioned in HW description
            sort(Key,Lock,left,pivot-1,n);//Sorting the left piece of the Array
            sort(Key,Lock,pivot+1,right,n);//Sorting the right piece of the Array
        }
}


int main(){
    int Key[MAX], Lock[MAX], N;
    printf("Enter the size of Arrays\n");
    scanf("%d",&N);
    //Reading the Arrays
    for(int i=0;i<N;i++){
        printf("Enter the %dth value of Lock array\n",i+1);
        scanf("%d",&Lock[i]);
    }
    for(int i=0;i<N;i++){
        printf("Enter the %dth value of Key array\n",i+1);
        scanf("%d",&Key[i]);
    }
    sort(Key,Lock,0,N-1,N); //Sorting the arrays
    printf("\n---------------------------------------------------");
    printf("\nSorted Key Array: ");
    for(int i=0;i<N;i++){
        printf("%d ",Lock[i]);
    }
    printf("\nSorted Lock Array: ");
    for(int i=0;i<N;i++){
        printf("%d ",Key[i]);
    }
}
