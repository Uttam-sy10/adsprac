#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i ){
    int smallest = i;
    int l = 2*i+1;
    int r = 2*i+1;
    if( l < n && arr[l] < arr[smallest])
    smallest = l;
    if( r < n && arr[r] < arr[smallest])
    smallest = r;
    if( smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(arr,n,smallest);

    }
   
}

void heapsort(int arr[],int n){
    for(int i = n/2 - 1;i>= 0; i--)
    heapify(arr,n,i);
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call min heapify on the reduced heap
        heapify(arr, i, 0);
    }

}

void print(int arr[],int n){
    for(int i = 0; i<n; ++i)
    cout<<"\n";
    }


    int main(){
        int arr[] = {4,6,8,3,2,9};
        int n = sizeof(arr)/ sizeof(arr[0]);

        heapsort(arr,n);
        cout<<"sorted ";
        print(arr,n);
    }