
// Vineet Mehta
// SUDOKU SOLVER USING SIMPLE BACKTRACKING
#include <bits/stdc++.h>

#define N 9
using namespace std;
/* 
EXAMPLE -> SUDOKU 9*9, 0 for empty squares.
   
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
   
   
one of the toughest sudoku->

8 5 0 0 0 2 4 0 0
7 2 0 0 0 0 0 0 9
0 0 4 0 0 0 0 0 0 
0 0 0 1 0 7 0 0 2
3 0 5 0 0 0 9 0 0
0 4 0 0 0 0 0 0 0
0 0 0 0 8 0 0 7 0
0 1 7 0 0 0 0 0 0
0 0 0 0 3 6 0 4 0

*/


// finds the next empty swuare and returns the pair of coordinates , if none found it return (-1,-1)
pair<int,int> getnext(int sudoku[N][N]){
	for(int i = 0; i < int(N); i++){
		for(int j = 0; j < int(N); j++){
			if(sudoku[i][j] == 0) 
				return make_pair(i,j);
		}
	}
	return {-1,-1};
}

// checks if the value num doesnt already occur in the row, returns false if found. meaning that num can not be used.
bool valid_row(int sudoku[N][N],int num,int row){
	for(int i = 0; i < int(N); i++){
		if(sudoku[row][i] == num) 
			return false;
	}
	return true;
}

// checks if the value num doesnt already occur in the column, returns false if found. meaning that num can not be used.
bool valid_column(int sudoku[N][N],int num,int column){
	for(int i = 0; i < int(N); i++){
		if(sudoku[i][column] == num) 
			return false;
	}
	return true;
}

// checks if the value num doesnt already occur in the 3*3 unit it belongs to, returns false if found. meaning that num can not be used.
bool valid_unit(int sudoku[N][N],int num, int row, int col){
int unitrow = row - row%3,unitcol = col - col%3;
	for(int i=unitrow;i<unitrow+3;i++){
		for(int j=unitcol;j<unitcol+3;j++){
			if(sudoku[i][j] == num) 
				return false;
		}
	}
	return true;
}

//checks if the assignment of num is valid
bool is_valid(int sudoku[N][N],int num, int row, int col){
	return valid_row(sudoku,num,row)&& valid_column(sudoku,num,col) && valid_unit(sudoku,num,row,col);
}


bool solve(int sudoku[N][N]){
	
	pair<int,int> p = getnext(sudoku);
	
	int row = p.first,col = p.second;
	if(row ==-1 && col == -1) 
		return true;
	for(int i=1;i<=N;i++){
		// if i is valid then it assigns it and calls next assignment recursively
		if(is_valid(sudoku,i,row,col)){
			sudoku[row][col] = i;
			if(solve(sudoku)) return true;
			// if not the solution the reassign it empty
			sudoku[row][col] = 0;
		}
	}
	return false;
}

// prints final sudoku
void print(int sudoku[N][N]){
cout<<"HERE IS YOUR SOLUTION"<<endl;
  for(int i = 0; i < int(N); i++){
	for(int j = 0; j < int(N); j++)
		cout<<sudoku[i][j]<<" "; 
	cout<<endl;
	}
}

int main()
{
ios::sync_with_stdio(false);	
cin.tie(NULL);

int sudoku[N][N];
for(int i = 0; i < int(N); i++)
	for(int j = 0; j < int(N); j++)
		cin>>sudoku[i][j];

cout<<endl<<endl;
if(solve(sudoku))
	print(sudoku);
else cout<<"No solution exists!!";
} 
           
