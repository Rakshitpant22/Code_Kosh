void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      vector<int>ans;

        for(int i=0;i<m;i++){
           ans.push_back(nums1[i]);
        }
         for(int i=0;i<n;i++){
           ans.push_back(nums2[i]);
        }
        sort(ans.begin(),ans.end());

        nums1=ans;
   
    }

//! without extra space:
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i=n-1;
            int j=0;
            while(i>=0 && j<m)
            {
                if(arr1[i]>arr2[j])
                {
                    swap(arr1[i],arr2[j]);
                    i--;
                    j++;
                }
                else
                {
                    break;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 

   