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

template<typename T, typename R, typename C, typename S>
void openmp_scan(size_t n, T initial, size_t tilesize, R reduce, C combine, S scan) {
	if (n > 0) {
		// Set t to the number of tiles that might be used, at most one tile
		// per thread with not ile smaller than the requested tilesize
		size_t = t = std::min(size_t(omp_get_max_threads()), (n-1)/tilesize + 1);
	}
}


int main(int argc, char **argv)
{
	
//	integral();
	return 0;
}
