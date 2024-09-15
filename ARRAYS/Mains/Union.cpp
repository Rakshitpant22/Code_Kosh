 //! Union of 2 sorted arrays

 vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i=0,j=0;
        vector<int>ans;
        while(i<n && j<m){
            if(arr1[i]<=arr2[j]){ 
                if(ans.empty() || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
                i++;
            }

            else{
               if(ans.empty() || ans.back()!=arr2[j]){
                ans.push_back(arr2[j]);
              }
                j++;
            }
        }
        
        // if both arrays are nt equal then :
        while(j<m){
             if(ans.empty() || ans.back()!=arr2[j]){
                ans.push_back(arr2[j]);
              }
                j++;
        }
        while(i<n){
           if(ans.empty() || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
              }
                i++;
        }
        return ans;
    }