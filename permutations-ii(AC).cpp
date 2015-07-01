#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        ans.clear();
        int n = nums.size();
        if (n == 0) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (nextPermutation(nums));
        return ans;
    }
private:
    vector<vector<int> > ans;
    
    bool nextPermutation(vector<int> &a) {
        int n = a.size();
        int i, j;
        for (i = n - 2; i >= 0; --i) {
            if (a[i] < a[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            return false;
        }
        j = n - 1;
        while (a[j] <= a[i]) {
            --j;
        }
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
        
        return true;
    }
};