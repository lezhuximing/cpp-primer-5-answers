#ifndef E29_H
#define E29_H

#include <string.h>
#include <iostream>

using namespace std;

class Screen {
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	inline Screen set(char c);
	inline Screen set(pos, pos, char);
	Screen move(pos r, pos c);
	Screen display(ostream &os)
		{ do_display(os); return *this; }
	const Screen display(ostream &os) const
		{ do_display(os); return *this; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(ostream &os) const { os << contents;}
};

inline
Screen Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline Screen Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen Screen::set(pos r, pos col, char c){
	contents[r*width + col] = c;
	return *this;
}

char Screen::get(pos r, pos c) const {
	pos row = r*width;
	return contents[row + c];
}
#endif