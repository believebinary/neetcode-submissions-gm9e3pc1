class Solution {
public:

    struct trieNode{
        string wordStr;
        bool endOfWord;
        trieNode *children[26];
    };
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->wordStr = "";
        newNode->endOfWord = false;
        for(int i =0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    vector<string> ans;
    int m;
    int n;
    void insert(trieNode* root , string word){
        trieNode* crawler = root;
        for(char ch:word){

            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a'] = getNode();
            }
            crawler = crawler->children[ch-'a'];
        }
        crawler->endOfWord = true;
        crawler->wordStr = word;
    }

    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    void findWordInTrie(vector<vector<char>>& board, int i, int j, trieNode* root){

        if(i<0 || j<0 || j>=n || i>=m){
            return;
        }
        if(board[i][j]=='#' || root->children[board[i][j]-'a']==NULL){
            return;
        }
        root = root->children[board[i][j]-'a'];
        if(root->endOfWord == true ){
            ans.push_back(root->wordStr);
            root->endOfWord = false;
        }
        char ch = board[i][j];
        board[i][j] = '#';
        
        for(vector<int> &dir : directions){
            int new_i = dir[0] + i;
            int new_j = dir[1] + j;
            findWordInTrie(board,new_i,new_j,root);
        }
        board[i][j]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trieNode* root = getNode();
        m = board.size();
        n = board[0].size();

        for(string &str :words){
            insert(root,str);
        }

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                findWordInTrie(board, i, j, root);
            }
        }
        return ans;

    }
};
