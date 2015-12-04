#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    Solution() {
        cur = 1;
        vector<string> v(1);
        v[0] = "";
        result.push_back(v);
        v[0] = "()";
        result.push_back(v);
    }
    
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return vector<string>();
        }
        while (cur < n) {
            calcCombination(++cur);
        }
        return result[n];
    }
protected:
    vector<vector<string> > result;
    int cur;
    
    void calcCombination(int n) {
        int i, j;
        int sz1;
        vector<string> singleResult;
        
        sz1 = result[n - 1].size();
        for (i = 0; i < sz1; ++i) {
            singleResult.push_back("(" + result[n - 1][i] + ")");
        }
        
        int k;
        int sz2;
        for (i = 1; i < n; ++i) {
            sz1 = result[i - 1].size();
            sz2 = result[n - i].size();
            for (j = 0; j < sz1; ++j) {
                for (k = 0; k < sz2; ++k) {
                    singleResult.push_back("(" + result[i - 1][j] + ")" + result[n - i][k]);
                }
            }
        }
        sort(singleResult.begin(), singleResult.end());
        result.push_back(singleResult);
    }
};
