#include <iostream>
#include <string>
#include "RockMusic.h"
#include "PopMusic.h"
#include "FinePodcast.h"
#include "TeachPodcast.h"
#include "Playlist.h"
#include <vector>
using namespace std;

class Application {
private:
	vector <RockMusic> list_rocks;
	vector <PopMusic> list_pops;
	vector <FinePodcast> list_fines;
	vector <TeachPodcast> list_teachs;
	bool state = false;
	string work_name = "0";
	string work_lable = "0";
	string work_author = "0";
	string work_style = "0";
public:
	void Turn_on_app() {
		state = true;
		cout << "Приложение включено.\n";
		return;
	}

	void Turn_off_app() {
		state = false;
		cout << "Приложение выключено.\n";
		return;
	}

	string Get_work_name() {
		return this->work_name;
	}

	string Get_work_lable() {
		return this->work_lable;
	}

	string Get_work_author() {
		return this->work_author;
	}

	string Get_work_style() {
		return this->work_style;
	}

	void Set_work_name(string name) {
		this->work_name = name;
	}

	void Set_work_lable(string lable) {
		this->work_lable = lable;
	}

	void Set_work_author(string author) {
		this->work_author = author;
	}

	void Set_work_style(string style) {
		this->work_style = style;
	}

	vector <RockMusic> Get_list_rocks() {
		return list_rocks;
	}

	vector <PopMusic> Get_list_pops() {
		return list_pops;
	}

	vector <FinePodcast> Get_list_fines() {
		return list_fines;
	}

	vector <TeachPodcast> Get_list_teachs() {
		return list_teachs;
	}

	int Get_state() {
		return this->state;
	}

	void Add_rock(string name, string lable, int length) {
		list_rocks.push_back(RockMusic(name, lable, length));
	}

	void Add_pop(string name, string lable, int length) {
		list_pops.push_back(PopMusic(name, lable, length));
	}

	void Add_fine(string name, string author, int length) {
		list_fines.push_back(FinePodcast(name, author, length));
	}

	void Add_teach(string name, string author, int length) {
		list_teachs.push_back(TeachPodcast(name, author, length));
	}

	void Del_rock(int number) {
		list_rocks.erase(list_rocks.begin() + number);
	}

	void Del_pop(int number) {
		list_pops.erase(list_pops.begin() + number);
	}

	void Del_fine(int number) {
		list_fines.erase(list_fines.begin() + number);
	}

	void Del_teach(int number) {
		list_teachs.erase(list_teachs.begin() + number);
	}

	bool Check_rock(string name, string lable) {
		for (int i = 0; i < list_rocks.size(); i++) {
			if ((list_rocks[i].Get_name() == name) && (list_rocks[i].Get_lable() == lable)) {
				return true;
			}
		}
		return false;
	}

	bool Check_pop(string name, string lable) {
		for (int i = 0; i < list_pops.size(); i++) {
			if ((list_pops[i].Get_name() == name) && (list_pops[i].Get_lable() == lable)) {
				return true;
			}
		}
		return false;
	}

	bool Check_fine(string name, string author) {
		for (int i = 0; i < list_fines.size(); i++) {
			if ((list_fines[i].Get_name() == name) && (list_fines[i].Get_author() == author)) {
				return true;
			}
		}
		return false;
	}

	bool Check_teach(string name, string author) {
		for (int i = 0; i < list_teachs.size(); i++) {
			if ((list_teachs[i].Get_name() == name) && (list_teachs[i].Get_author() == author)) {
				return true;
			}
		}
		return false;
	}

	int Get_number_music(string name, string lable, string style) {
		if (style == "Rock") {
			for (int i = 0; i < list_rocks.size(); i++) {
				if ((list_rocks[i].Get_name() == name) && (list_rocks[i].Get_lable() == lable)) {
					return i;
				}
			}
			return -1;
		}
		else if (style == "Pop") {
			for (int i = 0; i < list_pops.size(); i++) {
				if ((list_pops[i].Get_name() == name) && (list_pops[i].Get_lable() == lable)) {
					return i;
				}
			}
			return -1;
		}
		return -2;
	}

	int Get_number_podcast(string name, string author, string style) {
		if (style == "Teach") {
			for (int i = 0; i < list_teachs.size(); i++) {
				if ((list_teachs[i].Get_name() == name) && (list_teachs[i].Get_author() == author)) {
					return i;
				}
			}
			return -1;
		}
		else if (style == "Fine") {
			for (int i = 0; i < list_fines.size(); i++) {
				if ((list_fines[i].Get_name() == name) && (list_fines[i].Get_author() == author)) {
					return i;
				}
			}
			return -1;
		}
		return -2;
	}
};