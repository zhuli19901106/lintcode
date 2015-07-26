class Solution {
public:
    static Solution *getInstance() {
        if (instance == NULL) {
            instance = new Solution();
        }
		return instance;
    }
private:
    Solution();
    static Solution *instance;
};
Solution *Solution::instance = NULL;