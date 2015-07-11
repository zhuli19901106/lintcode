// O(log(m) * log(n)) solution
#include <algorithm>
using namespace std;

typedef vector<int> VI;
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(VI A, VI B) {
        na = A.size();
        nb = B.size();
        if ((na + nb) % 2) {
            return kthSmallest(A, B, 0, na - 1, 0, nb - 1, (na + nb) / 2);
        } else {
            int a1 = kthSmallest(A, B, 0, na - 1, 0, nb - 1, (na + nb - 1) / 2);
            int a2 = kthSmallest(A, B, 0, na - 1, 0, nb - 1, (na + nb) / 2);
            return (a1 + a2) / 2.0;
        }
    }
private:
    int na, nb;
    
    int kthSmallest(VI &a, VI &b, int la, int ra, int lb, int rb, int k) {
        if (la > ra) {
            return b[lb + k];
        }
        if (lb > rb) {
            return a[la + k];
        }
        if (a[ra] <= b[lb]) {
            return k <= ra - la ? a[la + k] : b[lb + k - (ra - la + 1)];
        }
        if (b[rb] <= a[la]) {
            return k <= rb - lb ? b[lb + k] : a[la + k - (rb - lb + 1)];
        }
        int ma = la + (ra - la) / 2;
        int mb = lower_bound(b.begin() + lb, b.begin() + rb + 1, a[ma]) - b.begin();
        if (b[mb] > a[ma]) {
            --mb;
        }
        int cc = (ma - la) + 1 + (mb - lb) + 1;
        if (k + 1 < cc) {
            return kthSmallest(a, b, la, ma - 1, lb, mb, k);
        } else if (k + 1 > cc) {
            return kthSmallest(a, b, ma + 1, ra, mb + 1, rb, k - cc);
        } else {
            return a[ma];
        }
    }
};