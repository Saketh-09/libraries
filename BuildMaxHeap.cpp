/*Building max heap
  referencec https://www.geeksforgeeks.org/heap-sort/
*/
#include<iostream>
using namespace std;

int heapify(int arr[],int n,int i) {
  int largest= i;
  int l= 2*i+1;
  int r=2*i+2;
  if(l<n&& arr[l]>arr[largest]) {
    largest=l;
  }
  if(r<n&& arr[r]>arr[largest]) {
    largest=r;
  }
  if(largest!=i) {
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
  }
}

void buildheap(int arr[],int n) {
  for(int j=n/2-1;j>=0;j--) {
    heapify(arr,n,j);
  }
}
void printarray(int arr[],int n) {
  for(int i=0;i<n;i++) {
    cout<<arr[i]<<endl;
  }
}

int main() {
  //sample input
  int n=7,arr[n];
  for(int i=0;i<n;i++) {
    arr[i]=i;
  }
  buildheap(arr,n);
  printarray(arr,n);
  return 0;
}
