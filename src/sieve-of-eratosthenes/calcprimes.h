#ifndef CALCPRIMES_CALCPRIMES_H
#define CALCPRIMES_CALCPRIMES_H

#include <vector>

class CalcPrimes {
public:
    explicit CalcPrimes(unsigned long);
    std::vector<unsigned long> getPrimes();
    unsigned long primeCount();

private:
    unsigned long upperLimit;
    std::vector<bool> boolPrimes; // Array of boolean values where true indices are prime and false are not
    std::vector<unsigned long> primes;
};

#endif //CALCPRIMES_CALCPRIMES_H
