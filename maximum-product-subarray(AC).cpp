#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int mm, MM;
        int mm1, MM1;
        int ans;
        
        ans = mm = MM = nums[0];
        int i;
        for (i = 1; i < n; ++i) {
            mm1 = min(nums[i], min(nums[i] * mm, nums[i] * MM));
            MM1 = max(nums[i], max(nums[i] * mm, nums[i] * MM));
            mm = mm1;
            MM = MM1;
            ans = max(ans, MM);
        }
        return ans;
    }
};