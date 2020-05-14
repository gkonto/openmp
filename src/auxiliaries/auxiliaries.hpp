#ifndef AUXILIARIES_HPP
#define AUXILIARIES_HPP

#include <sstream>

template<typename T>
extern void read_value(char *arg, int &val) {
    std::stringstream ss;
    ss << arg;
    ss >> val;
}

#endif
