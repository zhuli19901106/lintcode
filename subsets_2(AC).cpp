// The recursive solution
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        n = nums.size();
        if (n == 0) {
            return ans;
        }
        DFS(nums, 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> s;
    int n;
    
    void DFS(vector<int> &a, int idx) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }
        
        DFS(a, idx + 1);
        s.push_back(a[idx]);
        DFS(a, idx + 1);
        s.pop_back();
    }
};