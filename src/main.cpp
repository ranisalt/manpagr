/*
 * main.cpp
 *
 *  Created on: 9 Jul 2014
 *      Author: ranieri
 */

#include <iostream>
#include <fstream>
#include "avl_tree.h"
#include "doubly_linked_list.h"

int main(int argc, char** argv) {
	using std::cout;
	using std::endl;
	using std::ifstream;
	using std::pair;
	using std::string;

	/* Convert char* array into string list */
	doubly_linked_list<string> files;
	for (int i = 1; i < argc; ++i) {
		files.push_back(string(argv[i]));
	}

	avl_tree<pair<string, string>> primary;
	for (string path : files) {
		auto last_slash = path.find_last_of('/'), last_dot = path.find_last_of(
				'.');
		auto filename = path.substr(last_slash + 1,
				last_dot - (last_slash + 1));

		ifstream file(path);
		if (file.is_open()) {
			string word;
			while(file >> word) {
				cout << word << '\t';
				word.clear();
			}
		}
		file.close();
	}
}

