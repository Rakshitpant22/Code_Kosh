Given an array of integers arr of even length n and an integer k.
We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
Return true If you can find a way to do that or false otherwise.

// BRUTE FROCE
bool canArrange(vector<int>& arr, int k) {
int n=arr.size();
        vector<bool>used(n,false);
         
        for(int i=0;i<n;i++){
            if(used[i])continue; //if already marked
            bool flag=false;

            for(int j=i+1;j<n;j++){
                if(used[j])continue;

                if((arr[i]+arr[j])%k==0){
                    flag=true;
                    used[j]=true;
                    used[i]=true;
                    break;
                }
            }
            if(!flag)return false;
        }
        return true;
}
    
//! concept 
//^ if A+B is divisble by K then ==> A%K + B%K = K
So now in this ques we have to find remainder pairs whose sum ==k (2 SUM problem)

//! REMAINDER for -ve numbers (x = number)
//^ remainder= (x%k)+k)%k

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>store(k,0);
        // since remainders can be in range 0<=remainders<=k-1;
        // we can make array which stores remainder upto k-1;

        for(int i=0;i<n;i++){
            arr[i] = ((arr[i] % k) + k) % k; //remainder
            store[arr[i]]++;
        }

        if(store[0]%2!=0)return false;

        for(int i=1;i<=k/2;i++){ //can check upto half bcs after that it would be 
            if(store[i]!=store[k-i])return false;
        }
        return true;
        
    }
};


// Hashmap Solution 
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[i] = ((arr[i] % k) + k) % k;
        }
        unordered_map<int,int>mpp;
        for(auto it:arr){
            mpp[it]++;
        }

        for(auto it:mpp){
            if(it.first==0){
                if(it.second%2!=0)return false;
            }
            else{
            if(mpp[it.first]!=mpp[(k-it.first)])return false;
            }
        }
        return true;
    }
};

