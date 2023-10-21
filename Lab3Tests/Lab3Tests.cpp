#include "pch.h"
#include "CppUnitTest.h"
#include "../WorkFunctions.h"
#include <sstream>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace LabTest {
	TEST_CLASS(LabTeachPod) {
public:
	TEST_METHOD(Check_getter) {
		TeachPodcast tp("one", "bill", 4);
		string name = "one";
		string author = "bill";
		int length = 4;
		string style = "Teach";
		Assert::AreEqual(name, tp.Get_name());
		Assert::AreEqual(author, tp.Get_author());
		Assert::AreEqual(length, tp.Get_length());
		Assert::AreEqual(style, tp.Get_style());
	}
	};




	TEST_CLASS(LabSettings) {
public:
	TEST_METHOD(Check_getter) {
		Settings set;
		set.Set_shared_access();
		Assert::AreEqual(1, set.Get_access());
		set.Set_group_access();
		Assert::AreEqual(2, set.Get_access());
		set.Set_admin_access();
		Assert::AreEqual(3, set.Get_access());
		set.Set_password("1234");
		string pas = "1234";
		Assert::AreEqual(pas, set.Get_password());
		set.Set_temp_volume(20);
		Assert::AreEqual(20, set.Get_temp_volume());
		set.Set_volume(40);
		Assert::AreEqual(40, set.Get_volume());
		set.Set_username("bill");
		string username = "bill";
		Assert::AreEqual(username, set.Get_username());
	}

	TEST_METHOD(Check_incr_red_vol) {
		Settings set;
		set.Increase_volume(30);
		Assert::AreEqual(60, set.Get_volume());
		set.Reduce_volume(20);
		Assert::AreEqual(40, set.Get_volume());
	}
	};



	TEST_CLASS(LabsSearch) {
public:

	TEST_METHOD(Check_setter_getter) {
		Search s("one", "bill", "black", "rock");
		string name = "one";
		string author = "bill";
		string lable = "black";
		string style = "rock";
		Assert::AreEqual(name, s.Get_name());
		Assert::AreEqual(author, s.Get_author());
		Assert::AreEqual(lable, s.Get_lable());
		Assert::AreEqual(style, s.get_style());
	}
	};





	TEST_CLASS(LabRockMusic) {
public:
	TEST_METHOD(Check_getter_setter) {
		RockMusic rm("one", "black", 4);
		string name = "one";
		string lable = "black";
		int length = 4;
		string style = "Rock";
		Assert::AreEqual(name, rm.Get_name());
		Assert::AreEqual(lable, rm.Get_lable());
		Assert::AreEqual(length, rm.Get_length());
		Assert::AreEqual(style, rm.Get_style());
	}
	};



	TEST_CLASS(LabPopMusic) {
public:
	TEST_METHOD(Check_getter_setter) {
		PopMusic pm("one", "black", 4);
		string name = "one";
		string lable = "black";
		int length = 4;
		string style = "Pop";
		Assert::AreEqual(name, pm.Get_name());
		Assert::AreEqual(lable, pm.Get_lable());
		Assert::AreEqual(length, pm.Get_length());
		Assert::AreEqual(style, pm.Get_style());
	}
	};



	TEST_CLASS(LabPlaylist) {
	public:
		TEST_METHOD(Check_setter_getter) {
			Playlist pl;
			pl.Increase_cursor();
			Assert::AreEqual(1, pl.Get_cursor());
			pl.Reduce_cursor();
			Assert::AreEqual(0, pl.Get_cursor());
			pl.Set_cursor(4);
			Assert::AreEqual(4, pl.Get_cursor());
		}

		TEST_METHOD(Check_list) {
			Playlist pl;
			pl.Add_thing_in_list("first", "bill", "0", "Fine");
			pl.Add_thing_in_list("second", "0", "black", "Pop");
			int num = pl.Get_list_searchs().size();
			Assert::AreEqual(2, num);
			num = pl.Get_number_search("second", "0", "black", "Pop");
			Assert::AreEqual(1, num);
			num = pl.Get_number_search("0", "0", "0", "0");
			Assert::AreEqual(-1, num);
			pl.Del_thing_in_list("first", "bill", "0", "Fine");
			num = pl.Get_list_searchs().size();
			Assert::AreEqual(1, num);
			bool falseres = pl.Check_thing("first", "bill", "0", "Fine");
			bool trueres = pl.Check_thing("second", "0", "black", "Pop");
			Assert::IsFalse(falseres);
			Assert::IsTrue(trueres);
		}
	};



	TEST_CLASS(LabFinePodcast) {
	public:
		TEST_METHOD(Check_setter_getter) {
			FinePodcast fp("one", "bill", 4);
			string name = "one";
			string author = "bill";
			string style = "Fine";
			int length = 4;
			Assert::AreEqual(name, fp.Get_name());
			Assert::AreEqual(author, fp.Get_author());
			Assert::AreEqual(style, fp.Get_style());
			Assert::AreEqual(length, fp.Get_length());
		}
	};



	TEST_CLASS(LabApplication) {
	public:
		TEST_METHOD(Check_setter_getter) {
			Application app;
			app.Set_work_author("bill");
			app.Set_work_lable("black");
			app.Set_work_name("one");
			app.Set_work_style("Rock");
			string author = "bill";
			string lable = "black";
			string name = "one";
			string style = "Rock";
			Assert::AreEqual(author, app.Get_work_author());
			Assert::AreEqual(lable, app.Get_work_lable());
			Assert::AreEqual(name, app.Get_work_name());
			Assert::AreEqual(style, app.Get_work_style());
		}

		TEST_METHOD(Check_turn) {
			Application app;
			app.Turn_on_app();
			Assert::IsTrue(app.Get_state());
			app.Turn_off_app();
			Assert::IsFalse(app.Get_state());
		}

		TEST_METHOD(Check_add_del) {
			Application app;
			app.Add_fine("one", "bill", 4);
			app.Add_pop("one", "black", 4);
			app.Add_rock("one", "black", 4);
			app.Add_teach("one", "bill", 4);
			int num = app.Get_list_fines().size();
			Assert::AreEqual(1, num);
			num = app.Get_list_pops().size();
			Assert::AreEqual(1, num);
			num = app.Get_list_rocks().size();
			Assert::AreEqual(1, num);
			num = app.Get_list_teachs().size();
			Assert::AreEqual(1, num);
			app.Del_fine(0);
			app.Del_pop(0);
			app.Del_rock(0);
			app.Del_teach(0);
			num = app.Get_list_fines().size();
			Assert::AreEqual(0, num);
			num = app.Get_list_pops().size();
			Assert::AreEqual(0, num);
			num = app.Get_list_rocks().size();
			Assert::AreEqual(0, num);
			num = app.Get_list_teachs().size();
			Assert::AreEqual(0, num);
		}

		TEST_METHOD(Check_thing_number) {
			Application app;
			app.Add_fine("one", "bill", 4);
			app.Add_pop("one", "black", 4);
			app.Add_rock("one", "black", 4);
			app.Add_teach("one", "bill", 4);

			Assert::IsTrue(app.Check_fine("one", "bill"));
			Assert::IsFalse(app.Check_fine("0", "0"));
			Assert::IsTrue(app.Check_pop("one", "black"));
			Assert::IsFalse(app.Check_pop("0", "0"));
			Assert::IsTrue(app.Check_rock("one", "black"));
			Assert::IsFalse(app.Check_rock("0", "0"));
			Assert::IsTrue(app.Check_teach("one", "bill"));
			Assert::IsFalse(app.Check_teach("0", "0"));
		}

		TEST_METHOD(Check_get_number) {
			Application app;
			app.Add_fine("one", "bill", 4);
			app.Add_pop("one", "black", 4);
			app.Add_rock("one", "black", 4);
			app.Add_teach("one", "bill", 4);
			int num = app.Get_number_music("one", "black", "Rock");
			Assert::AreEqual(0, num);
			num = app.Get_number_music("0", "0", "Rock");
			Assert::AreEqual(-1, num);

			num = app.Get_number_music("one", "black", "Pop");
			Assert::AreEqual(0, num);
			num = app.Get_number_music("0", "0", "Pop");
			Assert::AreEqual(-1, num);

			num = app.Get_number_music("0", "0", "Rap");
			Assert::AreEqual(-2, num);

			num = app.Get_number_podcast("one", "bill", "Fine");
			Assert::AreEqual(0, num);
			num = app.Get_number_podcast("first", "0", "Fine");
			Assert::AreEqual(-1, num);			

			num = app.Get_number_podcast("one", "bill", "Teach");
			Assert::AreEqual(0, num);
			num = app.Get_number_podcast("0", "0", "Teach");
			Assert::AreEqual(-1, num);

			num = app.Get_number_podcast("0", "0", "Sport");
			Assert::AreEqual(-2, num);

		}
	};





	TEST_CLASS(LabWorkFunctions) {
	public:
		TEST_METHOD(Turn_off_on_app) {
			Application app;
			Assert::IsTrue(Turn_on_app(app));
			Assert::IsFalse(Turn_on_app(app));
			Assert::IsTrue(Turn_off_app(app));
			Assert::IsFalse(Turn_off_app(app));
		}

		TEST_METHOD(Check_inc_volume) {
			Settings set;
			stringstream input;
			input << "inc 20\n";
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			Assert::IsTrue(Work_volume(set));
			input << "inc 60\n";
			Assert::IsFalse(Work_volume(set));
		}

		TEST_METHOD(Check_red_volume) {
			Settings set;
			stringstream input;
			input << "red 20\n";
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			Assert::IsTrue(Work_volume(set));
			input << "red 60\n";
			Assert::IsFalse(Work_volume(set));
		}

		TEST_METHOD(Check_off_on_music) {
			Settings set;
			stringstream input;
			input << "off\n";
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			Assert::IsTrue(Work_volume(set));
			input << "on\n";
			Assert::IsTrue(Work_volume(set));
			input << "volume\n";
			Assert::IsFalse(Work_volume(set));
			cin.rdbuf(origCin);
		}

		TEST_METHOD(Check_add_music) {
			Application app;
			stringstream input;
			input << "one black Rock\n";
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			Assert::IsTrue(Add_music(app));
			input << "one black Pop\n";
			Assert::IsTrue(Add_music(app));
			input << "one black Rap\n";
			Assert::IsFalse(Add_music(app));
			input << "one black Pop\n";
			Assert::IsFalse(Add_music(app));
			cin.rdbuf(origCin);
		}

		TEST_METHOD(Check_del_music) {
			Application app;
			Playlist pl;
			pl.Add_thing_in_list("one", "0", "black", "Rock");
			pl.Add_thing_in_list("one", "0", "black", "Pop");
			stringstream input;
			input << "one black Rock\n";
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			Add_music(app);
			input << "one black Rock\n";
			Assert::IsTrue(Del_music(app, pl));
			input << "one black Pop\n";
			Add_music(app);
			input << "one black Pop\n";
			Assert::IsTrue(Del_music(app, pl));
			input << "one black Rap\n";
			Assert::IsFalse(Del_music(app, pl));
			input << "second black Pop\n";
			Assert::IsFalse(Del_music(app, pl));
			cin.rdbuf(origCin);
		}

		TEST_METHOD(Check_add_podcast) {
			Application app;
			stringstream input;
			input << "one black Fine\n";
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			Assert::IsTrue(Add_podcast(app));
			input << "one black Teach\n";
			Assert::IsTrue(Add_podcast(app));
			input << "one black Rap\n";
			Assert::IsFalse(Add_podcast(app));
			input << "one black Teach\n";
			Assert::IsFalse(Add_podcast(app));
			cin.rdbuf(origCin);
		}

		TEST_METHOD(Check_del_podcast) {
			Application app;
			Playlist pl;
			pl.Add_thing_in_list("one", "black", "0", "Fine");
			pl.Add_thing_in_list("one", "black", "0", "Teach");
			stringstream input;
			input << "one black Fine\n";
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			Add_podcast(app);
			input << "one black Fine\n";
			Assert::IsTrue(Del_podcast(app, pl));
			input << "one black Teach\n";
			Add_podcast(app);
			input << "one black Teach\n";
			Assert::IsTrue(Del_podcast(app, pl));
			input << "one black Rap\n";
			Assert::IsFalse(Del_podcast(app, pl));
			input << "one black Teach\n";
			Assert::IsFalse(Del_podcast(app, pl));
			cin.rdbuf(origCin);
		}

		TEST_METHOD(Check_add_pl_rock) {
			Application app;
			Playlist pl;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "one black Rock\n";
			Add_music(app);
			input << "one Rock black\n";
			Assert::IsTrue(Add_thing_playlist(app, pl));
			input << "one Rock start\n";
			Assert::IsFalse(Add_thing_playlist(app, pl));
		}

		TEST_METHOD(Check_add_pl_pop) {
			Application app;
			Playlist pl;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "one black Pop\n";
			Add_music(app);
			input << "one Pop black\n";
			Assert::IsTrue(Add_thing_playlist(app, pl));
			input << "one Pop start\n";
			Assert::IsFalse(Add_thing_playlist(app, pl));
		}

		TEST_METHOD(Check_add_pl_fine) {
			Application app;
			Playlist pl;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "one black Fine\n";
			Add_podcast(app);
			input << "one Fine black\n";
			Assert::IsTrue(Add_thing_playlist(app, pl));
			input << "one Fine start\n";
			Assert::IsFalse(Add_thing_playlist(app, pl));
		}

		TEST_METHOD(Check_add_pl_teach) {
			Application app;
			Playlist pl;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "one black Teach\n";
			Add_podcast(app);
			input << "one Teach black\n";
			Assert::IsTrue(Add_thing_playlist(app, pl));
			input << "one Teach star\n";
			Assert::IsFalse(Add_thing_playlist(app, pl));
			input << "one Rap star\n";
			Assert::IsFalse(Add_thing_playlist(app, pl));
		}

		TEST_METHOD(Check_del_pl_rock) {
			Application app;
			Playlist pl;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "one black Rock\n";
			Add_music(app);
			input << "one Rock black\n";
			Add_thing_playlist(app, pl);
			input << "one Rock black\n";
			Assert::IsTrue(Del_thing_playlist(app, pl));
			input << "one Rock star\n";
			Assert::IsFalse(Del_thing_playlist(app, pl));
		}

		TEST_METHOD(Check_del_pl_pop) {
			Application app;
			Playlist pl;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "one black Pop\n";
			Add_music(app);
			input << "one Pop black\n";
			Add_thing_playlist(app, pl);
			input << "one Pop black\n";
			Assert::IsTrue(Del_thing_playlist(app, pl));
			input << "one Pop star\n";
			Assert::IsFalse(Del_thing_playlist(app, pl));

		}

		TEST_METHOD(Check_del_pl_fine) {
			Application app;
			Playlist pl;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "one black Fine\n";
			Add_podcast(app);
			input << "one Fine black\n";
			Add_thing_playlist(app, pl);
			input << "one Fine black\n";
			Assert::IsTrue(Del_thing_playlist(app, pl));
			input << "one Fine star\n";
			Assert::IsFalse(Del_thing_playlist(app, pl));
		}

		TEST_METHOD(Check_del_pl_teach) {
			Application app;
			Playlist pl;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "one black Teach\n";
			Add_podcast(app);
			input << "one Teach black\n";
			Add_thing_playlist(app, pl);
			input << "one Teach black\n";
			Assert::IsTrue(Del_thing_playlist(app, pl));
			input << "one Teach star\n";
			Assert::IsFalse(Del_thing_playlist(app, pl));
			input << "one Rap star\n";
			Assert::IsFalse(Del_thing_playlist(app, pl));
		}

		TEST_METHOD(Check_work_mus) {
			Application app;
			Playlist pl;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "amusic one black Rock\n";
			Assert::IsTrue(Work_mus_thing(app, pl));
			input << "dmusic one black Rock\n";
			Assert::IsTrue(Work_mus_thing(app, pl));
			input << "apodcast one black Fine\n";
			Assert::IsTrue(Work_mus_thing(app, pl));
			input << "dpodcast one black Fine\n";
			Assert::IsTrue(Work_mus_thing(app, pl));
			input << "addplaylist one Rock black\n";
			Assert::IsFalse(Work_mus_thing(app, pl));
			input << "delplaylist one Rock black\n";
			Assert::IsFalse(Work_mus_thing(app, pl));
			input << "one\n";
			Assert::IsFalse(Work_mus_thing(app, pl));
		}

		TEST_METHOD(Check_change_pas) {
			Settings set;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "laboratornaya 1234 1234\n";
			Assert::IsTrue(Change_pas(set));
			input << "laboratornaya 1234 123\n";
			Assert::IsFalse(Change_pas(set));
			input << "laboratornay 1234 1234\n";
			Assert::IsFalse(Change_pas(set));
		}

		TEST_METHOD(Check_reset_pas) {
			Settings set;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "laboratornaya 1234 1234\n";
			Change_pas(set);
			input << "1234\n";
			Assert::IsTrue(Reset_pas(set));
			input << "first\n";
			Assert::IsFalse(Reset_pas(set));
		}

		TEST_METHOD(Check_change_username) {
			Settings set;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "laboratornaya Slava\n";
			Assert::IsTrue(Change_username(set));
			input << "laboratornay Slava\n";
			Assert::IsFalse(Change_username(set));
		}

		TEST_METHOD(Check_reset_username) {
			Settings set;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "laboratornaya\n";
			Assert::IsTrue(Reset_username(set));
			input << "laboratornay\n";
			Assert::IsFalse(Reset_username(set));
		}

		TEST_METHOD(Check_change_access) {
			Settings set;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "1\n";
			Assert::IsTrue(Change_access(set));
			input << "2\n";
			Assert::IsTrue(Change_access(set));
			input << "3 laboratornaya\n";
			Assert::IsTrue(Change_access(set));
			input << "3 laboratornay\n";
			Assert::IsFalse(Change_access(set));
			input << "4\n";
			Assert::IsFalse(Change_access(set));
		}

		TEST_METHOD(Check_reset_access) {
			Settings set;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "laboratornaya\n";
			Assert::IsTrue(Reset_access(set));
			input << "laboratornay\n";
			Assert::IsFalse(Reset_access(set));
		}

		TEST_METHOD(Check_work_settings) {
			Settings set;
			stringstream input;
			streambuf* origCin = std::cin.rdbuf(input.rdbuf());
			input << "cpas laboratornaya 1234 1234\n";
			Assert::IsTrue(Work_settings(set));
			input << "rpas 1234\n";
			Assert::IsTrue(Work_settings(set));
			input << "cusername laboratornaya Slava\n";
			Assert::IsTrue(Work_settings(set));
			input << "rusername laboratornaya\n";
			Assert::IsTrue(Work_settings(set));
			input << "caccess 2\n";
			Assert::IsTrue(Work_settings(set));
			input << "raccess laboratornaya\n";
			Assert::IsTrue(Work_settings(set));
			input << "first\n";
			Assert::IsFalse(Work_settings(set));
		}
	};

}
