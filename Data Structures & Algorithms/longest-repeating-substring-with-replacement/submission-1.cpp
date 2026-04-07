class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int maxLen = 0;
        unordered_map<char,int> mp;
        mp.reserve(26);
        while(l<n && r<n){
            mp[s[r]-'A']++;
            maxFreq = max(maxFreq,mp[s[r]-'A']);
            while((r-l+1-maxFreq)>k){
                mp[s[l]-'A']--;
                maxFreq=0;
                for(int i =0;i<26;i++){
                    maxFreq = max(maxFreq,mp[i]);
                }
                l++;
            }
            if((r-l+1-maxFreq)<=k){
                maxLen = max(maxLen,r-l+1);
            }
            r++;
            
        }
        return maxLen;
    }
};
