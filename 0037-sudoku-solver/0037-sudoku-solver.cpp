class Solution {
    int row[9], col[9], box[9];

    bool dfs(vector<vector<char>>& b) {
        // sabse kam options wali empty cell chuno (MRV)
        int bi = -1, bj = -1, bestCnt = 10, bestMask = 0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (b[i][j] != '.') continue;
                int used = row[i] | col[j] | box[(i / 3) * 3 + j / 3];
                int avail = (~used) & 0x1FF;
                int cnt = __builtin_popcount(avail);
                if (cnt == 0) return false;
                if (cnt < bestCnt) {
                    bestCnt = cnt; bi = i; bj = j; bestMask = avail;
                }
            }
        if (bi == -1) return true;   // koi empty cell nahi bacha

        int bx = (bi / 3) * 3 + bj / 3;
        for (int d = 0; d < 9; d++) {
            if (!(bestMask & (1 << d))) continue;
            b[bi][bj] = '1' + d;
            row[bi] |= 1 << d; col[bj] |= 1 << d; box[bx] |= 1 << d;
            if (dfs(b)) return true;
            row[bi] &= ~(1 << d); col[bj] &= ~(1 << d); box[bx] &= ~(1 << d);
            b[bi][bj] = '.';
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int d = board[i][j] - '1';
                    row[i] |= 1 << d;
                    col[j] |= 1 << d;
                    box[(i / 3) * 3 + j / 3] |= 1 << d;
                }
        dfs(board);
    }
};