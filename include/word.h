#ifndef WORD_H_
#define WORD_H_
	
#include <string>
#include "doubly_linked_list.h"
	
class word {
public:
	word(std::string key);
	
	std::string key() const;
	void pages(std::string);
	doubly_linked_list<std::string> pages() const;
	
	bool operator<(const word& rhs) const;
	
private:
	std::string _key;
	doubly_linked_list<std::string> _pages;
};
	
#endif