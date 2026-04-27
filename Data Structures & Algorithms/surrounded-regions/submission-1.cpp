class Solution {
public:
    int m,n;
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i,int j, vector<vector<bool>>& boolMat, vector<vector<char>>& board){
        if(i<0||j<0||i>=m||j>=n||board[i][j]=='X' || boolMat[i][j]){
            return;
        }
        boolMat[i][j] = true;
        for(vector<int> &dir:directions){
            int new_i = dir[0]+i;
            int new_j = dir[1]+j;
            dfs(new_i,new_j,boolMat,board);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n= board[0].size();
        vector<vector<bool>> boolMat(m,vector<bool>(n,false));
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0||i==m-1||j==n-1) && board[i][j]=='O'){
                    dfs(i,j,boolMat,board);
                }
            }
        }
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && boolMat[i][j]==false){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
