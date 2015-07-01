class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        vector<vector<int> > &a = matrix;
        int n, m;
        n = a.size();
        if (n == 0) {
            return 0;
        }
        m = a[0].size();
        if (m == 0) {
            return 0;
        }
        
        int i, j;
        int ans = 0;
        i = 0;
        j = m - 1;
        while (i <= n - 1 && j >= 0) {
            if (a[i][j] < target) {
                ++i;
            } else if (a[i][j] > target) {
                --j;
            } else {
                ++ans;
                --j;
            }
        }
        return ans;
    }
};