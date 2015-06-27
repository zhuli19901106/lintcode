#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        vector<int> &a = nums;
        int n = a.size();
        int msum, sum;
        int i;
        
        msum = a[0];
        for (i = 1; i < n; ++i) {
            msum = min(msum, a[i]);
        }
        if (msum > 0) {
            return msum;
        }
        
        sum = 0;
        for (i = 0; i < n; ++i) {
            sum += a[i];
            if (sum > 0) {
                sum = 0;
            }
            msum = min(msum, sum);
        }
        return msum;
    }
};