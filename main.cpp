#include<iostream>
#include<fparser.hh>
#include<string>
#include<cmath>

int main()
{
	FunctionParser fparser;
	std::string function;
	double start_point = 0, epsilon = 0.00001, derivative_accuracy = 0.01;

	std::cin >> function;
	fparser.Parse("function", "x");

	double x = start_point;
	while (fabs(fparser.Eval(&x)) > epsilon) {
		double deltax1 = x - derivative_accuracy;
		double deltax2 = x + derivative_accuracy;
		double derivative = (fparser.Eval(&deltax1) - fparser.Eval(&deltax2)) / (2 * derivative_accuracy);
		x = x - fparser.Eval(&x) / derivative;
	}
	std::cout << x;
	return 0;
}