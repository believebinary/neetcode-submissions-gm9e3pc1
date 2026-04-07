class Solution {
public:
    unordered_map<char, string> m = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    int n;
    vector<string> ans;
    void solve(string& s,string digits,int idx){
        if(idx == digits.length()){
            ans.push_back(s);
            return;
        }
        string newStr = m[digits[idx]];
        for(int i = 0;i<newStr.length();i++){
            s.push_back(newStr[i]);
            solve(s,digits,idx+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        string s = "";
        if(digits.length()==0){
            return {};
        }
        solve(s,digits,0);
        return ans;
    }
};
