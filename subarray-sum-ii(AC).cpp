// O(n ^ 2) solution
// There is no negative number?
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        if (start == end) {
            return 0;
            return 0;
        }
        
        vector<int> &a = A;
        int n = a.size();
        vector<int> s(n + 1, 0);
        int i;
        for (i = 0; i < n; ++i) {
            s[i + 1] = s[i] + a[i];
        }
        // sort(s.begin(), s.end());
        int ans = 0;
        int j;
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j <= n; ++j) {
                if (s[j] - s[i] >= start && s[j] - s[i] <= end) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};