class Solution {
public:
    int sumOfDigits(int num){
        int n=0;
        while(num>0){
            int n1 = num%10;
            n+=n1*n1;
            num = num/10;
        }
        return n;
    }
    bool isHappy(int n) {
        int rev = sumOfDigits(n);
        unordered_set<int> set1;
        set1.insert(rev);
        while(rev!=1){
          rev = sumOfDigits(rev);
          if(set1.find(rev) != set1.end() ){
            return false;
          }
          set1.insert(rev);
          
        }
        return true;
        
        
    }
};
