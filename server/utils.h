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
#include <QTextStream>

std::string uID();

char *getPostBody(char *);
std::string replaceOnce(
						std::string result, 
						const std::string& replaceWhat, 
						const std::string& replaceWithWhat);
std::string dbin(std::string str);

QString getFileContents(QString filename);
void precompileMJS(QString &script);

#endif
