#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
	Solution() {
		ans[1] = "1";
		max_n = 1;
	}
	
    string countAndSay(int n) {
		if (ans.find(n) != ans.end()) {
			return ans[n];
		}
		int i;
		for (i = max_n; i < n; ++i) {
			ans[i + 1] = next(ans[i]);
		}
		max_n = n;
		return ans[n];
    }
	
	~Solution() {
		ans.clear();
	}
private:
	unordered_map<int, string> ans;
	int max_n;
	
	string next(string s) {
		string s1;
		int n, i, j;
		
		n = s.length();
		i = 0;
		s1 = "";
		while (i < n) {
			j = i;
			while (j < n && s[i] == s[j]) {
				++j;
			}
			s1 += to_string(j - i);
			s1.push_back(s[i]);
			i = j;
		}
		return s1;
	}
};