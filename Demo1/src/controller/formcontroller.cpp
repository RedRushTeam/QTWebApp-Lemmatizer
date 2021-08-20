/**
  @file
  @author Stefan Frings
*/

#include "formcontroller.h"
#include <iostream>
#include <QRegExp>
#include <re2.h>

FormController::FormController()
{}

void FormController::prepare_lemmatizer()
{
    const char* dict_path = NULL;
    const char* language = "russian";

    if (dict_path == NULL)
        dict_path = LEMADR;

    int flags = FLAGS;

    std::cout << std::endl << "Loading the lemmatizator from: " << dict_path << "\n";

    FormController::lemmas_engine = sol_LoadLemmatizatorA(dict_path, flags);

    if (lemmas_engine == NULL)
    {
        std::cout << "Could not load the lemmatizator from: " << dict_path << " With flag: " << flags << "\n";
        system("pause");
        exit(1);
    }
}

void FormController::service(HttpRequest& request, HttpResponse& response)
{
    response.setHeader("Content-Type", "text/html; charset=utf-8");


    if (request.getParameter("action")=="show")
    {

        response.write("<html><body>");
        response.write("<title>Лемматизация</title>");
        response.write("<form method=\"post\">");
        response.write("<input type=\"hidden\" name=\"action\" value=\"second_show\">");

        response.write("<center><h1>ОНЛАЙН-ЛЕММАТИЗАЦИЯ<h1><center><center><p><font size=\"1\"> <font><p><center><center>");

        response.write("<textarea style=\"height:200px; width:500px;\" name=\"input\" placeholder=\"Введите текст\" autofocus></textarea>");

        auto input_string = QString(QString(request.getParameter("input")).toUtf8());
        auto input_string_as_std = QString(QString(request.getParameter("input")).toUtf8()).toStdString();

        std::string wrapped_pattern_for_symbols = "[^А-Яа-я ]+";
        RE2::Options opt_for_symbols;
        opt_for_symbols.set_log_errors(false);
        opt_for_symbols.set_case_sensitive(false);
        opt_for_symbols.set_encoding(re2::RE2::Options::Encoding::EncodingLatin1);
        RE2 re2_for_symbols(wrapped_pattern_for_symbols, opt_for_symbols);

        std::string wrapped_pattern_for_spaces = "( {2,})+";
        RE2::Options opt_for_spaces;
        opt_for_spaces.set_log_errors(false);
        opt_for_spaces.set_case_sensitive(false);
        opt_for_spaces.set_encoding(re2::RE2::Options::Encoding::EncodingLatin1);
        RE2 re2_for_spaces(wrapped_pattern_for_spaces, opt_for_spaces);

        RE2::GlobalReplace(&input_string_as_std, re2_for_symbols, " ");
        RE2::GlobalReplace(&input_string_as_std, re2_for_spaces, " ");

        input_string = QString::fromStdString(input_string_as_std);

        auto only_words = input_string.split(" ");

        for(auto& obj : only_words){
            char utf8[128];
            sol_GetLemma8(FormController::lemmas_engine, obj.toStdString().c_str(), utf8, sizeof(utf8));
            obj = QString(utf8);
        }
        QByteArray data_for_write = "<textarea name=\"output\" style=\"height:200px; width:500px;\" readonly=\"readonly\">";

        for(int i = 0; i < only_words.size(); ++i)
            data_for_write.append(QString(only_words[i] + " "));

        data_for_write.append("</textarea><center>");

        response.write(data_for_write);

        response.write("<center><p><font size=\"1\"> <font><p><center><input type=\"submit\" name=\"one more\" value=\"Отправить\" style=\"height:100px; width:200px; font-size:20px\">");
        response.write("<center><p><font size=\"4\" color=\"black\" face=\"Times New Roman\">Сервис онлайн-лемматизации текстов позволяет получить начальные формы всех встреченных слов. <wbr>Все символы, не являющиеся кириллическими, будут удалены.<font><p><center>");
        response.write("<center><p><font size=\"5\" color=\"red\" face=\"Arial\">место для рекламы :)<font><p><center>");
        response.write("<center><p><font size=\"3\" color=\"black\" face=\"Times New Roman\">Автор библиотеки лемматизации: <a href=\"https://github.com/Koziev\" target=\"_blank\">Илья Козиев</a> <font><p><center>");
        response.write("<center><p><font size=\"3\" color=\"black\" face=\"Times New Roman\">Авторы микросервиса и обёртки: <a href=\"https://github.com/RedRushTeam\" target=\"_blank\">Александр Селиванов</a>, <a href=\"https://github.com/aylhttd\" target=\"_blank\">Дмитрий Андреев</a> <font><p><center>");
        response.write("<center><p><font size=\"2\" color=\"gray\" face=\"Times New Roman\">онлайн лемматизация бесплатно онлайн-лемматизация начальная форма слово русский язык терм словоформа текст текстовый анализ лса алгоритм лемма лемматизатор<font><p><center>");
        response.write("</form>");
        response.write("</body></html>",true);

    }

    else if (request.getParameter("action")=="second_show")
        {
        response.write("<html><body>");
        response.write("<title>Лемматизация</title>");
        response.write("<form method=\"post\">");
        response.write("<input type=\"hidden\" name=\"action\" value=\"show\">");

        response.write("<center><h1>ОНЛАЙН-ЛЕММАТИЗАЦИЯ<h1><center><center><p><font size=\"1\"> <font><p><center><center>");

        response.write("<textarea style=\"height:200px; width:500px;\" name=\"input\" placeholder=\"Введите текст\" autofocus></textarea>");

        auto input_string = QString(QString(request.getParameter("input")).toUtf8());
        auto input_string_as_std = QString(QString(request.getParameter("input")).toUtf8()).toStdString();

        std::string wrapped_pattern_for_symbols = "[^А-Яа-я ]+";
        RE2::Options opt_for_symbols;
        opt_for_symbols.set_log_errors(false);
        opt_for_symbols.set_case_sensitive(false);
        opt_for_symbols.set_encoding(re2::RE2::Options::Encoding::EncodingLatin1);
        RE2 re2_for_symbols(wrapped_pattern_for_symbols, opt_for_symbols);

        std::string wrapped_pattern_for_spaces = "( {2,})+";
        RE2::Options opt_for_spaces;
        opt_for_spaces.set_log_errors(false);
        opt_for_spaces.set_case_sensitive(false);
        opt_for_spaces.set_encoding(re2::RE2::Options::Encoding::EncodingLatin1);
        RE2 re2_for_spaces(wrapped_pattern_for_spaces, opt_for_spaces);

        RE2::GlobalReplace(&input_string_as_std, re2_for_symbols, " ");
        RE2::GlobalReplace(&input_string_as_std, re2_for_spaces, " ");

        input_string = QString::fromStdString(input_string_as_std);

        auto only_words = input_string.split(" ");

        for(auto& obj : only_words){
            char utf8[128];
            auto tmp = sol_GetLemma8(FormController::lemmas_engine, obj.toStdString().c_str(), utf8, sizeof(utf8));
            obj = QString(utf8);
        }
        QByteArray data_for_write = "<textarea name=\"output\" style=\"height:200px; width:500px;\" readonly=\"readonly\">";

        for(int i = 0; i < only_words.size(); ++i)
            data_for_write.append(QString(only_words[i] + " "));

        data_for_write.append("</textarea><center>");

        response.write(data_for_write);

        response.write("<center><p><font size=\"1\"> <font><p><center><input type=\"submit\" name=\"one more\" value=\"Отправить\" style=\"height:100px; width:200px; font-size:20px\">");
        response.write("<center><p><font size=\"4\" color=\"black\" face=\"Times New Roman\">Сервис онлайн-лемматизации текстов позволяет получить начальные формы всех встреченных слов. <wbr>Все символы, не являющиеся кириллическими, будут удалены.<font><p><center>");
        response.write("<center><p><font size=\"5\" color=\"red\" face=\"Arial\">место для рекламы :)<font><p><center>");
        response.write("<center><p><font size=\"3\" color=\"black\" face=\"Times New Roman\">Автор библиотеки лемматизации: <a href=\"https://github.com/Koziev\" target=\"_blank\">Илья Козиев</a> <font><p><center>");
        response.write("<center><p><font size=\"3\" color=\"black\" face=\"Times New Roman\">Авторы микросервиса и обёртки: <a href=\"https://github.com/RedRushTeam\" target=\"_blank\">Александр Селиванов</a>, <a href=\"https://github.com/aylhttd\" target=\"_blank\">Дмитрий Андреев</a> <font><p><center>");
        response.write("<center><p><font size=\"2\" color=\"gray\" face=\"Times New Roman\">онлайн лемматизация бесплатно онлайн-лемматизация начальная форма слово русский язык терм словоформа текст текстовый анализ лса алгоритм лемма лемматизатор<font><p><center>");
        response.write("</form>");
        response.write("</body></html>",true);

    }

    else
        {
            response.write("<html><body>");

            response.write("<title>Лемматизация</title>");
            response.write("<form method=\"post\">");
            response.write("<input type=\"hidden\" name=\"action\" value=\"show\">");

            response.write("<center><h1>ОНЛАЙН-ЛЕММАТИЗАЦИЯ<h1><center><center><p><font size=\"1\"> <font><p><center><center>");

            response.write("<textarea style=\"height:200px; width:500px;\" name=\"input\" placeholder=\"Введите текст\" autofocus></textarea>");
            response.write("<textarea name=\"output\" style=\"height:200px; width:500px;\" disabled=\"disabled\" placeholder=\"Здесь появится лемматизированный текст\" text-align=\"center\";></textarea><center>");

            response.write("<center><p><font size=\"1\"> <font><p><center><input type=\"submit\" name=\"one more\" value=\"Отправить\" style=\"height:100px; width:200px; font-size:20px\">");
            response.write("<center><p><font size=\"4\" color=\"black\" face=\"Times New Roman\">Сервис онлайн-лемматизации текстов позволяет получить начальные формы всех встреченных слов. <wbr>Все символы, не являющиеся кириллическими, будут удалены.<font><p><center>");
            response.write("<center><p><font size=\"5\" color=\"red\" face=\"Arial\">место для рекламы :)<font><p><center>");
            response.write("<center><p><font size=\"3\" color=\"black\" face=\"Times New Roman\">Автор библиотеки лемматизации: <a href=\"https://github.com/Koziev\" target=\"_blank\">Илья Козиев</a> <font><p><center>");
            response.write("<center><p><font size=\"3\" color=\"black\" face=\"Times New Roman\">Авторы микросервиса и обёртки: <a href=\"https://github.com/RedRushTeam\" target=\"_blank\">Александр Селиванов</a>, <a href=\"https://github.com/aylhttd\" target=\"_blank\">Дмитрий Андреев</a> <font><p><center>");
            response.write("<center><p><font size=\"2\" color=\"gray\" face=\"Times New Roman\">онлайн лемматизация бесплатно онлайн-лемматизация начальная форма слово русский язык терм словоформа текст текстовый анализ лса алгоритм лемма лемматизатор<font><p><center>");
            response.write("</form>");
            response.write("</body></html>",true);

            //style="position: absolute; left: -9999px; width: 1px; height: 1px;"
        }
}

