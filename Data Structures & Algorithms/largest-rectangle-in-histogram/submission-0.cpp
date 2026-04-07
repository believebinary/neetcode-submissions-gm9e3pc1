class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea =0;
        int n= heights.size();
        stack<pair<int,int>> stk;
        for(int i =0;i<heights.size();i++){
            int startIndex = i;
            while(stk.size()>0 && stk.top().first>heights[i]){
                int currHeight = stk.top().first;
                int indexCurr = stk.top().second;
                maxArea = max(maxArea,(currHeight*(i-indexCurr)));
                startIndex = indexCurr;
                stk.pop();
            }
            stk.push({heights[i],startIndex});
        }
        while(stk.size()>0){
            int currHeight = stk.top().first;
            int indexCurr = stk.top().second;
            maxArea = max(maxArea,(currHeight*(n-indexCurr)));
            stk.pop();
        }
        return maxArea;
    }
};
