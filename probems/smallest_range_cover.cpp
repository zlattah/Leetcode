#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
    public:
        vector<int> smallestRange(vector<vector<int>>& nums) {
            vector<int>pointer(nums.size(),0);
            vector<int>size(nums.size());
            int smallestvalue = INT_MAX;
            priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
            for(int i=0;i<nums.size();i++){
                size[i] = nums[i].size();
                pq.emplace(nums[i][0],0);
                
            }
            while(!pq.empty()){
                auto& [val,index] = pq.top();
                pq.pop();
                pointer[index]++;
                if(pointer[index]<size[index])
                    pq.emplace(nums[index][pointer[index]],index);
                
            }
        }
};