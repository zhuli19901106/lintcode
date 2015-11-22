#include <vector>
using namespace std;
typedef vector<vector<char> > V2DC;

class Solution {
public:
    Solution() {
        d[0][0] = 0;
        d[0][1] = +1;
        d[1][0] = 0;
        d[1][1] = -1;
        d[2][0] = +1;
        d[2][1] = 0;
        d[3][0] = -1;
        d[3][1] = 0;
    }
    
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(V2DC &board) {
        n = board.size();
        m = n ? board[0].size() : 0;
        
        int i, j;
        for (i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                flood(board, i, 0, '?');
            }
            if (board[i][m - 1] == 'O') {
                flood(board, i, m - 1, '?');
            }
        }
        for (j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                flood(board, 0, j, '?');
            }
            if (board[n - 1][j] == 'O') {
                flood(board, n - 1, j, '?');
            }
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if (board[i][j] == '?') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
protected:
    int n, m;
    int d[4][2];
    
    bool inbound(int x, int y) {
        return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
    }
    
    void flood(V2DC &board, int x, int y, char mark) {
        int x1, y1;
        int i;
        board[x][y] = mark;
        for (i = 0; i < 4; ++i) {
            x1 = x + d[i][0];
            y1 = y + d[i][1];
            if (inbound(x1, y1) && board[x1][y1] == 'O') {
                flood(board, x1, y1, mark);
            }
        }
    }
};