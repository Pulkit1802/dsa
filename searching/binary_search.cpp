#include <iostream>
using namespace std;

int binary_search(int *arr, int h, int key){
    int l=0;
    while(l<=h){
        int mid = (l+h)/2;
        cout<<mid<<arr[mid];
        if(key == arr[mid]) return mid;
        else if(key < arr[mid]) h=mid-1;
        else l=mid+1;
    }

    return -1;
}

int main(){
    int n, search, res;
    cin>>n;
    int *arr = (int *)malloc(n*sizeof(n));
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>search;
    res = binary_search(arr, n, search);
    if(res==-1){
        printf("No such elt");
    } else {
        printf("Elt found at %d index", res);
    }
}