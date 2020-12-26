/*
�����Dr.?Kong?�����һ��������Bill����̨�����˺ܴ���������������顣
Ω������Ȼ������������಻һ��,���Ǵ������������
���磬������123ʱ��������321�������Ƚ�23��15��һ������˵15��
ԭ�������Ĵ��Ի���Ϊ��32��51�ڽ��бȽϡ��ٱ��������Ƚ�29��30����˵29��
����Bill������Ȼ��A��B��������?[A��B]?�����е�����������С������������������Ϊ���������
http://acm.zzuli.edu.cn/problem.php?id=1473 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int toggle(int a){
	int res = 0;
	while(a != 0){
		int s = a % 10;
		res = res * 10 + s;
		a = a / 10; 
	}
	return res;
} 
bool compare(int a,int b){   
  return toggle(a) < toggle(b);
}
int main()
{
  int N;
  cin>>N;
  int* P;
  for(int i = 0; i < N; i++){
  	int A,B;
	cin >> A >> B;
	int len = B - A + 1;
	P = new int[len];
	for(int j = 0; j < len; j++){
		P[j] = A+j;
	};
	sort(P,P + len, compare);
  	for(int j = 0;j < len; j++){
  	 	cout << P[j] <<' ';
	}
	cout << endl;
  }
  delete []P;
  return 0;
}
