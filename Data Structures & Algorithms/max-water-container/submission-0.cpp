class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int n = heights.size();
        int start = 0;
        int end = n-1;
        int maxArea = min(heights[start],heights[end])*(end-start);
        while(start<end){
            if(heights[start] > heights[end]){
                end--;
            }
            else{
                start++;
            }
            maxArea = max(maxArea,(min(heights[start],heights[end])*(end-start)));
        }
        return maxArea;
    }
};
