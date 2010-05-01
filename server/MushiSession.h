/*
 *  MushiSession.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *
 */
#ifndef MUSHISESSION
#define MUSHISESSION

#include <QObject>

#include "../lib_json/json.h"
#include "MushiDBResult.h"





class MushiSession : public QObject {
Q_OBJECT
public:
        MushiSession(QString id);
        MushiSession(QObject *parent=0);

	void save();
        void load(QString id);
	void load();

	Json::Value data;
    public slots:
        QString getID();
        QString get(QString key);
        void set(QString key, QString value);

private:
		
};



#endif
