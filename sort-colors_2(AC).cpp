// How tricky...
// It took me over 20 minutes to put it right.
#include <algorithm>
using namespace std;

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        auto &a = nums;
        int n = a.size();
        int i, j;
        int ii, jj;
        ii = i = 0;
        jj = j = n - 1;
        while (i < j) {
            if (a[i] == 0) {
                swap(a[i], a[ii]);
                ++ii;
                i = max(i, ii);
            } else if (a[j] == 2) {
                swap(a[j], a[jj]);
                --jj;
                j = min(j, jj);
            } else if (a[i] == 2) {
                swap(a[i], a[jj]);
                --jj;
                j = min(j, jj);
            } else if (a[j] == 0) {
                swap(a[j], a[ii]);
                ++ii;
                i = max(i, ii);
            } else {
                ++i;
            }
        }
        while (ii <= jj) {
            a[ii++] = 1;
        }
    }
};