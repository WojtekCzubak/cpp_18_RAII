#include <iostream>
// ponizszy kod przedstawia realizacje idiomu RAII !!!
using namespace std;

class C
{
  public:
    C(){cout << "C::C()" << endl;}
    ~C(){cout << "~C::C()" << endl;}
};

class SimpleSmartPointerToC
{
public:
    SimpleSmartPointerToC(C *p) : p_{p} {}
    ~SimpleSmartPointerToC() {if (p_ != nullptr) delete p_;}
private:
    C *p_ = nullptr;
};


int main()
{

    C* p1 = new C {};
    delete p1;

    {
        C* p2 = new C{};
    }

    {
        SimpleSmartPointerToC ssp {new C()};
    }

    return 0;
}
