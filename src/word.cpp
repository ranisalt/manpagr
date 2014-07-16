#include <iostream>
#include <string>
#include "doubly_linked_list.h"
#include "word.h"
	
word::word(std::string key) : _key(key), _pages() {}
	
std::string word::key() const {
	return _key;
}

void word::pages(std::string page) {
	if (!_pages.has(page)) {
		_pages.push_back(page);
	}
}
	
doubly_linked_list<std::string> word::pages() const {
	return _pages;
}
	
bool word::operator<(const word& rhs) const {
	return _key < rhs._key;
}