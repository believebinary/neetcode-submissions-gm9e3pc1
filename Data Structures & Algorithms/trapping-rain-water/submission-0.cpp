class Solution {
public:
    int trap(vector<int>& height) {
        

        int start =0;
        int end = height.size()-1;
        int leftMax = 0;
        int rightMax = 0;
        int maxArea = 0;
        while(start<end){
            if(height[start]>height[end]){
                rightMax = max(height[end],rightMax);
                end--;
                if(height[end]<rightMax){
                    maxArea+=(rightMax-height[end]);
                } 
            }
            else{
                leftMax = max(leftMax,height[start]);
                start++;
                if(height[start]<leftMax){
                    maxArea+=(leftMax-height[start]);
                } 
            }
            

        }
        return maxArea;
    }
};
