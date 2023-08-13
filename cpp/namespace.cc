#include <iostream>

namespace math
{

double square(double number) { return number * number; }

}

using namespace math;
using namespace std;

int main()
{
    double n;

    n = square(3);
    cout << "number " << n << endl;

    return 0;
}

