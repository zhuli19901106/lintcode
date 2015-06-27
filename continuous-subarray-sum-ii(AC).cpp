class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        int msum1;
        vector<int> ans1;
        ans1 = continuousSubarraySum(A, msum1);
        if (ans1[0] == ans1[1]) {
            return ans1;
        }
        
        vector<int> s1;
        vector<int> i1;
        vector<int> s2;
        vector<int> i2;
        
        int n = A.size();
        int i;
        int sum;
        
        s1.resize(n);
        i1.resize(n);
        s2.resize(n);
        i2.resize(n);
        
        sum = A[0];
        s1[0] = A[0];
        i1[0] = 0;
        for (i = 1; i <= n - 1; ++i) {
            sum += A[i];
            if (sum > s1[i - 1]) {
                s1[i] = sum;
                i1[i] = i;
            } else {
                s1[i] = s1[i - 1];
                i1[i] = i1[i - 1];
            }
        }
        
        sum = A[n - 1];
        s2[n - 1] = A[n - 1];
        i2[n - 1] = n - 1;
        for (i = n - 2; i >= 0; --i) {
            sum += A[i];
            if (sum > s2[i + 1]) {
                s2[i] = sum;
                i2[i] = i;
            } else {
                s2[i] = s2[i + 1];
                i2[i] = i2[i + 1];
            }
        }
        
        int msum2 = 0;
        vector<int> ans2;
        ans2.resize(2);
        for (i = 0; i < n - 1; ++i) {
            if (s1[i] + s2[i + 1] > msum2) {
                msum2 = s1[i] + s2[i + 1];
                ans2[0] = i2[i + 1];
                ans2[1] = i1[i];
            }
        }
        return msum1 > msum2 ? ans1 : ans2;
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
