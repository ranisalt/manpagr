#include <string>
#include "page.h"

page::page(std::string title, std::string content) : _title(title), _content(content) {}

std::string page::title() const {
	return _title;
}

std::string page::content() const {
	return _content;
}

bool page::operator<(const page& rhs) const {
	return _title < rhs._title;
}