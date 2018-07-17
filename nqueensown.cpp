#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
const int D = 4;
void printBoard(bool board[][D])
{
	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < D; j++)
		{
			cout << setw(3) << board[i][j] << " ";
		}
		cout << "\n";
	}
}
bool checker(bool board[][D], int row, int col)
{
	for (int i = 0; i < D; i++)
		// check for column and row
	{
		if (board[row][i] == true) return false;
		if (board[i][col] == true) return false;
	}
	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < D; j++)
		{
			// check for right diagonal
			if ((i - j) == (row - col)) {
				if (board[i][j]) return false;
			}
			// check for left diagonal
			if ((i + j) == (row + col)) {
				if (board[i][j]) return false;
			}
		}
	}
	return true;
}
bool nQueensSol(bool board[][D], int n)
{
	if (n == D) {
		printBoard(board);
		// nQueensSol(board, 0);
		cout << "\n";
		return true;
	}
	for (int r = 0; r < D; r++)
	{
		for (int c = 0; c < D; c++)
		{
			if (checker(board, r, c)) {
				board[r][c] = true;
				bool remainingBoard = nQueensSol(board, n + 1);
				if (remainingBoard) {
					return true;
				}
				else {
					board[r][c] = false;
				}
			}
		}
	}
	return false;
}
int main()
{
	bool board[D][D] = {0};
	bool sol = nQueensSol(board, 0);
	if (sol) {
		printBoard(board);
	}
}