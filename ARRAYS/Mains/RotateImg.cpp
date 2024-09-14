//!for clockwise pehle transpose nikalo for sari row ko reverse krdo

void rotate(vector<vector<int>>& matrix) {
      int n=  matrix.size();

      for(int i=0;i<n;i++){
        for (int j=i;j<n;j++){
          swap(matrix[i][j],matrix[j][i]);
        }
      }

       for(int i=0;i<n;i++){
         reverse(matrix[i].begin(),matrix[i].end());
       }

    }
//!  for anticlockwise pehle reverse krdo for transpose nikaldo