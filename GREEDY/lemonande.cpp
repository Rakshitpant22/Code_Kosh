//Lemonande change
 int i5=0,i10=0;
 int n=bills.size();

        for(int i=0;i<n;i++){
            if(bills[i]==5) {
                i5++;
            }
            else if(bills[i]==10){
                if(i5==0)return false;

                else {
                    i10++; 
                    i5--;
                }
            }
            else{
                if(i10>0 && i5>0){
                    i10--;i5--;
                }
                else if(i5>=3){
                    i5-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
        
//Assign cookies
