#include <iostream>
#include <sstream>
#include <stdexcept>

#include "throws.hpp"

void myFunc() {

	std::cout << "\nthrowing now" << std::endl;
	throws << "this is" << " " << "error\n" << "with 2 lines(but line feeds are trimmed)" << std::endl;
	std::cout << "\ndid throw (you should not be seeing this line, because we have just been thrown..)" << std::endl;
}

int main(int argc, char **argv) {

	try {
		myFunc();
	} catch ( const std::runtime_error& e ) {

		std::cout << "function myFunc did throw with a reason: '" << e.what() << "'" << std::endl;

	}

	std::cout << "\nNow throwing without trying..." << std::endl;
	throws << "error without trying" << std::endl;

	return 0;

}
