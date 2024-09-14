class Solution
{
private:
    void findcombinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
       
        if (index == arr.size()){
            if (target == 0){
                ans.push_back(ds);
            }
            return;
        }
        // pick up the element
        if (target >= arr[index]){
            ds.push_back(arr[index]);
            findcombinations(index, target - arr[index], arr, ans, ds);
            ds.pop_back();
        }

        findcombinations(index + 1, target, arr, ans, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombinations(0, target, candidates, ans, ds);
        return ans;
    }
};