class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
		int n, m;
		vector<vector<int> > &a = obstacleGrid;
		
		n = a.size();
		if (n == 0) {
			return 0;
		}
		m = a[0].size();
		if (m == 0) {
			return 0;
		}
		
		int i, j;
		a[0][0] = a[0][0] ? 0 : 1;
		for (i = 1; i < n; ++i) {
			a[i][0] = a[i][0] ? 0 : a[i - 1][0];
		}
		for (j = 1; j < m; ++j) {
			a[0][j] = a[0][j] ? 0 : a[0][j - 1];
		}
		for (i = 1; i < n; ++i) {
			for (j = 1; j < m; ++j) {
				a[i][j] = a[i][j] ? 0 : a[i][j - 1] + a[i - 1][j];
			}
		}
		return a[n - 1][m - 1];
    }
};
