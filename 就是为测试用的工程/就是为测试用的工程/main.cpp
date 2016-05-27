#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int maxn = 105;
int equ, var; // ��equ�����̣�var����Ԫ������������Ϊequ, �ֱ�Ϊ0��equ - 1������Ϊvar + 1���ֱ�Ϊ0��var.
int a[maxn][maxn];
int x[maxn]; // �⼯.
bool free_x[maxn]; // �ж��Ƿ��ǲ�ȷ���ı�Ԫ.
int free_num;
void Debug(void)
{
	int i, j;
	for (i = 0; i < equ; i++)
	{
		for (j = 0; j < var + 1; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
inline int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}
inline int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
// ��˹��Ԫ���ⷽ����(Gauss-Jordan elimination).(-2��ʾ�и������⣬���������⣬-1��ʾ�޽⣬0��ʾΨһ�⣬����0��ʾ����⣬���������ɱ�Ԫ�ĸ���)
int Gauss(){
	int col = 0;
	for(int hang = 0;hang<equ&&col<var;col++,hang++){
		int max_hang = hang;
		for(int i=hang+1;i<equ;i++){
			if(abs(a[i][col])>abs(a[max_hang][col]))max_hang = i;
		}

		if(a[max_hang][col]==0){
			hang--;
			continue;
		}
		if(max_hang!=hang)
		for(int j = col;j<var+1;j++){
			swap(a[hang][j],a[max_hang][j]);
		}

		for(int i = hang+1;i<equ;i++){
			if(a[i][col]!=0){
				int lcm_temp = lcm(a[hang][col],a[i][col]);
				int ta = lcm_temp/a[hang][col];
				int tb = lcm_temp/a[i][col];
				if(a[hang][col]*a[i][col]<0)tb = -tb;
				for(int j = col;j<var+1;j++){
					a[i][j] = tb*a[i][j] - ta*a[hang][j] ;
				}
			}
		}

		Debug();

	}
	return 1;


}

int aa[]={5,4,3,2,1};


class A{
public:
	void print(long a){
		printf("long");
	}
	void print(double a){
		printf("double");
	}

};

int main(void)
{
	/*for(int i=0;i<5;i++){
		int temp = i;
		for(int j=i;j<5;j++){
			if(aa[temp]>aa[j])temp = j;
		}
		swap(aa[temp],aa[i]);
	}
	for(int k=0;k<5;k++){
		cout<<aa[k]<<endl;

	}*/

	A a = A();
	a.print(2);

	while(1);

	return 0;
}