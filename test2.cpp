#include <iostream>
class Base
{
protected:
	int * data;
public:
	Base();
	virtual ~Base()=0; // Pure virtual destructor

	void set_data(int n);
};

Base::Base() {
	data = new int;
	*data = 5;
}

Base::~Base()
{
    std::cout << "Pure virtual destructor is called\n";
    delete data;
}

void Base::set_data(int n) {
	*data = n;
}

class Derived : public Base
{
public:

	~Derived() {
		std::cout << "~Derived() is executed\n";
	}

	void data_out() {
		std::cout << *data << "\n";
	}
};

int main()
{
    Base *b = new Derived();
    Derived * d = dynamic_cast<Derived *>(b);
    d->data_out();
    d->set_data(12);
    d->data_out();
    delete b;
    return 0;
}
