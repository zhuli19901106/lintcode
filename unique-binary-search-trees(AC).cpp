class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        int i, j;
        for (i = 2; i <= n; ++i) {
            v.push_back(0);
            for (j = 0; j < i; ++j) {
                v[i] += v[j] * v[i - 1 - j];
            }
        }
        return v[n];
    }
};