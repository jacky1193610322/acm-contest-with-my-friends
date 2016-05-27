#include <iostream>
using namespace std;
#define MAXN 50
int girl[MAXN];
/*
bool find(int x){
	int i,j;
	for (j=1;j<=m;j++){    //扫描每个妹子
		if (line[x][j]==true && used[j]==false)      
			//如果有暧昧并且还没有标记过(这里标记的意思是这次查找曾试图改变过该妹子的归属问题，但是没有成功，所以就不用瞎费工夫了）
		{
			used[j]=1;
			if (girl[j]==0 || find(girl[j])) { 
				//名花无主或者能腾出个位置来，这里使用递归
				girl[j]=x;
				return true;
			}
		}
	}
	return false;
}
*/

//上面注释的代码是这个网页的  http://blog.csdn.net/dark_scope/article/details/8880547  但是代码写得没有简洁性 
//下面我写的  改写版
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

bool myfind(int x){//x 代表男孩
	int girl_num = 10;
	int m = girl_num;//具体应该是每个男生有可能的girl
	for(int i=0;i<m;i++){
		if(girl[i] == 0){//代表没有 那就直接占有
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