#include <algorithm>
using namespace std;

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return;
        }
        
        int i;
        for (i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                break;
            }
        }
        if (i == n - 1) {
            return;
        }
        reverse(nums.begin(), nums.begin() + i + 1);
        reverse(nums.begin() + i + 1, nums.end());
        reverse(nums.begin(), nums.end());
    }
};