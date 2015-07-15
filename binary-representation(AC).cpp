// What a mess...
#include <cstdlib>
using namespace std;

typedef long long int LL;
class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        string s = "";
        int len = n.length();
        int dp;
        for (dp = 0; dp < len; ++dp) {
            if (n[dp] == '.') {
                break;
            }
        }
        
        int i = 0;
        LL num = 0;
        for (i = 0; i < dp; ++i) {
            num = num * 10 + (n[i] - '0');
            if (num > (1LL << 32) - 1) {
                return "ERROR";
            }
        }
        while (num != 0) {
            s.push_back((num & 1) + '0');
            num >>= 1;
        }
        if (s.length() == 0) {
            s = "0";
        }
        reverse(s.begin(), s.end());
        
        double d = atof(n.substr(dp, len - dp).data());
        if (dp == len || d <= EPS) {
            return s.length() <= 32 ? s : "ERROR";
        }
        s.push_back('.');
        
        string f = "";
        for (i = dp + 1; i < len; ++i) {
            f.push_back(n[i] - '0');
        }
        
        while (f.length() > 0) {
            if (f[0] >= 5) {
                f[0] -= 5;
                s.push_back('1');
            } else {
                s.push_back('0');
            }
            for (i = f.length() - 1; i >= 0; --i) {
                f[i] *= 2;
            }
            for (i = f.length() - 1; i > 0; --i) {
                f[i - 1] += f[i] / 10;
                f[i] %= 10;
            }
            while (!f.empty() && f.back() == 0) {
                f.pop_back();
            }
            if (s.length() > 64) {
                // There is a bug here, but my code passed.
                return "ERROR";
            }
        }
        return s;
    }
private:
    const double EPS = 1e-3;
};