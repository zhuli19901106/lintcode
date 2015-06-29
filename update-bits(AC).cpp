class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        if (i == 0 && j == 31) {
            return m;
        }
        return (~(((1 << (j - i + 1)) - 1) << i) & n) | (m << i);
    }
};