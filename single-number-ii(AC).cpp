#include <cstring>
using namespace std;

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        const int NB = 32;
        int c[NB];
        int i, j;
        int n = A.size();
        
        memset(c, 0, sizeof(c));
        for (i = 0; i < n; ++i) {
            for (j = 0; j < NB; ++j) {
                if (A[i] & (1 << j)) {
                    ++c[j];
                }
            }
        }
        int ans = 0;
        for (i = 0; i < NB; ++i) {
            if (c[i] % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};