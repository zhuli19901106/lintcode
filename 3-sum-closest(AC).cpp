#include <algorithm>
using namespace std;

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        vector<int> &a = nums;
        int n = a.size();
        int i, j, k;
        int ans;
        
        sort(a.begin(), a.end());
        ans = a[0] + a[1] + a[2];
        int s;
        for (i = 0; i < n - 2; ++i) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                s = a[i] + a[j] + a[k];
                if (s < target) {
                    if (abs(s - target) < abs(ans - target)) {
                        ans = s;
                    }
                    ++j;
                } else if (s > target) {
                    if (abs(s - target) < abs(ans - target)) {
                        ans = s;
                    }
                    --k;
                } else {
                    return target;
                }
            }
        }
        return ans;
    }
private:
    int abs(int x) {
        return x >= 0 ? x : -x;
    }
};