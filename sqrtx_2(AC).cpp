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
        int ll = 1;
        int rr = x;
        int mm;
        while (rr - ll > 1) {
            mm = ll + (rr - ll >> 1);
            if (x / mm >= mm) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        return ll;
    }
};
