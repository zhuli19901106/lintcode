class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> ans(2);
        int n = A.size();
        if (n == 0) {
            ans[0] = ans[1] = -1;
            return ans;
        }
        ans[0] = lower_bound(A.begin(), A.end(), target) - A.begin();
        if (A[ans[0]] != target) {
            ans[0] = ans[1] = -1;
            return ans;
        }
        ans[1] = upper_bound(A.begin(), A.end(), target) - A.begin() - 1;
        return ans;
    }
};