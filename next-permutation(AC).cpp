class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        vector<int> &a = nums;
        int n = a.size();
        
        if (n == 0) {
            return a;
        }
        int i, j;
        
        for (i = n - 2; i >= 0; --i) {
            if (a[i] < a[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(a.begin(), a.end());
            return a;
        }
        for (j = n - 1; j > i; --j) {
            if (a[j] > a[i]) {
                break;
            }
        }
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
        return a;
    }
};