#include <iostream>
using namespace std;
#define MAXN 50
int girl[MAXN];
/*
bool find(int x){
	int i,j;
	for (j=1;j<=m;j++){    //ɨ��ÿ������
		if (line[x][j]==true && used[j]==false)      
			//������������һ�û�б�ǹ�(�����ǵ���˼����β�������ͼ�ı�������ӵĹ������⣬����û�гɹ������ԾͲ���Ϲ�ѹ����ˣ�
		{
			used[j]=1;
			if (girl[j]==0 || find(girl[j])) { 
				//���������������ڳ���λ����������ʹ�õݹ�
				girl[j]=x;
				return true;
			}
		}
	}
	return false;
}
*/

//����ע�͵Ĵ����������ҳ��  http://blog.csdn.net/dark_scope/article/details/8880547  ���Ǵ���д��û�м���� 
//������д��  ��д��
/*
bool huishuo(int x){
	used[i] = 1;
	int boy_de_girl_num = 10;
	for(int i=0;i<boy_de_girl_num;i++){
		if(link[x][i] == true && used[i]==false){
			
			if(girl[i] == 0||huishuo(girl[x])){
				girl[i] = x;
				return true;
			}
		}
	}
	return false;
}

bool myfind(int x){//x �����к�
	int girl_num = 10;
	int m = girl_num;//����Ӧ����ÿ�������п��ܵ�girl
	for(int i=0;i<m;i++){
		if(girl[i] == 0){//����û�� �Ǿ�ֱ��ռ��
			girl[i] = x;
		}else{
			if(huishuo(x))return true;
		}
	}
	return false;

}
*/
 int main(){

	 return 0;
 }