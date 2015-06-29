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
        addBit(a, b, s, 0, c);
        addBit(a, b, s, 1, c);
        addBit(a, b, s, 2, c);
        addBit(a, b, s, 3, c);
        addBit(a, b, s, 4, c);
        addBit(a, b, s, 5, c);
        addBit(a, b, s, 6, c);
        addBit(a, b, s, 7, c);
        addBit(a, b, s, 8, c);
        addBit(a, b, s, 9, c);
        addBit(a, b, s, 10, c);
        addBit(a, b, s, 11, c);
        addBit(a, b, s, 12, c);
        addBit(a, b, s, 13, c);
        addBit(a, b, s, 14, c);
        addBit(a, b, s, 15, c);
        addBit(a, b, s, 16, c);
        addBit(a, b, s, 17, c);
        addBit(a, b, s, 18, c);
        addBit(a, b, s, 19, c);
        addBit(a, b, s, 20, c);
        addBit(a, b, s, 21, c);
        addBit(a, b, s, 22, c);
        addBit(a, b, s, 23, c);
        addBit(a, b, s, 24, c);
        addBit(a, b, s, 25, c);
        addBit(a, b, s, 26, c);
        addBit(a, b, s, 27, c);
        addBit(a, b, s, 28, c);
        addBit(a, b, s, 29, c);
        addBit(a, b, s, 30, c);
        addBit(a, b, s, 31, c);
        return s;
    }
private:
    void addBit(int &a, int &b, int &s, int i, int &c) {
        s |= (a ^ b ^ c) & (1 << i);
        c = (a & b & (1 << i)) | (b & c & (1 << i)) | (c & a & (1 << i));
        c <<= 1;
    }
};
