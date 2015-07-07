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
        vector<int> c(k, 0);
        int i, j, cc;
        
        for (i = 0; i < n; ++i) {
            ++c[a[i] - 1];
        }
        cc = 0;
        for (i = 0; i < k; ++i) {
            for (j = 0; j < c[i]; ++j) {
                a[cc++] = i + 1;
            }
        }
    }
};