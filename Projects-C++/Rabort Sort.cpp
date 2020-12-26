/*
最近，Dr.?Kong?新设计一个机器人Bill。这台机器人很聪明，会做许多事情。
惟独对自然数的理解与人类不一样,它是从右往左读数。
比如，它看到123时，会理解成321。让它比较23与15哪一个大，它说15大。
原因是它的大脑会以为是32与51在进行比较。再比如让它比较29与30，它说29大。
给定Bill两个自然数A和B，让它将?[A，B]?区间中的所有数按从小到大排序出来。你会认为它如何排序？
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
