class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        vector<int> &a = nums;
        int n = a.size();
        vector<int> dl, dr;
        dl.resize(n);
        dr.resize(n);
        
        int sum;
        int i;
        
        dl[0] = sum = a[0];
        for (i = 1; i <= n - 1; ++i) {
            sum = max(sum, 0);
            sum += a[i];
            dl[i] = max(dl[i - 1], sum);
        }
        
        dr[n - 1] = sum = a[n - 1];
        for (i = n - 2; i >= 0; --i) {
            sum = max(sum, 0);
            sum += a[i];
            dr[i] = max(dr[i + 1], sum);
        }
        
        sum = dl[0] + dr[1];
        for (i = 1; i < n - 1; ++i) {
            sum = max(sum, dl[i] + dr[i + 1]);
        }
        return sum;
    }
};