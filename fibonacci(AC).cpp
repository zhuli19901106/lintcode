class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
		if (n == 1) {
			return 0;
		}
		if (n == 2) {
			return 1;
		}
		int a1 = 0;
		int a2 = 1;
		int a3;
		int i;
		for (i = 3; i <= n; ++i) {
			a3 = a1 + a2;
			a1 = a2;
			a2 = a3;
		}
		return a3;
    }
};