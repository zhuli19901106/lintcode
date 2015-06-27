#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return;
        }
        int i;
        for (i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = i + 1;
        while (j < n && nums[j] > nums[i]) {
            ++j;
        }
        --j;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};