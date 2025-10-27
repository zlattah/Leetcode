#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

const int p = 31;
const int m = 1e9 + 9;

string largestNonOverlappingSubstring(const string& s) {
    int n = (int)s.size();
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    // Compute prefix hashes
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // Function to get hash of substring s[l..r]
    auto getHash = [&](int l, int r) {
        long long hash_val = (h[r + 1] + m - h[l]) % m;
        hash_val = (hash_val * p_pow[n - l - 1]) % m; // normalize hash to same power
        return hash_val;
    };

    // Binary search for the longest length L such that
    // there are at least two non-overlapping substrings of length L with the same hash
    int left = 1, right = n / 2, ans_len = 0;
    set<string> candidates; // to store candidates for lexicographical comparison

    while (left <= right) {
        int mid = (left + right) / 2;
        bool found = false;
        unordered_map<long long, vector<int>> seen; // hash -> list of starting indices

        for (int i = 0; i + mid <= n; i++) {
            long long cur_hash = getHash(i, i + mid - 1);
            seen[cur_hash].push_back(i); // store all starting indices for the hash
        }

        // Check for non-overlapping pairs
        for (const auto& entry : seen) {
            const auto& indices = entry.second;
            if (indices.size() < 2) continue; // need at least two occurrences

            for (size_t j = 0; j < indices.size(); ++j) {
                for (size_t k = j + 1; k < indices.size(); ++k) {
                    if (indices[k] >= indices[j] + mid) { // non-overlapping condition
                        found = true;
                        candidates.insert(s.substr(indices[j], mid)); // add candidate
                        break;
                    }
                }
                if (found) break; // Break outer loop if found
            }
        }

        if (found) {
            ans_len = mid;
            left = mid + 1; // Try for longer substrings
        } else {
            right = mid - 1; // Try shorter substrings
        }
    }

    if (candidates.empty()) return ""; // no repeated non-overlapping substring

    return *candidates.begin(); // return the lexicographically smallest substring
}

int main() {
    string s;
    while (getline(cin, s)) {
        string result = largestNonOverlappingSubstring(s);
        if (result == "") 
            cout << "No LRS is found." << "\n";
        else 
            cout << result << "\n";
    }
    return 0;
}