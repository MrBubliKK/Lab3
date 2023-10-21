#pragma once
#include <iostream>
#include <string>

class Search {
private:
	string name;
	string author;
	string lable;
	string style;

public:
	Search(string name, string author, string lable, string style) {
		this->name = name;
		this->author = author;
		this->lable = lable;
		this->style = style;
	}

	string Get_name() {
		return this->name;
	}

	string Get_author() {
		return this->author;
	}

	string Get_lable() {
		return this->lable;
	}

	string get_style() {
		return this->style;
	}

};