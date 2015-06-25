class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
		int i, j;
		int n = A.size();
		
		j = 0;
		for (i = 0; i < n; ++i) {
			if (A[i] != elem) {
				A[j++] = A[i];
			}
		}
		return j;
    }
};