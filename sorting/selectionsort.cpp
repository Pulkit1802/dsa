#include <iostream>
#include <cstdlib>
using namespace std;

int *selection_sort(int *arr, int n) {
    int temp;
    for(int i=0;i < n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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

    int *sortedarr = selection_sort(arr, n);

    for(int i=0; i<n; i++){
        cout<<sortedarr[i]<<", ";
    }

    return 0;
}