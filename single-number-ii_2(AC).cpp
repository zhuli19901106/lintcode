#include <cstring>
using namespace std;

typedef long long int LL;
class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        const int NB = 32;
        LL c = 0;
        LL i, j;
        LL bit;
        int n = A.size();
        
        for (i = 0; i < n; ++i) {
            for (j = 0; j < NB; ++j) {
                if (A[i] & (1 << j)) {
                    bit = (c >> (j << 1)) & 3;
                    bit = bit == 2 ? 0 : bit + 1;
                    c = (c & ~(3LL << (j << 1))) | (bit << (j << 1));
                }
            }
        }
        int ans = 0;
        for (i = 0; i < NB; ++i) {
            bit = (c >> (i << 1)) & 3;
            if (bit) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};