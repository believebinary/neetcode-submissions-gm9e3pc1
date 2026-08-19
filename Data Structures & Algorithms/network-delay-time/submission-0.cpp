class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    int m = times.size();
    unordered_map<int,vector<pair<int,int>>> mp;
    for(vector<int> &vec : times){
        mp[vec[0]].push_back({vec[2],vec[1]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,k});
    vector<int> res(n,INT_MAX);
    res[k-1] = 0;
    while(!pq.empty()){
        pair<int,int> topEle = pq.top();
        pq.pop();
        int d = topEle.first;
        for(pair<int,int> &vec : mp[topEle.second]){
            
            int targetEle = vec.second;
            int weight = vec.first;
            if(res[targetEle-1] > weight+d){
                res[targetEle-1] = weight+d;
                pq.push({weight+d,targetEle});
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans = max(ans,res[i]);
    }
    return ans==INT_MAX ? -1: ans;
  }
};
