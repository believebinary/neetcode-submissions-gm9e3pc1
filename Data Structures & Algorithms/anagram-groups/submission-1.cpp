class Solution {
public:
    string returnString(string str){
        int n = str.length();
        int chaArr[26] = {0};
        
        for(int i = 0; i<n;i++){
            chaArr[str[i]-'a']++;
        }
        string newStr = "";
        for(int i=0;i<26;i++){
            if(chaArr[i]!=0){
               newStr+= string(chaArr[i],i+'a');
            }
        }
        return newStr;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<string,vector<string>> mp;
       vector<vector<string>> result;
       for(int i = 0;i< strs.size(); i++){
          string str = returnString(strs[i]);
          
          mp[str].push_back(strs[i]);
       }
       for(auto t :mp){
          result.push_back(t.second);
       } 
       return result;
    }
};
