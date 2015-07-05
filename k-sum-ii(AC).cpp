#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        ans.clear();
        v.clear();
        sort(A.begin(), A.end());
        v.resize(k);
        this->n = A.size();
        this->k = k;
        this->target = target;
        if (k == 1) {
            solveOne(A, target);
            return ans;
        }
        DFS(A, 0, 0, 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> v;
    int n;
    int k;
    int target;
    
    void solveOne(vector<int> &A, int target) {
        int i;
        for (i = 0; i < n; ++i) {
            if (A[i] == target) {
                v[0] = target;
                ans.push_back(v);
            }
        }
    }
    
    void DFS(vector<int> &A, int idx, int sum, int cc) {
        if (sum + A[idx] * (k - cc) > target) {
            return;
        }
        if (sum + A[n - 1] * (k - cc) < target) {
            return;
        }
        
        if (cc == k - 2) {
            int ll = idx;
            int rr = n - 1;
            while (ll < rr) {
                if (A[ll] + A[rr] < target - sum) {
                    ++ll;
                } else if (A[ll] + A[rr] > target - sum) {
                    --rr;
                } else {
                    v[k - 2] = A[ll];
                    v[k - 1] = A[rr];
                    ans.push_back(v);
                    ++ll;
                }
            }
            return;
        }
        
        int i;
        for (i = idx; i <= n - (k - cc); ++i) {
            v[cc] = A[i];
            DFS(A, i + 1, sum + A[i], cc + 1);
        }
    }
};