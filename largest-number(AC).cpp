#include <algorithm>
using namespace std;

bool comp(const string &s1, const string &s2)
{
    return s1 + s2 > s2 + s1;
}

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        int n = num.size();
        int i;
        vector<string> a;
        for (i = 0; i < n; ++i) {
            a.push_back(to_string(num[i]));
        }
        sort(a.begin(), a.end(), comp);
        i = 0;
        while (i < n - 1 && a[i] == "0") {
            ++i;
        }
        string ans = "";
        while (i < n) {
            ans += a[i++];
        }
        return ans;
    }
};