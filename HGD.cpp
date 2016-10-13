#include <iostream>
#include <math.h>

using namespace std;

// Combination number
double cn(int x, int n) {
	double* c = new double[n+1];
	c[0] = 1.0;
	for (int i = 1; i < n+1; i++) {
		c[i] = c[i-1] / i * (n - i + 1); 
	}

	double out = c[x];
	delete[] c;
	return out;
}

int main() {
	cout << "Hypergrometric Distribution Computer " << endl;
	cout << "enter x, n, M, N:" << endl;
	int x = 0, n = 0, M = 0, N = 0;
	cin >> x >>  n >>  M >> N;
	// cout << x << ' ' << n << ' ' << M << ' ' << N;
	cout << "h(x;n, M, N) == " << (cn(x, M) * cn(n-x, N -M) / cn(n, N));
	return 0;
}
