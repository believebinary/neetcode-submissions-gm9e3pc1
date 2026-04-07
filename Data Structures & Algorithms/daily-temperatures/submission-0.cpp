class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        vector<int> ans(temperatures.size(),0);
        for(int i = 0;i<temperatures.size();i++){
            while(stk.size()>0 && stk.top().first<temperatures[i]){
                ans[stk.top().second] = i-stk.top().second;
                stk.pop();
            }
            stk.push({temperatures[i],i});

        }
        return ans;
    }
};
