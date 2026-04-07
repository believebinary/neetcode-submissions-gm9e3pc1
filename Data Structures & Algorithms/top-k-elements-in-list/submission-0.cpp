class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int smallest = 1;
        vector<int> result;
        vector<pair<int,int>> freqArr;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto m : mp){
            freqArr.push_back(make_pair(m.second,m.first));
        }
        sort(freqArr.rbegin(),freqArr.rend());
        for(int i=0;i<k;i++){
            result.push_back(freqArr[i].second);
        }
        return result;

    }
};
