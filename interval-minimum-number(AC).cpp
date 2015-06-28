// Solution using sparse table
#include <algorithm>
using namespace std;
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // Sparse table
        vector<vector<int> > st;
        int base = 1;
        int n = A.size();
        int m = 1;
        while (base << 1 <= n) {
            base <<= 1;
            ++m;
        }
        base = 1;
        st.resize(m);
        
        int i;
        for (i = 0; i < m; ++i) {
            st[i].resize(n - base + 1);
            base <<= 1;
        }
        
        for (i = 0; i < n; ++i) {
            st[0][i] = A[i];
        }
        
        int j;
        base = 1;
        for (i = 1; i < m; ++i) {
            base <<= 1;
            for (j = 0; j + base <= n; ++j) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (base >> 1)]);
            }
        }
        
        m = queries.size();
        int x, y;
        vector<int> ans;
        for (i = 0; i < m; ++i) {
            x = queries[i].start;
            y = queries[i].end;
            base = 1;
            j = 0;
            while (base << 1 <= y - x + 1) {
                base <<= 1;
                ++j;
            }
            ans.push_back(min(st[j][x], st[j][y + 1 - base]));
        }
        return ans;
    }
};