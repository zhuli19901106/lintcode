typedef long long int LL;
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<LL> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<LL> sum;
        int n = A.size();
        sum.resize(n + 1, 0);
        int i;
        for (i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + A[i];
        }
        vector<LL> ans;
        int m = queries.size();
        for (i = 0; i < m; ++i) {
            ans.push_back(sum[queries[i].end + 1] - sum[queries[i].start]);
        }
        return ans;
    }
};