#include<iostream>
#include<vector>
using namespace std;
int max(int arr[],int n){
    int mx=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>mx) mx=arr[i];
    }
    return mx;
}
int main(){
    int arr[]={2,3,5,7,6,1};
    int x=max(arr,6);
    for(int i=0;i<6;i++){
        if(arr[i]==x){
            arr[i]=-1;
        }
    }
    cout<<max(arr,6);
}