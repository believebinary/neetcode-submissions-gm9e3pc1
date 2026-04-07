class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> pq;
        vector<vector<int>> ans;
        for(int i =0;i<points.size();i++){
            vector<int> point = points[i];
            double distance = sqrt(point[0]*point[0]+point[1]*point[1]);
            pq.push({distance,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            pair<int,int> topEle = pq.top();
            pq.pop();
            ans.push_back(points[topEle.second]);
        }
        return ans;
    }
};
