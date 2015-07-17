import re
'''
Definition of ExpressionTreeNode:
class ExpressionTreeNode:
    def __init__(self, symbol):
        self.symbol = symbol
        self.left, self.right = None, None
'''
ETN = ExpressionTreeNode

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
        
    # @param expression: A string list
    # @return: The Reverse Polish notation of this expression
    def convertToRPN(self, expression):
        if (len(expression) == 0):
            return None
        
        num = []
        op = []
        for token in expression:
            if re.match(r'[+\-]?\d+', token):
                num.append(ETN(token))
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
            
        ans = []
        root = num.pop() if len(num) > 0 else None
        self.__postorder(root, ans)
        return ans
        
    def __calculate(self, num, op):
        n2 = num.pop()
        n1 = num.pop()
        single_op = ETN(op.pop())
        single_op.left = n1
        single_op.right = n2
        num.append(single_op)
        
    def __postorder(self, root, ans):
        if root == None:
            return
        self.__postorder(root.left, ans)
        self.__postorder(root.right, ans)
        ans.append(root.symbol)
        