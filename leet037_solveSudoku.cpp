#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty()) return;
        solveSK(board);
    }
    bool solveSK(vector<vector<int>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(int x = '1'; x <= '9'; x++){
                        if(isValid(board,i,j,x)){
                            board[i][j] = x;
                            
                            if(solveSK(board))
                                return true;
                            else
                                board[i][j] = '.';
                            
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<int>>& board, int row, int col, int ch){
        for(int i = 0; i < 9; i++){
            if(board[row][i] != '.' && board[row][i] == ch) return false;
            if(board[i][col] != '.' && board[i][col] == ch) return false;
            if(board[row/3 * 3 + i/3][col/3 * 3 + i % 3] != '.' && board[row/3 * 3 + i/3][col/3 * 3 + i%3] == ch) return false;
        }
        return true;
    }
};

int main(){

    return 0;
}