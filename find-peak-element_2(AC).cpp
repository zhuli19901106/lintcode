// The O(log(n)) solution
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int n = A.size();
        int ll, rr, mm;
        
        ll = 0;
        rr = n - 1;
        while (rr - ll > 2) {
            mm = (ll + rr) / 2;
            if (A[mm] > A[mm - 1] && A[mm] > A[mm + 1]) {
                return mm;
            } else if (A[mm - 1] < A[mm]) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        return (ll + rr) / 2;
    }
};