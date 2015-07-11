#include <queue>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> &a = nums;
        int n = a.size();
        // The smaller half
        priority_queue<int, vector<int>, less<int> > small;
        // The larger half
        priority_queue<int, vector<int>, greater<int> > large;
        int i;
        vector<int> ans;
        
        small.push(INT_MIN);
        large.push(INT_MAX);
        int vs, vl;
        for (i = 0; i < n; ++i) {
            if (i & 1) {
                large.push(a[i]);
            } else {
                small.push(a[i]);
            }
            vs = small.top();
            vl = large.top();
            if (vs > vl) {
                small.pop();
                small.push(vl);
                large.pop();
                large.push(vs);
            }
            ans.push_back(small.top());
        }
        return ans;
    }
};