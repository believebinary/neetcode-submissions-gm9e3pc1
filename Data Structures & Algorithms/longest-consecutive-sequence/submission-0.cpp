class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx = 0;
        unordered_set<int> hashSet(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(hashSet.find(nums[i]-1)==hashSet.end()){
                int startNum = nums[i];
                int len = 1;
                while(hashSet.find(startNum+1)!=hashSet.end()){
                     startNum++;
                     len++;
                }
                mx= mx>len ? mx : len;
            }
            
        }
        return mx;
    }
};
