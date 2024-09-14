//^ BINARY SEARCH - intuition ana chahie jha:
//? givem data /array or ek parameter dia ho--> or data p kisi requirement puri krni h  with (max/min)

//! ques1:
You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 
Return the minimum time required for all buses to complete at least totalTrips trips.

same pattern question:

//! ques2:
Input: candies = [5,8,6], k = 3
hme k logo m candies batni hai such that hr candies[i]/bande  ko equal amount m candy mile ;
at most ek pura pile kisi bache ko de skte ha
Return the maximum number of candies each child can get.

lass Solution {
    #define ll long long
    bool ispossible(vector<int>& candies, long long k, ll maxcandies){
          ll cnt=0;
          for(int i=0;i<candies.size();i++){
             cnt+= candies[i]/maxcandies;
          }
           if(cnt>=k)return true;
           return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int high=*(max_element(candies.begin(),candies.end()));
        int ans=0;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(ispossible(candies,k,mid)){
                ans=mid;
                low=mid+1;  // yaha p or greater k lie binary search lagaenge kyuki ques m max candies per balak chahie;
            }
            else{
                    high=mid-1;
            }
        }
        return ans;
    }
};