#pragma once
#include "math_core.h"
//#include"Server.h"


int main(/*int argc, char* argv[]*/)
{
    
   /* Poco::Net::HTTPServer serv(new  myRequestHandlerFactory, Poco::Net::ServerSocket(8080), new  Poco::Net::HTTPServerParams);
    serv.start();
    while (true);
    serv.stop();*/

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string _result_text;
    getline(cin, _result_text, '~');//last simbol '~'!!
    //SetConsoleOutputCP(65001);
    TCHAR path_to___w[MAX_PATH];//путь к исполняемому файлу
    GetModuleFileName(NULL,path_to___w, MAX_PATH);
    std::wstring temp_path;
    temp_path = path_to___w;

    string path_to___(temp_path.begin(), temp_path.end());
    string path_to_files;
    string path_to_tema;    //то, какая у нас сейчас тематика
    string path_to_file;    //путь к тексту для анализа/текс для анализа
    
    
    path_to_files = path_to___;
   /* string path_file="D:\\test_text.txt";
    path_to_file = path_file;*/
    string path_tema("sport");
    path_to_tema = path_tema;


    path_to___ = path_to___.substr(0, path_to___.rfind("\\"));
    global_var::TEXTS_PATH = path_to___ + "\\rasp";

    global_var::SUPER_PATH = path_to___;

    global_var::LEMADR = path_to___ + "\\lemmatizer.db";
    //cout << global_var::SUPER_PATH;
    //auto start = clock();
    //setlocale(LC_ALL, "ru_RU.UTF-8");
    setlocale(LC_ALL, "Russian");

    //list_of_functions::is_cpp17_possible();
    //list_of_functions::print_info_about_sysyem();

    auto texts = list_of_functions::get_input_texts();
    //cout << endl << endl << "Всего обнаружено " << texts->size() << " текстов." << endl;

    //global_var::TEXTS_PATH = path_to_tema;
    math_core _math_core(texts);
    analyzer::grab_dict(path_to___ + "\\1" + path_to_tema + ".txt");
    _math_core.analyze_one_text(/*path_to_file*/_result_text);
    _math_core.find_SVD_terms(path_to_tema, /*path_to_file*/_result_text);

    cout <<endl<<endl<< analyzer::get_text();
    //auto finish = clock();
    //cout << endl << endl << ">>> " << finish - start << "ms <<<" << endl;
    //system("pause");
    return 0;
}
