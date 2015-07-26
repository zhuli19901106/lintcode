#include <unordered_map>
using namespace std;

unordered_map<char, int> val;
unordered_map<char, char> nextchar;

class Solution {
public:
    Solution() {
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        nextchar['V'] = 'I';
        nextchar['X'] = 'I';
        nextchar['L'] = 'X';
        nextchar['C'] = 'X';
        nextchar['D'] = 'C';
        nextchar['M'] = 'C';
    }
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        int n = s.length();
        int i;
        int ans;
        
        ans = 0;
        i = 0;
        while (i < n) {
            if (i < n - 1 && nextchar[s[i + 1]] == s[i]) {
                ans += val[s[i + 1]] - val[s[i]];
                i += 2;
            } else {
                ans += val[s[i]];
                i += 1;
            }
        }
        return ans;
    }
};