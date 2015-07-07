// O(1) space, but three passes
// Why bother such a tricky one?
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        auto &a = colors;
        int n = a.size();
        int mod = 2 * k + 2;
        
        int i;
        for (i = 0; i < n; ++i) {
            a[a[i] % mod - 1] += mod;
        }
        
        int j, cc;
        int c;
        cc = 0;
        for (i = 0; i < k; ++i) {
            c = a[i] / mod;
            for (j = 0; j < c; ++j) {
                a[cc] = a[cc] / mod * mod + (i + 1);
                ++cc;
            }
        }
        for (i = 0; i < n; ++i) {
            a[i] %= mod;
        }
    }
};