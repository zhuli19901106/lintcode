#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
		if (a.length() < b.length()) {
			return addBinary(b, a);
		}
		
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		
		string s = "";
		int al = a.length();
		int bl = b.length();
		int i;
		for (i = 0; i < bl; ++i) {
			s.push_back(a[i] + b[i] - '0');
		}
		for (i = bl; i < al; ++i) {
			s.push_back(a[i]);
		}
        
        int c = 0;
        for (i = 0; i < al - 1; ++i) {
            c = s[i] - '0' >> 1;
            s[i] = (s[i] - '0' & 1) + '0';
            s[i + 1] += c;
        }
        c = s[i] - '0' >> 1;
        s[i] = (s[i] - '0' & 1) + '0';
		if (c) {
			s.push_back('1');
		}
		reverse(s.begin(), s.end());
		
		return s;
    }
};