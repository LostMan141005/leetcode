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
			if(0 == i/3) {
				for(int k = 0; k < 9; k +=3) {
                    int arr[256] = {0};
                    for(int j = 0; j < 3; j++){
                        ++arr[board[i+j+k][i+0]];
                        ++arr[board[i+j+k][i+1]];
                        ++arr[board[i+j+k][i+2]];
                        if((arr[board[i+j+k][0]] > 1 && board[i+j+k][0] != '.') || (arr[board[i+j+k][1]] > 1 && board[i+j+k][1] != '.') || (arr[board[i+j+k][2]] > 1 && board[i+j+k][2] != '.')) {
						return false;
                        }
                    }
				}
			}
		}
        return true;
	}
};

int main() {

	return 0;
}