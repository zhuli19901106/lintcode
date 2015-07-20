// Solution using quaternary search
typedef vector<vector<int> > V2DI;
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(V2DI &matrix, int target) {
        V2DI &a = matrix;
        int n = a.size();
        int m = n ? a[0].size() : 0;
        this->ans = 0;
        this->target = target;
        if (n == 0 || m == 0) {
            return 0;
        }
        quadSearch(a, 0, n - 1, 0, m - 1);
        return ans;
    }
private:
    int ans;
    int target;
    
    void quadSearch(V2DI &a, int tt, int bb, int ll, int rr) {
        if (tt == bb && ll == rr) {
            ans += a[tt][ll] == target;
            return;
        }
        int mmr = tt + (bb - tt + 1 >> 1);
        int mmc = ll + (rr - ll + 1 >> 1);
        if (mmr > tt && mmc > ll && target < a[mmr][mmc]) {
            // Search the top left submatrix
            quadSearch(a, tt, mmr - 1, ll, mmc - 1);
        }
        if (mmr > tt) {
            // Search the top right submatrix
            quadSearch(a, tt, mmr - 1, mmc, rr);
        }
        if (mmc > ll) {
            // Search the bottom left submatrix
            quadSearch(a, mmr, bb, ll, mmc - 1);
        }
        if (target >= a[mmr][mmc]) {
            // Search the bottom right submatrix
            quadSearch(a, mmr, bb, mmc, rr);
        }
    }
};