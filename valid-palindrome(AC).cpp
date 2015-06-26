#include <cctype>
using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
		int i = 0;
		int j = s.length() - 1;
		
		while (i < j) {
			if (!isalnum(s[i])) {
				++i;
			} else if (!isalnum(s[j])) {
				--j;
			} else if (s[i] == s[j]) {
				++i;
				--j;
			} else if (isalpha(s[i]) && isalpha(s[j]) && 
			           tolower(s[i]) == tolower(s[j])) {
				++i;
				--j;
			} else {
				return false;
			}
		}
		return true;
    }
};