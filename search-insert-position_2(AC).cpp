#include <algorithm>
using namespace std;

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        return lower_bound(A.begin(), A.end(), target) - A.begin();
    }
};