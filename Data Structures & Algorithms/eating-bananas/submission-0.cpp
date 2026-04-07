class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left =1;
        int right = piles[0];
        int n= piles.size();
        for(int i = 1;i<n;i++){
            right = max(right,piles[i]);
        }
        int ans = right;
        while(left<=right){
            int mid = left + (right-left)/2;
            
            int newHours = getValidHours(piles,mid);

            if(newHours <= h){
                ans = min(ans, mid);
                right=mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }

    int getValidHours(vector<int>& piles, int num){
        int sum =0;
        for(int i=0;i<piles.size();i++){
            sum += (piles[i] + num - 1) / num;
        }
        return sum;
    }
};
