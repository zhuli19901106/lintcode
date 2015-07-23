// Magic?
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if (x < 2) {
            return x;
        }
        float f = x;
        float half = 0.5f * f;
        int i = *(int *)&f;
        i = 0x5f375a86 - (i >> 1);
        f = *(float *)&i;
        
        // Newton Iteration
        f = f * (1.5f - half * f * f);
        f = f * (1.5f - half * f * f);
        
        return (int)(1.0 / f);
    }
};