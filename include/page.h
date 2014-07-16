#ifndef PAGE_H_
#define PAGE_H_

#include <string>

class page {
public:
	page(std::string title, std::string content);
	
	std::string title() const;
	std::string content() const;
	
	bool operator<(const page& rhs) const;
	
private:
	std::string _title;
	std::string _content;
};

#endif