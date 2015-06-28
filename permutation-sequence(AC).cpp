class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        string ans = "";
        --k;
        vector<int> v;
        int f = 1;
        int i, j;
        for (i = 1; i < n; ++i) {
            f *= i;
        }
        
        v.resize(n);
        for (i = 0; i < n; ++i) {
            v[i] = i;
        }
        
        int p;
        for (i = n - 1; i >= 1; --i) {
            p = k / f;
            k %= f;
            ans.push_back('1' + v[p]);
            for (j = p; j < i; ++j) {
                v[j] = v[j + 1];
            }
            v.pop_back();
            f /= i;
        }
        ans.push_back('1' + v[0]);
        return ans;
    }
};