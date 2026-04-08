class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh =0;
        vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int time = 0;
        while(!q.empty() && fresh>0){
            int len = q.size();
            for(int i =0;i<len;i++){

                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(vector<int> &dir : directions){
                    int new_r = r+dir[0];
                    int new_c = c+dir[1];
                    if(new_r<0 || new_r >= m || new_c <0 || new_c>=n || grid[new_r][new_c] != 1){
                        continue;
                    }
                    else{
                        q.push({new_r,new_c});
                        grid[new_r][new_c] = 2;
                        fresh--;
                    }
                }
            }
            time++;
            
        }
        // for(int i =0;i<m;i++){
        //     for(int j =0;j<n;j++){
        //         if(grid[i][j] != 0 || !visit[i][j]){
        //             return -1;
        //         }
        //     }
        // }
        return fresh==0?time:-1;
 
    }
};
