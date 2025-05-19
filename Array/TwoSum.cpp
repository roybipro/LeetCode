#include <iostream>
using namespace std;

// brute force
int twoSumBB(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (target == arr[i] + arr[j])
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}
// sorted and bainary search
 int sortedBinary(int arr[],int n,int target){
    
 }

int main()
{
    // Your code goes here
    int arr[] = {2, 3, 5, 6, 7, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    twoSumBB(arr, n, target);
    return 0;
}