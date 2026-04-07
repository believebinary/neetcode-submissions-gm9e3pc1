class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,int>> combinedVec;
        stack<float> stk;

        for(int i =0;i<position.size();i++){
            combinedVec.push_back({position[i],speed[i]});
        }
        sort(combinedVec.begin(),combinedVec.end(),greater<pair<int, int>>());

        for(int i =0; i<combinedVec.size();i++){
            float timeTaken = (float)(target-combinedVec[i].first)/combinedVec[i].second;
            if(stk.size()>0){
                float topEle = stk.top();
                if(topEle>=timeTaken){
                    continue;
                }
            }
            stk.push(timeTaken);
            
        }
        return stk.size();
    }
};
