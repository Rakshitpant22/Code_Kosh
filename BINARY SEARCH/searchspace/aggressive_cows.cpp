same ques= https://leetcode.com/problems/magnetic-force-between-two-balls/description/
// TODO-> given a array with a parameter here cows,hme sari cows ko place krna h or max distance bwtween 2 cows batana hai. 

#include<bits/stdc++.h>
bool ispossible(vector<int> &stalls, int distance,int cows){
    int cntcows=1;
    int lastcow_at=stalls[0];

    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-lastcow_at>=distance){
            cntcows++;
            lastcow_at=stalls[i];
        }
        if (cntcows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows)
{ 
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());

    int low=1;
    int high=stalls[n-1]-stalls[0];

     int ans=-1e9;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(ispossible(stalls,mid,cows)==true){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
        return ans;
   

}