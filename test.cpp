#include <iostream>
using namespace std;

template <typename ClassType, typename Result, typename Context>
class Functor
{
	typedef Result (ClassType::*FunctionType)(Context*);
	ClassType* obj;
	FunctionType fn;
public:
	Functor(ClassType& object, FunctionType method): obj(&object), fn(method) {}

	Result Invoke(Context * context)
	{
		return (*obj.*fn)(context);
	}
};

template <typename ClassType, typename Result>
class A
{
	typedef Result (ClassType::*FunctionType)(A*);
	Functor<ClassType, Result, A> * myFunc;
public:
	A(ClassType& object, FunctionType method) {
		myFunc = new Functor<ClassType, Result, A>(object, method);
	}
	~A() {
		delete myFunc;
	}
	void runFunction() {
		myFunc->Invoke(this);
	}
	void printMessage() {
		std::cout << "Worked!\n";
	}
};

class B
{
	A<B, void> * myObj;
	int value;
public:
	B(int v) {
		value = v;
		myObj = new A<B, void>(*this, &B::getValue);
	}
	~B() {
		delete myObj;
	}
	void run() {
		myObj->runFunction();
	}
	void getValue(A<B, void> * instance) {
		cout << value;
		instance->printMessage();
	}
};


int main()
{
	B b(2);
	b.run();
}
