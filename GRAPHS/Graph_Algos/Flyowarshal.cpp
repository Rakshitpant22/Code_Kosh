//& matrix m -1 ka mtlb ki koi link nhi h dono k beech
//^ to hum min lenge iske lie -1 (jah link nhi direct usko infinity declare kr denge)
// flyod warshall can detect negative cycles as when grid[i][j]<0return cycle present 
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix [i][j]=1e9;
	            }
	        }
	    }
	    for(int k=0;k<n;k++){// via =k
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               matrix[i][j]= min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	 //   last m jo apni suvidha k lie hamne -1 ko inf kia tha use dubara original krdo
	  for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix [i][j]=-1;
	            }
	        }
     	}
	   return matrix;
	}
};