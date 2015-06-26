class Solution {
public:
	/**
	 * @param nums: The integer array.
	 * @param target: Target number to find.
	 * @return: The first position of target. Position starts from 0. 
	 */
	int binarySearch(vector<int> &array, int target) {
		int n = array.size();
		if (target < array[0] || target > array[n - 1]) {
			return -1;
		}
		if (target == array[0]) {
			return 0;
		}
		
		int ll, rr, mm;
		ll = 0;
		rr = n - 1;
		while (rr - ll > 1) {
			mm = (ll + rr) / 2;
			if (array[mm] < target) {
				ll = mm;
			} else {
				rr = mm;
			}
		}
		
		return array[rr] == target ? rr : -1;
	}
};