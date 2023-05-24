/*
    
    Median of Two Sorted Arrays 
    https://leetcode.com/problems/median-of-two-sorted-arrays/

*/

#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    int m = nums1.size();
    int n = nums2.size();

    int s = 0; //indicates min. #elements from nums1 we can add to the left partition
    int e = m; //indicates max. #elements from nums1 we can add to the left partition

    while(s <= e) {
            
        int x = s+(e-s)/2;
            
        // add first 'x' elements from nums1 i.e. nums1[0..x-1] to the 
        // left partition and the remaining 'm-x' elements from nums1 i.e. 
        // nums1[x...m-1] to the right partition
            
        int l1 = x == 0 ? INT_MIN : nums1[x-1];
        int r1 = x == m ? INT_MAX : nums1[x];

        // since the size of both the left and right parititon is equal i.e. (n+m)/2 
        // add the first (n+m)/2-x elements from nums2 i.e. nums2[0...(n+m)/2-x-1] 
        // to the left partition and the remaining 'n-(n+m)/2-x' elements from nums2 i.e. 
        // i.e. nums2[((n+m)/2-x)...n-1] in the right partition.
        
        int l2 = (n+m)/2-x == 0 ? INT_MIN : nums2[(n+m)/2-x-1];
        int r2 = (n+m)/2-x == n ? INT_MAX : nums2[(n+m)/2-x];

        // can we add first 'x' elements from nums1 i.e. nums1[0...x-1] 
        // to the left partition ?
            
        if(l1 <= r2 and l2 <= r1) {

            // you've found a valid parition
            if((m+n)%2 == 0) {
                // merged sequence is of even length
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                // merge sequence is of odd length
                return min(r1, r2);
            }

        } else if(l1 > r2) {
            // decrease l1
            e = x - 1;
        } else if(l2 > r1) {
            // increase r1
            s = x +1;
        }
    }

    return 0.0;

}

int main() {
    
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {0, 2, 4, 6, 8};

    nums1.size() < nums2.size() ? cout << findMedianSortedArrays(nums1, nums2) :
                                  cout << findMedianSortedArrays(nums2, nums1) ;

    return 0;
}