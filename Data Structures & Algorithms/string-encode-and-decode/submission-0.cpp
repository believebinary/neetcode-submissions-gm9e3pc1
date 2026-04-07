class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(int i = 0;i<strs.size();i++){
            string str = strs[i];
            int len = strs[i].length();
            result = result + to_string(len) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,(j-i)));
            ans.push_back(s.substr(j+1,len));
            i = j+len+1;
        }
        return ans;
    }
};
