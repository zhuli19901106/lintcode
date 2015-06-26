class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
		a ^= b;
		int c = 0;
		while (a) {
			a = a & a - 1;
			++c;
		}
		return c;
    }
};