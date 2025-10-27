#include<iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> opt(n);
            // fill matrix with zeros
            for (int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    opt[i].push_back(0);
            // fill for length 1
            for (int i=0;i<n;i++){
                opt[i][i] = nums[i];
            }
            // fill for length 2
            for (int i=0;i<n-1;i++){
                opt[i][i+1] = max(nums[i],nums[i+1]);
            }
            for (int len=2;len<n;len++){
                for (int i=0;i<n-len;i++){
                    int j = i+len;
                    //if you include num[i]
                    int res1 = opt[i][j-2] + nums[j];
                    //if you exclude num[i]
                    int res2 = opt[i][j-1];
                    opt[i][j] = max(res1,res2);
                }
            }
            return opt[0][n-1];
        }
};
int main(){
    vector<int> nums = {1,2,3};
    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}