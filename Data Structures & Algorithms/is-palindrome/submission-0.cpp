class Solution {
public:
    bool isPalindrome(string s) {
        int n= s.length();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int start=0;
        int end = s.length()-1;
        while(start < end){
            if(!(s[start]>='a' && s[start]<='z' || s[start]>='0' && s[start]<='9')){
                start++;
                continue;
            }
            if(!(s[end]>='a' && s[end]<='z' || s[end]>='0' && s[end]<='9')){
                end--;
                continue;
            }
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
