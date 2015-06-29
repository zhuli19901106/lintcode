#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> um;
        int n = strs.size();
        vector<string> ss;
        vector<string> ans;
        int i;
        
        ss = strs;
        for (i = 0; i < n; ++i) {
            sort(ss[i].begin(), ss[i].end());
            ++um[ss[i]];
        }
        for (i = 0; i < n; ++i) {
            if (um[ss[i]] > 1) {
                ans.push_back(strs[i]);
            }
        }
        return ans;
    }
};