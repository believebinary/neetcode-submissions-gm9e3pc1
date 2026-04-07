class Solution {
public:
    // double findAns(vector<int>& nums1, vector<int>& nums2){
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     int left =0;
    //     int right = m-1;
    //     int totalSize = m+n;
        
    //     while(left<=right){
    //         int mid = left + (right-left)/2;

    //         if(nums1[mid] < nums2[])
    //     }
    // }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int totalSize = m+n;
        int idx1 = (totalSize/2)-1;
        int element1 = -1;
        int idx2 = (totalSize/2);
        int element2 = -1;
        int k=0;
        int j=0;
        int i=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                if(k==idx1){
                  element1= nums1[i];
                }
                if(k==idx2){
                    element2= nums1[i];
                }
                i++;
            }
            else{
                if(k==idx1){
                  element1= nums2[j];
                }
                if(k==idx2){
                    element2= nums2[j];
                }
                j++;
            }
            k++;
        }
        while(i<m){
            if(k==idx1){
                element1= nums1[i];
            }
            if(k==idx2){
                element2= nums1[i];
            }
            i++;  
            k++; 
        }
        while(j<n){
             if(k==idx1){
                element1= nums2[j];
             }
             if(k==idx2){
                element2= nums2[j];
             }
             j++;  
             k++; 
        }
        if(totalSize%2 == 0){
            return (element1+element2)/2.0;
        }
        else{
            return element2;
        }
        return -1;
    }
};
