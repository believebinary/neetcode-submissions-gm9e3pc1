class PrefixTree {
public:
    
    struct trieNode{
        bool endOfWord;
        trieNode *charArr[26];
    };
    trieNode* getTrieNode(){
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        for(int i=0;i<26;i++){
            newNode->charArr[i]= NULL;
        }

        return newNode;
    }
    trieNode* root;
    PrefixTree() {
        root = getTrieNode();
    }
    
    void insert(string word) {
        trieNode* crawl = root;
        for(char ch : word){
            if(crawl->charArr[ch-'a'] == NULL){
                crawl->charArr[ch-'a'] = getTrieNode();
            }
            crawl = crawl->charArr[ch-'a'];
        }
        crawl->endOfWord = true;
    }
    
    bool search(string word) {

        trieNode* crawl = root;
        for(char ch : word){
            if(crawl->charArr[ch-'a'] == NULL){
                return false;
            }
            crawl = crawl->charArr[ch-'a'];
        }
        if(crawl->endOfWord == true){
            return true;
        }
        return false;
        
        
    }
    
    bool startsWith(string prefix) {
        
        trieNode* crawl = root;
        int i =0;
        for(char ch : prefix){
            if(crawl->charArr[ch-'a'] == NULL){
                return false;
            }
            crawl = crawl->charArr[ch-'a'];
            i++;
        }
        if(i == prefix.length()){
            return true;
        }
        return false;
    }
};
