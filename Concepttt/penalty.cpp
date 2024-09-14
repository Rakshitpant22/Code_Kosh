//! USING PREFIX AND SUFFIX  TC=3*O(n) and SC=2*O(n);

public:
    int bestClosingTime(string customers) {
       int n= customers.size();

       vector<int>suffix(n+1,0);
       vector<int>prefix(n+1,0);
     
     
       for(int i=1;i<=n;i++){
           if(customers[i-1]=='N'){
               prefix[i]=prefix[i-1]+1;
           }
           else
           prefix[i]=prefix[i-1];
       }
       
       suffix[n]=0;
       for(int i=n-1;i>=0;i--){
           if(customers[i]=='Y'){
               suffix[i]=suffix[i+1]+1;
           }
           else
           suffix[i]=suffix[i+1];
       }

       int min1=1e9;
        int index=0;
       for(int i=0;i<=n;i++){
           if (suffix[i]+prefix[i] < min1){
                min1 = suffix[i]+prefix[i];
                index = i;
            }
        }
        return index;
    }

    //! for O(1) and TC= 2 * O(n)
int bestClosingTime(string customers) {
         int  n=customers.size();
         int hour=0;
         int penalty=count(customers.begin(),customers.end(),'Y');

         int min_penalty=penalty;
         for(int i=0;i<n;i++){
             if(customers[i]=='Y'){
                 penalty--;
             }
             else {
                 penalty++;
             }

         if(min_penalty > penalty){
             min_penalty= penalty;
             hour= i+1;
            }

         }
         return hour;
    }