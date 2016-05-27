#include <iostream>
using namespace std;
#define N  1000
#define Base 1000
class BigNum
{
public:
	int len;
	int data[N];
	BigNum():len(0){

	}
	BigNum(int n):len(0){

		while(n>0){
			data[len++] = n%Base;
			n = n/Base;
		}
	}

	BigNum(char s[]):len(0){
		int i,j=1;
		data[len] = 0;
		for(i=strlen(s)-1;i>=0;i--){
			data[len] += j*(s[i]-'0');
			j*=10;
			if(j>=Base){
				j = 1;
				data[++len] = 0;
			}
		}
		if(data[len]>0)len++;
		
	}

	void tostring(){
		cout<<data[len-1];
		for(int i=len-2;i>=0;i--){
			printf("%03d",data[i]);
		}
		cout<<endl;
	}

	
	
protected:
private:
};

BigNum operator +(BigNum& add1,BigNum& add2){
	int i,carry = 0;
	BigNum result;
	for( i=0;i<add1.len||i<add2.len||carry>0;i++){
		if(i<add1.len)carry += add1.data[i];
		if(i<add2.len)carry += add2.data[i];
		result.data[i] = carry%Base;
		carry /= Base;
	}
	result.len = i;
	return result;
}

int cmp(BigNum& add1,BigNum& add2){
	if(add1.len!=add2.len) return add1.len>add2.len?1:-1;
	int i = add1.len-1;
	for(;i>=0&&add1.data[i]==add2.data[i];i--);
	if(i<0)return 0;
	else return add1.data[i]>add2.data[i]?1:-1;

}
BigNum operator - (BigNum& add1,BigNum& add2){
	int i,carry = 0;
	BigNum result;
	for(i=0;i<add1.len;i++){
		result.data[i]= add1.data[i] - carry;
		if(i<add2.len) result.data[i]-=add2.data[i];
		if(result.data[i]<0){
			carry = 1;
			result.data[i]+=Base;
		}
	}
	result.len = add1.len;
	while(result.len>0&&result.data[result.len-1]==0)result.len--;
	return result;
}

BigNum operator *(BigNum& mult1, BigNum& mult2){
	int i,j,carry = 0;
	BigNum res;
	for(i = 0;i<mult1.len;i++){
		carry = 0;
		for(j = 0;j<mult2.len||carry>0;j++){
			
			if(j<mult2.len) carry+= mult1.data[i]*mult2.data[j];
			if(i+j<res.len) carry+= res.data[i+j];
			if(i+j>=res.len) res.data[res.len++] = carry%Base;
			else res.data[i+j] = carry%Base;
			carry = carry/Base;
		}
	}
	cout<<"res"<<res.len<<endl;
	return res;
}
BigNum operator *(BigNum& mult1, int mult2){
	int i,j,carry = 0;
	BigNum res;
	if(mult2==0)return res; //如果没有这句  那么  会执行下面的语句  造成len++  比如测试123456789 乘以0 就会出错 
							//那么在进行比较的时候就会出错 而除法要用到比较  而比较是先比较长度的所以不能少了这句
							//比如123456 /1234  就会出错
	for(i = 0;i<mult1.len||carry>0;i++){
		if(i<mult1.len)carry = mult1.data[i]*mult2+carry;
		res.data[res.len++] = carry%Base;
		carry/=Base;
	}
	return res;
}
BigNum operator /(BigNum& mult1, BigNum& mult2){
	BigNum res,carry(0);
	int div = 0,i=mult1.len-1;
	for(;i>=0;i--){
		div = div*Base+mult1.data[i];
		carry = carry*Base + BigNum(mult1.data[i]);
		int mid = 0,left =0,right = Base-1;
		while(left<=right){
			mid = (left+right)/2;
			int r  = cmp(mult2*mid,carry);
			if(r>0){
				right = mid -1;
			}else{
				left = mid+1;
			}
		}	
		res.data[i] = right;
		carry = carry - mult2*(right);
	}
	res.len = mult1.len;
	while(res.len>0&&res.data[res.len-1]==0)res.len--;
	return res;
}

BigNum operator %(BigNum& mult1, BigNum& mult2){
	BigNum res,carry(0);
	int div = 0,i=mult1.len-1;

	for(;i>=0;i--){
		div = div*Base+mult1.data[i];
		carry = carry*Base + BigNum(mult1.data[i]);
		int mid = 0,left =0,right = Base-1;
		while(left<=right){
			mid = (left+right+1)/2;
			int r  = cmp(mult2*mid,carry);
			if(r == 0){
				//mid = mid+1;
				mid = mid;
				break;
			}
			else if(r>0){
				right = mid -1;
			}else{
				left = mid+1;
			}
		}
		int r =cmp(mult2*mid,carry);
		if(r>0)mid=mid--;
		res.data[i] = mid;
		carry = carry - mult2*(mid);
	}
	carry.len = mult2.len;
	while(carry.len>0&&carry.data[carry.len-1]==0)carry.len--;
	return carry;
}

int main(){
	char s[1000],d[1000];
	while(cin>>s>>d){
		BigNum big(s);
		BigNum big2(d);
		BigNum res = big/big2;
		res.tostring();
	}
	while(1);
	return 0;
}