#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        v.clear();
        us.clear();
        a.clear();
        ans.clear();
        
        n = candidates.size();
        int i;
        for (i = 0; i < n; ++i) {
            us.insert(candidates[i]);
        }
        for (auto it = us.begin(); it != us.end(); ++it) {
            a.push_back(*it);
        }
        n = a.size();
        sort(a.begin(), a.end());
        t = target;
        DFS(0, 0);
        return ans;
    }
private:
    vector<int> v;
    unordered_set<int> us;
    vector<int> a;
    vector<vector<int> > ans;
    int n;
    int t;
    
    void DFS(int idx, int sum) {
        if (sum == t) {
            ans.push_back(v);
            return;
        }
        if (idx == n) {
            return;
        }
        if (sum + a[idx] > t) {
            return;
        }
        int i = 0;
        int j;
        while (sum + i * a[idx] <= t) {
            for (j = 0; j < i; ++j) {
                v.push_back(a[idx]);
            }
            DFS(idx + 1, sum + i * a[idx]);
            for (j = 0; j < i; ++j) {
                v.pop_back();
            }
            ++i;
        }
    }
};