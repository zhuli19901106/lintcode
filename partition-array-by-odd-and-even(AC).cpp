#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // Think about quick sort.
        vector<int> &a = nums;
        int n = a.size();
        if (n <= 1) {
            return;
        }
        int i = 0;
        int j = n - 1;
        while (true) {
            while (i <= j && a[i] % 2 == 1) {
                ++i;
            }
            while (i <= j && a[j] % 2 == 0) {
                --j;
            }
            if (i > j) {
                break;
            }
            swap(a[i], a[j]);
        }
    }
};