class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int smallest = 1;
        vector<int> result;
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto m:mp){
            pq.push(make_pair(m.second,m.first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;

    }
};
