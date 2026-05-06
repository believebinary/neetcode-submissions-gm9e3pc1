class Solution {
public:
    unordered_map<int,vector<int>> adjMap;

    void dfs(int i, vector<bool>& visited){
        if(visited[i]){
            return;
        }
        visited[i]=true;

        for(int& ele: adjMap[i]){
            dfs(ele,visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        adjMap.clear();
        vector<bool> visited(n,false);
        for(vector<int>& vec :edges){
            int a = vec[0];
            int b = vec[1];

            adjMap[a].push_back(b);
            adjMap[b].push_back(a);
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited);
                count++;
            }
            
        }

        return count;
    }
};
