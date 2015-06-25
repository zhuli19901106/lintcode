class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
		int c;
		int val;
		int n = nums.size();
		int i;
		
		val = nums[0];
		c = 1;
		for (i = 1; i < n; ++i) {
			if (nums[i] == val) {
				++c;
			} else {
				--c;
			}
			if (c == 0) {
				val = nums[i];
				c = 1;
			}
		}
		
		return val;
    }
};