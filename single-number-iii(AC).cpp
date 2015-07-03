class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        int lb;
        int n = A.size();
        int i;
        int n1, n2;
        
        lb = n1 = n2 = 0;
        for (i = 0; i < n; ++i) {
            lb ^= A[i];
        }
        lb = lb & -lb;
        for (i = 0; i < n; ++i) {
            if (A[i] & lb) {
                n1 ^= A[i];
            } else {
                n2 ^= A[i];
            }
        }
        vector<int> ans;
        ans.push_back(n1);
        ans.push_back(n2);
        return ans;
    }
};