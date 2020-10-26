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
#include "auxiliaries.hpp"
#include "dprod.hpp"

namespace {
	struct Opts {
		size_t size = 0;
	};
}

void parseArgs(int argc, char **argv, Opts &o)
{
	if (argc != 2) {
		std::cout << "Specify array size!" << std::endl;
		exit(1);
	}
	read_value<size_t>(argv[1], o.size);
}

static void fill_random_arr(float *arr, size_t size) {
//#pragma omp parallel for
    for (size_t k = 0; k < size; ++k) {
        arr[k] = (float)(rand()) / RAND_MAX;
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
	dprod(o.size, a, b);
	auto end = omp_get_wtime();

	std::cout << "Execution time: " << std::fixed << end - start << std::setprecision(5);
	std::cout << " src " << std::endl;

	delete []a;
	delete []b;

	return 0;
}

