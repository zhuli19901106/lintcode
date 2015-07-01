// The recursive solution
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        ans.clear();
        n = nums.size();
        if (n == 0) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        b.resize(n, false);
        DFS(nums, 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> p;
    vector<bool> b;
    int n;
    
    void DFS(vector<int> &nums, int idx) {
        if (idx == n) {
            ans.push_back(p);
            return;
        }
        int i;
        for (i = 0; i < n; ++i) {
            if (b[i]) {
                continue;
            }
            p.push_back(nums[i]);
            b[i] = true;
            DFS(nums, idx + 1);
            b[i] = false;
            p.pop_back();
        }
    }
};