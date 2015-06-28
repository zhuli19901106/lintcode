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
            for (j = i + 1; j < n; ++j) {
                for (k = j + 1; k < n && S[i] + S[j] > S[k]; ++k) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};