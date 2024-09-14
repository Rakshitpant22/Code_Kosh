// TC-O(n+m) SC-O(1)
        int n=nums1.size(),m=nums2.size();  
        int size= n+m;
        
        int idx1 = (size/2)-1;
        int el1=-1;
        int idx2 = size/2;
        int el2=-1;

        int i=0,j=0,k=0;
   
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(k==idx1){
                    el1=nums1[i];
                }
                 if(k==idx2){
                    el2=nums1[i];
                }
                i++;
            }

            else{
                if(k==idx1){
                    el1=nums2[j];
                }
                 if(k==idx2){
                    el2=nums2[j];
                }
                j++;
            }
            k++;
        }
    // AGR 1 NUMS khtm hogya to dusre chlega sirf

    while(i<n){
                if(k==idx1){
                    el1=nums1[i];
                }
                 if(k==idx2){
                    el2=nums1[i];
                }
                i++;
                k++;
                
    }

    while(j<m){
         if(k==idx1){
         el1=nums2[j];
            }

         if(k==idx2){
         el2=nums2[j];
            }
            j++;
            k++;
    }

        if(size%2==1)return el2;
        return (el1+el2)/2.0;