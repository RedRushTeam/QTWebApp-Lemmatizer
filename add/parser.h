#pragma once
#include "sparce_container_class.h"

class parser
{
public:
	//parser() {}
	/*std::reference_wrapper<*/fs::path/*>*/ _filename;
	string text_to_change;
	parser(fs::path filename) : _filename(filename) {}
	parser(string _text) :text_to_change(_text) {}
	static void prepair_stop_words();
	shared_ptr<list<string>> parse();
	void set_filename(fs::path filename);
	fs::path get_filename() const;
	void print_all_words(string text);
	shared_ptr<list<string>> delete_trash();

	~parser() {}

//private:
	
	static inline unordered_set<string> stop_words/* = {
"�-��",
"���",
"����",
"���������",
"����",
"�",
"������",
"�����",
"�����",
"�����",
"������",
"���",
"��",
"��������",
"�����",
"������",
"�������",
"������",
"�������",
"������",
"�������",
"�����",
"����������",
"���",
"���-����",
"��",
"��",
"������",
"�������",
"��",
"��-��",
"��-���",
"��-����",
"�������",
"���",
"�",
"�������",
"����������",
"��",
"�����",
"���",
"�����",
"����",
"��",
"�������",
"�������",
"���������",
"���",
"����",
"�����",
"������",
"�����",
"�������",
"���������",
"���������",
"����������",
"���������",
"���������",
"��������",
"����������",
"������",
"��������",
"�",
"��",
"���",
"����",
"�����",
"�����",
"������",
"������",
"������",
"�����",
"������",
"������",
"��",
"������������",
"���",
"�����",
"������",
"��",
"��-��",
"��-���",
"��-���",
"�������",
"������",
"���",
"�����",
"����",
"�������",
"������",
"������",
"�������",
"������",
"������",
"������",
"�������",
"��������",
"��������",
"����������",
"��������",
"��������",
"�����",
"�������",
"���������",
"�����������",
"����",
"�����",
"����",
"������",
"���",
"���",
"������",
"��������",
"������",
"��������",
"�������",
"����",
"�����",
"�",
"�����",
"������",
"�����",
"������",
"������",
"�����",
"������",
"������",
"�����",
"��",
"��������",
"������",
"�����",
"�����",
"������",
"��������",
"�",
"�����",
"������",
"����",
"�",
"�����",
"�����-����",
"���",
"����",
"��",
"����",
"������",
"�����",
"��",
"���",
"�����",
"�����",
"�",
"����",
"�����",
"��",
"����",
"�������",
"����",
"��",
"���",
"���",
"���-���",
"�����",
"����",
"���� ��",
"��",
"��-����",
"�����",
"��",
"��",
"�����",
"�����-��",
"����",
"���",
"��",
"�������������",
"�������",
"�����",
"�����",
"��������",
"��������",
"���",
"����",
"���",
"�",
"��",
"�",
"���",
"���",
"������",
"����",
"��",
"����",
"����",
"���",
"���",
"���",
"�������",
"���",
"�������",
"����",
"�����",
"�������",
"��",
"���",
"����",
"�����",
"��",
"���",
"��",
"��-���",
"�������",
"������ ��",
"������",
"������",
"��������",
"��",
"��-�",
"������",
"�������",
"���",
"���-���",
"����",
"������",
"�������",
"����",
"�������",
"������",
"������",
"�����",
"�����",
"��",
"�����",
"������",
"�����",
"������",
"��",
"��-��",
"��-�",
"������",
"������",
"��������",
"����",
"��������",
"��-��������",
"����",
"�������",
"����������",
"����",
"�����",
"�������",
"������",
"������",
"������",
"������-��������",
"����",
"�����",
"������",
"�����",
"�����",
"�����",
"����������",
"��",
"��",
"��-��",
"������",
"������",
"����������",
"�������",
"����������",
"���",
"����",
"����",
"��-�",
"��-��",
"����",
"����",
"������",
"������",
"������",
"����-����",
"���",
"�����",
"�����",
"����",
"���",
"�������",
"������",
"����",
"����",
"����",
"��������",
"��-��",
"�������",
"����",
"����",
"����",
"����-��������",
"����",
"������",
"����",
"���",
"���-��",
"����",
"�����",
"����-��",
"����",
"���",
"���",
"����",
"��",
"����",
"���",
"�����",
"�",
"���",
"��",
"����",
"��",
"��",
"���",
"���",
"���",
"���",
"��",
"���",
"�����",
"���������",
"��",
"����",
"�����",
"����",
"�������",
"��",
"��-����",
"����������",
"���",
"���-��",
"��",
"����",
"����",
"������",
"������",
"����",
"����",
"���",
"�����",
"�����",
"����",
"���",
"����",
"������",
"����",
"�����",
"������",
"�",
"�/���",
"���",
"���",
"���",
"������",
"����",
"�����",
"�����",
"����",
"���",
"����",
"����",
"���",
"��� ��",
"���-��",
"�����",
"�����",
"�����",
"�����",
"�����",
"�����",
"����",
"����",
"�������",
"����",
"��",
"����",
"����",
"��",
"�",
"���������",
"������",
"������",
"��",
"����",
"�����",
"��",
"�����",
"������",
"������",
"������",
"������",
"��������",
"������",
"������",
"�������",
"����",
"��������",
"���������",
"������",
"��������",
"��������",
"������",
"������",
"������",
"������",
"���������",
"����",
"��������",
"������",
"�����",
"������",
"������",
"����",
"������",
"������",
"������",
"������",
"������",
"�����",
"�����",
"���",
"�����",
"�����",
"������",
"�������",
"�������������",
"������",
"�������",
"�����",
"��",
"���",
"����",
"������",
"����",
"����",
"����",
"���",
"��",
"���",
"����",
"�����",
"����",
"����",
"�����",
"���",
"�����"
	}*/;
};
