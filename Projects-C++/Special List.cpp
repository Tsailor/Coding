/*
���ӣ�https://ac.nowcoder.com/acm/contest/9752/B
��Դ��ţ����

ţţ������һ������Ϊlenֻ����Сд��ĸ��a��-'z'���ַ���x����������Ҫһ������������У�
��������еĳ���Ϊ3*n��nΪ�Ǹ��������������еĵ�[1,n]����ĸȫ��Ϊ��a����
�����е�[n+1,2*n]����ĸȫ��Ϊ��b���������е�[2*n+1,3*n]����ĸȫ��Ϊ��c����
ţţ��֪����ķ��������Ķ��������еĳ����Ƕ��١�
*/

#include<iostream>
//#include<string.h>
using namespace std;
int main(){
	int Maximumlength(string x);
	string x;
	cin>>x;
//	int res = Maximumlength(x);
	cout<<Maximumlength(x)<<endl;
	
	return 0;
} 
int Maximumlength(string x) {
        // write code here
        int Max = 0;
        int len = x.size();
        for(int i = 0;i < len&&x[i] == 'a'; i++){ // �� a ��ʼƥ��  ƥ�䵽�� a �ſ�ʼ 
            int a= 0;int b = 0; int c = 0; // ��ָ��
            int j = 0;
            for( ;i+j < len; j++ ){
                if(x[i+j] != 'a'){
                   break;
                }
            }
            a = j;    // ƥ�䵽��a �ĸ��� 
            for(; i+j < len; j++ ){
                if(x[i+j] != 'b'){
                    break;
                }
            }
            b = j - a;   // ƥ�䵽��b �ĸ���  ƥ�䲻���� 0 
            for(; i+j < len; j++ ){
                if(x[i+j] != 'c'){
                    break;
                }
            }
            c = j -a- b;  // ƥ�䵽��c �ĸ��� 
            int curM = 0;
            if(a>=b && b <= c ){   // ��������Ҫ��� ����Ҫ b���������٣�����ȣ� 
                curM = b;
            }
            if(curM > Max){
                Max = curM;
            }
            i = i+j;  
        }
        return 3*Max;
}
