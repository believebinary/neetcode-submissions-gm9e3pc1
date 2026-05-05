class Solution {
public:
    unordered_map<int,vector<int>> adjMat;
    
    bool isCycle(int parent,int child,vector<bool> &visited){
        if(visited[child]){
            return true;
        }
        visited[child] = true;

        for(int &val :adjMat[child]){
            if(val != parent){
                if(isCycle(child,val,visited)){
                    return true;
                }
            }
        }

        return false;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<bool> visited(n,false);
        adjMat.clear();
        for(vector<int> &edge : edges){
            int a = edge[0];
            int b = edge[1];

            adjMat[a].push_back(b);
            adjMat[b].push_back(a);
        }

        if(isCycle(-1,0,visited)){
            return false;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};
