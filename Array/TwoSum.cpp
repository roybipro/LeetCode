#include <iostream>
using namespace std;

//brute force
int twoSum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        int sum = arr[i]+arr[j];
        if(sum==target){
            cout<<i<<" "<<j<<endl;
            return 0;

        }
        }

    }
    return 0;
}

int main() {
    // Your code goes here
    int arr[]={2,3,5,6,7,4,7};
    int n= sizeof(arr)/sizeof(arr[0]);
    int target=9;
    twoSum(arr,n,target);
    return 0;
}