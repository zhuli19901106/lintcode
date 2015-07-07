#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        int n = A.size();
        if (n < 2) {
            return;
        }
        int i, j, k;
        int minVal;
        
        for (i = (n - 1) / 2; i >= 0; --i) {
            j = i;
            while (j * 2 + 1 <= n - 1) {
                k = j;
                minVal = A[j];
                if (A[j * 2 + 1] < minVal) {
                    k = j * 2 + 1;
                    minVal = A[k];
                }
                if (j * 2 + 2 <= n - 1 && A[j * 2 + 2] < minVal) {
                    k = j * 2 + 2;
                    minVal = A[k];
                }
                if (k == j) {
                    break;
                }
                swap(A[j], A[k]);
                j = k;
            }
        }
    }
};