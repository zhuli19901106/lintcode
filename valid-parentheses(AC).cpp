#include <map>
#include <stack>
using namespace std;

class Solution {
public:
	Solution() {
		m[')'] = '(';
		m[']'] = '[';
		m['}'] = '{';
	}
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
		int n = s.length();
		stack<char> st;
		
		int i;
		for (i = 0; i < n; ++i) {
			switch (s[i]) {
			case '(':
			case '[':
			case '{':
				st.push(s[i]);
				break;
			case ')':
			case ']':
			case '}':
				if (st.empty() || st.top() != m[s[i]]) {
					return false;
				}
				st.pop();
				break;
			}
		}
		return st.empty();
    }
private:
	map<char, char> m;
};