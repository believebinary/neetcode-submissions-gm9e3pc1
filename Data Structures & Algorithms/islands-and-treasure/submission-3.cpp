class Solution {
public:
    const int INF = 2147483647 ;
    int m,n;
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

    int bfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visitVec){
        queue<pair<int,int>> bfsQueue;
        bfsQueue.push({i,j});
        int ans = 1;
        while(!bfsQueue.empty()){
            pair<int,int> front = bfsQueue.front();
            bfsQueue.pop();
            for(vector<int> &dir :directions){
                int new_I = dir[0]+front.first;
                int new_J = dir[1]+front.second;

                if(grid[new_I][new_I] == INF){
                    bfsQueue.push({new_I,new_J});
                    visitVec[new_I][new_J] = true;
                }
                if(grid[new_I][new_I] == 0){
                    return ans;
                }

            }
            ans++;
        }
        
        return INF;
    }
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visitVec){
        if(i>=m || j>=n || i<0 || j<0 || visitVec[i][j] || grid[i][j] == -1){
            return INF;
        }
        if(grid[i][j] == 0){
            return 0;
        }
        int ans = INF;
        visitVec[i][j] = true;

        for(vector<int> &dir : directions){
            int new_i = dir[0]+i;
            int new_j = dir[1]+j;
            
            int cur = dfs(grid,new_i,new_j,visitVec);

            if(cur != INF){
                ans = min(ans, 1+ cur);
            }
        }
        visitVec[i][j] = false;
        return ans;
    }
    queue<pair<int,int>> bfsQueue;
    void addRoom(int i ,int j,vector<vector<int>>& grid,vector<vector<bool>> &visitVec){
        if(i<0 || j<0||i>=m || j>=n || grid[i][j] == -1 || visitVec[i][j]){
            return;
        }
        visitVec[i][j]=true;
        bfsQueue.push({i,j});
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n= grid[0].size();
        vector<vector<bool>> visitVec(m,vector<bool>(n,false));
        
        
        for(int i =0;i< m;i++){
            for(int j=0;j<n;j++){
                // if(grid[i][j]!=-1 && grid[i][j]!=0){
                //     grid[i][j] = dfs(grid,i,j,visitVec);
                // }
                if(grid[i][j] == 0){
                    visitVec[i][j]= true;
                    bfsQueue.push({i,j});
                }
            }
        }

        while(!bfsQueue.empty()){
                int row = bfsQueue.front().first;
                int col = bfsQueue.front().second;
                bfsQueue.pop();
                for(vector<int> &dir : directions){
                    int r = row+dir[0];
                    int c = col+dir[1];
                    if (r < 0 || r >= m || c < 0 ||
                    c >= n || grid[r][c] != INT_MAX) {
                    continue;
                }
                grid[r][c] = grid[row][col] + 1;
                bfsQueue.push({r, c});
                }
            }
        }

    
};
