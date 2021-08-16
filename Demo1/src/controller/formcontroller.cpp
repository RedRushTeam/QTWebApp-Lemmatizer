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
        response.write("<form method=\"post\">");
        response.write("  <input type=\"hidden\" name=\"action\" value=\"show\">");
        response.write("<textarea name=\"name\" cols=\"100\" rows=\"10\" placeholder=\"input text\"></textarea>");

        response.write("<html><body>");
        response.write("<form method=\"post\">");
        response.write("<input type=\"hidden\" name=\"action\" value=\"show\">");

        auto input_string = QString(QString(request.getParameter("name")).toUtf8());
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
        QByteArray data_for_write = "<textarea name=\"name\" cols=\"100\" rows=\"10\" readonly=\"readonly\">";

        for(int i = 0; i < only_words.size(); ++i)
            data_for_write.append(QString(only_words[i] + " "));

        data_for_write.append("</textarea>");

        response.write(data_for_write);

        response.write("<input type=\"submit\"> ");
        response.write("</form>");
        response.write("</body></html>",true);
    }
    else
    {
        response.write("<html><body>");
        response.write("<form method=\"post\">");
        response.write("<input type=\"hidden\" name=\"action\" value=\"show\">");

        response.write("<textarea name=\"name\" cols=\"100\" rows=\"10\" placeholder=\"input text\" autofocus></textarea>");
        response.write("<textarea name=\"city\" padding=\"100\" cols=\"100\" rows=\"10\" disabled=\"disabled\" placeholder=\"output text\"></textarea>");

        response.write("<input type=\"submit\"> ");
        response.write("</form>");
        response.write("</body></html>",true);

    }
}

