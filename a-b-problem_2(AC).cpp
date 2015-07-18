// Use your smart, not your brute force...
class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        int s = 0;
        int c = 0;
        int mask;
        for (mask = 1; mask; mask <<= 1) {
            addBit(a, b, s, mask, c);
        }
        return s;
    }
private:
    void addBit(int &a, int &b, int &s, int mask, int &c) {
        s |= (a ^ b ^ c) & mask;
        c = (a & b & mask) | (b & c & mask) | (c & a & mask);
        c <<= 1;
    }
};