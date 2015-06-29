#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int n = num.size();
        if (n == 1) {
            return num[0];
        }
        int ll, mm, rr;
        ll = 0;
        rr = n - 1;
        while (rr - ll > 1) {
            if (num[ll] < num[rr]) {
                return num[ll];
            }
            if (num[ll] == num[rr]) {
                ++ll;
                continue;
            }
            mm = ll + (rr - ll) / 2;
            if (num[mm] > num[rr]) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        return min(num[ll], num[rr]);
    }
};