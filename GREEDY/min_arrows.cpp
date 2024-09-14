// An array points where each element [xstart, xend] represents a balloon with a horizontal span from xstart to xend.
// Find the minimum number of arrows needed to burst all balloons. An arrow shot at a point x will burst all balloons whose horizontal span includes x.

//brute
    vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            if(ans.empty()|| ans.back()[1]< points[i][0]){
                ans.push_back(points[i]);
            }
            else{
                ans.back()[0]=max(ans.back()[0],points[i][0]);
                ans.back()[1]=min(ans.back()[1],points[i][1]);

            }
        }
        return ans.size();

//! optimal
    sort(points.begin(),points.end());
        int prev=points[0][1];
        int cnt=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>prev){
                cnt++;
                prev=points[i][1];
            }
            else{
                 prev=min(prev,points[i][1]);
            }   
        }
        return cnt;
        
    