#include <algorithm>
using namespace std;

static bool lt(const int &x, const int &y) {
    return x < y;
}

static bool gt(const int &x, const int &y) {
    return x > y;
}

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        return max(solve(A, lt), solve(A, gt));
    }
private:
    int solve(vector<int> &a, bool (*comp)(const int &, const int &)) {
        int n = a.size();
        int ans = 0;
        int i, j;
        i = 0;
        while (i < n) {
            j = i + 1;
            while (j < n && comp(a[j - 1], a[j])) {
                ++j;
            }
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }
};