#include <iostream>
#include <cstdlib>
using namespace std;

int *binarysort(int *arr, int n) {
    int temp;
    for(int i=0;i < n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

int main(){
    int n;
    cin>>n;
    int *arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i<n;i++) cin>>arr[i];

    int *sortedarr = binarysort(arr, n);

    for(int i=0; i<n; i++){
        cout<<sortedarr[i]<<", ";
    }

    return 0;
}
