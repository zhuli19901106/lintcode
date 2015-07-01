#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        vector<int> &a = nums;
        int n = nums.size();
        vector<int> minl, minr, maxl, maxr;
        int sum;
        int i;
        
        minl.resize(n);
        minr.resize(n);
        maxl.resize(n);
        maxr.resize(n);
        
        minl[0] = sum = a[0];
        for (i = 1; i <= n - 1; ++i) {
            sum = min(sum, 0);
            sum += a[i];
            minl[i] = min(minl[i - 1], sum);
        }
        
        maxl[0] = sum = a[0];
        for (i = 1; i <= n - 1; ++i) {
            sum = max(sum, 0);
            sum += a[i];
            maxl[i] = max(maxl[i - 1], sum);
        }
        
        minr[n - 1] = sum = a[n - 1];
        for (i = n - 2; i >= 0; --i) {
            sum = min(sum, 0);
            sum += a[i];
            minr[i] = min(minr[i + 1], sum);
        }
        
        maxr[n - 1] = sum = a[n - 1];
        for (i = n - 2; i >= 0; --i) {
            sum = max(sum, 0);
            sum += a[i];
            maxr[i] = max(maxr[i + 1], sum);
        }
        
        int ans = INT_MIN;
        for (i = 0; i < n - 1; ++i) {
            ans = max(ans, myabs(maxl[i] - minr[i + 1]));
            ans = max(ans, myabs(maxr[i + 1] - minl[i]));
        }
        return ans;
    }
private:
    int myabs(int x) {
        return x >= 0 ? x : -x;
    }
};