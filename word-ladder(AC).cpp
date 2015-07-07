// Solution using BFS
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

typedef unordered_set<string> uss;
class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, uss &dict) {
        if (start == end) {
            return 0;
        }
        
        dict.insert(start);
        dict.insert(end);
        
        queue<string> q;
        unordered_map<string, int> um;
        
        string p;
        char ch;
        int i, j, len = start.length();
        int cc;
        
        um[start] = 1;
        q.push(start);
        while (um.find(end) == um.end() && !q.empty()) {
            p = q.front();
            cc = um[p];
            q.pop();
            for (i = 0; i < len; ++i) {
                ch = p[i];
                for (j = 0; j < 26; ++j) {
                    if (ch == 'a' + j) {
                        continue;
                    }
                    p[i] = 'a' + j;
                    if (dict.find(p) == dict.end()) {
                        // Not in dict
                        continue;
                    }
                    if (um.find(p) != um.end()) {
                        // Already visited
                        continue;
                    }
                    um[p] = cc + 1;
                    q.push(p);
                }
                p[i] = ch;
            }
        }
        return um[end];
    }
};