//! Sieve of Eratosthenes
 vector<bool>prime(n,true);

     for(int i=2;i*i<n;i++){
           if(!prime[i])continue;
           for(int j=i*i;j<n;j+=i){
               prime[j]=false;
           }
     }
https://github.com/adrianhajdin/project_chat_application
https://github.com/adrianhajdin/project_video_chat

//! set bits in Number
int countSetBits(int n)
    {   int cnt=0;
    // for(int i=1;i<=n;i++){
    //     cnt+= __builtin_popcount(i);
    // }
        
    //     for(int i=1;i<=n;i++){
    //      for(int bit=0;bit<32;bit++){
    //         if( i & (1<<bit)){
    //             cnt++;
    //         }
    //     }
    // }
    
    //  vector<int>dp(n+1,0); //no of set bits in ith number 
    //  for(int i=1;i<=n;i++){
    //      if(i%2==0){
    //          dp[i]=dp[i/2];
    //      }
    //      else{
    //          dp[i]=dp[i/2]+1;
    //      }
    //      cnt+=dp[i];
    //  }
    
    int x= floor(sqrt(n));
    
    
      return cnt;
    }