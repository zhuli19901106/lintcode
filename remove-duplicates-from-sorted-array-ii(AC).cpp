class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
		int m = 0;
		int i, j;
		i = 0;
		while (i < n) {
			j = i + 1;
			while (j < n && nums[i] == nums[j]) {
				++j;
			}
			nums[m++] = nums[i];
			if (j - i > 1) {
				nums[m++] = nums[i];
			}
			i = j;
		}
		while (nums.size() > m) {
			nums.pop_back();
		}
		return m;
    }
};