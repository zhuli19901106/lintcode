#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int n = nums.size();
        int i, j;
        int piv = INT_MAX;
        int mi = -1;
        for (i = 0; i < n; ++i) {
            if (nums[i] >= k) {
                piv = min(piv, nums[i]);
                mi = i;
            }
        }
        if (mi == -1) {
            return n;
        }
        swap(nums[0], nums[mi]);
        
        i = 1;
        j = n - 1;
        while (true) {
            while (i <= j && nums[i] < piv) {
                ++i;
            }
            while (i <= j && nums[j] >= piv) {
                --j;
            }
            if (i > j) {
                break;
            }
            swap(nums[i++], nums[j--]);
        }
        swap(nums[0], nums[j]);
        while (j > 0 && nums[j - 1] >= k) {
            --j;
        }
        return j;
    }
};