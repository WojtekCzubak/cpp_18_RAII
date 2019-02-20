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
       // SimpleSmartPointerToC ssp {new C()};
       // auto up = std::make_unique<C>(); // up to unique pointer //to w C++14
        auto up2 = std::unique_ptr<C>(new C()); //to w C++11
    }
        // w C++14 std::make_unique<C>()
    return 0;
}
