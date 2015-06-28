class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        int i, j;
        int ans = 0;
        int n = heights.size();
        
        i = 0;
        j = n - 1;
        while (i < j) {
            ans = max(ans, (j - i) * min(heights[j], heights[i]));
            if (heights[i] < heights[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return ans;
    }
};