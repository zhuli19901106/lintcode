class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        ans.clear();
        DFS(0, 0, n);
        return ans;
    }
private:
    vector<int> ans;
    
    void DFS(int num, int idx, int n) {
        if (idx == n) {
            if (num > 0) {
                ans.push_back(num);
            }
            return;
        }
        
        int i;
        for (i = 0; i < 10; ++i) {
            DFS(num * 10 + i, idx + 1, n);
        }
    }
};