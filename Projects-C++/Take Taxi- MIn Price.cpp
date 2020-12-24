// 坐车问题
// desc: 出租车起步价 4公里 10 元。4 - 8 公里的部分 2元/ 公里。8公里以上的部分，2.4元/公里
// 求最小费用？（可以多次换乘，如 16公里 换乘两次，最小费用36元） 
//  F[X] = Min( F[x-i] + g(i) )   F[x]: X公里的最小费用  i: X公里内最后一次换乘的公里数 
#include<iostream>
using namespace std;
int main(){
	double g(int x);  // 计算价格 
	int M; // 总里程 
	double* F;
	while(cin >> M && M != 0){
		F = new double[M+1];
		F[0] = 0;
		for(int i = 1; i <= M; i++){
			double min = 999999999;
			for(int j = 1; j <= i; j++){
				double curP = F[i - j] + g(j);
				if(min > curP){
					min = curP;
				}
			}
			F[i] = min;
		}
		cout<<F[M]<<endl;
	} 
	delete F;
} 
double g(int x){  // 计算价格 
	if(x == 0)
		return 0;
	else if(x <= 4)
		return 10.0;
	else if(x <= 8)
		return (x - 4)*2 + 10.0;
	else 
		return (x -8)*2.4 + 18.0;
}
