class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int n = gas.size();
		int i;
		int sum = 0;
		int j = 0;
		for (i = 0; i < 2 * n - 1; ++i) {
			sum += gas[i % n] - cost[i % n];
			if (sum < 0) {
				sum = 0;
				j = i + 1;
			}
			if (i - j == n - 1) {
				return j;
			}
		}
		return -1;
    }
};