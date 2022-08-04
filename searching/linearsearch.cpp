#include <iostream>
using namespace std;

int main(){
    int n, key;
    cin>>n;
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>key;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("Elt found at ind %d",i);
            break;
        }
        if(i==n-1){
            printf("Elt not found");
        }
    }
}