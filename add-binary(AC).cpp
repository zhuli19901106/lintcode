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
		int c = 0;
		int al = a.length();
		int bl = b.length();
		int i;
		for (i = 0; i < bl; ++i) {
			s.push_back(c + a[i] - '0' + b[i] - '0');
			c = s[i] >> 1;
			s[i] &= 1;
		}
		for (i = bl; i < al; ++i) {
			s.push_back(c + a[i] - '0');
			c = s[i] >> 1;
			s[i] &= 1;
		}
		if (c) {
			s.push_back(1);
		}
		for (i = 0; i < s.length(); ++i) {
			s[i] += '0';
		}
		reverse(s.begin(), s.end());
		
		return s;
    }
};