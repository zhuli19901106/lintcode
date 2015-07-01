#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<int> &a = nums;
        vector<int> v(3);
        int n = a.size();
        
        ans.clear();
        int i, j, k;
        sort(a.begin(), a.end());
        for (i = 0; i < n - 2; ++i) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                if (a[i] + a[j] + a[k] < 0) {
                    ++j;
                } else if (a[i] + a[j] + a[k] > 0) {
                    --k;
                } else {
                    string s = calcSign(a[i], a[j], a[k]);
                    if (us.find(s) == us.end()) {
                        v[0] = a[i];
                        v[1] = a[j];
                        v[2] = a[k];
                        ans.push_back(v);
                        us.insert(s);
                    }
                    ++j;
                }
            }
        }
        us.clear();
        return ans;
    }
private:
    unordered_set<string> us;
    vector<vector<int> > ans;
    
    string calcSign(int a, int b, int c) {
        return to_string(a) + to_string(b) + to_string(c);
    }
};