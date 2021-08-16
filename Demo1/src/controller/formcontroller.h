/**
  @file
  @author Stefan Frings
*/

#ifndef FORMCONTROLLER_H
#define FORMCONTROLLER_H

#include "httprequest.h"
#include "httpresponse.h"
#include "httprequesthandler.h"

//lemmatizator include
#include <lemmatizator_engine.h>

//lemmatizer prop
constexpr auto LEMADR = "C:\\RGD\\RussianGrammaticalDictionary\\bin-windows64\\lemmatizer.db";
constexpr int FLAGS = LEME_DEFAULT;

using namespace stefanfrings;

/**
  This controller displays a HTML form and dumps the submitted input.
*/


class FormController : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(FormController)
public:

    /** Constructor */
    FormController();

    /** Preparing lematizer */
    static void prepare_lemmatizer();

    /** Generates the response */
    void service(HttpRequest& request, HttpResponse& response);

private:
    static inline HLEM lemmas_engine;
};

#endif // FORMCONTROLLER_H
