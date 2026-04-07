class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i =0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        if(pq.size()==0){
            return 0;
        }
        while(pq.size()!=1){
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            pq.push(abs(top1-top2));
        }
        return pq.top();
    }
};
