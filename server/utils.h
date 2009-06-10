/*
 *  utils.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.

 *
 */
#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <QFile>
#include <QScriptValue>
#include <QTextStream>
#include "../lib_json/json.h"
std::string uID();

char *getPostBody(char *);
std::string replaceOnce(
						std::string result, 
						const std::string& replaceWhat, 
						const std::string& replaceWithWhat);
std::string dbin(std::string str);

QString getFileContents(QString filename);
void precompileMJS(QString &script);
Json::Value scriptValue2Json(QScriptValue val);
#endif
