#include <iostream>
#include <math.h>

using namespace std;

int main () {
	int n;
	cout << "Type in n: ";
	cin >> n;

	double* c = new double[n+1];
	c[0] = 1;
	for (int i = 1; i < n+1; i++) {
		c[i] = c[i-1] / i * (n - i + 1); 
	}

	double successProbability;
	cout << "Type in the success probability: ";
	cin >> successProbability;
	
	// 每个i对应的概率 
	double* sp = new double[n+1];
	for (int i = 0; i < n + 1; i++) {
		sp[i] = c[i] * pow(successProbability, i) * pow(1 - successProbability, n - i); 
	}

	//所求的加权、不加权部分和的起止[begin, end]
	int begin, end = 0;
	cout << "To get the sum,the begin index: ";
	cin >> begin;
	cout << "To get the sum,the end index: ";
	cin >> end;

	// 无权部分和
	double sum = 0;
	for (int i = begin; i < end + 1; i++) {
		sum += sp[i];
	}
	cout << "[begin, end] sum of probability is: " << sum << endl;

	// 加权部分和
	double sumWithWeight = 0;
	for (int i = begin; i < end + 1; i++) {
		sumWithWeight += sp[i] * i;
	}
	cout << "[begin, end] sum of probability with weight is: " << sumWithWeight << endl;

	// 数学期望
	double expectedValue = 0;
	for (int i = 0; i < n + 1; i++) {
		expectedValue += sp[i] * i;
	}
	cout << "[0, n] sum expected value is: " << expectedValue << endl;
	
	// 方差
	double variance = 0;
	for (int i = 0; i < n + 1; i++) {
		variance +=  (i - expectedValue) * (i - expectedValue) * sp[i];
	}
	cout << "[0, n] the variance is: " << variance << endl;
	cout << "[0, n] the standard deviation is: " << sqrt(variance) << endl;

	delete[] c;
	delete[] sp;
	return 0;
}
