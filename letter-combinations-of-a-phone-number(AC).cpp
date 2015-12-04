#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    Solution() {
        mapper.push_back(" ");
        mapper.push_back("");
        mapper.push_back("abc");
        mapper.push_back("def");
        mapper.push_back("ghi");
        mapper.push_back("jkl");
        mapper.push_back("mno");
        mapper.push_back("pqrs");
        mapper.push_back("tuv");
        mapper.push_back("wxyz");
    }
    
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        string comb = "";
        vector<string> ans;
        DFS(digits, 0, comb, ans);
        return ans;
    }
protected:
    vector<string> mapper;
    
    void DFS(const string &digits, int idx, string &comb, vector<string> &ans) {
        if (idx == digits.length()) {
            if (comb.length() > 0) {
                ans.push_back(comb);
            }
            return;
        }
        int i;
        for (i = 0; i < mapper[digits[idx] - '0'].length(); ++i) {
            comb.push_back(mapper[digits[idx] - '0'][i]);
            DFS(digits, idx + 1, comb, ans);
            comb.pop_back();
        }
    }
};