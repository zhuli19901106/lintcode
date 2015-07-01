#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        ans.clear();
        vector<int> &a = nums;
        vector<int> v(4);
        int n = nums.size();
        int i1, i2, i3, i4;
        
        sort(a.begin(), a.end());
        for (i1 = 0; i1 < n - 3; ++i1) {
            for (i4 = i1 + 3; i4 < n; ++i4) {
                i2 = i1 + 1;
                i3 = i4 - 1;
                while (i2 < i3) {
                    if (a[i1] + a[i2] + a[i3] + a[i4] < target) {
                        ++i2;
                    } else if (a[i1] + a[i2] + a[i3] + a[i4] > target) {
                        --i3;
                    } else {
                        v[0] = a[i1];
                        v[1] = a[i2];
                        v[2] = a[i3];
                        v[3] = a[i4];
                        string s = calcSign(v);
                        if (us.find(s) == us.end()) {
                            ans.push_back(v);
                            us.insert(s);
                        }
                        ++i2;
                    }
                }
            }
        }
        us.clear();
        return ans;
    }
private:
    unordered_set<string> us;
    vector<vector<int> > ans;
    
    string calcSign(vector<int> &v) {
        int n = v.size();
        string s = "";
        int i;
        for (i = 0; i < n; ++i) {
            s += to_string(v[i]);
        }
        return s;
    }
};