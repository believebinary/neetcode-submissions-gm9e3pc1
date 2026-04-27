class Solution {
public:
    int m,n;
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i,int j, vector<vector<bool>>& boolMat, vector<vector<int>>& heights,int height){
        if(i<0||j<0||i>=m||j>=n||boolMat[i][j]==true || heights[i][j]<height){
            return;
        }
        boolMat[i][j] = true;
        for(vector<int> &dir:directions){
            int new_i = dir[0]+i;
            int new_j = dir[1]+j;
            dfs(new_i,new_j,boolMat,heights,heights[i][j]);
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> altantic(m,vector<bool>(n,false));
        // pacific
        for(int i = 0; i < m; i++) dfs(i, 0, pacific, heights, INT_MIN);
        for(int j = 0; j < n; j++) dfs(0, j, pacific, heights, INT_MIN);

        // Atlantic: bottom row + right column
        for(int i = 0; i < m; i++) dfs(i, n-1, altantic, heights, INT_MIN);
        for(int j = 0; j < n; j++) dfs(m-1, j, altantic, heights, INT_MIN);
        vector<vector<int>> ans;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]==true && altantic[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;



   }
};
