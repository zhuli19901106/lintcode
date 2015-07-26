class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string &s) {
        int i, j;
        
        j = s.length() - 1;
        while (j >= 0 && s[j] == ' ') {
            --j;
        }
        i = j;
        while (i >= 0 && s[i] != ' ') {
            --i;
        }
        return j - i;
    }
};