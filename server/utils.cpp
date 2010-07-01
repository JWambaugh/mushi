/*
 *  utils.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *
 */
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "time.h"
#include <unistd.h>
#include <string.h>
#include <QDebug>
#include <QScriptValueIterator>
std::string uID(){
	std::ostringstream str;
	time_t t;
	t=time(&t);
        str << t << rand();
	return str.str();
}


/**
 *Returns the body of a post (stripts headers)
 **/
char *getPostBody(char *search){
	char* found;
        //printf("%s\n",search);
	found=strstr(search, "\r\n");
        //printf("%d", found);
	return search + 4;
}


std::string replaceOnce(
						std::string result, 
						const std::string& replaceWhat, 
						const std::string& replaceWithWhat)
{
	const int pos = result.find(replaceWhat);
	if (pos==-1) return result;
	result.replace(pos,replaceWhat.size(),replaceWithWhat);
	return result;
}

std::string dbin(std::string str){
	int pos=0;
	while((pos= str.find("'", pos))!=-1){
		
		str.replace(pos,1,"''");
		pos+=2;
	}
	return str;
}



QString getFileContents(QString filename){
    QFile scriptFile(filename);
    if (!scriptFile.open(QIODevice::ReadOnly)){
         printf("error loading file\n");
         return "";
     }
    QTextStream stream(&scriptFile);
    QString contents = stream.readAll();
    scriptFile.close();
    return contents;
}


Json::Value scriptValue2Json(QScriptValue val){
    Json::ValueType type;
    type=Json::objectValue;
    if(val.isArray())type=Json::arrayValue;

    Json::Value jVal(type);


    QScriptValueIterator it(val);
    while (it.hasNext()) {
        bool ok;
        it.next();
        if (it.flags() )
         continue;

        std::string name=it.name().toStdString();
    //    qDebug() <<it.name()<<" "<<it.value().toString();
        Json::Value newValue;
        if(it.value().isError()){
             newValue="Error";
             return jVal;
        }
        else if(it.value().isObject()||it.value().isArray()){
   //         qDebug()<<"start call";
            newValue=scriptValue2Json(it.value());
    //        qDebug()<<"end call";
        }
        else if (it.value().isFunction()){
            continue;
        }
        else if(it.value().isString() || it.value().isNumber()||it.value().isBool()) {
            newValue=it.value().toString().toStdString();
        }

        //arrays must be appended to
        if(val.isArray()){
      //      qDebug()<<"appending as array";
            jVal.append(newValue);
        }else{
      //      qDebug()<<"appending as object";
            jVal[name]=newValue;
        }

    }
    return jVal;
}

/*
  Takes a script of output/javascript mixed code and turns it all into javascript.
  Single-pass.
  Script code appears within <??> tags.
  a print shortcut is also supported: <?=value?> [same as <?Mushi.conn.print(value)?>]

  */
void precompileMJS(QString &script){
    QString buffer;
    //QTextStream buffer(&bufferString);
    bool inCode=true;
    int startPos=2; //where the block started

    if(!(script.at(0)=='<' && script.at(1)=='?')){
        buffer.append("Mushi.conn.print('");
        inCode=false;
        startPos=0;
    }

    QChar c;
    QChar quoteChar;
    bool inQuote=false;
    bool printMode=false;
    for(int pos =startPos;pos<script.length();pos++){
        c=script.at(pos);

        if(!inCode && c=='\''){
            buffer.append( "\\'");
        }else if(!inCode && c=='\n'){
            buffer.append("\\n'+\n'");
        }else if(!inCode&&c=='\\'){
            buffer.append("\\\\");
        }else if(inCode && c=='\'' || c== '"'){
            if(inQuote){
                if(c==quoteChar && script.at(pos-1)!='\\')
                    inQuote=false;
            }else{
                inQuote=true;
                quoteChar=c;
            }
            buffer.append(c);
        }
        else if(c=='\r'){//strip carriage returns. nothing but a headache.
            continue;
        }

       else if( c=='<' && pos < script.length()-2 && !inCode  && script.at(pos+1)=='?' ){
            printMode=false;

           inCode = true;
           inQuote=false;
            //make any string we've come to so far to a print and send to buffer
            buffer.append("');\n");
            if(pos<script.length()-3 && script.at(pos+2) == '='){
                printMode=true;
                buffer.append("Mushi.conn.print(");
                pos++;
            }
            pos+=1;

        }else if(c=='?' && !inQuote && pos < script.length()-2 && inCode && script.at(pos+1)=='>' ){
            if(printMode){
                buffer.append(");");
            }
            buffer.append("\nMushi.conn.print('");
            inCode=false;
            pos+=1;
        }else {
            buffer.append(c);
        }

    }
    if(!inCode){
        buffer.append(" ');\n");
    }
    //qDebug()<<buffer;
    script=buffer;


}




