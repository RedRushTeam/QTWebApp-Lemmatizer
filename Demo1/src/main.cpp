/**
  @file
  @author Stefan Frings
*/

#include <QCoreApplication>
#include <QDir>
#include "global.h"
#include "httplistener.h"
#include "requestmapper.h"
//lemmatizator include
#include <lemmatizator_engine.h>
#include <iostream>
using namespace stefanfrings;

/** Search the configuration file */
QString searchConfigFile()
{
    QString binDir=QCoreApplication::applicationDirPath();
    QString fileName("Demo1.ini");

    QStringList searchList;
    searchList.append(binDir);
    searchList.append(binDir+"/etc");
    searchList.append(binDir+"/../etc");
    searchList.append(binDir+"/../Demo1/etc"); // for development with shadow build (Linux)
    searchList.append(binDir+"/../../Demo1/etc"); // for development with shadow build (Windows)
    searchList.append(QDir::rootPath()+"etc/opt");
    searchList.append(QDir::rootPath()+"etc");

    foreach (QString dir, searchList)
    {
        QFile file(dir+"/"+fileName);
        if (file.exists())
        {
            fileName=QDir(file.fileName()).canonicalPath();
            qDebug("Using config file %s",qPrintable(fileName));
            return fileName;
        }
    }

    // not found
    foreach (QString dir, searchList)
    {
        qWarning("%s/%s not found",qPrintable(dir),qPrintable(fileName));
    }
    qFatal("Cannot find config file %s",qPrintable(fileName));
    return nullptr;
}
constexpr auto LEMADR = "C:\\RGD\\RussianGrammaticalDictionary\\bin-windows64\\lemmatizer.db";
constexpr int FLAGS = LEME_FASTEST;
/**
  Entry point of the program.
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");

    const char* dict_path = NULL;
    const char* language = "russian";

    if (dict_path == NULL)
        dict_path = LEMADR;

    int flags = FLAGS;

    std::cout << std::endl << "Loading the lemmatizator from: " << dict_path;

    auto lemmas_engine = sol_LoadLemmatizatorA(dict_path, flags);

    /*if (lemmas_engine == NULL)
    {
        std::cout << "Could not load the lemmatizator from: " << dict_path << " With flag: " << flags;
        system("pause");
        exit(1);
    }*/

    QCoreApplication app(argc,argv);
    app.setApplicationName("Demo1");

    // Find the configuration file
    QString configFileName=searchConfigFile();

    // Configure logging into a file
    QSettings* logSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    logSettings->beginGroup("logging");
    FileLogger* logger=new FileLogger(logSettings,10000,&app);
    logger->installMsgHandler();

    // Configure template loader and cache
    QSettings* templateSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    templateSettings->beginGroup("templates");
    templateCache=new TemplateCache(templateSettings,&app);

    // Configure session store
    QSettings* sessionSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    sessionSettings->beginGroup("sessions");
    sessionStore=new HttpSessionStore(sessionSettings,&app);

    // Configure static file controller
    QSettings* fileSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    fileSettings->beginGroup("docroot");
    staticFileController=new StaticFileController(fileSettings,&app);

    // Configure and start the TCP listener
    QSettings* listenerSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    listenerSettings->beginGroup("listener");
    new HttpListener(listenerSettings,new RequestMapper(&app),&app);

    qWarning("Application has started");
    app.exec();
    qWarning("Application has stopped");
}
