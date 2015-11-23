// Strange, it's supposed to be faster, but not quite so.
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > &A) {
        int n, m;
        n = A.size();
        m = n ? A[0].size() : 0;
        vector<int> ans;
        
        int ll, rr, mm, pp;
        
        ll = 1;
        rr = n - 2;
        while (ll <= rr) {
            mm = ll + (rr - ll >> 1);
            pp = findPeak(A[mm]);
            if (A[mm][pp] < A[mm + 1][pp]) {
                ll = mm + 1;
            } else if (A[mm][pp] < A[mm - 1][pp]) {
                rr = mm - 1;
            } else {
                ans.push_back(mm);
                ans.push_back(pp);
                break;
            }
        }
        
        return ans;
    }
protected:
    // 1166 ms
    int findPeak(vector<int> &A) {
        int n = A.size();
        int ll, rr, mm;
        
        ll = 0;
        rr = n - 1;
        while (rr - ll > 2) {
            mm = ll + (rr - ll >> 1);
            if (A[mm] > A[mm - 1] && A[mm] > A[mm + 1]) {
                return mm;
            } else if (A[mm - 1] < A[mm]) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        return ll + (rr - ll >> 1);
    }
    
    /*
    // 1239 ms
    int findPeak(vector<int> &A) {
        int mi = 0;
        int i;
        for (i = 1; i < A.size(); ++i) {
            if (A[i] > A[mi]) {
                mi = i;
            }
        }
        return mi;
    }
    */
};
