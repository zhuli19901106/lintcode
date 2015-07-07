// O(n * log(n)) solution
#include <algorithm>
#include <climits>
using namespace std;

typedef struct Term {
    int i;
    int s;
} Term;

bool comp(const Term &t1, const Term &t2)
{
    return t1.s < t2.s;
}

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        auto &a = nums;
        int n = a.size();
        vector<Term> v;
        Term t;
        
        t.i = 0;
        t.s = 0;
        v.push_back(t);
        int i;
        for (i = 0; i < n; ++i) {
            t.i = i + 1;
            t.s += a[i];
            v.push_back(t);
        }
        sort(v.begin(), v.end(), comp);
        
        vector<int> ans(2);
        int sum = INT_MAX;
        for (i = 0; i < n; ++i) {
            if (v[i + 1].s - v[i].s < sum) {
                sum = v[i + 1].s - v[i].s;
                ans[0] = min(v[i].i, v[i + 1].i);
                ans[1] = max(v[i].i, v[i + 1].i) - 1;
            }
        }
        return ans;
    }
};