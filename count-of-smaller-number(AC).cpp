#include <algorithm>
using namespace std;

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        int n = queries.size();
        int i, j;
        vector<int> ans;
        
        sort(A.begin(), A.end());
        for (i = 0; i < n; ++i) {
            j = lower_bound(A.begin(), A.end(), queries[i]) - A.begin();
            ans.push_back(j);
        }
        return ans;
    }
};