// BackTracking-Maze 
// Recursion
#include<iostream>
using namespace std;
int M,N; // M:row, N:col
int main(){
	int visitMaze(int** A, int rol, int col);
	cin>>M>>N;
	int** Maze = new int* [M+2]; // originate Maze cell 
	for(int i = 0; i < M + 2; i++){
		Maze[i] = new int [N+2];
	} 
	for(int i = 1;i < M + 1 ; i++ ){
		for(int j = 1; j < N + 1; j++){
			cin>>Maze[i][j];
		}
	}
	for(int i = 0; i < M + 2; i++){  // init Maze cell 
		for(int j = 0; j < N + 2; j++){
			if(i == 0 || i == M + 1){
				Maze[i][j] = 2; // 2 means wall, cannot go through
			}
			if(j == 0 || j == N + 1){
				Maze[i][j] = 2;
			}
		}
	}
    // the original Maze Cell
	for(int i = 0; i < M + 2; i++ ){
		for(int j = 0; j < N + 2; j++){
			cout<<Maze[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"=================="<<endl;
	
	visitMaze(Maze, 1, 1);  // setting : (1,1) is entry;  (M,N) is export
	for(int i = 0; i < M + 2; i++){
		delete [] Maze[i];
	}
	delete [] Maze;
	return 0;
}
int visitMaze(int** A, int i, int j){
//	cout<<M<<" "<<N;
	A[i][j] = 1;  // setting: 1 means already visited
	if(i == M && j == N){  // is already attach the export
		for(int i = 0; i < M + 2; i++){
			for(int j = 0; j < N + 2; j++){
				if(A[i][j] == 2){
					cout<<"2 ";
				}else if(A[i][j] == 1){  // the correct way
					cout <<"  ";
				}else {
					cout<<"0 ";
				}
			}
			cout << endl;
		}
		cout<<"--------------------"
	}
	if(A[i - 1][j] == 0){   // setting : 0 means allow to go
		visitMaze(A, i - 1, j);
	}
	if(A[i + 1][j] == 0){   // setting : 0 means allow to go
		visitMaze(A, i + 1, j);
	}
	if(A[i][j + 1] == 0){   // setting : 0 means allow to go
		visitMaze(A, i, j + 1);
	}
	if(A[i][j - 1] == 0){   // setting : 0 means allow to go
		visitMaze(A, i, j - 1);
	}
	A[i][j] = 0;  // Execute here means : cannot find way ; reset the status becauseof A[i][j] = 1; 
	return 0; 
}
