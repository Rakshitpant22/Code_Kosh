Return the minimum integer k such that koko can eat all the bananas within h hours where k is speed of eating per hour;

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

int time(vector<int>& piles, int hourly,int n){
      int totalhours=0;
        for(int i=0;i<n;i++){
          totalhours += ceil((double)(piles[i]) / (double)(hourly));
        }
        return totalhours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int ans=-1;
        int low=1;
        int high= *max_element(piles.begin(), piles.end());

        while(low<=high){
            int mid= low+(high-low)/2;
            long long totalhours=time(piles,mid,n);

//agr mid pass krne p abhi bhi h bda h to mtlb or chota available hai k ki;
            if(h>=totalhours){ 
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }


