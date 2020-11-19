// http://acm.hdu.edu.cn/showproblem.php?pid=1034
#include<iostream>
using namespace std;
int main (){	
	int N;   // 学生的人数
	int *arr;
	bool isSameCandy(int* arr,int N);
	while(cin>>N && N != 0){ // N==0 游戏结束 
		arr = new int [N];
		for(int i = 0; i < N; i++){
			cin>>arr[i];
		}
		int count = 0; // 计数 
		int candyNumbers = 0; // 最终的糖果数量 
		while( !isSameCandy(arr,N) ){
			int preNums = arr[0] / 2; // 上一个的一半  
			int curNums; // 当前的一半 
			for(int i = 1; i < N; i++){
				curNums = arr[i] /2 ;
				arr[i] = arr[i] / 2 + preNums;
				preNums = curNums;
			}
			arr[0] = arr[0]/2 + preNums;
			for(int i = 0; i < N; i++){
				if(arr[i]&1){
					arr[i]++;
				}
			}
			count++;
		}
		candyNumbers = arr[0];
		cout<<count<<" "<<candyNumbers<<endl;
	}
	delete []arr;
	return 0; 
}
bool isSameCandy(int* arr,int N){	
	int i;
	for(i = 0 ; i < N-1; i++){
		if(arr[i] != arr[i+1]){
				break;
		}
	}
	if(N-1 == i){
		return true;
	}
	return false;
}
