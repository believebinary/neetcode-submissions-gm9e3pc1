class WordDictionary {
public:
    
    struct trieNode {
        bool endOfWord;
        trieNode *arr[26];
    };
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;

        for(int i =0;i<26;i++){
            newNode->arr[i]= NULL;
        }
        return newNode;
    }
    trieNode* root;
    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        trieNode* crawler = root;

        for(char ch : word){
            if(crawler->arr[ch-'a']==NULL){
                trieNode* newNode = getNode();
                crawler->arr[ch-'a'] = newNode;
            }
            crawler = crawler->arr[ch-'a'];
        }
        crawler->endOfWord = true;
    }
    bool searchUtil(trieNode* root, string word){
        trieNode* crawler = root;
        
        for(int j=0;j<word.length();j++){
            char ch = word[j];
            if(ch == '.'){
                 for(int i =0; i<26;i++){

                    if(crawler->arr[i] != NULL && searchUtil(crawler->arr[i],word.substr(j+1))){
                        return true;
                    }
                 }
                 return false;
            }
            else if(crawler->arr[ch-'a']==NULL){
                return false;
            }
            crawler = crawler->arr[ch-'a'];
        }

        return crawler!= NULL && crawler->endOfWord;
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
};
