// O(n) time and space. How to reach O(1) space?
class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int> &ratings) {
        vector<int> &a = ratings;
        int n = a.size();
        vector<int> c(n, 1);
        int i;
        for (i = 1; i <= n - 1; ++i) {
            if (a[i] > a[i - 1]) {
                c[i] = c[i - 1] + 1;
            }
        }
        for (i = n - 2; i >= 0; --i) {
            if (a[i] > a[i + 1] && c[i] <= c[i + 1]) {
                c[i] = c[i + 1] + 1;
            }
        }
        int sum = 0;
        for (i = 0; i <= n - 1; ++i) {
            sum += c[i];
        }
        return sum;
    }
};