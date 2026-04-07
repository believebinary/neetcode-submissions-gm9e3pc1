class Solution {
public:
    vector<string> ans;
    bool isValid(string s){
        stack<char> st;

        for(int i =0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
    void solve(string& s, int n){
        if(s.length()==n*2){
            if(isValid(s)){
               ans.push_back(s);
            }
            return;
        }
        s.push_back('(');
        solve(s,n);
        s.pop_back();
        s.push_back(')');
        solve(s,n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s,n);
        return ans;
    }
};
