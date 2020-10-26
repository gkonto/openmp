#include <iostream>
#include <cmath>
#include <omp.h>
#include <sstream>
#include "integ.hpp"
#include "auxiliaries.hpp"

/*
Description of the problem
Dotheisas mias sinartisis f me oria oloklirosis [a, b],
	  prospathoume na na upologisoume apo prin ena pinaka pou tha epitrepei 
	  to grigoro upologismo tou olokliromatos tis f se ena mikrotero tmima 
	  tou [a, b]. Esto oti Dx = (b-a)/(n-1). O pinakas diatrexei to athroisma 
	  ton upotmimaton tis f.
	  		
	  		tablei = DxSf(a + iDx);
	
	To olokliroma tis f se ena tmima [c, d] mporei na upologistei os:
			
			des selida 170
	opou to interp(x) einai i grammiki paremvoli tou pinaka.
*/

namespace {
    struct Opts {
        long num_steps = 0;
    };
}

static void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify number of steps" << std::endl;
        exit(1);
    }

    read_value<long>(argv[1], o.num_steps);
}

int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);
    auto seconds = omp_get_wtime();
    double p = pi(o.num_steps);
    std::cout << "Elapsed Time: " << omp_get_wtime() - seconds << std::endl;
    std::cout << "pi Value: " << p << std::endl;
    return 0;
}
