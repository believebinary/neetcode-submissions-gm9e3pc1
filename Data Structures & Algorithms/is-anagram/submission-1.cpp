class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> set1;
        map<char,int> set2;
        if(s.length() != t.length()){
            return false;
        }
        for(int i = 0; i<s.length() ; i++){
            set1[s[i]]++;
        }
        for(int i = 0; i<t.length() ; i++){
            set2[t[i]]++;
        }
        if(set1==set2){
            return true;
        }
        return false;

    }
};
