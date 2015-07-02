/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int ll = 1;
        int rr = n;
        if (VersionControl::isBadVersion(ll)) {
            return ll;
        }
        int mm;
        while (rr - ll > 1) {
            mm = ll + (rr - ll) / 2;
            if (VersionControl::isBadVersion(mm)) {
                rr = mm;
            } else {
                ll = mm;
            }
        }
        return rr;
    }
};