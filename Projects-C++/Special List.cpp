/*
链接：https://ac.nowcoder.com/acm/contest/9752/B
来源：牛客网

牛牛现在有一个长度为len只包含小写字母‘a’-'z'的字符串x，他现在想要一个特殊的子序列，
这个子序列的长度为3*n（n为非负整数），子序列的第[1,n]个字母全部为‘a’，
子序列的[n+1,2*n]个字母全部为‘b’，子序列的[2*n+1,3*n]个字母全部为‘c’，
牛牛想知道最长的符合条件的独特子序列的长度是多少。
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
        for(int i = 0;i < len&&x[i] == 'a'; i++){ // 从 a 开始匹配  匹配到了 a 才开始 
            int a= 0;int b = 0; int c = 0; // 三指针
            int j = 0;
            for( ;i+j < len; j++ ){
                if(x[i+j] != 'a'){
                   break;
                }
            }
            a = j;    // 匹配到了a 的个数 
            for(; i+j < len; j++ ){
                if(x[i+j] != 'b'){
                    break;
                }
            }
            b = j - a;   // 匹配到了b 的个数  匹配不到就 0 
            for(; i+j < len; j++ ){
                if(x[i+j] != 'c'){
                    break;
                }
            }
            c = j -a- b;  // 匹配到了c 的个数 
            int curM = 0;
            if(a>=b && b <= c ){   // 但凡符合要求的 必须要 b的数量最少（可相等） 
                curM = b;
            }
            if(curM > Max){
                Max = curM;
            }
            i = i+j;  
        }
        return 3*Max;
}
