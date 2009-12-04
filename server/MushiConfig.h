/*
 *  MushiConfig.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#include <QObject>
#ifndef MUSHICONFIG_H
#define MUSHICONFIG_H
class MushiConfig: public QObject{
    Q_OBJECT
public slots:
        static QString getValue(QString key);
        static int setValue(QString key, QString value,QString description="");
public:
	static void setDefaults();
};
#endif
