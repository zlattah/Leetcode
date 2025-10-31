#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        double findMedian(vector<int>& nums, int st, int end){
            //st is the starting index
            //end is the ending index
            if (end-st == 0) return 0;
            if (end-st == 1) return nums[st];
            int mid = (end+st)/2;
            if ((end-st)%2 == 1) return nums[mid];
            else return (nums[mid]+nums[mid-1])/2;
        }
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int st1 = 0, st2 = 0, end1 = nums1.size(), end2 = nums2.size();
            int m1, m2;
            while (true){
                m1 = findMedian(nums1, st1, end1);
                m2 = findMedian(nums2, st2, end2);
                if (m1 == m2) return m1;
                if (end1-st1 == 0) return m2;
                if (end2-st2 == 0) return m1;
                

            }
            return 0;
        }
};
int main(){
    Solution s;
    vector <int> nums1 = {1,2,3,4};
    vector <int> nums2 = {2,3,4,5};
    s.findMedianSortedArrays(nums1,nums2);
    return 0;
}