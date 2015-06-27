class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n, m;
        n = matrix.size();
        if (n == 0) {
            return false;
        }
        m = matrix[0].size();
        if (m == 0) {
            return false;
        }
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1]) {
            return false;
        }
        int ll, rr, mm;
        
        ll = 0;
        rr = n * m - 1;
        while (ll <= rr) {
            mm = (ll + rr) / 2;
            if (matrix[mm / m][mm % m] < target) {
               ll = mm + 1;
            } else if (matrix[mm / m][mm % m] > target) {
                rr = mm - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};