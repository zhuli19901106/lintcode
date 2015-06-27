class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int n = A.size();
        if (n == 0 || target > A[n - 1]) {
            return n;
        }
        if (target <= A[0]) {
            return 0;
        }
        int ll, rr, mm;
        
        ll = 0;
        rr = n - 1;
        while (rr - ll > 1) {
            mm = (ll + rr) / 2;
            if (A[mm] < target) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        return rr;
    }
};