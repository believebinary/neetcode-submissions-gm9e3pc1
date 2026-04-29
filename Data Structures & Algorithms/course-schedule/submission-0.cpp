class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adjMap;
        vector<int> indegree(numCourses,0);
        for(vector<int> &pre :prerequisites){
            int a = pre[0];
            int b = pre[1];

            adjMap[b].push_back(a);
            indegree[a]++;
        }

        queue<int> que;
        int count =0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }
        
        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int& v :adjMap[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                    count++;
                }
            }
        }

        if(count == numCourses){
            return true;
        }
        return false;
    }
};
