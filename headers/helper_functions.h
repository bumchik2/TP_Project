#pragma once


#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>


inline int randomInt (int l, int r) {
	return l + rand() % (r - l + 1);
}


inline double randomDouble (double l = 0, double r = 1) {
	return l + (r - l) * (static_cast<double>(rand() % 10000) / 10000);
}


template<typename T>
bool contains (const std::vector<T>& v, const T& target) {
	for (unsigned i = 0; i < v.size(); ++i) {
		if (v[i] == target) {
			return true;
		}
	}
	return false;
}


template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) {
	for (unsigned i = 0; i < v.size(); ++i) {
		os << v[i] << std::endl;
	}
	return os;
}

