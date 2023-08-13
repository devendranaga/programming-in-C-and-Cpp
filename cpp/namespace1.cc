#include <iostream>

namespace math
{

double square(double number) { return number * number; }

}

int main()
{
    double n;

    n = math::square(3);
    std::cout << "number " << n << std::endl;

    return 0;
}

