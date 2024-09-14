// this will give ways to generate a true output .. 
class Solution {
    int f(int i,int j,int isTrue,string expression ){
         if(i>j)return 0;
         if(i==j){
             if(isTrue==1) return expression[i]=='t';
             else expression[i]== 'f';
         }
       int ways=0;
         for(ind=i+1; ind<=j-1;ind+=2){
           int lt= f(i,ind-1,1,expression);
           int rt= f(ind+1,j,1,expression);
           int lf= f(i,ind-1,0,expression);
           int rf= f(ind+1,j,0,expression);

           if(expression[ind]=='&'){
               if(isTrue) ways+=(lt*rt);
               else ways+= ((lt*rf)+(rt*lf)+(lf*rf));
           }

           else if(expression[ind]=='|'){
    
            if (isTrue) ways = (ways + (lf * rt) + (lt * rf) + (lt * rt));
            else ways = (ways + (lf * rf) );
        }
        else {
            if (isTrue) ways = (ways + (lf * rt) + (lt * rf)) ;
            else ways = (ways + (lf * rf) + (lt * rt));
        }
    }
    return ways;
           }
        
    }
public:
    bool parseBoolExpr(string expression) {
         int n = exp.size();
    return f(0, n - 1, 1, exp);
    }
};