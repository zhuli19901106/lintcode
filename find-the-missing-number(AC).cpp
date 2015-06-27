class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        
        int i;
        nums.push_back(0);
        for (i = 0; i < n; ++i) {
            nums[nums[i] % (n + 1)] += n + 1;
        }
        for (i = 0; i <= n; ++i) {
            if (nums[i] < n + 1) {
                break;
            }
        }
        return i;
    }
};