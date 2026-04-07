class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()==0){
            return true;
        }
        vector<unordered_set<char>> rowSet(board.size());
        vector<unordered_set<char>> colSet(board.size());
        vector<unordered_set<char>> matrixSet(board.size());
        for(int i =0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
               if(board[i][j]=='.'){
                continue;
               }
               if(rowSet[i].find(board[i][j])!= rowSet[i].end()){
                return false;
               }
               rowSet[i].insert(board[i][j]);
               if(colSet[j].find(board[i][j])!= colSet[j].end()){
                return false;
               }
               colSet[j].insert(board[i][j]);
               int matrixIndex = (i/3)*3+(j/3);
               if(matrixSet[matrixIndex].find(board[i][j])!= matrixSet[matrixIndex].end()){
                return false;
               }
               matrixSet[matrixIndex].insert(board[i][j]);
            }
        }

        return true;
    }
};
