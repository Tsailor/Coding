// BackTracking-Maze 
#include<iostream>
using namespace std;
int main(){
	int M,N; // M:row, N:col
	cin>>M>>N;
	int** Maze = new int* [M+2]; // Maze cell
	for(int i = 0; i < M + 2; i++){
		Maze[i] = new int [N+2];
	} 
	for(int i = 1;i < M + 1 ; i++ ){
		for(int j = 1; j < N + 1; j++){
			cin>>Maze[i][j];
		}
	}
	for(int i = 0; i < M + 2; i++){
		for(int j = 0; j < N + 2; j++){
		//	Maze[i][j]=0; 
			if(i == 0 || i == M + 1){
				Maze[i][j] = 2; // 2 means wall, cannot go through
			}
			if(j == 0 || j == N + 1){
				Maze[i][j] = 2;
			}
			
		}
	}

	for(int i = 0; i < M + 2; i++ ){
		for(int j = 0; j < N + 2; j++){
			cout<<Maze[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0; i < M + 2; i++){
		delete [] Maze[i];
	}
	delete [] Maze;
	return 0;
}
