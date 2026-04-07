class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        for(int i =0 ;i<n;i++){
            unordered_map<char,int> mp;
            mp.reserve(255);
            for(int j=i;j<n;j++){
                if(mp[s[j]]==1){
                    break;
                }
                maxLen = max(maxLen,(j-i+1));
                mp[s[j]]++;
            }
        }
        return maxLen;
    }
};
