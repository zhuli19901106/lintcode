typedef long long int LL;
class Solution {
public:
    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        n = A.size();
        a.resize(n + 1, 0);
        int i;
        for (i = 0; i < n; ++i) {
            add(i + 1, A[i]);
        }
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    LL query(int start, int end) {
        ++start;
        ++end;
        return sum(end) - sum(start - 1);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        int oldValue = query(index, index);
        ++index;
        add(index, value - oldValue);
    }
private:
    vector<LL> a;
    int n;
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int index, int value) {
        while (index <= n) {
            a[index] += value;
            index += lowbit(index);
        }
    }
    
    LL sum(int index) {
        LL s = 0;
        while (index > 0) {
            s += a[index];
            index -= lowbit(index);
        }
        return s;
    }
};