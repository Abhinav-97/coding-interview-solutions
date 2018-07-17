#include<iostream>
#include<iomanip>
using namespace std;
const int D = 8;
void print_board(int board[D][D], int n){
	for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<setw(3)<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"---------------------------------"<<endl;
}
bool checkPlace(int board[D][D], int n, int r, int c){
	if(r < n && r >= 0 && c < n && c >= 0 && board[r][c] == 0){
		return true;
	}
	else{
		return false;
	}
}
bool solveKnightMove(int board[D][D], int n, int no_moves, int curRow, int curCol){
	if(no_moves == n*n){
		print_board(board,n);
		return true; // if we have moved 64 moves then
	}
	int rowDie[] = {-2,-1,1,2,2,1,-1,-2};
	int colDie[] = {1,2,2,1,-1,-2,-2,-1};
	for(int i=0;i<8;i++){
		int nextRow = curRow + rowDie[i];
		int nextCol = curCol + colDie[i];
		if(checkPlace(board,n,nextRow,nextCol)) { // If the board is not placed
			board[nextRow][nextCol] = no_moves + 1;  // Place the board with move number
			bool isSuccessfull = solveKnightMove(board, n, no_moves+1, nextRow, nextCol); // solve other places
			// if(isSuccessfull) return true;
			board[nextRow][nextCol] = 0; // erase the board if its not true
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int board[D][D] = {0};
	board[0][0] = 1;
	bool ans = solveKnightMove(board, n, 1, 0, 0);
	if(ans){
		print_board(board,n);
	}
}
