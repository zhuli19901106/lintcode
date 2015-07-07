class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        auto &a = nums;
        int n = a.size();
        vector<int> c(3, 0);
        int i;
        for (i = 0; i < n; ++i) {
            ++c[a[i]];
        }
        int j, k = 0;
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < c[i]; ++j) {
                a[k++] = i;
            }
        }
    }
};