class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool find(vector<vector<char>>& board, string word,int i, int j,int idx){
         if(idx == word.length()){
            return true;
         }
         if(i<0 || j<0 || i>=n || j>= m || board[i][j] == '#'){
            return false;
         }
         if(board[i][j]!=word[idx]){
            return false;
         }
         char temp = board[i][j];
         board[i][j] = '#';
         
         for(auto& dir: directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(find(board,word,new_i,new_j,idx+1)){
                return true;
            }
         }
         board[i][j] = temp;
         return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i =0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[i][j]==word[0]&&find(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
