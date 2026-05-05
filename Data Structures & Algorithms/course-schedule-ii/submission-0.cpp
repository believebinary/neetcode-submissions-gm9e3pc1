class Solution {
public:
    stack<int> st;
    int n;
    bool dfs(int currentIndex ,unordered_map<int, vector<int>> adjMap, vector<bool>& visited ,unordered_map<int,int>& cycle){
        if(visited[currentIndex] || currentIndex<0 || currentIndex>=n || cycle.count(currentIndex)){
            return false;
        }  
        cycle[currentIndex]++;
        visited[currentIndex] = true;
        for(int& adj: adjMap[currentIndex]){
             if(!visited[adj]){
                if(!dfs(adj,adjMap,visited,cycle)){
                   return false;
                }
             }
        }
        
        st.push(currentIndex);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjMap;
        vector<bool> visited(numCourses,false);
        unordered_map<int, int> cycle;
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        queue<int> q;
        n = numCourses;
        for(vector<int> &pre :prerequisites){
            int a = pre[0];
            int b = pre[1];
            adjMap[b].push_back(a);
            indegree[a]++;
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
                count++;
            }
        }

        // for(int i =0;i<numCourses;i++){
        //     if(!dfs(i,adjMap,visited,cycle)){
        //         return {};
        //     }
        // }
        // vector<int> ans;
        // while(!st.empty()){
        //     int ele = st.top();
        //     st.pop();
        //     ans.push_back(ele);
        // }

        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(int i =0;i<adjMap[ele].size();i++){
                indegree[adjMap[ele][i]]--;
                if(indegree[adjMap[ele][i]] == 0){
                    q.push(adjMap[ele][i]);
                    ans.push_back(adjMap[ele][i]);
                    count++;
                }
            }

        }

        if(count==n){
            return ans;
        }
        return {};
        


    }
};
