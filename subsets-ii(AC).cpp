// The recursive solution
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        ans.clear();
        n = S.size();
        if (n == 0) {
            return ans;
        }
        int i, j;
        int cc;
        
        vector<int> ss;
        for (i = 0; i < n; ++i) {
            ss.push_back(S[i]);
        }
        sort(ss.begin(), ss.end());
        a.clear();
        c.clear();
        i = 0;
        while (i < n) {
            j = i + 1;
            while (j < n && ss[i] == ss[j]) {
                ++j;
            }
            cc = j - i;
            a.push_back(ss[i]);
            c.push_back(cc);
            i = j;
        }
        n = a.size();
        DFS(0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> s;
    vector<int> a;
    vector<int> c;
    int n;
    
    void DFS(int idx) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }
        int i, j;
        for (i = 0; i <= c[idx]; ++i) {
            for (j = 0; j < i; ++j) {
                s.push_back(a[idx]);
            }
            DFS(idx + 1);
            for (j = 0; j < i; ++j) {
                s.pop_back();
            }
        }
    }
};