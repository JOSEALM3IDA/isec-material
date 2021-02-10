#include "randomgen.h"

using namespace std;

double uDist01() {
    static default_random_engine e(time(0));        // gerador de numeros aleatorios (unsigned int)  
    static uniform_real_distribution<double> u(0.0, 1.0);

    return  u(e);
}