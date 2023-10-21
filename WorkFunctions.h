#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Application.h";
#include "Settings.h"
using namespace std;

//�������� ����������
bool Turn_on_app(Application& app) {
	if (app.Get_state() == false) {
		app.Turn_on_app();
		cout << "���������� ����������.\n";
		return true;
	}
	cout << "���������� ��� ��������!\n";
	return false;
}

//��������� ����������
bool Turn_off_app(Application& app) {
	if (app.Get_state() == true) {
		app.Turn_off_app();
		cout << "���������� �����������.\n";
		return true;
	}
	cout << "���������� ��� ���������!\n";
	return false;
}

//����������� ���������
bool Increase_volume(Settings& settings, int val) {
	if (settings.Get_volume() + val > 100) {
		cout << "������ ��������� ��������� ������ 100%\n";
		return false;
	}
	settings.Increase_volume(val);
	return true;
}

//��������� ���������
bool Reduce_volume(Settings& settings, int val) {
	if (settings.Get_volume() - val < 0) {
		cout << "������ ��������� ��������� ������ 0%\n";
		return false;
	}
	settings.Reduce_volume(val);
	return true;
}

//������� ������ � ����������
bool Work_volume(Settings& settings) {
	int val;
	string change;
	cout << "������� ���������: " << settings.Get_volume() << "%\n";
	cout << "'inc' - ��������� ���������   'red' - ��������� ���������\n";
	cout << "'off' - ��������� ����   'on' - �������� ����\n";
	cin >> change;
	if (change == "inc") {
		cout << "������� ������: ";
		cin >> val;
		return Increase_volume(settings, val);
	}
	else if (change == "red") {
		cout << "������� ������: ";
		cin >> val;
		return Reduce_volume(settings, val);
	}
	else if (change == "off") {
		settings.Set_temp_volume(settings.Get_volume());
		settings.Set_volume(0);
		return true;
	}
	else if (change == "on") {
		settings.Set_volume(settings.Get_temp_volume());
		settings.Set_temp_volume(0);
		return true;
	}
	else {
		cout << "������������ ��������!\n";
		return false;
	}
	return false;

}

//��������� ������ � ����������
bool Add_music(Application& app) {
	string name;
	string lable;
	string style;
	srand(time(0));
	int length = rand() % 6 + 1;
	cout << "������� ��������: ";
	cin >> name;
	cout << "������� �����: ";
	cin >> lable;
	cout << "������� �����(Rock/Pop): ";
	cin >> style;
	if ((style == "Rock") && (!app.Check_rock(name, lable))) {
		app.Add_rock(name, lable, length);
		cout << "������ ���������!\n";
		return true;
	}
	else if ((style == "Pop") && (!app.Check_pop(name, lable))) {
		app.Add_pop(name, lable, length);
		cout << "������ ���������!\n";
		return true;
	}
	else if ((style != "Rock") && (style != "Pop")) {
		cout << "������������ �����!\n";
		return false;
	}
	else {
		cout << "����� ������ ��� ����������!\n";
		return false;
	}
	return false;
}

//������� ������ �� ����������
bool Del_music(Application& app, Playlist& pl) {
	string name;
	string lable;
	string style;
	string author = "0";
	srand(time(0));
	int length = rand() % 6 + 1;
	cout << "������� ��������: ";
	cin >> name;
	cout << "������� �����: ";
	cin >> lable;
	cout << "������� �����(Rock/Pop): ";
	cin >> style;
	if ((style == "Rock") && (app.Check_rock(name, lable))) {
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			pl.Set_cursor(0);
		}
		app.Del_rock(app.Get_number_music(name, lable, style));
		cout << "������ �������!\n";
		return true;
	}
	else if ((style == "Pop") && (app.Check_pop(name, lable))) {
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			pl.Set_cursor(0);
		}
		app.Del_pop(app.Get_number_music(name, lable, style));
		cout << "������ �������!\n";
		return true;
	}
	else if ((style != "Rock") && (style != "Pop")) {
		cout << "������ ����� �� ����������!\n";
		return false;
	}
	else {
		cout << "����� ������ �� ����������!\n";
		return false;
	}
	return false;
}

//��������� ������� � ����������
bool Add_podcast(Application& app) {
	string name;
	string author;
	string style;
	srand(time(0));
	int length = rand() % 6 + 1;
	cout << "������� ��������: ";
	cin >> name;
	cout << "������� ������: ";
	cin >> author;
	cout << "������� �����(Fine/Teach): ";
	cin >> style;
	if ((style == "Fine") && (!app.Check_fine(name, author))) {
		app.Add_fine(name, author, length);
		cout << "������� ��������!\n";
		return true;
	}
	else if ((style == "Teach") && (!app.Check_teach(name, author))) {
		app.Add_teach(name, author, length);
		cout << "������� ��������!\n";
		return true;
	}
	else if ((style != "Fine") && (style != "Teach")) {
		cout << "������ ����� �� ����������!\n";
		return false;
	}
	else {
		cout << "����� ������� ��� ����������!\n";
		return false;
	}
	return false;
}

//������� ������� �� ����������
bool Del_podcast(Application& app, Playlist& pl) {
	string name;
	string author;
	string style;
	string lable = "0";
	cout << "������� ��������: ";
	cin >> name;
	cout << "������� ������: ";
	cin >> author;
	cout << "������� ����� (Fine/Teach): ";
	cin >> style;
	if ((style == "Fine") && (app.Check_fine(name, author))) {
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			pl.Set_cursor(0);
		}
		app.Del_fine(app.Get_number_podcast(name, author, style));
		cout << "������� ������!\n";
		return true;
	}
	else if ((style == "Teach") && (app.Check_teach(name, author))) {
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			pl.Set_cursor(0);
		}
		app.Del_teach(app.Get_number_podcast(name, author, style));
		cout << "������� ������!\n";
		return true;
	}
	else if ((style != "Fine") && (style != "Teach")) {
		cout << "������ ����� �� ����������!\n";
		return false;
	}
	else {
		cout << "������ �������� �� ����������!\n";
		return false;
	}
	return false;
}

//��������� ��� ������������ � ��������
bool Add_thing_playlist(Application& app, Playlist& pl) {
	string name = "0";
	string author = "0";
	string lable = "0";
	string style = "0";
	cout << "������� ��������: ";
	cin >> name;
	cout << "������� �����: ";
	cin >> style;
	if (style == "Rock") {
		cout << "������� �������� ������: ";
		cin >> lable;
		if (app.Check_rock(name, lable)) {
			pl.Add_thing_in_list(name, author, lable, style);
			cout << "������������ ���������!\n";
			return true;
		}
		cout << "����� ����� ���!\n";
		return false;
	}
	else if (style == "Pop") {
		cout << "������� �������� ������: ";
		cin >> lable;
		if (app.Check_pop(name, lable)) {
			pl.Add_thing_in_list(name, author, lable, style);
			cout << "������������ ���������!\n";
			return true;
		}
		cout << "����� ����� ���!\n";
		return false;
	}
	else if (style == "Fine") {
		cout << "������� ������: ";
		cin >> author;
		if (app.Check_fine(name, author)) {
			pl.Add_thing_in_list(name, author, lable, style);
			cout << "������������ ���������!\n";
			return true;
		}
		cout << "������ �������� ���!\n";
		return false;
	}
	else if (style == "Teach") {
		cout << "������� ������: ";
		cin >> author;
		if (app.Check_teach(name, author)) {
			pl.Add_thing_in_list(name, author, lable, style);
			cout << "������������ ���������!\n";
			return true;
		}
		cout << "������ �������� ���!\n";
		return false;
	}
	cout << "������������ �����!\n";
	return false;
}

//������� ������������ �� ���������
bool Del_thing_playlist(Application& app, Playlist& pl) {
	string name = "0";
	string author = "0";
	string lable = "0";
	string style = "0";
	cout << "������� ��������: ";
	cin >> name;
	cout << "������� �����: ";
	cin >> style;
	if (style == "Rock") {
		cout << "������� �������� ������: ";
		cin >> lable;
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			cout << "������������ �������!\n";
			return true;
		}
		cout << "����� ����� ���!\n";
		return false;
	}
	else if (style == "Pop") {
		cout << "������� �������� ������: ";
		cin >> lable;
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			cout << "������������ �������!\n";
			return true;
		}
		cout << "����� ����� ���!\n";
		return false;
	}
	else if (style == "Fine") {
		cout << "������� ������: ";
		cin >> author;
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			cout << "������������ �������!\n";
			return true;
		}
		cout << "������ �������� ���!\n";
		return false;
	}
	else if (style == "Teach") {
		cout << "������� ������: ";
		cin >> author;
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			cout << "������������ �������!\n";
			return true;
		}
		cout << "������ �������� ���!\n";
		return false;
	}
	cout << "������������ �����!\n";
	return false;
}

//������� ������ � ��� ��������������
bool Work_mus_thing(Application& app, Playlist& pl) {
	string change;
	cout << "'amusic' - �������� ������   'dmusic' - ������� ������\n";
	cout << "'apodcast' - �������� �������   'dpodcast' - ������� �������\n";
	cout << "'addplaylist' - �������� � ��������   'delplaylist' - ������� �� ���������\n";
	cin >> change;
	if (change == "amusic") {
		return Add_music(app);
	}
	else if (change == "dmusic") {
		return Del_music(app, pl);
	}
	else if (change == "apodcast") {
		return Add_podcast(app);
	}
	else if (change == "dpodcast") {
		return Del_podcast(app, pl);
	}
	else if (change == "addplaylist") {
		return Add_thing_playlist(app, pl);
	}
	else if (change == "delplaylist") {
		return Del_thing_playlist(app, pl);
	}
	else {
		cout << "������������ ������!\n";
		return false;
	}
	return false;
}

//�������� ������
bool Change_pas(Settings& settings) {
	string old_pas;
	string new_pas;
	string rep_pas;
	cout << "������� ������ ������: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		cout << "������� ����� ������: ";
		cin >> new_pas;
		cout << "��������� ������: ";
		cin >> rep_pas;
		if (new_pas == rep_pas) {
			settings.Set_password(new_pas);
			return true;
		}
		cout << "������ �� ������!\n";
		return false;
	}
	cout << "�� ����� ������������ ������!\n";
	return false;
}

//���������� ������
bool Reset_pas(Settings& settings) {
	string old_pas;
	cout << "������� ������ ������: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		settings.Set_password("laboratornaya");
		cout << "������ ������� �� ����������. " << settings.Get_password() << endl;;
		return true;
	}
	cout << "�� ����� ������������ ������!\n";
	return false;
}

//�������� ��� ������������
bool Change_username(Settings& settings) {
	string old_pas;
	string username;
	cout << "������� ������: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		cout << "������� ����� ��� ������������: ";
		cin >> username;
		settings.Set_username(username);
		cout << "��� ������������: " << settings.Get_username() << endl;
		return true;
	}
	cout << "�� ����� ������������ ������!\n";
	return false;
}

//���������� ��� ������������
bool Reset_username(Settings& settings) {
	string old_pas;
	cout << "������� ������: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		settings.Set_username("User");
		cout << "��� ������������ �������� �� ����������." << settings.Get_username() << endl;
		return true;
	}
	cout << "�� ����� ������������ ������!\n";
	return false;
}

//������ ������ �����
bool Change_access(Settings& settings) {
	string old_pas;
	int change;
	cout << "1 - ����� ������   2 - ��������� ������   3 - ������ ������\n";
	cin >> change;
	if (change == 1) {
		settings.Set_shared_access();
		cout << "������ ������� �� �����.\n";
		return true;
	}
	else if (change == 2) {
		settings.Set_group_access();
		cout << "������ ������� �� ���������.\n";
		return true;
	}
	else if (change == 3) {
		cout << "������� ������: ";
		cin >> old_pas;
		if (settings.Get_password() == old_pas) {
			settings.Set_admin_access();
			cout << "������ ������� �� �����������.\n";
			return true;
		}
		cout << "�� ����������� ����� ������!\n";
		return false;
	}
	else {
		cout << "������������ ������!\n";
		return false;
	}
}

//���������� ������
bool Reset_access(Settings& settings) {
	string old_pas;
	cout << "������� ������: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		settings.Set_shared_access();
		cout << "������ ������� �� ������.\n";
		return true;
	}
	cout << "�� ����� ������������ ������!\n";
	return false;
}

//������ � �����������
bool Work_settings(Settings& settings) {
	string change;
	cout << "'cpas' - �������� ������   'rpas' - �������� ������\n";
	cout << "'cusername' - �������� ��� ������������   'rusername' - �������� ��� ������������\n";
	cout << "'caccess' - �������� ������   'raccess' - �������� ������\n";
	cin >> change;
	if (change == "cpas") {
		return Change_pas(settings);
	}
	else if (change == "rpas") {
		return Reset_pas(settings);
	}
	else if (change == "cusername") {
		return Change_username(settings);
	}
	else if (change == "rusername") {
		return Reset_username(settings);
	}
	else if (change == "caccess") {
		return Change_access(settings);
	}
	else if (change == "raccess") {
		return Reset_access(settings);
	}
	else {
		cout << "������������ ������\n";
		return false;
	}
}
//�������� ������
bool On_music(Application& app) {
	string name;
	string lable;
	string style;
	cout << "������� ��������: ";
	cin >> name;
	cout << "������� ����� �����: ";
	cin >> lable;
	cout << "������� �����: ";
	cin >> style;
	if ((style == "Rock") && (app.Check_rock(name, lable))) {
		cout << "�������� �����: " << name << ". �����: " << lable << ". �����: ���\n";
		app.Set_work_name(name);
		app.Set_work_lable(lable);
		app.Set_work_style(style);
		app.Set_work_author("0");
		return true;
	}
	else if ((style == "Pop") && (app.Check_pop(name, lable))) {
		cout << "�������� �����: " << name << ". �����: " << lable << ". �����: ���\n";
		app.Set_work_name(name);
		app.Set_work_lable(lable);
		app.Set_work_style(style);
		app.Set_work_author("0");
		return true;
	}
	else if ((style != "Rock") && (style != "Pop")) {
		cout << "������������ �����!\n";
		return false;
	}
	cout << "����� ����� ���!\n";
	return false;
}

//��������� ������
bool Off_music(Application& app) {
	if ((app.Get_work_name() != "0") && ((app.Get_work_style() == "Rock") || (app.Get_work_style() == "Pop"))) {
		cout << "������ " << app.Get_work_name() << " ���������.\n";
		app.Set_work_name("0");
		app.Set_work_lable("0");
		app.Set_work_style("0");
		app.Set_work_author("0");
		return true;
	}
	cout << "������ �� ��������!\n";
	return false;
}

//�������� �������
bool On_podcast(Application& app) {
	string name;
	string author;
	string style;
	cout << "������� ��������: ";
	cin >> name;
	cout << "������� ������ ��������: ";
	cin >> author;
	cout << "������� �����: ";
	cin >> style;
	if ((style == "Fine") && (app.Check_fine(name, author))) {
		cout << "������� �������: " << name << ". �����: " << author << ". �����: ���������������\n";
		app.Set_work_name(name);
		app.Set_work_lable("0");
		app.Set_work_style(style);
		app.Set_work_author(author);
		return true;
	}
	else if ((style == "Teach") && (app.Check_pop(name, author))) {
		cout << "������� �������: " << name << ". �����: " << author << ". �����: �������\n";
		app.Set_work_name(name);
		app.Set_work_lable("0");
		app.Set_work_style(style);
		app.Set_work_author(author);
		return true;
	}
	else if ((style != "Fine") && (style != "Teach")) {
		cout << "������������ �����!\n";
		return false;
	}
	cout << "������ �������� ���!\n";
	return false;
}

//��������� �������
bool Off_podcast(Application& app) {
	if ((app.Get_work_name() != "0") && ((app.Get_work_style() == "Teach") || (app.Get_work_style() == "Fine"))) {
		cout << "������� " << app.Get_work_name() << " ��������.\n";
		app.Set_work_name("0");
		app.Set_work_lable("0");
		app.Set_work_style("0");
		app.Set_work_author("0");
		return true;
	}
	cout << "������� �� �������!\n";
	return false;
}

bool On_playlist(Application& app, Playlist& pl) {
	if (pl.Get_list_searchs().size() != 0) {
		if ((pl.Get_list_searchs()[0].get_style() == "Rock") || (pl.Get_list_searchs()[0].get_style() == "Pop")) {
			cout << "������ �����: " << pl.Get_list_searchs()[0].Get_name() << ". �����: "
				<< pl.Get_list_searchs()[0].Get_lable() << ". �����: " << pl.Get_list_searchs()[0].get_style() << endl;
			app.Set_work_name(pl.Get_list_searchs()[0].Get_name());
			app.Set_work_lable(pl.Get_list_searchs()[0].Get_lable());
			app.Set_work_style(pl.Get_list_searchs()[0].get_style());
			app.Set_work_author("0");
			pl.Set_cursor(0);
			return true;
		}
		else if ((pl.Get_list_searchs()[0].get_style() == "Fine") || (pl.Get_list_searchs()[0].get_style() == "Teach")) {
			cout << "������ �������: " << pl.Get_list_searchs()[0].Get_name() << ". �����: "
				<< pl.Get_list_searchs()[0].Get_author() << ". �����: " << pl.Get_list_searchs()[0].get_style() << endl;
			app.Set_work_name(pl.Get_list_searchs()[0].Get_name());
			app.Set_work_lable("0");
			app.Set_work_style(pl.Get_list_searchs()[0].get_style());
			app.Set_work_author(pl.Get_list_searchs()[0].Get_author());
			pl.Set_cursor(0);
			return true;
		}
		cout << "��� ������ �����!\n";
		return false;
	}
	cout << "�������� ����!\n";
	return false;
}

//�������� ���� ������������ � ���������
bool Turn_next(Application& app, Playlist& pl) {
	if (pl.Get_cursor() + 2 <= pl.Get_list_searchs().size()) {
		pl.Increase_cursor();
		if ((pl.Get_list_searchs()[pl.Get_cursor()].get_style() == "Rock") || (pl.Get_list_searchs()[pl.Get_cursor()].get_style() == "Pop")) {
			cout << "������ �����: " << pl.Get_list_searchs()[pl.Get_cursor()].Get_name() << ". �����: "
				<< pl.Get_list_searchs()[pl.Get_cursor()].Get_lable() << ". �����: " << pl.Get_list_searchs()[pl.Get_cursor()].get_style() << endl;
			app.Set_work_name(pl.Get_list_searchs()[pl.Get_cursor()].Get_name());
			app.Set_work_lable(pl.Get_list_searchs()[pl.Get_cursor()].Get_lable());
			app.Set_work_style(pl.Get_list_searchs()[pl.Get_cursor()].get_style());
			app.Set_work_author("0");
			return true;
		}
		else if ((pl.Get_list_searchs()[pl.Get_cursor()].get_style() == "Fine") || (pl.Get_list_searchs()[pl.Get_cursor()].get_style() == "Teach")) {
			cout << "������ �������: " << pl.Get_list_searchs()[pl.Get_cursor()].Get_name() << ". �����: "
				<< pl.Get_list_searchs()[pl.Get_cursor()].Get_author() << ". �����: " << pl.Get_list_searchs()[pl.Get_cursor()].get_style() << endl;
			app.Set_work_name(pl.Get_list_searchs()[pl.Get_cursor()].Get_name());
			app.Set_work_lable("0");
			app.Set_work_style(pl.Get_list_searchs()[pl.Get_cursor()].get_style());
			app.Set_work_author(pl.Get_list_searchs()[pl.Get_cursor()].Get_author());
			return true;
		}
		pl.Reduce_cursor();
		cout << "��� ������ �����!\n";
		return false;
	}
	cout << "����� ���������!\n";
	return false;
}

//��������� ��� ������������
bool Play_thing(Application& app, Playlist& pl) {
	string change;
	cout << "'onmusic' - �������� ������   'offmusic' - ��������� ������\n";
	cout << "'onpodcast' - �������� �������   'offpodcast' - ��������� �������\n";
	cout << "'onplaylist' - �������� ��������   'next' - ��������� ������������ � ���������\n";
	cin >> change;
	if (change == "onmusic") {
		return On_music(app);
	}
	else if (change == "offmusic") {
		return Off_music(app);
	}
	else if (change == "onpodcast") {
		return On_podcast(app);
	}
	else if (change == "offpodcast") {
		return Off_podcast(app);
	}
	else if (change == "onplaylist") {
		return On_playlist(app, pl);
	}
	else if (change == "next") {
		return Turn_next(app, pl);
	}
	else {
		cout << "������������ ������!\n";
		return false;
	}
	return false;
}

void Main_menu(Application& app, Playlist& pl, Settings& settings) {
	string change;
	while (true) {
		cout << "'on' - �������� ����������\n";
		cout << "'off' - ��������� ����������\n";
		cout << "'volume' - ������ �� ������\n";
		cout << "'thing' - ������ � ��������������\n";
		cout << "'settings' - ������ � �����������\n";
		cout << "'play' - �������� �������������\n";
		cout << "'exit' - �����\n";
		cin >> change;
		if (change == "on") {
			Turn_on_app(app);
			continue;
		}
		else if (change == "off") {
			Turn_off_app(app);
			continue;
		}
		else if (change == "volume") {
			if (app.Get_state() == true) {
				Work_volume(settings);
				continue;
			}
			cout << "������ �������� ��� ����������� ����������!\n";
			continue;
		}
		else if (change == "thing") {
			if (app.Get_state() == true) {
				Work_mus_thing(app, pl);
				continue;
			}
			cout << "������ �������� ��� ����������� ����������!\n";
			continue;
		}
		else if (change == "settings") {
			if (app.Get_state() == true) {
				Work_settings(settings);
				continue;
			}
			cout << "������ �������� ��� ����������� ����������!\n";
			continue;
		}
		else if (change == "play") {
			if (app.Get_state() == true) {
				Play_thing(app, pl);
				continue;
			}
			cout << "������ �������� ��� ����������� ����������!\n";
			continue;
		}
		else if (change == "exit") {
			return;
		}
		else {
			cout << "������������ ������!\n";
			continue;
		}

	}
}