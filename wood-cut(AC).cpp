#include <algorithm>
using namespace std;

typedef long long int LL;

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        LL ll, rr, mm;
        int n = L.size();
        int i;
        ll = 1;
        rr = 0;
        for (i = 0; i < n; ++i) {
            rr = max(rr, (LL)L[i]);
        }
        if (calc(L, ll) < k) {
            return 0;
        }
        if (calc(L, rr) >= k) {
            return rr;
        }
        while (rr - ll > 1) {
            mm = ll + (rr - ll) / 2;
            if (calc(L, mm) >= k) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        return ll;
    }
private:
    LL calc(vector<int> &L, LL len) {
        int n = L.size();
        int i;
        LL sum = 0;
        for (i = 0; i < n; ++i) {
            sum += L[i] / len;
        }
        return sum;
    }
};