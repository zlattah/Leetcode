#include <iostream>
#include<vector>
#include <set>
using namespace std;
class Solution {
    public:
        int minAbsoluteDifference(vector<int>& nums, int x) {
            int n = nums.size();
            set<int> window;
            int min_diff = INT_MAX;

            for (int i = x; i < n; ++i) {
                window.insert(nums[i - x]);

                auto it = window.lower_bound(nums[i]);
                if (it != window.end()) {
                    min_diff = min(min_diff, abs(*it - nums[i]));
                }
                if (it != window.begin()) {
                    --it;
                    min_diff = min(min_diff, abs(*it - nums[i]));
                }
            }

            return min_diff;
        }
};
int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout<<s.minAbsoluteDifference(nums,3);
    return 0;
}