#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int> &A) {
        vector<int> pos1(2), pos2(2);
        int msum1, msum2;
        int n = A.size();
        int i;
        
        pos1 = continuousSubarraySum(A, msum1);
        if (msum1 <= 0) {
            return pos1;
        }
        
        int sum = 0;
        for (i = 0; i < n; ++i) {
            sum += A[i];
            A[i] = -A[i];
        }
        pos2 = continuousSubarraySum(A, msum2);
        msum2 = sum + msum2;
        
        pos2[0] = (pos2[0] + n - 1) % n;
        pos2[1] = (pos2[1] + 1) % n;
        swap(pos2[0], pos2[1]);
        
        return msum1 >= msum2 ? pos1 : pos2;
    }
private:
    vector<int> continuousSubarraySum(vector<int>& A, int &msum) {
        int n = A.size();
        int ll;
        int sum;
        
        ll = 0;
        msum = A[0];
        int i;
        for (i = 1; i < n; ++i) {
            if (A[i] > msum) {
                msum = A[i];
                ll = i;
            }
        }
        vector<int> ans;
        if (msum <= 0) {
            ans.push_back(ll);
            ans.push_back(ll);
            return ans;
        }
        
        int mll, mrr;
        ll = 0;
        msum = sum = 0;
        for (i = 0; i < n; ++i) {
            sum += A[i];
            if (sum < 0) {
                sum = 0;
                ll = i + 1;
            }
            if (sum > msum) {
                msum = sum;
                mll = ll;
                mrr = i;
            }
        }
        ans.push_back(mll);
        ans.push_back(mrr);
        return ans;
    }
};