class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(int i = 0; i<s.length(); i++){
            if(!st.empty() && closeToOpen.count(s[i]) && closeToOpen[s[i]] == st.top()){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};
