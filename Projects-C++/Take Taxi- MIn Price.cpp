// ��������
// desc: ���⳵�𲽼� 4���� 10 Ԫ��4 - 8 ����Ĳ��� 2Ԫ/ ���8�������ϵĲ��֣�2.4Ԫ/����
// ����С���ã������Զ�λ��ˣ��� 16���� �������Σ���С����36Ԫ�� 
//  F[X] = Min( F[x-i] + g(i) )   F[x]: X�������С����  i: X���������һ�λ��˵Ĺ����� 
#include<iostream>
using namespace std;
int main(){
	double g(int x);  // ����۸� 
	int M; // ����� 
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
double g(int x){  // ����۸� 
	if(x == 0)
		return 0;
	else if(x <= 4)
		return 10.0;
	else if(x <= 8)
		return (x - 4)*2 + 10.0;
	else 
		return (x -8)*2.4 + 18.0;
}
