class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n){
            return "";
        }
        unordered_map<char,int> smap;
        
        unordered_map<char,int> tmap;
        for(int i =0;i<m;i++){
            tmap[t[i]]++;
        }
        int left = 0;
        int right = 0;
        string ans = "";
        int need = tmap.size();
        int have =0;
        int startIndex = 0;
        int ansLen = INT_MAX;
        while(right<n){
            smap[s[right]]++;
            if(tmap.count(s[right]) && smap[s[right]] == tmap[s[right]]){
                have++;
            }
            while(need == have){
                if(ansLen>(right-left+1)){
                   startIndex = left;
                   ansLen = right-left+1;
                }
                smap[s[left]]--;
                if(tmap.count(s[left]) && smap[s[left]] < tmap[s[left]]){
                   have--;
                }
                left++;
            }
            right++;
        }

        
        return ansLen == INT_MAX ? "": s.substr(startIndex,ansLen);
    }
};
