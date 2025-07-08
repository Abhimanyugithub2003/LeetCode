#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> function(vector<int> &arr){
    int n=arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    st.push(0);
    int idx=0;
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            idx=i-st.top();
            ans[st.top()]=idx;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ans[st.top()]=0;
        st.pop();
    }
    return ans;
}
int main(){
    vector<int> arr{73,74,75,71,69,72,76,73};
    vector<int> ans=function(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}