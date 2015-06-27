import re

class Solution:
    # @param s : A string
    # @return : A string
    def reverseWords(self, s):
        return (' '.join([val[::-1] for val in re.split('\s+', s.strip())]))[::-1]
        