#include <map>
using namespace std;

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        v.clear();
        a.clear();
        c.clear();
        ans.clear();
        
        n = num.size();
        if (n == 0) {
            return ans;
        }
        map<int, int> mm;
        int i;
        for (i = 0; i < n; ++i) {
            ++mm[num[i]];
        }
        for (auto it = mm.begin(); it != mm.end(); ++it) {
            a.push_back(it->first);
            c.push_back(it->second);
        }
        n = a.size();
        t = target;
        DFS(0, 0);
        return ans;
    }
private:
    vector<int> a, c;
    vector<int> v;
    int n;
    int t;
    vector<vector<int> > ans;
    
    void DFS(int idx, int sum) {
        if (sum == t) {
            ans.push_back(v);
            return;
        }
        if (idx == n) {
            return;
        }
        int i, j;
        for (i = 0; i <= c[idx]; ++i) {
            if (sum + i * a[idx] > t) {
                break;
            }
            for (j = 0; j < i; ++j) {
                v.push_back(a[idx]);
            }
            DFS(idx + 1, sum + i * a[idx]);
            for (j = 0; j < i; ++j) {
                v.pop_back();
            }
        }
    }
};