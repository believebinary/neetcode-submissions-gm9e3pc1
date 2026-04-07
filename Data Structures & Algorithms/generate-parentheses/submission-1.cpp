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
    void solve(string& s, int n ,int open,int close){
        if(s.length()==n*2){
            if(isValid(s)){
               ans.push_back(s);
            }
            return;
        }
        if(open>0){
           s.push_back('(');
           solve(s,n,open-1,close);
           s.pop_back();
        }
        if(close>0){
            s.push_back(')');
            solve(s,n,open, close-1);
            s.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int open =n;
        int close = n;
        solve(s,n,open,close);
        return ans;
    }
};
