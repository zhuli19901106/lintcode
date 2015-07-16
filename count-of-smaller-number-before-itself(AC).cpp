class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> s(N + 1, 0);
        vector<int> ans;
        int n = A.size();
        int i;
        for (i = 0; i < n; ++i) {
            // Offset by 1
            ans.push_back(sum(s, A[i]));
            add(s, A[i] + 1, 1);
        }
        return ans;
    }
private:
    static const int N = 10001;
    
    int lowbit(int x) {
        return x & -x;
    }
    
    int sum(vector<int> &a, int i) {
        int sum = 0;
        while (i > 0) {
            sum += a[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
    void add(vector<int> &a, int i, int val) {
        if (i == 0) {
            return;
        }
        while (i <= N) {
            a[i] += val;
            i += lowbit(i);
        }
    }
};