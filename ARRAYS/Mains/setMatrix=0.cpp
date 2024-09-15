// brute
void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m =  matrix[0].size();
        vector<vector<int>>vis=matrix;
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    vis[i][j]=0;
                   for(int k=0;k<m;k++){// for row=0..
                       vis[i][k]=0;
                   }
                }
            }
        }
              
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    vis[i][j]=0;
                   for(int k=0;k<n;k++){// for col=0..
                       vis[k][j]=0;
                   }
                }
            }
        }
       matrix = vis;
    }

//better 
vector<bool>row(n,0),col(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]){
                    matrix[i][j]=0;
                }
                else if(col[j]){
                    matrix[i][j]=0;
                }
            }
        }


