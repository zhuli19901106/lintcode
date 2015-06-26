#include <cmath>
using namespace std;

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char> >& board) {
		int n2 = board.size();
		int n = (int)sqrt(n2);
		vector<vector<bool> > row;
		vector<vector<bool> > col;
		vector<vector<bool> > block;
		
		row.resize(n2, vector<bool>(n2, false));
		col.resize(n2, vector<bool>(n2, false));
		block.resize(n2, vector<bool>(n2, false));
		
		int i, j;
		int idx;
		for (i = 0; i < n2; ++i) {
			for (j = 0; j < n2; ++j) {
				if (board[i][j] == '.') {
					continue;
				}
				idx = board[i][j] - '1';
				if (row[i][idx]) {
					return false;
				}
				row[i][idx] = true;
				if (col[j][idx]) {
					return false;
				}
				col[j][idx] = true;
				if (block[i / n * n + j / n][idx]) {
					return false;
				}
				block[i / n * n + j / n][idx] = true;
			}
		}
		return true;		
    }
};