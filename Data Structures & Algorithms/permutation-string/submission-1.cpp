class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n2<n1){
            return false;
        }
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        for(int i =0;i<n1;i++){
            arr1[s1[i]- 'a']++;
        }
        int left = 0;
        int right = 0;
        while(right<n2){
            arr2[s2[right]- 'a']++;
            if(right-left+1>n1){
                arr2[s2[left]-'a']--;
                left++;
            }
            if(arr1 == arr2){
                return true;
            }
            right++;
        }
        return false;

    }
};
