class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        int i, j;
        int b;
        
        b = 1;
        for (i = 0; i < n; ++i) {
            for (j = b - 1; j >= 0; --j) {
                v.push_back(b | v[j]);
            }
            b <<= 1;
        }
        return v;
    }
};