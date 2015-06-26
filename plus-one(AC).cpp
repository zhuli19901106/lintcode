#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int> &digits) {
		vector<int> &a = digits;
		
		reverse(a.begin(), a.end());
		int i, n = a.size();
		int c = 0;
		a[0] += 1;
		for (i = 0; i < n; ++i) {
			a[i] += c;
			c = a[i] / 10;
			a[i] %= 10;
		}
		if (c) {
			a.push_back(c);
		}
		reverse(a.begin(), a.end());
		return a;
    }
};