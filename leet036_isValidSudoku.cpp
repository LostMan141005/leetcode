#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:

	bool isValidSudoku(vector<vector<char>>& board) {
		if(board.size() != 9) return false;
		for(int i = 0; i < board.size(); i++) {
			int col[256] = {0}, row[256] = {0};
			for(int j = 0; j < board.size(); j++) {
				++col[board[j][i]];
                ++row[board[i][j]];
				if((col[board[j][i]] > 1 && board[j][i] != '.' ) || (row[board[i][j]] > 1 && board[i][j] != '.')) {
					return false;
				}
			}
			if(0 == i % 3) {
				for(int k = 0; k < 9; k+=3) {
                    int arr[256] = {0};
                    for(int j = 0; j < 3; j++){
                        ++arr[board[j+k][i+0]];
                        ++arr[board[j+k][i+1]];
                        ++arr[board[j+k][i+2]];
                        if((arr[board[j+k][i+0]] > 1 && board[j+k][i+0] != '.') || (arr[board[j+k][i+1]] > 1 && board[j+k][i+1] != '.') || (arr[board[j+k][i+2]] > 1 && board[j+k][i+2] != '.')) {
                            return false;
                        }
                    }
				}
			}
		}
        return true;
	}
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if (row[i][num] || col[j][num] || box[k][num]) return false;
                    row[i][num] = col[j][num] = box[k][num] = true;
                }
            }
        }
        return true;
    }
};

int main() {

	return 0;
}