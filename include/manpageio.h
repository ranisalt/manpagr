#ifndef MANPAGEIO_H_
#define MANPAGEIO_H_

#include <fstream>
#include <sstream>
#include "page.h"
#include "word.h"
	
class ManpageIO {	
public:	
	page read(std::string path) {
		std::ifstream input{ path };
		// Ignorar primeira linha, porque todas são <beginning of page>
		//input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		auto last_slash = path.find_last_of('/'),
		     last_dot   = path.find_last_of('.');
		auto filename   = path.substr(last_slash + 1,	last_dot - (last_slash + 1));
			
		std::stringstream content;
		content << input.rdbuf();
		input.close();
		return { filename, content.str() };
	}
	
	void write_primary_record(std::string filename, avl_tree<page>& tree) {
		std::ofstream output { filename };
		auto list = tree.breadth_first();
		for (auto it : list) {
			output << it.title() << ' ' << it.content() << '\3';
		}
		output.close();
	}
	
	void write_secondary_record(std::string filename, avl_tree<word>& tree) {
		std::ofstream output { filename };
		auto list = tree.breadth_first();
		for (auto it : list) {
			output << it.key();
			auto pages = it.pages();
			for (auto page : pages) {
				output << ' ' << page;
			}
			output << std::endl;
		}
		output.close();
	}
};
	
#endif