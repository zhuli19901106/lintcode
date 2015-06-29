#include <algorithm>
using namespace std;

typedef long long int LL;

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    LL kthPrimeNumber(int k) {
        vector<LL> v;
        int p1, p2, p3;
        LL a1, a2, a3;
        LL val;
        
        p1 = p2 = p3 = 0;
        v.push_back(1);
        while (v.size() <= k) {
            a1 = v[p1] * 3;
            a2 = v[p2] * 5;
            a3 = v[p3] * 7;
            val = min(a1, min(a2, a3));
            if (val == a1) {
                ++p1;
            }
            if (val == a2) {
                ++p2;
            }
            if (val == a3) {
                ++p3;
            }
            v.push_back(val);
        }
        return v[k];
    }
};