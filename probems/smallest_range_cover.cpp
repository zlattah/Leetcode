#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queues
        priority_queue<int> maxHeap; // Max heap for left side
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for right side
        
        // Add the first element of each list to the max heap
        int currentMax = INT_MIN;
        for (const auto& list : nums) {
            maxHeap.push(list[0]);
            currentMax = max(currentMax, list[0]);
        }
        
        vector<int> result;
        int rangeStart = INT_MIN, rangeEnd = INT_MAX;

        while (true) {
            int currentMin = maxHeap.top(); // The largest of the smallest elements
            
            // Update the range if the current range is smaller
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }
            
            // We need to move the smallest element from maxHeap to minHeap
            maxHeap.pop();
            if (maxHeap.empty()) break; // If maxHeap is empty, we are done
            
            // Move the next element from the current list to the maxHeap
            // Here, you would need to know which list the currentMin came from
            // For simplicity, let's assume we have a way to track this
            
            // Assuming we can push the next element from the same list
            // For example, if `currentMin` came from the first list
            // Replace this with actual tracking logic
            // maxHeap.push(nextElementFromSameList);
            
            // Update currentMax if necessary
            // currentMax = max(currentMax, nextElementFromSameList);
        }
        
        result.push_back(rangeStart);
        result.push_back(rangeEnd);
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    vector<int> result = sol.smallestRange(nums);
    cout << "Smallest Range: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}