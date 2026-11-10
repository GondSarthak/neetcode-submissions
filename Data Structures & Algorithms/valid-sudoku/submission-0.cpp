
class Solution {
public:
    // bool isValid(vector<char> cells) {
    //     vector<bool> present(10, false);

    //     for (int i = 0; i < cells.size(); i++) {
    //         if (cells[i] == '.') continue;

    //         int digit = cells[i] - '0';

    //         if (present[digit]) return false;

    //         present[digit] = true;
    //     }

    //     return true;
    // }

    bool isValidSudoku(vector<vector<char>>& board) {
        // // 1. Validate rows
        // for (int i = 0; i < 9; i++) {
        //     vector<char> cells;

        //     for (int j = 0; j < 9; j++) {
        //         cells.push_back(board[i][j]);
        //     }

        //     if (!isValid(cells)) return false;
        // }

        // // 2. Validate columns
        // for (int i = 0; i < 9; i++) {
        //     vector<char> cells;

        //     for (int j = 0; j < 9; j++) {
        //         cells.push_back(board[j][i]);
        //     }

        //     if (!isValid(cells)) return false;
        // }

        // // 3. Validate 3x3 boxes
        // for (int row = 0; row < 9; row += 3) {
        //     for (int col = 0; col < 9; col += 3) {
        //         vector<char> cells;

        //         for (int i = row; i < row + 3; i++) {
        //             for (int j = col; j < col + 3; j++) {
        //                 cells.push_back(board[i][j]);
        //             }
        //         }

        //         if (!isValid(cells)) return false;
        //     }
        // }

        // vector<vector<bool>> rows(9, vector<bool>(10, false));
        // vector<vector<bool>> cols(9, vector<bool>(10, false));
        // vector<vector<bool>> boxes(9, vector<bool>(10, false));

        // for (int i = 0; i < 9; i++) {
        //     for (int j = 0; j < 9; j++) {
        //         if (board[i][j] == '.') continue;

        //         int digit = board[i][j] - '0';
        //         int boxIndex = (i / 3) * 3 + (j / 3);

        //         if (rows[i][digit] ||
        //             cols[j][digit] ||
        //             boxes[boxIndex][digit]) {
        //             return false;
        //         }

        //         rows[i][digit] = true;
        //         cols[j][digit] = true;
        //         boxes[boxIndex][digit] = true;
        //     }
        // }

        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int digit = board[i][j] - '0';
                int boxIndex = (i / 3) * 3 + (j / 3);

                int mask = 1 << digit;

                if ((rows[i] & mask) ||
                    (cols[j] & mask) ||
                    (boxes[boxIndex] & mask)) {
                    return false;
                }

                rows[i] |= mask;
                cols[j] |= mask;
                boxes[boxIndex] |= mask;
            }
        }

        return true;
    }
};
