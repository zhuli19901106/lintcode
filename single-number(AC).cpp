class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        int i;
        int n = A.size();
        int ans = 0;
        for (i = 0; i < n; ++i) {
            ans ^= A[i];
        }
        return ans;
    }
};