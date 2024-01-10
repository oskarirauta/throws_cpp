#pragma once

#include <sstream>
#include <string>

class THROWS_T {

	private:
		void append(const std::string& s) const;

	public:

		std::ostream& endl(std::ostream& stream);
		using endl_type = std::ostream& (std::ostream&);

		std::string flush() const;

		template<typename T>
		const THROWS_T& operator <<(const T& in) const {
			std::stringstream s;
			s << in;
			this -> append(s.str());
			return *this;
		}
};

extern THROWS_T throws;

[[noreturn]]
const THROWS_T& operator <<(const THROWS_T& os, const THROWS_T::endl_type endl);
