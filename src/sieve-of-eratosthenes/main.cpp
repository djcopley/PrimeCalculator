#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>

#include "calcprimes.h"

using namespace std;

int main(int argc, char **argv)
{
    auto start = time(nullptr);
    auto primes = CalcPrimes(1000000);
    auto finish = difftime(time(nullptr), start);

    for (auto b : primes.getPrimes()) {
        cout << b << endl;
    }

    std::cout << "\n" << primes.primeCount() << " primes found" << " in " << finish << " seconds." << std::endl;
}
