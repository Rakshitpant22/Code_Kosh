//!--> MOORE VOTING ALGORITHM
//? for array max majority elements can be k-1 where n/k;

int majorityElement(vector<int>& nums) {
  int n=nums.size();
        int cnt=0;
        int element;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                element=nums[i];
            }
            else if(nums[i]==element){
                cnt++;
            }
            else{
            cnt--;
            }
        }

//verification;:
    int cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el)cnt2++;
        }
        if(cnt2 > n/2){
            return el;
        }
        return -1;
    }



//^ for > n/3 majority element;

 vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;int cnt2=0;
        int element1=0;int element2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==element1){
                cnt1++;
            }
            else if(nums[i]==element2){
                cnt2++;
            }
            else if(cnt1==0){
                element1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
            element2=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

    vector<int>res;
        int freq1=0;
        int freq2=0;
        for(int i=0;i<n;i++){
          if(nums[i]==element1)
              freq1++;
          
        else if(nums[i]==element2)
              freq2++;
        }

        if(freq1 >floor(n/3)){
            res.push_back(element1);
        }
         if(freq2 >floor(n/3)){
            res.push_back(element2);
        }
        return res;
    }

