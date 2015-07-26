class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int c;
        while (num > 0) {
            num = num & num - 1;
            ++c;
        }
        return c;
    }
};