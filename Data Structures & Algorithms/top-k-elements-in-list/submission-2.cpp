class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int smallest = 1;
        vector<int> result;
        vector<vector<int>> bucketVec(n+1);
        //using index as frequency
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto &m :mp){
            bucketVec[m.second].push_back(m.first);
        }
        for(int i= bucketVec.size()-1;i>=0;i--){
            if(bucketVec[i].size()==0){
                continue;
            }
            while(!bucketVec[i].empty() && k>0){
                result.push_back(bucketVec[i].back());
                bucketVec[i].pop_back();
                k--;
            }
        }
        return result;

    }
};
