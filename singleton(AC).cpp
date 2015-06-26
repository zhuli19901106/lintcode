class Solution {
private:
	Solution() {}
public:
    static Solution *getInstance() {
		static Solution *instance;
		if (instance == NULL) {
			instance = new Solution();
		}
		return instance;
    }
};