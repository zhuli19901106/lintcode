// O(n) solution with O(n) space
#include <algorithm>
using namespace std;

int abs(int x)
{
    return x >= 0 ? x : -x;
}

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        vector<int> tag;
        vector<int> C;
        
        int na = A.size();
        int nb = B.size();
        int i, j;
        i = j = 0;
        while (i < na && j < nb) {
            if (A[i] < B[j]) {
                C.push_back(A[i++]);
                tag.push_back(0);
            } else {
                C.push_back(B[j++]);
                tag.push_back(1);
            }
        }
        if (i < na) {
            C.push_back(A[i++]);
            tag.push_back(0);
        } else {
            C.push_back(B[j++]);
            tag.push_back(1);
        }
        
        int n = C.size();
        int ans = INT_MAX;
        for (i = 0; i < n - 1; ++i) {
            if (tag[i] ^ tag[i + 1]) {
                ans = min(ans, abs(C[i] - C[i + 1]));
            }
        }
        
        return ans;
    }
};