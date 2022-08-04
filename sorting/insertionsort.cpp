#include <iostream>
#include <cstdlib>
using namespace std;

int *insertion_sort(int *arr, int n) {
    int temp;
    for(int i=1;i < n; i++){
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            } else {
                break;
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

    int *sortedarr = insertion_sort(arr, n);

    for(int i=0; i<n; i++){
        cout<<sortedarr[i]<<", ";
    }

    return 0;
}