class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> C;
        int i, j;
        int na, nb;
        
        na = A.size();
        nb = B.size();
        i = j = 0;
        while (i < na && j < nb) {
            if (A[i] < B[j]) {
                C.push_back(A[i++]);
            } else {
                C.push_back(B[j++]);
            }
        }
        while (i < na) {
            C.push_back(A[i++]);
        }
        while (j < nb) {
            C.push_back(B[j++]);
        }
        return C;
    }
};