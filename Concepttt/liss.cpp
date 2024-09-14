#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& arr,int n){
    vector<int>ans;

    for(int i=0;i<n;i++){
        if(ans.empty() || ans.back()<arr[i]){
            ans.push_back(arr[i]);
        }
        else{
            int idx= lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[idx]=arr[i];
        }
    }
    return ans.size();
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n);

}