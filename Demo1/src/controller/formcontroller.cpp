/**
  @file
  @author Stefan Frings
*/

#include "formcontroller.h"
#include <iostream>

FormController::FormController()
{}

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
        response.write("<textarea name=\"name\" cols=\"100\" rows=\"10\" readonly=\"readonly\">" + QString(request.getParameter("name")).toUtf8() + "</textarea>");

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

