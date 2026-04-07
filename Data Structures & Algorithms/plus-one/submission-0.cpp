class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum =0;
        int n = digits.size();
        vector<int> ans;
        int sum1= digits[n-1]+1;
        int carry = -1;
        if(sum1>9){
           carry = sum1/10;
        }
        if(carry == -1){
            digits[n-1] = digits[n-1]+1;
            return digits;
        }
        ans.push_back(sum1%10);
        for(int i =n-2;i>=0;i--){
            int digit = digits[i]+carry;
            if(digit>9){
                carry = digit/10;
                digit = digit%10;
            }
            else{
                carry = 0;
            }
            ans.push_back(digit);
        }
        if(carry>0){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
