

template<typename Y, typename X>
Y generic_f(X x) {
	return Y(abs(sqrt(x) * sin(X(0.12) * x + x*x)));
}

float f(float x) {
	return generic_f<float, float>(x);
}

/*
a: starting position of sampling
b: end position of sampling
size_t : number of samples to take
Y: destination for table samples
f = function prameters
*/
template<typename X, typename Y, typename F>
void integral_prepare(X a, Y b, size_t n, Y *table, F f) {
	// Handle empty request
	if (n == 0) return;

	//Compute sample spacing
	const X dx = (b - a)/X(n-1); // cast

	//Stoer scaled running sum of sample points in table[0:n]
	Y sum = Y(0);
	for (size_t i = 0; i < n; ++i) {
		sum += f(a + dx * i); // f: x\ maps to Y
		table[i] = sum * dx;
	}
}
