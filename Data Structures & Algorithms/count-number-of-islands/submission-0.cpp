class Solution {
public:
    int m,n;
    int ans =0;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void find(vector<vector<char>>& grid, int i, int j){
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';

        for(vector<int> &dir : directions){
            int new_i = dir[0]+i;
            int new_j = dir[1]+j;
            find(grid,new_i,new_j);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    find(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
