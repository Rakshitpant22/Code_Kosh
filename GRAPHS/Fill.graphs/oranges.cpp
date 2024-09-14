
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         // to store {<row,col> time}
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m]; // replica bna dia 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){ // agr i,j me jake rotten mila
                    q.push({{i,j},0});  //to q me push krdo TIME 0 k sath
                    vis[i][j]=2; // or lage hath visited m bhi rotten mark krdo
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        // 4 DIRECTIONS M DEKHNE K LIE FUNCTION TAYYAR KIA H
        int delrow[]={0,0,-1,1};
       int delcol[]={-1,1,0,0};
        int time=0; //time ko initially 0 declare kia hai
        while(!q.empty()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            time= q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                
            int nrow= row+delrow[i];
            int ncol= col +delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  && vis[nrow][ncol] != 2 
            && grid[nrow][ncol]==1){
                q.push({{nrow,ncol},time+1});
                vis[nrow][ncol]=2;
                }
            }
         
        }
        // check agr koi bhi fresh last m rotten nhi rha to retuen -1;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] !=2 && grid[i][j]==1 ){
                 return -1;
                }
            }
            }
        return time;
    }
    