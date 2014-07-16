#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "doubly_linked_list.h"

int main(int argc, char** argv) {
	using std::cout;
	using std::endl;
	using std::string;
	
	if (argc < 3) {
		cout << 					 "usage: "                 																			<< endl
			   << argv[0] << " --page <page name>"    																			<< endl
				 << argv[0] << " --terms <search term 1> <search term 2> ... <search term n>" << endl;
		return 0;
	}
	
	if (argv[1] == string{ "--page" }) {
		if (argc != 3) {
			cout << "Você só pode pesquisar 1 page de cada vez." << endl;
			return 0;
		}
		
		std::ifstream input{ "manpages.dat" };

		string page, manpage;
		
		while (!input.eof()) {
			input >> page;
			if (page == argv[2]) {
				std::getline(input, manpage, '\3');
				cout << manpage;
				break;
			} else {
				input.ignore(std::numeric_limits<std::streamsize>::max(), '\3');
			}
		}
	} else if (argv[1] == string{ "--terms" }) {
		doubly_linked_list<string> matches;
		for (int i = 2; i < argc; ++i) {
			std::ifstream input{ "manwords.dat" };
			
			string word;
			while (!input.eof()) {
				input >> word;
				if (word == argv[i]) {
					std::string _line;
					std::getline(input, _line, '\n');
					word.clear();
					
					std::stringstream line { _line };
					doubly_linked_list<string> teriyaki;
					while (line >> word) {
						teriyaki.push_back(word);
						word.clear();
					}
					if (matches.size() > 0) {
						matches.intersect(teriyaki);
					} else {
						std::swap(matches, teriyaki);
					}
					break;
				}
			}
		}
		
		if (matches.size() > 0) {
			cout << "Páginas que contém os termos pesquisados:" << endl;
			for (auto it : matches) {
				cout << it << endl;
			}
		} else {
			cout << "Os termos não foram encontrados em um mesmo arquivo." << endl;
		}
	}
}
