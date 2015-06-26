#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
		if (string == NULL) {
			return 0;
		}
		
		int i, j;
		char *s = string;
		int n = length;
		int m = n;
		int ans;
		for (i = 0; i < n; ++i) {
			if (s[i] == ' ') {
				m += 2;
			}
		}
		ans = m;
		s[m--] = 0;
		for (i = n - 1; i >= 0; --i) {
			if (s[i] == ' ') {
				s[m--] = '0';
				s[m--] = '2';
				s[m--] = '%';
			} else {
				s[m--] = s[i];
			}
		}
		return ans;
    }
};