// O(n) time and O(1) space
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        int n = A.size();
        int n1, n2;
        int i, j;
        auto cmp = [](int x, int y)-> int {return x < y;};
        
        n1 = n2 = 0;
        for (i = 0; i < n; ++i) {
            if (A[i] < 0) {
                ++n1;
            } else {
                ++n2;
            }
        }
        
        int f = n1 >= n2 ? 0 : 1;
        i = 0;
        j = 1;
        while (i < n && j < n) {
            if (cmp(A[i], 0) ^ f) {
                i += 2;
            } else if ((!cmp(A[j],0)) ^ f) {
                j += 2;
            } else {
                swap(A[i], A[j]);
                i += 2;
                j += 2;
            }
        }
    }
};