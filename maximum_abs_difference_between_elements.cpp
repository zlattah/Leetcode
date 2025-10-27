#include <iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int maxDifference(vector<int>& nums, int x) {
            vector<pair<int,int>> sorted_order;
            for (int i=0;i<nums.size();i++){
                sorted_order.emplace_back(nums[i],i);
            }
            sort(sorted_order.begin(),sorted_order.end(),[](const pair<int,int>&a, const pair<int,int>&b){
                return a.first<b.first;
            });
            int i = 0, j = nums.size()-1;
            int val_smaller, val_bigger, index_smaller, index_bigger;
            while (i<j){
                index_smaller = sorted_order[i].second;
                index_bigger = sorted_order[j].second;
                if (abs(index_bigger-index_smaller)>x){
                    val_smaller = sorted_order[i].first;
                    val_bigger = sorted_order[j].first;
                    return val_bigger-val_smaller;
                }
            }
            return -1;
        }
};
int main(){
    return 0;
}