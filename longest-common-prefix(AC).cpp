class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if (n == 0) {
            return "";
        }
        string ans = strs[0];
        int i, j;
        for (i = 1; i < n; ++i) {
            j = 0;
            while (j < ans.length() && j < strs[i].length()) {
                if (ans[j] != strs[i][j]) {
                    break;
                }
                ++j;
            }
            while (ans.length() > j) {
                ans.pop_back();
            }
        }
        return ans;
    }
};