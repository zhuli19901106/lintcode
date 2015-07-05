#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        int n = A.size();
        if (n == 0) {
            return true;
        }
        
        int r = 0;
        int i;
        for (i = 0; i < n; ++i) {
            if (r < i) {
                break;
            }
            r = max(r, i + A[i]);
        }
        return r >= n - 1;
    }
};