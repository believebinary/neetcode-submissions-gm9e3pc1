class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<string,vector<string>> mp;
       vector<vector<string>> result;
       for(int i = 0;i< strs.size(); i++){
          string str = strs[i];
          sort(begin(str),end(str));
          mp[str].push_back(strs[i]);
       }
       for(auto t :mp){
          result.push_back(t.second);
       } 
       return result;
    }
};
