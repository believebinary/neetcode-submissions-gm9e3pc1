class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int arr[26]={0};
        for(int i=0;i<tasks.size();i++){
            arr[tasks[i]-'A']++;
        }
        for(int i =0;i<26;i++){
            if(arr[i]!=0){
               pq.push(arr[i]);
            } 
        }
        int ans =0;
        while(!pq.empty()){
            vector<int> tempVec;
            for(int i=0;i<=n;i++){
               if(!pq.empty()){
                  int freq = pq.top();
                  pq.pop();
                  freq--;
                  tempVec.push_back(freq);
               }
            }
            for(int i=0;i<tempVec.size();i++){
                if(tempVec[i]!=0){
                   pq.push(tempVec[i]);
                }
            }
            if(pq.empty()){
               ans+=tempVec.size();
            }
            else{
                ans+=n+1;
            }
        }
        return ans;
    }
};
