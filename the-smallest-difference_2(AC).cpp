// O(n * log(n)) solution with O(1) space
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        if (A.size() > B.size()) {
            return smallestDifference(B, A);
        }
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int i, j;
        int ans = INT_MAX;
        int na = A.size();
        int nb = B.size();
        
        for (i = 0; i < na; ++i) {
            j = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            if (j < nb) {
                ans = min(ans, B[j] - A[i]);
            }
            if (j > 0) {
                ans = min(ans, A[i] - B[j - 1]);
            }
        }
        return ans;
    }
};