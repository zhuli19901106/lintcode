#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        ans.clear();
        bt.clear();
        
        dict.insert(start);
        dict.insert(end);
        
        vector<vector<string> > a(2);
        string s1, s2;
        int f, nf;
        a[0].push_back(start);
        f = 1;
        nf = !f;
        
        int i, j, k, n, len;
        char ch;
        while (true) {
            a[f].clear();
            n = a[nf].size();
            for (i = 0; i < n; ++i) {
                dict.erase(a[nf][i]);
            }
            for (i = 0; i < n; ++i) {
                s1 = s2 = a[nf][i];
                len = s1.length();
                for (j = 0; j < len; ++j) {
                    ch = s1[j];
                    for (k = 0; k < 26; ++k) {
                        if (ch == 'a' + k) {
                            continue;
                        }
                        s1[j] = 'a' + k;
                        if (dict.find(s1) == dict.end()) {
                            continue;
                        }
                        a[f].push_back(s1);
                        bt[s1].insert(s2);
                    }
                    s1[j] = ch;
                }
            }
            if (a[f].empty() || bt.find(end) != bt.end()) {
                break;
            }
            f = !f;
            nf = !f;
        }
        if (bt.find(end) == bt.end()) {
            return ans;
        }
        res.clear();
        backTrace(end);
        return ans;
    }
private:
    vector<vector<string> > ans;
    unordered_map<string, unordered_set<string> > bt;
    vector<string> res;
    
    void backTrace(string s) {
        if (bt.find(s) == bt.end()) {
            // End of back trac
            vector<string> r(res);
            r.push_back(s);
            reverse(r.begin(), r.end());
            ans.push_back(r);
            return;
        }
        unordered_set<string> &v = bt[s];
        res.push_back(s);
        for (auto it = v.begin(); it != v.end(); ++it) {
            backTrace(*it);
        }
        res.pop_back();
    }
};