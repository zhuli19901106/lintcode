import re

class Solution:
    # @param {string} s the string that represents a number
    # @return {boolean} whether the string is a valid number
    def isNumber(self, s):
        p = r'[+\-]?((\d+(\.\d*)?)|(\.\d+))([eE][+\-]?\d+)?'
        return re.match(p, s.strip()) != None
        