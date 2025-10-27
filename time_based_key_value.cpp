#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class TimeMap {
    private:
        unordered_map<string, vector<pair<int, string>>> map;
    public:
        TimeMap() {}
        
        void set(string key, string value, int timestamp) {
            map[key].emplace_back(timestamp, value);
        }
        
        string get(string key, int timestamp) {
            if (map.find(key) == map.end()) {
                return "";
            }
            
            auto it = lower_bound(map[key].begin(), map[key].end(), make_pair(timestamp + 1, string()));
            
            // Check if `it` is at the beginning of the vector or if there are no valid timestamps
            if (it == map[key].begin()) {
                return ""; // No valid timestamps less than or equal to `timestamp`
            } else {
                return prev(it)->second; // Return the value of the last valid timestamp
            }
        }
};

int main() {
    TimeMap tm;
    tm.set("foo", "bar", 1);
    cout << tm.get("foo", 1) << endl; // Should output "bar"
    cout << tm.get("foo", 3) << endl; // Should output "bar"
    tm.set("foo", "baz", 2);
    cout << tm.get("foo", 2) << endl; // Should output "baz"
    cout << tm.get("foo", 4) << endl; // Should output "baz"
    return 0;
}