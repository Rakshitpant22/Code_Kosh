 int solve(int n){  //calculates xor from 1 to n as xor is cyclic property
      if(n%4==0)return n;
      if(n%4==1)return 1;
      if(n%4==2)return n+1;
      return 0;
  }

    int findXOR(int l, int r) {
       if(l==0)return solve(r);
       return solve(r)^solve(l-1);
    }