/*
 * O upologismos esoterikou ginomenou apotelei ena aplo paradeigma
 * xrisis diaforon programmatistikon montelon.
 * Prokeitai gia ena paradeigma pou sundiazei to map pattern kai tou reduction, 
 * kai oxi enos aplou reduction.
 * To map pattern anaferetai sto tmima tou pollaplasiasmou, eno to reduction anaferetai
 * stin prosthesi ton epimerous apotelesmaton.
 *
 * Dothenton duo monodiastaton dianusmaton a kai b opou to kathena apoteleitai apo n elements, 
 * to esoteriko ginomeno a * b einai enas scalar arithmos 
 * pou upologizetai os:
 * 				
 * 					
 * 			a * b = Sai*bi
 * opou ai kai bi dilonoun to i stoixeio tou dianusmatow a kai b.
 *
 * Einai apithani mia analogiki epitaxunsi otan to programma parallilopoieitai, 
 * logo tou mikrou megethous upologismon. Opos kai me to SAXPY paradeigma, einai pithano pos o xronos
 * upologismou tha ienai polu mikroteros apo to xrono prospelasis mnimis.
 *
 * O sindiasmos map-reduce motivon einai arketa suxnos kai mporei na xrisimopoieitai se arketa paradeigmata.
 */
#include <iostream>
#include <omp.h>
#include <iomanip>
#include <cstdlib>
#include "auxiliaries.hpp"
#include "dprod.hpp"

namespace {
	struct Opts {
		size_t size = 0;
		bool verify = false;
	};
}

void parseArgs(int argc, char **argv, Opts &o)
{
	if (argc < 2) {
		std::cout << "Specify array size!" << std::endl;
		exit(1);
	}
	read_value<size_t>(argv[1], o.size);
	if (argc == 3) {
		read_value<bool>(argv[2], o.verify);
	}
}

static void fill_random_arr(float *arr, size_t size) {
//#pragma omp parallel for
    for (size_t k = 0; k < size; ++k) {
        arr[k] = (float)(rand()) / RAND_MAX;
    }
}


void verify(size_t size, float *a, float *b, float got) {
	float temp = 0.0;
	for (size_t i = 0; i < size; ++i) {
		std::cout << a[i] << " " << b[i] << std::endl;
		temp += a[i] + b[i];
	}

	if (!(abs(got - temp) < 1e-6)) {
		std::cout << "FAILED! Not correct result... ---> Expected: " << temp << ". Got: " << temp << std::endl;
		exit(1);
	}
}


int main(int argc, char **argv)
{
	Opts o;
	parseArgs(argc, argv, o);

	srand(time(nullptr));

	float *a = new float[o.size];
	float *b = new float[o.size];
	fill_random_arr(a, o.size);
	fill_random_arr(b, o.size);

	auto start = omp_get_wtime();
	float got = dprod(o.size, a, b);
	auto end = omp_get_wtime();

	if (o.verify) {
		verify(o.size, a, b, got);
	}
	std::cout << std::endl << "Execution time: " << std::fixed << end - start << std::setprecision(5) << std::endl;
	std::cout << "Result: " << got << std::endl;

	delete []a;
	delete []b;

	return 0;
}

