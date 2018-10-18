#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <time.h>

#include "calcprimes.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Program requires one positional arguments:\n"
                        "\t(required) 0: range: upper limit\n"
			"\t(optional) 1: print the primes to the screen (type yes to enable)\n");
        return -1;
    }

    // Yes I am aware of the proper ways to parse user input. I'm lazy.
    unsigned long upperLimit = strtoul(argv[1], nullptr, 10);
    bool displayPrimes = false;

    if (argc > 2)
	    displayPrimes = strcmp(argv[2], "yes") == 0;

    auto start = time(nullptr);
    auto primes = CalcPrimes(upperLimit);
    auto finish = difftime(time(nullptr), start);
    
    if (displayPrimes) {
        for (auto b : primes.getPrimes()) {
            cout << b << endl;
        }
    }

    std::cout << primes.primeCount() << " primes found between 0 and " << upperLimit << " in " << finish << " seconds."
	      << std::endl;
}
