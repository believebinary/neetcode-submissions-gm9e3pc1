class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        int start = 0;
        int end = numbers.size()-1;
        while(start<end){
            if(numbers[start]+numbers[end]==target){
                return {start+1,end+1};
            }
            if(numbers[start]+numbers[end]>target){
                end--;
            }
            if(numbers[start]+numbers[end]<target){
                start++;
            }

        }
        return {};
            
        
    }
};
