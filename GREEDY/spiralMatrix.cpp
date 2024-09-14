//! spiral matrix 1
int n=matrix.size(),m=matrix[0].size();

    int left=0,right=m-1,top=0,bottom=n-1;
    
    vector<int>ans;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

       for(int i=top;i<=bottom;i++){
          ans.push_back(matrix[i][right]);
       
       right--;

        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
     return ans;
    }

//! give spiral matrix in cloclwise direction(given from where to start) travel E S W N
        vector<vector<int>>ans;
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};

        int steps=0,dir=0; //steps taken in dir(dkrection)
        
        ans.push_back({rStart,cStart});
        while(ans.size()!=rows*cols){
             if(dir==0 ||dir==2){  //east or west me hi steps bd rhe hai
                steps++;
             }

             for(int i=0;i<steps;i++){
                rStart=rStart+directions[dir][0];
                cStart=cStart+directions[dir][1];

                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                    ans.push_back({rStart,cStart});
                }
             }
             dir=(dir+1)%4; // change east->south->west->north directions
        }
        return ans;

