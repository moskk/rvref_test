#include <iostream>
#include <memory>
using namespace std;

struct rref
{
    rref():p(new int[10]){}

    rref(rref& other):rref()
    {
        copy(p, p + 10, other.p);
    }

    rref(rref&& other)
        : p(other.p)
    {
        other.p = nullptr;
        p[5] = 5;
    }

    ~rref()
    {
        delete []p;
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
    rref&& rr(getrref());
    std::cout << rr.p[5] << std::endl;
    return 0;
}
