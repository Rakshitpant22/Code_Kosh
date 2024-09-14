class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>numbers;
        for(int i=1;i<n;i++){
            fact=fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans=""; //intialising string which will store ans as empty
        k=k-1; // sice 0 based indexing..
        while(true){
          ans= ans+ to_string(numbers[k/fact]);
          // for erasing that particular index bcs has been used..
          numbers.erase(numbers.begin()+ k/fact);
          if(numbers.size()==0){
              break;
          }
          k=k%fact;
          fact= fact/numbers.size();
        }
       return ans;
    }
};