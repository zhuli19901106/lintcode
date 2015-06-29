#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
private:
    int quickSelect(vector<int> &a, int ll, int rr, int k) {
        if (ll == rr) {
            return a[k];
        }
        int i = ll + 1;
        int j = rr;
        int piv = a[ll];
        while (true) {
            while (i <= j && a[i] < piv) {
                ++i;
            }
            while (i <= j && a[j] > piv) {
                --j;
            }
            if (i > j) {
                break;
            }
            swap(a[i++], a[j--]);
        }
        swap(a[ll], a[j]);
        if (k < j) {
            return quickSelect(a, ll, j - 1, k);
        } else if (k > j) {
            return quickSelect(a, j + 1, rr, k);
        } else {
            return a[k];
        }
    }
};