class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int m = nums1.size();
        int n = nums2.size();

        int totalSize = m+n;


        int l=0;
        int r=m;
        while(l<=r){

            int idx1 = l+(r-l)/2;
            int n2 = (totalSize+1)/2 - idx1;
            
            //left partition
            int x1 = (idx1 == 0) ? INT_MIN : nums1[idx1-1];
            int x2 = (n2 == 0) ? INT_MIN : nums2[n2-1];

            // right partition
            int x3 = (idx1 == m) ? INT_MAX : nums1[idx1];
            int x4 = (n2 == n) ? INT_MAX : nums2[n2];

            if(x1<=x4 && x2<=x3){
               if(totalSize%2 == 1){
                 return max(x1,x2);
               }
               else{
                  return (max(x1,x2) + min(x3,x4))/2.0;
               }
            }

            if(x1 > x4){
                r = idx1-1;
                
            }
            else{
                l = idx1+1;
            }
            
        }
        return -1;
    }
};
