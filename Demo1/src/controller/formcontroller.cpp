/**
  @file
  @author Stefan Frings
*/

#include "formcontroller.h"
#include <iostream>
#include <QRegExp>

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
        std::cout << "Could not load the lemmatizator from: " << dict_path << " With flag: " << flags << endl;
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
        QRegExp reg_for_symbl("[^А-Яа-я ]+");
        input_string.replace(reg_for_symbl, " ");

        QRegExp reg_for_letters("( {2,})+");
        input_string.replace(reg_for_letters, " ");

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
        response.write("<center><p><font size=\"3\" color=\"black\" face=\"Arial\">Сервис онлайн-лемматизации текстов позволяет получить начальные формы всех встреченных слов. <wbr>Все символы, не являющиеся кириллическими, будут удалены.<font><p><center>");
        response.write("<center><p><font size=\"5\" color=\"red\" face=\"Arial\">место для рекламы :)<font><p><center>");
        response.write("<center><p><font size=\"2\" color=\"gray\" face=\"Arial\">онлайн лемматизация онлайн-лемматизация начальная форма слово русский язык терм словоформа текст текстовый анализ лса алгоритм лемма лемматизатор<font><p><center>");
        response.write("</form>");
        response.write("</body></html>",true);;
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
        QRegExp reg_for_symbl("[^А-Яа-я ]+");
        input_string.replace(reg_for_symbl, " ");

        QRegExp reg_for_letters("( {2,})+");
        input_string.replace(reg_for_letters, " ");

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
        response.write("<center><p><font size=\"3\" color=\"black\" face=\"Arial\">Сервис онлайн-лемматизации текстов позволяет получить начальные формы всех встреченных слов. <wbr>Все символы, не являющиеся кириллическими, будут удалены.<font><p><center>");
        response.write("<center><p><font size=\"5\" color=\"red\" face=\"Arial\">место для рекламы :)<font><p><center>");
        response.write("<center><p><font size=\"2\" color=\"gray\" face=\"Arial\">онлайн лемматизация онлайн-лемматизация начальная форма слово русский язык терм словоформа текст текстовый анализ лса алгоритм лемма лемматизатор<font><p><center>");
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
            response.write("<center><p><font size=\"3\" color=\"black\" face=\"Arial\">Сервис онлайн-лемматизации текстов позволяет получить начальные формы всех встреченных слов. <wbr>Все символы, не являющиеся кириллическими, будут удалены.<font><p><center>");
            response.write("<center><p><font size=\"5\" color=\"red\" face=\"Arial\">место для рекламы :)<font><p><center>");
            response.write("<center><p><font size=\"2\" color=\"gray\" face=\"Arial\">онлайн лемматизация онлайн-лемматизация начальная форма слово русский язык терм словоформа текст текстовый анализ лса алгоритм лемма лемматизатор<font><p><center>");
            response.write("</form>");
            response.write("</body></html>",true);

            //style="position: absolute; left: -9999px; width: 1px; height: 1px;"
        }
}

