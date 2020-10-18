#include <iostream> 
using namespace std; 
   
class Empty 
{}; 
   
class Derived1 : public Empty 
{}; 
   
class Derived2 : virtual public Empty 
{}; 
   
class Derived3 : public Empty 
{     
    char c; 
}; 
   
class Derived4 : virtual public Empty 
{ 
    char c; 
}; 
   
class Dummy 
{ 
    char c; 
}; 

int addI(int a,int b)
{
	return a+b;
}

struct B {
    int n;
    B(int x) : n(x) {}
};
struct X : virtual B { X() : B(1) {} };
struct Y : virtual B { Y() : B(2) {} };
struct AA : X, Y     { AA() : B(3), X(), Y() {} };
 

int main() 
{ 
    cout << "sizeof(Empty) " << sizeof(Empty) << endl; 
    cout << "sizeof(Derived1) " << sizeof(Derived1) << endl; 
    cout << "sizeof(Derived2) " << sizeof(Derived2) << endl; 
    cout << "sizeof(Derived3) " << sizeof(Derived3) << endl; 
    cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;     
    cout << "sizeof(Dummy) " << sizeof(Dummy) << endl; 
  
   Derived2 obj; 
    int (*funcPtr)(int,int) = &addI;
    cout<< funcPtr(1,2)<<endl; 

    AA a; // a.n == 3
    cout<<"N: "<<a.n<<endl;
    // the default constructor of X calls the constructor of B
    X x; //
    cout<<"N: "<<x.n<<endl;

	 return 0; 
}
