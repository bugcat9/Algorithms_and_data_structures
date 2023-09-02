#include "factor.h"

int Gcd(int a, int b)
{
    return b ? Gcd(b, a % b) : a;
}
