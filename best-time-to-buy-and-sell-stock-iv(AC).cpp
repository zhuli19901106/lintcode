// O(n * k) DP, global and local optimal
class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        vector<int> &a = prices;
        int i, j;
        int n = a.size();
        j = 0;
        int sum = 0;
        for (i = 0; i < n - 1; ++i) {
            if (a[i] < a[i + 1]) {
                sum += a[i + 1] - a[i];
                ++j;
            }
        }
        if (j <= k) {
            return sum;
        }
        
        vector<int> local(k + 1, 0), global(k + 1, 0);
        int diff;
        for (i = 1; i < n; ++i) {
            diff = a[i] - a[i - 1];
            // j from k to 1, why?
            for (j = k; j >= 1; --j) {
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }
};