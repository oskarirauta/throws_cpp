#include <algorithm>
#include "throws.hpp"

THROWS_T throws;
static std::string throw_desc;

static std::string whitespace = " \t\n\r\f\v";

std::string trim_ws(const std::string& s) {

	std::string _s(s);

	_s.erase(0, _s.find_first_not_of(whitespace));
	_s.erase(_s.find_last_not_of(whitespace) + 1);
	return _s;
}

std::ostream& THROWS_T::endl(std::ostream& stream) {
                        stream << "\x1B\n";
                        return stream;
}

void THROWS_T::append(const std::string& s) const {
	throw_desc += s;
}


#if __cplusplus <= 201803L
template <class charT, class traits, class A, class Predicate>
void erase_if(std::basic_string<charT, traits, A>& c, Predicate pred) {
    c.erase(remove_if(c.begin(), c.end(), pred), c.end());
}
#endif

std::string THROWS_T::flush() const {

	std::string s = throw_desc;
	throw_desc = "";

	if ( !s.empty() && s.back() == '\n' )
		s.pop_back();

	#if __cplusplus > 201803L
	std::erase_if(s, [](char ch) { return std::string("\r\v").find(ch) != std::string::npos; });
	#else
	erase_if(s, [](char ch) { return std::string("\r\v").find(ch) != std::string::npos; });
	#endif
	std::replace_if(s.begin(), s.end(),
		[](char ch) { return std::string("\n\t").find(ch) != std::string::npos; }, ' ');

	return s;
}

[[noreturn]]
const THROWS_T& operator <<(const THROWS_T& os, const THROWS_T::endl_type endl) {

	std::string reason = trim_ws(throws.flush());
	throw std::runtime_error(reason.empty() ? "unknown error" : reason);
}
