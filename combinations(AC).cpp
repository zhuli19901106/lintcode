class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        ans.clear();
        v.clear();
        this->n = n;
        this->k = k;
        DFS(1, 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> v;
    int n, k;
    
    void DFS(int idx, int cc) {
        if (cc == k) {
            ans.push_back(v);
            return;
        }
        
        int i;
        for (i = idx; i <= cc + n - k + 1; ++i) {
            v.push_back(i);
            DFS(i + 1, cc + 1);
            v.pop_back();
        }
    }
};
