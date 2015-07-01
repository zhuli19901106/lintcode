// The iterative solution
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
        int n = nums.size();
        if (n == 0) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        int f = 1;
        int i;
        for (i = 2; i <= n; ++i) {
            f *= i;
        }
        for (i = 0; i < f; ++i) {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
private:
    vector<vector<int> > ans;
};