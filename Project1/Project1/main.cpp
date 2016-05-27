#include<iostream>
using namespace std;

class A{
public:
	A(){
		//fun();
	}
	virtual ~A(){
		fun();
	}

	void f(){
		fun();
	}
	virtual void fun(){
		
	}
};

class B:A{
public:
	B():A(){
		//fun();	
	}
	virtual void fun(){
		cout<<"B"<<endl;
	}
	virtual ~B(){
		fun();
	}
};

int main(){
	
	B b;
	b.f();
	return 0;
}