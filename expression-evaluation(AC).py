# There're some illegal cases, it's unfair
import re

class Solution:
    # Define the precedence of operators
    __pre = {}
    __fun = {}
    
    def __init__(self):
        pre_count = -1
        
        self.__pre['('] = pre_count
        pre_count += 1
        
        self.__pre['+'] = pre_count
        self.__pre['-'] = pre_count
        pre_count += 1
        
        self.__pre['*'] = pre_count
        self.__pre['/'] = pre_count
        self.__pre['%'] = pre_count
        pre_count += 1
        
        self.__fun['+'] = lambda x, y: x + y
        self.__fun['-'] = lambda x, y: x - y
        self.__fun['*'] = lambda x, y: x * y
        self.__fun['/'] = lambda x, y: x / y
        self.__fun['%'] = lambda x, y: x % y
        
    # @param expression: a list of strings;
    # @return: an integer
    def evaluateExpression(self, expression):
        if (len(expression) == 0):
            return 0
        
        num = []
        op = []
        for token in expression:
            if re.match(r'[+\-]?\d+', token):
                num.append(int(token))
            elif token == '(':
                op.append(token)
            elif token == ')':
                while op[-1] != '(':
                    self.__calculate(num, op)
                op.pop()
            else:
                while len(op) > 0 and self.__pre[op[-1]] >= self.__pre[token]:
                    self.__calculate(num, op)
                op.append(token)
        while len(op) > 0:
            self.__calculate(num, op)
        
        return num.pop() if len(num) > 0 else 0
        
    def __calculate(self, num, op):
        n2 = num.pop()
        n1 = num.pop()
        single_op = op.pop()
        num.append(self.__fun[single_op](n1, n2))
        