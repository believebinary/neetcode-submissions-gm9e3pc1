class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n2<n1){
            return false;
        }
        sort(begin(s1),end(s1));
        for(int i = 0;i<=n2-n1;i++){
            string str = s2.substr(i,n1);
            sort(begin(str),end(str));
            if(str == s1){
                return true;
            }
        }
        return false;

    }
};
