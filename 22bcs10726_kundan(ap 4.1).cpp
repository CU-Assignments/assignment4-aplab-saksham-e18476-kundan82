#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;  // Stores (x, height) pairs
        
        // Convert buildings into sorted events
        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]); // Building start (negative for sorting)
            events.emplace_back(b[1], b[2]);  // Building end (positive)
        }
        
        // Sort the events
        sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second; // Sort by height if x is the same
            return a.first < b.first; // Otherwise, sort by x
        });
        
        multiset<int> heights = {0}; // Max heap using multiset (sorted ascending)
        vector<vector<int>> result;
        int prevHeight = 0;
        
        // Process all events
        for (auto& e : events) {
            int x = e.first, h = e.second;
            
            if (h < 0) { // Building start
                heights.insert(-h);
            } else { // Building end
                heights.erase(heights.find(h));
            }
            
            // Get current max height
            int currHeight = *heights.rbegin();
            
            // If skyline height changes, record key point
            if (currHeight != prevHeight) {
                result.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }
        
        return result;
    }
};
