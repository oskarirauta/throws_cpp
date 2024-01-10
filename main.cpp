#include <iostream>
#include <sstream>
#include <stdexcept>

#include "throws.hpp"

void myFunc() {

	std::cout << "throwing now\n" << std::endl;

	throws << "   this is" << " error\n" << "  second line  " << std::endl;

	std::cout << "\ndid throw" << std::endl;

}

int main(int argc, char **argv) {

	try {
		myFunc();
	} catch ( const std::runtime_error& e ) {

		std::cout << "got throw.." << std::endl;
		std::cout << "function myFunc throw'd: '" << e.what() << "'" << std::endl;

	}

	throws << "hello" << std::endl;

	return 0;

}
