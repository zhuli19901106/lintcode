class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        vector<int> &a = nums;
        int n = a.size();
        int msum, sum;
        int i;
        
        msum = a[0];
        for (i = 1; i < n; ++i) {
            msum = max(msum, a[i]);
        }
        if (msum < 0) {
            return msum;
        }
        
        sum = 0;
        for (i = 0; i < n; ++i) {
            sum += a[i];
            if (sum < 0) {
                sum = 0;
            }
            msum = max(msum, sum);
        }
        return msum;
    }
};