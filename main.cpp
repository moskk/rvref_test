#include <iostream>
#include <memory>
using namespace std;

struct rref
{
    rref():p(new int)
    {
        *p = 1;
    }

    rref(const rref& other):rref()
    {
        *p = *other.p;
    }

    rref(rref&& other)
    {
        std::swap(p, other.p);
    }

    ~rref()
    {
        delete p;
    }

    int* p = nullptr;
};

rref&& getrref()
{
    rref ref;
    return std::move(ref);
}

int main()
{
    rref rr(getrref());
    std::cout << *rr.p << std::endl;
    return 0;
}
