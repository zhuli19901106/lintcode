#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        int i;
        int len = 0;
        vector<string> ans;
        
        for (i = 0; i < dictionary.size(); ++i) {
            len = max(len, (int)dictionary[i].length());
        }
        for (i = 0; i < dictionary.size(); ++i) {
            if (len == dictionary[i].length()) {
                ans.push_back(dictionary[i]);
            }
        }
        return ans;
    }
};