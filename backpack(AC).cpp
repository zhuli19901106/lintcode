class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        vector<bool> dp;
        dp.resize(m + 1, false);
        dp[0] = true;
        
        int n = A.size();
        int i, j;
        for (i = 0; i < n; ++i) {
            for (j = m; j >= A[i]; --j) {
                if (dp[j - A[i]]) {
                    dp[j] = true;
                }
            }
        }
        i = m;
        while (!dp[i]) {
            --i;
        }
        return i;
    }
};