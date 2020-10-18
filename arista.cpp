#include<iostream>


using namespace std;

int a(unsigned int i){
	int c= 0;
	while(i){
		if ( i & 1 ) {c++;}
		i >>= 1;
	}
	return c;
}

int b(unsigned int i ){
	static unsigned char n[]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
	int c= 0 ;
	while(i){
		c=n[i&15];
		i>>= 4;
	}
	return c;
}

int main()
{
	cout<<a(15)<<endl;
	cout<<b(15)<<endl;


	return 0;
}
