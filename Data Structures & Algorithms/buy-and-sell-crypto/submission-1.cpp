class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int left =0;
        int right =1;
        int end = prices.size();
        int maxProfit = 0;
        while(right<end){
            if(prices[left]<prices[right]){
                maxProfit = max((prices[right]-prices[left]),maxProfit);
            }
            else{
               left = right;
            }
            right++;
        }
        return maxProfit;
    }
    
};
