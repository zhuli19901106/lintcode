class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int sum = 0;
        int n = prices.size();
        int i;
        for (i = 0; i < n - 1; ++i) {
            if (prices[i + 1] > prices[i]) {
                sum += prices[i + 1] - prices[i];
            }
        }
        return sum;
    }
};