class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
		vector<int> ans;
		int n, m;
		n = matrix.size();
		if (n == 0) {
			return ans;
		}
		m = matrix[0].size();
		if (m == 0) {
			return ans;
		}
		int i, j;
		int f = 0;
		for (i = 0; i <= n + m - 2; ++i) {
			if (f) {
				for (j = i; j >= 0; --j) {
					if (i - j < 0 || i - j > n - 1) {
						continue;
					}
					if (j < 0 || j > m - 1) {
						continue;
					}
					ans.push_back(matrix[i - j][j]);
				}
			} else {
				for (j = 0; j <= i; ++j) {
					if (i - j < 0 || i - j > n - 1) {
						continue;
					}
					if (j < 0 || j > m - 1) {
						continue;
					}
					ans.push_back(matrix[i - j][j]);
				}
			}
			f = !f;
		}
		return ans;
    }
};