import re

class Solution:
    op = {}
    
    def sign(self, x):
        return 0 if x == 0 else 1 if x > 0 else -1
        
    def __init__(self):
        self.op['+'] = lambda x, y: x + y
        self.op['-'] = lambda x, y: x - y
        self.op['*'] = lambda x, y: x * y
        self.op['/'] = lambda x, y: abs(x) / abs(y) * self.sign(x * y)
        
    # @param {string[]} tokens The Reverse Polish Notation
    # @return {int} the value
    def evalRPN(self, tokens):
        st = []
        for token in tokens:
            if re.match(r'[\+\-]?\d+', token):
                st.append(int(token))
            else:
                n2 = st.pop()
                n1 = st.pop()
                st.append(self.op[token](n1, n2))
        return st.pop()
        