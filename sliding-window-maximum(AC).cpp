#include <deque>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        d.clear();
        vector<int> ans;
        vector<int> &a = nums;
        int n = a.size();
        if (n == 0 || k == 0) {
            return ans;
        }
        
        int i;
        for (i = 0; i < k - 1; ++i) {
            enQueue(a, i, k);
        }
        for (i = k - 1; i < n; ++i) {
            enQueue(a, i, k);
            ans.push_back(a[d.front()]);
        }
        return ans;
    }
private:
    deque<int> d;
    
    void enQueue(vector<int> &a, int i, int k) {
        while (!d.empty() && i - d.front() >= k) {
            d.pop_front();
        }
        while (!d.empty() && a[d.back()] < a[i]) {
            d.pop_back();
        }
        d.push_back(i);
    }
};