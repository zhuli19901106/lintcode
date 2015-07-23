class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if (x < 2) {
            return x;
        }
        int p = x;
        int q;
        while (true) {
            q = p;
            p = (0LL + p + x / p) / 2;
            if (q - p <= 1) {
                break;
            }
        }
        return p;
    }
};
