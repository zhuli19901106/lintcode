class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        vector<int> &a = nums;
        int n = a.size();
        int i;
        int a1, a2;
        int c1, c2;
        
        a1 = a2 = 0;
        c1 = c2 = 0;
        for (i = 0; i < n; ++i) {
            if (a1 == a[i]) {
                ++c1;
            } else if (a2 == a[i]) {
                ++c2;
            } else if (c1 == 0) {
                a1 = a[i];
                c1 = 1;
            } else if (c2 == 0) {
                a2 = a[i];
                c2 = 1;
            } else {
                --c1;
                --c2;
            }
        }
        c1 = c2 = 0;
        for (i = 0; i < n; ++i) {
            if (a1 == a[i]) {
                ++c1;
            } else if (a2 == a[i]) {
                ++c2;
            }
        }
        if (c1 > n / 3) {
            return a1;
        }
        if (c2 > n / 3) {
            return a2;
        }
    }
};