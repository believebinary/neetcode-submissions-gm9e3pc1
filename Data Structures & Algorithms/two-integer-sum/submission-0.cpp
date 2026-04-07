class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int len = nums.size()-1;
        for(int i = 0;i<nums.size();i++){
            int sumNeeded = target-nums[i];
            if((mp.find(sumNeeded)!= mp.end()) && mp[sumNeeded]!=i){
                return {mp[sumNeeded],i};
            }
            mp[nums[i]]=i;
        }
        int neededSum = target-nums[nums.size()-1];
        if(mp.find(neededSum) != mp.end()){
            return {mp[neededSum],len};
        }
        return {};
    }
};
