// O(n * log(n)) solution
// So, there is no negative number.
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
        sort(s.begin(), s.end());
        int ans = 0;
        int j1, j2;
        for (i = 0; i < n; ++i) {
            j1 = lower_bound(s.begin() + i, s.end(), start + s[i]) - s.begin();
            j2 = upper_bound(s.begin() + i, s.end(), end + s[i]) - s.begin();
            ans += j2 - j1;
        }
        return ans;
    }
};