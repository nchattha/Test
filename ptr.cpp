#include<stdio.h>
#include<stdint.h>
#include<iostream>

using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	int *p1 = &a;
	int *p2 = &b;
	cout<<"P1: "<<p1<<endl;
	cout<<"P2: "<<p2<<endl;
	cout<<"P1: "<<(uintptr_t)p1<<endl;
	cout<<"P2: "<<(uintptr_t)p2<<endl;
	uintptr_t f = ((uintptr_t)p1^(uintptr_t)p2);
	cout<<"P1^P2: "<<f<<endl;
	cout<<"f^P2: "<<(void *)(f^(uintptr_t)p2)<<endl;


	return 0;

}
