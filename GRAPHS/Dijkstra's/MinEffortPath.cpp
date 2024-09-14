class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
         vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

        vector<vector<int>> distance(n, vector<int>(m, 1e9));

        distance[0][0] = 0;
        pq.push({0, {0, 0}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while (!pq.empty())
        {
            auto it = pq.top();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {

                    int neweffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if (neweffort < distance[nrow][ncol])
                    {
                        distance[nrow][ncol] = neweffort;
                        pq.push({neweffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0; // if unreachable;
    }
};