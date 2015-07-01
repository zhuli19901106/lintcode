// The iterative solution
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return ans;
        }
        vector<int> s;
        int i, j;
        int n2 = 1 << n;
        for (i = 0; i < n2; ++i) {
            for (j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    s.push_back(nums[j]);
                }
            }
            ans.push_back(s);
            s.clear();
        }
        return ans;
    }
private:
    vector<vector<int> > ans;
};