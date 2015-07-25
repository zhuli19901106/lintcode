#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        sort(S.begin(), S.end());
        
        int i, j, k;
        int ans = 0;
        int n = S.size();
        
        for (i = 0; i < n; ++i) {
            j = i + 1;
            k = j + 1;
            while (j < n - 1) {
                while (k < n && S[k] - S[j] < S[i]) {
                    ++k;
                }
                ans += k - j - 1;
                ++j;
            }
        }
        return ans;
    }
};