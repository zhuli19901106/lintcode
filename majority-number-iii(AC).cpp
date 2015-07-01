class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        vector<int> &a = nums;
        int n = a.size();
        int i, j;
        vector<int> m, c;
        
        m.resize(k - 1, 0);
        c.resize(k - 1, 0);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < k - 1; ++j) {
                if (m[j] == a[i]) {
                    ++c[j];
                    break;
                }
            }
            if (j < k - 1) {
                continue;
            }
            
            for (j = 0; j < k - 1; ++j) {
                if (c[j] == 0) {
                    m[j] = a[i];
                    c[j] = 1;
                    break;
                }
            }
            if (j < k - 1) {
                continue;
            }
            
            for (j = 0; j < k - 1; ++j) {
                --c[j];
            }
        }
        
        for (i = 0; i < k - 1; ++i) {
            c[i] = 0;
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < k - 1; ++j) {
                if (a[i] == m[j]) {
                    ++c[j];
                    break;
                }
            }
        }
        for (i = 0; i < k - 1; ++i) {
            if (c[i] > n / k) {
                return m[i];
            }
        }
    }
};