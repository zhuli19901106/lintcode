typedef long long int LL;
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        int n = nums.size();
        int i;
        LL sum = 0;
        for (i = 0; i < n; ++i) {
            sum += nums[i];
        }
        return 1LL * n * (n + 1) / 2 - sum;
    }
};