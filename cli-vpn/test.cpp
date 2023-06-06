#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <vector>

int main () {
	std::vector<int> list;
	for (int i = 0; i < 10; ++i) {
		list.push_back(i+1);
	}
	
	std::vector<int> nx_list;
	nx_list = list;
	
	for (int i = 0; i < 10; ++i) {
		std::cout << nx_list[i] << std::endl;
	}
	return 0;
}
