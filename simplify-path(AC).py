import re

class Solution:
    # @param {string} path the original path
    # @return {string} the simplified path
    def simplifyPath(self, path):
        path = re.split('/+', path.strip('/ \n\t'))
        st = []
        for token in path:
            if token == '.':
                continue
            elif token == '..':
                if len(st) > 0:
                    st.pop()
            else:
                st.append(token)
        return '/' + '/'.join(st)