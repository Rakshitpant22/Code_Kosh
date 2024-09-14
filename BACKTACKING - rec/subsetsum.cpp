
class Solution
{ 
    private:
    void subs(int index,int sum, vector<int> &arr, int N, vector<int>&ans){
        if(index == N){
            ans.push_back(sum);
            return;
        }
        subs(index+1,sum+arr[index],arr,N,ans);
        subs(index+1,sum,arr,N,ans);
    
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        subs(0,0,arr,N,ans);
        sort(ans.begin(),ans.end());f
        return ans;
    }
};
//N = sizeof()arr;