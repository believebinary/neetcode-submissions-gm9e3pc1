class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int start =i+1;
            int end = n-1;
            while(start<end){
                int sum = nums[start]+nums[end]+nums[i];
                if(sum>0){
                    end--;
                }
                else if(sum<0){
                    start++;
                }
                else if(sum==0){
                    ans.push_back({nums[start],nums[end],nums[i]});
                    start++;
                    while(start>0 && nums[start]==nums[start-1]){
                        start++;
                    }
                    
                }
            }

        }
        return ans;
    }
};
