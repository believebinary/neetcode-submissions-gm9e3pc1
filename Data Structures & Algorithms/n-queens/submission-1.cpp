class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> colSet;
    unordered_set<int> diagonalSet;
    unordered_set<int> antiDiagonalSet;
    bool isValid(vector<string> grid,int col,int row){

        for(int i=row-1;i>=0;i--){
            if(grid[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0 && j<grid.size();i--,j++){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>& grid,int row,int n){
         if(row>=n){
            ans.push_back(grid);
            return;
         }
         for(int col = 0;col<n;col++){
            int diagCol = col+row;
            int antidiagCol = row-col;

            if(colSet.find(col) == colSet.end() && antiDiagonalSet.find(antidiagCol) == antiDiagonalSet.end() && diagonalSet.find(diagCol) == diagonalSet.end()){
                colSet.insert(col);
                antiDiagonalSet.insert(antidiagCol);
                diagonalSet.insert(diagCol);
                grid[row][col]='Q';
                solve(grid,row+1,n);
                grid[row][col]='.';
                colSet.erase(col);
                antiDiagonalSet.erase(antidiagCol);
                diagonalSet.erase(diagCol);
            }
         }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n,string(n,'.'));
        int row = 0;
        solve(grid,row,n);
        return ans;
    }
};
