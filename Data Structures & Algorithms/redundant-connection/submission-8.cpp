class Solution {
public:
    unordered_map<int,vector<int>> adjMap;
    bool dfs(int a,int b,vector<bool>& visited){
         if(a==b){
            return true;
         }
         visited[a] = true;
         for(int& ele :adjMap[a]){
            if(!visited[ele]){
                if(dfs(ele,b,visited)){
                    return true;
                }
            }
         }

         return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        adjMap.clear();
        int n = edges.size();
        unordered_set<int> vertices;
        bool flag = false;
        vector<int> ans;
        bool flag2 = false;
        bool ansfound = false;
        for(vector<int>& vec :edges){
            int a = vec[0];
            int b = vec[1];
            vector<bool> visited(n + 1, false);
            if(adjMap.find(a)!=adjMap.end() && adjMap.find(b)!=adjMap.end() && dfs(a,b,visited)){
                return {a,b};
            }
            adjMap[b].push_back(a);
            adjMap[a].push_back(b);
        }
        return {};
        
        

    }
};
