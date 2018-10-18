#include <cmath>
#include "calcprimes.h"

CalcPrimes::CalcPrimes(unsigned long upperLimit) : upperLimit(upperLimit)
{
    boolPrimes.assign(upperLimit + 1, true);
    boolPrimes[0] = boolPrimes[1] = false;
    for (unsigned long i = 2; i < sqrt(upperLimit); i++) {
        if (boolPrimes[i]) {
            int count = 0;
            for (unsigned long j = (i * i); j <= upperLimit; j = i * i + (count * i)) {
                boolPrimes[j] = false;
                count++;
            }
        }
    }
    for (unsigned long i = 0; i < boolPrimes.size(); i++) {
        if (boolPrimes[i]) {
            primes.push_back(i);
        }
    }
}

std::vector<unsigned long> CalcPrimes::getPrimes()
{
    return primes;
}

unsigned long CalcPrimes::primeCount()
{
    return primes.size();
}
