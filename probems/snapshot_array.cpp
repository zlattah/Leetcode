#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class SnapshotArray {
    private:
        vector<vector<pair<int, int>>> snaps;
        // for each index we save the snap it has changed in
        // and what is the value for that change
        int snap_id = 0;

    public:
        SnapshotArray(int length) {
            snaps.resize(length);
            for (int i=0;i<snaps.size();i++)
                snaps[i].emplace_back(0, 0);
        }

        void set(int index, int val) {

            pair<int,int> l = snaps[index].back(); // the element in question & all its snaps where it changed
            int lastSnapId = l.first; // last snap id where the element changed
            int lastVal = l.second; // last value the element had
            if (lastSnapId == snap_id) // if the snap id hasnt changed just change the value
                lastVal = val; 
            else
                snaps[index].emplace_back(snap_id, val); //since this is a new snap id we need to place the new value
        }

        int snap() {
            return snap_id++; //increase the snap id
        }

        int get(int index, int snap_id) {
            const vector<pair<int, int>>& snap = snaps[index]; //all snaps for this index
            // binary search to find the last snap id <= snap id where the value has changed
            auto it = lower_bound(snap.begin(), snap.end(), make_pair(snap_id + 1, 0));
            // return the second argument aka the value
            return prev(it)->second;
        }
};