#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Application.h";
#include "Settings.h"
using namespace std;

//Включает приложение
bool Turn_on_app(Application& app) {
	if (app.Get_state() == false) {
		app.Turn_on_app();
		cout << "Приложение включилось.\n";
		return true;
	}
	cout << "Приложение уже включено!\n";
	return false;
}

//Выключает приложение
bool Turn_off_app(Application& app) {
	if (app.Get_state() == true) {
		app.Turn_off_app();
		cout << "Приложение выключилось.\n";
		return true;
	}
	cout << "Приложение уже выключено!\n";
	return false;
}

//Увеличивает громкость
bool Increase_volume(Settings& settings, int val) {
	if (settings.Get_volume() + val > 100) {
		cout << "Нельзя поставить громкость больше 100%\n";
		return false;
	}
	settings.Increase_volume(val);
	return true;
}

//Уменьшает громкость
bool Reduce_volume(Settings& settings, int val) {
	if (settings.Get_volume() - val < 0) {
		cout << "Нельзя поставить громкость меньше 0%\n";
		return false;
	}
	settings.Reduce_volume(val);
	return true;
}

//функция работы с громкостью
bool Work_volume(Settings& settings) {
	int val;
	string change;
	cout << "Текущая громкость: " << settings.Get_volume() << "%\n";
	cout << "'inc' - Увеличить громкость   'red' - Уменьшить громкость\n";
	cout << "'off' - Выключить звук   'on' - Включить звук\n";
	cin >> change;
	if (change == "inc") {
		cout << "Введите размер: ";
		cin >> val;
		return Increase_volume(settings, val);
	}
	else if (change == "red") {
		cout << "Введите размер: ";
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
		cout << "Некорректное значение!\n";
		return false;
	}
	return false;

}

//Добавляет музыку в приложение
bool Add_music(Application& app) {
	string name;
	string lable;
	string style;
	srand(time(0));
	int length = rand() % 6 + 1;
	cout << "Введите название: ";
	cin >> name;
	cout << "Введите лейбл: ";
	cin >> lable;
	cout << "Введите стиль(Rock/Pop): ";
	cin >> style;
	if ((style == "Rock") && (!app.Check_rock(name, lable))) {
		app.Add_rock(name, lable, length);
		cout << "Музыка добавлена!\n";
		return true;
	}
	else if ((style == "Pop") && (!app.Check_pop(name, lable))) {
		app.Add_pop(name, lable, length);
		cout << "Музыка добавлена!\n";
		return true;
	}
	else if ((style != "Rock") && (style != "Pop")) {
		cout << "Некорректный стиль!\n";
		return false;
	}
	else {
		cout << "Такая музыка уже существует!\n";
		return false;
	}
	return false;
}

//Удаляет музыку из приложения
bool Del_music(Application& app, Playlist& pl) {
	string name;
	string lable;
	string style;
	string author = "0";
	srand(time(0));
	int length = rand() % 6 + 1;
	cout << "Введите название: ";
	cin >> name;
	cout << "Введите лейбл: ";
	cin >> lable;
	cout << "Введите стиль(Rock/Pop): ";
	cin >> style;
	if ((style == "Rock") && (app.Check_rock(name, lable))) {
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			pl.Set_cursor(0);
		}
		app.Del_rock(app.Get_number_music(name, lable, style));
		cout << "Музыка удалена!\n";
		return true;
	}
	else if ((style == "Pop") && (app.Check_pop(name, lable))) {
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			pl.Set_cursor(0);
		}
		app.Del_pop(app.Get_number_music(name, lable, style));
		cout << "Музыка удалена!\n";
		return true;
	}
	else if ((style != "Rock") && (style != "Pop")) {
		cout << "Такого стиля не существует!\n";
		return false;
	}
	else {
		cout << "Такой музыки не сущетсвует!\n";
		return false;
	}
	return false;
}

//Добавляет подкаст в приложение
bool Add_podcast(Application& app) {
	string name;
	string author;
	string style;
	srand(time(0));
	int length = rand() % 6 + 1;
	cout << "Введите название: ";
	cin >> name;
	cout << "Введите автора: ";
	cin >> author;
	cout << "Введите стиль(Fine/Teach): ";
	cin >> style;
	if ((style == "Fine") && (!app.Check_fine(name, author))) {
		app.Add_fine(name, author, length);
		cout << "Подкаст добавлен!\n";
		return true;
	}
	else if ((style == "Teach") && (!app.Check_teach(name, author))) {
		app.Add_teach(name, author, length);
		cout << "Подкаст добавлен!\n";
		return true;
	}
	else if ((style != "Fine") && (style != "Teach")) {
		cout << "Такого стиля не существует!\n";
		return false;
	}
	else {
		cout << "Такой подкаст уже сущетсвует!\n";
		return false;
	}
	return false;
}

//Удаляет подкаст из приложения
bool Del_podcast(Application& app, Playlist& pl) {
	string name;
	string author;
	string style;
	string lable = "0";
	cout << "Введите название: ";
	cin >> name;
	cout << "Введите автора: ";
	cin >> author;
	cout << "Введите стиль (Fine/Teach): ";
	cin >> style;
	if ((style == "Fine") && (app.Check_fine(name, author))) {
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			pl.Set_cursor(0);
		}
		app.Del_fine(app.Get_number_podcast(name, author, style));
		cout << "Подкаст удален!\n";
		return true;
	}
	else if ((style == "Teach") && (app.Check_teach(name, author))) {
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			pl.Set_cursor(0);
		}
		app.Del_teach(app.Get_number_podcast(name, author, style));
		cout << "Подкаст удален!\n";
		return true;
	}
	else if ((style != "Fine") && (style != "Teach")) {
		cout << "Такого стиля не существует!\n";
		return false;
	}
	else {
		cout << "Такого подкаста не существует!\n";
		return false;
	}
	return false;
}

//Добавляет муз произведение в плейлист
bool Add_thing_playlist(Application& app, Playlist& pl) {
	string name = "0";
	string author = "0";
	string lable = "0";
	string style = "0";
	cout << "Введите название: ";
	cin >> name;
	cout << "Введите стиль: ";
	cin >> style;
	if (style == "Rock") {
		cout << "Введите название лэйбла: ";
		cin >> lable;
		if (app.Check_rock(name, lable)) {
			pl.Add_thing_in_list(name, author, lable, style);
			cout << "Произведение добавлено!\n";
			return true;
		}
		cout << "Такой песни нет!\n";
		return false;
	}
	else if (style == "Pop") {
		cout << "Введите название лэйбла: ";
		cin >> lable;
		if (app.Check_pop(name, lable)) {
			pl.Add_thing_in_list(name, author, lable, style);
			cout << "Произведение добавлено!\n";
			return true;
		}
		cout << "Такой песни нет!\n";
		return false;
	}
	else if (style == "Fine") {
		cout << "Введите автора: ";
		cin >> author;
		if (app.Check_fine(name, author)) {
			pl.Add_thing_in_list(name, author, lable, style);
			cout << "Произведение добавлено!\n";
			return true;
		}
		cout << "Такого подкаста нет!\n";
		return false;
	}
	else if (style == "Teach") {
		cout << "Введите автора: ";
		cin >> author;
		if (app.Check_teach(name, author)) {
			pl.Add_thing_in_list(name, author, lable, style);
			cout << "Произведение добавлено!\n";
			return true;
		}
		cout << "Такого подкаста нет!\n";
		return false;
	}
	cout << "Некорректный стиль!\n";
	return false;
}

//Удаляет произведение из плейлиста
bool Del_thing_playlist(Application& app, Playlist& pl) {
	string name = "0";
	string author = "0";
	string lable = "0";
	string style = "0";
	cout << "Введите название: ";
	cin >> name;
	cout << "Введите стиль: ";
	cin >> style;
	if (style == "Rock") {
		cout << "Введите название лэйбла: ";
		cin >> lable;
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			cout << "Произведение удалено!\n";
			return true;
		}
		cout << "Такой песни нет!\n";
		return false;
	}
	else if (style == "Pop") {
		cout << "Введите название лэйбла: ";
		cin >> lable;
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			cout << "Произведение удалено!\n";
			return true;
		}
		cout << "Такой песни нет!\n";
		return false;
	}
	else if (style == "Fine") {
		cout << "Введите автора: ";
		cin >> author;
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			cout << "Произведение удалено!\n";
			return true;
		}
		cout << "Такого подкаста нет!\n";
		return false;
	}
	else if (style == "Teach") {
		cout << "Введите автора: ";
		cin >> author;
		if (pl.Check_thing(name, author, lable, style)) {
			pl.Del_thing_in_list(name, author, lable, style);
			cout << "Произведение удалено!\n";
			return true;
		}
		cout << "Такого подкаста нет!\n";
		return false;
	}
	cout << "Некорректный стиль!\n";
	return false;
}

//Функция работы с муз произведениями
bool Work_mus_thing(Application& app, Playlist& pl) {
	string change;
	cout << "'amusic' - Добавить музыку   'dmusic' - Удалить музыку\n";
	cout << "'apodcast' - Добавить подкаст   'dpodcast' - Удалить подкаст\n";
	cout << "'addplaylist' - Добавить в плейлист   'delplaylist' - Удалить из плейлиста\n";
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
		cout << "Некорректные данные!\n";
		return false;
	}
	return false;
}

//Изменяет пароль
bool Change_pas(Settings& settings) {
	string old_pas;
	string new_pas;
	string rep_pas;
	cout << "Введите старый пароль: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		cout << "Введите новый пароль: ";
		cin >> new_pas;
		cout << "Повторите пароль: ";
		cin >> rep_pas;
		if (new_pas == rep_pas) {
			settings.Set_password(new_pas);
			return true;
		}
		cout << "Пароль не совпал!\n";
		return false;
	}
	cout << "Вы ввели неправильный пароль!\n";
	return false;
}

//Сбрасывает пароль
bool Reset_pas(Settings& settings) {
	string old_pas;
	cout << "Введите старый пароль: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		settings.Set_password("laboratornaya");
		cout << "Пароль сброшен до начального. " << settings.Get_password() << endl;;
		return true;
	}
	cout << "Вы ввели неправильный пароль!\n";
	return false;
}

//Изменяет имя пользователя
bool Change_username(Settings& settings) {
	string old_pas;
	string username;
	cout << "Введите пароль: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		cout << "Введите новое имя пользователя: ";
		cin >> username;
		settings.Set_username(username);
		cout << "Имя пользователя: " << settings.Get_username() << endl;
		return true;
	}
	cout << "Вы ввели неправильный пароль!\n";
	return false;
}

//Сбрасывает имя пользователя
bool Reset_username(Settings& settings) {
	string old_pas;
	cout << "Введите пароль: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		settings.Set_username("User");
		cout << "Имя пользователя сброшено до начального." << settings.Get_username() << endl;
		return true;
	}
	cout << "Вы ввели неправильный пароль!\n";
	return false;
}

//Меняет доступ юзера
bool Change_access(Settings& settings) {
	string old_pas;
	int change;
	cout << "1 - Общий доступ   2 - Групповой доступ   3 - Доступ админа\n";
	cin >> change;
	if (change == 1) {
		settings.Set_shared_access();
		cout << "Доступ изменен на общий.\n";
		return true;
	}
	else if (change == 2) {
		settings.Set_group_access();
		cout << "Доступ изменен на групповой.\n";
		return true;
	}
	else if (change == 3) {
		cout << "Введите пароль: ";
		cin >> old_pas;
		if (settings.Get_password() == old_pas) {
			settings.Set_admin_access();
			cout << "Доступ изменен на админовский.\n";
			return true;
		}
		cout << "Вы неправильно ввели пароль!\n";
		return false;
	}
	else {
		cout << "Некорректные данные!\n";
		return false;
	}
}

//Сбрасывает доступ
bool Reset_access(Settings& settings) {
	string old_pas;
	cout << "Введите пароль: ";
	cin >> old_pas;
	if (settings.Get_password() == old_pas) {
		settings.Set_shared_access();
		cout << "Доступ сброшен до общего.\n";
		return true;
	}
	cout << "Вы ввели неправильный пароль!\n";
	return false;
}

//Работа с настройками
bool Work_settings(Settings& settings) {
	string change;
	cout << "'cpas' - Изменить пароль   'rpas' - Сбросить пароль\n";
	cout << "'cusername' - Изменить имя пользователя   'rusername' - Сбросить имя пользователя\n";
	cout << "'caccess' - Изменить доступ   'raccess' - Сбросить доступ\n";
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
		cout << "Некорректные данные\n";
		return false;
	}
}
//Включает музыку
bool On_music(Application& app) {
	string name;
	string lable;
	string style;
	cout << "Введите название: ";
	cin >> name;
	cout << "Введите лэйбл песни: ";
	cin >> lable;
	cout << "Введите стиль: ";
	cin >> style;
	if ((style == "Rock") && (app.Check_rock(name, lable))) {
		cout << "Включена песня: " << name << ". Лэйбл: " << lable << ". Стиль: рок\n";
		app.Set_work_name(name);
		app.Set_work_lable(lable);
		app.Set_work_style(style);
		app.Set_work_author("0");
		return true;
	}
	else if ((style == "Pop") && (app.Check_pop(name, lable))) {
		cout << "Включена песня: " << name << ". Лэйбл: " << lable << ". Стиль: поп\n";
		app.Set_work_name(name);
		app.Set_work_lable(lable);
		app.Set_work_style(style);
		app.Set_work_author("0");
		return true;
	}
	else if ((style != "Rock") && (style != "Pop")) {
		cout << "Некорректный стиль!\n";
		return false;
	}
	cout << "Такой песни нет!\n";
	return false;
}

//Выключает музыку
bool Off_music(Application& app) {
	if ((app.Get_work_name() != "0") && ((app.Get_work_style() == "Rock") || (app.Get_work_style() == "Pop"))) {
		cout << "Музыка " << app.Get_work_name() << " выключена.\n";
		app.Set_work_name("0");
		app.Set_work_lable("0");
		app.Set_work_style("0");
		app.Set_work_author("0");
		return true;
	}
	cout << "Музыка не включена!\n";
	return false;
}

//Включает подкаст
bool On_podcast(Application& app) {
	string name;
	string author;
	string style;
	cout << "Введите название: ";
	cin >> name;
	cout << "Введите автора подкаста: ";
	cin >> author;
	cout << "Введите стиль: ";
	cin >> style;
	if ((style == "Fine") && (app.Check_fine(name, author))) {
		cout << "Включен подкаст: " << name << ". Автор: " << author << ". Стиль: развлекательный\n";
		app.Set_work_name(name);
		app.Set_work_lable("0");
		app.Set_work_style(style);
		app.Set_work_author(author);
		return true;
	}
	else if ((style == "Teach") && (app.Check_pop(name, author))) {
		cout << "Включен подкаст: " << name << ". Автор: " << author << ". Стиль: учебный\n";
		app.Set_work_name(name);
		app.Set_work_lable("0");
		app.Set_work_style(style);
		app.Set_work_author(author);
		return true;
	}
	else if ((style != "Fine") && (style != "Teach")) {
		cout << "Некорректный стиль!\n";
		return false;
	}
	cout << "Такого подкаста нет!\n";
	return false;
}

//Выключает подкаст
bool Off_podcast(Application& app) {
	if ((app.Get_work_name() != "0") && ((app.Get_work_style() == "Teach") || (app.Get_work_style() == "Fine"))) {
		cout << "Подкаст " << app.Get_work_name() << " выключен.\n";
		app.Set_work_name("0");
		app.Set_work_lable("0");
		app.Set_work_style("0");
		app.Set_work_author("0");
		return true;
	}
	cout << "Подкаст не включен!\n";
	return false;
}

bool On_playlist(Application& app, Playlist& pl) {
	if (pl.Get_list_searchs().size() != 0) {
		if ((pl.Get_list_searchs()[0].get_style() == "Rock") || (pl.Get_list_searchs()[0].get_style() == "Pop")) {
			cout << "Играет песня: " << pl.Get_list_searchs()[0].Get_name() << ". Лэйбл: "
				<< pl.Get_list_searchs()[0].Get_lable() << ". Стиль: " << pl.Get_list_searchs()[0].get_style() << endl;
			app.Set_work_name(pl.Get_list_searchs()[0].Get_name());
			app.Set_work_lable(pl.Get_list_searchs()[0].Get_lable());
			app.Set_work_style(pl.Get_list_searchs()[0].get_style());
			app.Set_work_author("0");
			pl.Set_cursor(0);
			return true;
		}
		else if ((pl.Get_list_searchs()[0].get_style() == "Fine") || (pl.Get_list_searchs()[0].get_style() == "Teach")) {
			cout << "Играет подкаст: " << pl.Get_list_searchs()[0].Get_name() << ". Автор: "
				<< pl.Get_list_searchs()[0].Get_author() << ". Стиль: " << pl.Get_list_searchs()[0].get_style() << endl;
			app.Set_work_name(pl.Get_list_searchs()[0].Get_name());
			app.Set_work_lable("0");
			app.Set_work_style(pl.Get_list_searchs()[0].get_style());
			app.Set_work_author(pl.Get_list_searchs()[0].Get_author());
			pl.Set_cursor(0);
			return true;
		}
		cout << "Нет такого стиля!\n";
		return false;
	}
	cout << "Плейлист пуст!\n";
	return false;
}

//Включает след произведение в плейлисте
bool Turn_next(Application& app, Playlist& pl) {
	if (pl.Get_cursor() + 2 <= pl.Get_list_searchs().size()) {
		pl.Increase_cursor();
		if ((pl.Get_list_searchs()[pl.Get_cursor()].get_style() == "Rock") || (pl.Get_list_searchs()[pl.Get_cursor()].get_style() == "Pop")) {
			cout << "Играет песня: " << pl.Get_list_searchs()[pl.Get_cursor()].Get_name() << ". Лэйбл: "
				<< pl.Get_list_searchs()[pl.Get_cursor()].Get_lable() << ". Стиль: " << pl.Get_list_searchs()[pl.Get_cursor()].get_style() << endl;
			app.Set_work_name(pl.Get_list_searchs()[pl.Get_cursor()].Get_name());
			app.Set_work_lable(pl.Get_list_searchs()[pl.Get_cursor()].Get_lable());
			app.Set_work_style(pl.Get_list_searchs()[pl.Get_cursor()].get_style());
			app.Set_work_author("0");
			return true;
		}
		else if ((pl.Get_list_searchs()[pl.Get_cursor()].get_style() == "Fine") || (pl.Get_list_searchs()[pl.Get_cursor()].get_style() == "Teach")) {
			cout << "Играет подкаст: " << pl.Get_list_searchs()[pl.Get_cursor()].Get_name() << ". Автор: "
				<< pl.Get_list_searchs()[pl.Get_cursor()].Get_author() << ". Стиль: " << pl.Get_list_searchs()[pl.Get_cursor()].get_style() << endl;
			app.Set_work_name(pl.Get_list_searchs()[pl.Get_cursor()].Get_name());
			app.Set_work_lable("0");
			app.Set_work_style(pl.Get_list_searchs()[pl.Get_cursor()].get_style());
			app.Set_work_author(pl.Get_list_searchs()[pl.Get_cursor()].Get_author());
			return true;
		}
		pl.Reduce_cursor();
		cout << "Нет такого стиля!\n";
		return false;
	}
	cout << "Конец плейлиста!\n";
	return false;
}

//Включение муз произведений
bool Play_thing(Application& app, Playlist& pl) {
	string change;
	cout << "'onmusic' - Включить музыку   'offmusic' - Выключить музыку\n";
	cout << "'onpodcast' - Включить подкаст   'offpodcast' - Выключить подкаст\n";
	cout << "'onplaylist' - Включить плейлист   'next' - Следующее произведение в плейлисте\n";
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
		cout << "Некорректные данные!\n";
		return false;
	}
	return false;
}

void Main_menu(Application& app, Playlist& pl, Settings& settings) {
	string change;
	while (true) {
		cout << "'on' - Включить приложение\n";
		cout << "'off' - Выключить приложение\n";
		cout << "'volume' - Работа со звуком\n";
		cout << "'thing' - Работа с произведениями\n";
		cout << "'settings' - Работа с настройками\n";
		cout << "'play' - Включить произведенине\n";
		cout << "'exit' - Выход\n";
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
			cout << "Нельзя работать при выключенном приложении!\n";
			continue;
		}
		else if (change == "thing") {
			if (app.Get_state() == true) {
				Work_mus_thing(app, pl);
				continue;
			}
			cout << "Нельзя работать при выключенном приложении!\n";
			continue;
		}
		else if (change == "settings") {
			if (app.Get_state() == true) {
				Work_settings(settings);
				continue;
			}
			cout << "Нельзя работать при выключенном приложении!\n";
			continue;
		}
		else if (change == "play") {
			if (app.Get_state() == true) {
				Play_thing(app, pl);
				continue;
			}
			cout << "Нельзя работать при выключенном приложении!\n";
			continue;
		}
		else if (change == "exit") {
			return;
		}
		else {
			cout << "Некорректные данные!\n";
			continue;
		}

	}
}