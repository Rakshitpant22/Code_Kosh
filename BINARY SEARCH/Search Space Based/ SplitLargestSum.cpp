// Same pattern problems
//! 1. Capacity to Ship Packages within D Days
//! 2. Book Allocation Problem
//! 3. Split array - Largest Sum
//! 4. Painter's partition



//! BOOK ALLOCATION 
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of 
any subarray is minimized.Return the minimized largest sum of the split.

Input: nums = [7,2,5,10,8], k = 2   ---> Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

 // TODO ----> ALLOCATE BOOKS // SPLIT ARRAY LARGEST SUM  // PAINTERS PARTITION --> Same approach

EK KISI PARAMETER DIA HOGA OR ARRAY 
IN CONTIGIOUS MANNER DISTRIBUTIVE AMONG ARRAY 
DIVIDE DISTRUBUTION TO EXACTLY GIVEN PARAMETER:(ex agr book allocate 4 student m hogi to <4 or>4 is not allowed only =4 is allowed)
//! SUCH THAT THE MAX NO OF PAGES ASSIGNED TO ANY STIDENT IS MINIMUM:\

#include<bits/stdc++.h>

int count_students(vector<int>& arr, int max_pages, int n, int m){
     int cntstudents=1;
     int pages=0;
     for(int i=0;i<n;i++){
         if(pages+arr[i]<=max_pages){
            pages+=arr[i];
         }
         else{
               cntstudents++;
               pages= arr[i];
         }
     }
     return cntstudents;
}

int findPages(vector<int>& arr, int n, int m) {
if(m>n)return -1;
 
 int low= *(max_element(arr.begin(),arr.end()));
 int high= accumulate(arr.begin(),arr.end(),0);

 int ans=-1e9;

 while(low<=high){
     int mid=low+(high-low)/2;
     int students= count_students(arr,mid,n,m);
     if(students <= m){
         ans=mid;
         high=mid-1;
     }
     else{
       low=mid+1;
     }
 }
    return ans;
   
   
}



//! SPLIT ARRRAY LARGEST SUM
https://leetcode.com/problems/split-array-largest-sum/description/

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

int solve(vector<int>& nums, int k,int maxsum){
int cnt=1,sum=0;
for(int i=0;i<nums.size();i++){
    if(sum+nums[i]<=maxsum){
        sum+=nums[i];
    }
    else{
        cnt++;
        sum=nums[i];
    }
}
return cnt;
}
    int splitArray(vector<int>& nums, int k) {
        //sum ko id lelenge;
        int n=nums.size();
        //!low = max value beacuse we want nn empty subarrays so for that min sum can be the max value of the array element
        int low=*max_element(nums.begin(),nums.end());

        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=solve(nums,k,mid); // no of subarrays with (sum<=mid)

            if(cnt<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }




//! Capacity to Ship Packages within D Days
//TODO::  Same approach- ship question:
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
// ex:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages 
into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

public:
    int check_days(vector<int>& weights, int cap,int n){
        int day=1,load=0;
// agr khi load+weight[i] bda hogya cap weight se mtlb us din utna hi ship m ja skta h
// agla din ka weight load m refresh kradia or sath hi agle din jaega aage k weights to day++
for(int i=0;i<n;i++){
        if(load+weights[i]>cap){ 
            day++;
            load= weights[i];
        }
// jabtak cap weight s jyada na hoaje load weight bdhate jao.
        else{
              load+=weights[i];
        }
}
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();

        int low= *(max_element(weights.begin(),weights.end()));
        int high= accumulate(weights.begin(),weights.end(),0);
       int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int required_days= check_days(weights,mid,n);
//agr abhi bhi days given bda h predicted s mtlb or chota weight-cap hona chahie for each day
// high ko mid-1 p lejao;
            if(days>=required_days){
                ans=mid;
                high=mid-1;
            }
// agr days km pd rhe h to low ko bdado
            else{
                low=mid+1;
            }
        }
        return ans;
    }