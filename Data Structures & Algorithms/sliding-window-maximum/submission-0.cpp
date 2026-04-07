class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int left=0;
        while(left<n){
            pq.push({nums[left],left});
            if(left>=k-1){
                while(pq.top().second <= left-k){
                    pq.pop();
                }
                int max = pq.top().first;
                ans.push_back(max);
            }
            left++;
        }
        return ans;
    }
};
