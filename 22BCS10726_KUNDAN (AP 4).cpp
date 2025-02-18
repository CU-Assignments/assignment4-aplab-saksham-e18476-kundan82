#include <vector>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};  // Base case
        
        while (res.size() < n) {
            vector<int> temp;
            
            // Generate odd numbers
            for (int num : res) {
                if (2 * num - 1 <= n)
                    temp.push_back(2 * num - 1);
            }
            
            // Generate even numbers
            for (int num : res) {
                if (2 * num <= n)
                    temp.push_back(2 * num);
            }
            
            res = temp; // Update the result array
        }
        
        return res;
    }
};
