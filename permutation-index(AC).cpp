#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef long long LL;
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    LL permutationIndex(vector<int> &A) {
        vector<int> a;
        mapping(A, a);
        return normalizedPermutationIndex(a) + 1;
    }
protected:
    void mapping(vector<int> &A, vector<int> &a) {
        // The array is supposed to be without duplicates.
        map<int, int> mm;
        int n = A.size();
        int i;
        for (i = 0; i < n; ++i) {
            mm[A[i]] = 1;
        }
        i = 0;
        for (auto it = mm.begin(); it != mm.end(); ++it) {
            it->second = i++;
        }
        for (i = 0; i < n; ++i) {
            a.push_back(mm[A[i]]);
        }
    }
    
    LL normalizedPermutationIndex(vector<int> &a) {
        // Find the permutation index of a permutation of [0, 1, ..., n - 1]
        int n = a.size();
        LL f = 1;
        int i;
        for (i = 1; i < n; ++i) {
            f *= i;
        }
        vector<int> v;
        for (i = 0; i < n; ++i) {
            v.push_back(i);
        }
        
        int j;
        LL ans = 0;
        for (i = 0; i < n - 1; ++i) {
            j = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v.erase(v.begin() + j);
            ans += j * f;
            f /= n - 1 - i;
        }
        return ans;
    }
};