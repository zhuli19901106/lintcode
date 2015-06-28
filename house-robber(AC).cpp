typedef long long int LL;

LL max(LL x, LL y)
{
    return x > y ? x : y;
}

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    LL houseRobber(vector<int> A) {
        int n = A.size();
        LL a1, a2, a3, a4;
        LL ans;
        
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return A[0];
        } else if (n == 2) {
            return max(A[0], A[1]);
        }
        A[2] += A[0];
        ans = max(A[0], A[1]);
        ans = max(ans, A[2]);
        
        int i;
        a1 = A[0];
        a2 = A[1];
        a3 = A[2];
        for (i = 3; i < n; ++i) {
            a4 = max(a1, a2) + A[i];
            ans = max(ans, a4);
            a1 = a2;
            a2 = a3;
            a3 = a4;
        }
        return ans;
    }
};