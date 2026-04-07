class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int l=0;
        int r=0;
        unordered_map<char,int> mp;
        mp.reserve(255);
        while(r<n && l<n){
            
            if(mp[s[r]]==1){
                mp[s[l]]=0;
                l++;
            }
            else{
                mp[s[r]]++;
                r++;
            }
            maxLen = max(maxLen,(r-l));
        }
        return maxLen;
    }
};
