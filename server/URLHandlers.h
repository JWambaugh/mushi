/*
 *  URLHandlers.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/6/08.
 *
 */
#ifndef URLHANDLERS
#define URLHANDLERS
#include <QString>
static void m_showIndex(struct mg_connection *conn, const struct mg_request_info *ri,	 void *user_data);
static void m_showVersion(struct mg_connection *conn, const struct mg_request_info *ri,	 void *user_data);
static void m_showConfig(struct mg_connection *conn, const struct mg_request_info *ri,	 void *user_data);
static void m_receiveCommand(struct mg_connection *conn, const struct mg_request_info *ri,	 void *user_data);
static void m_script(struct mg_connection *conn, const struct mg_request_info *ri,void *user_data);
static size_t url_decode(const char *src, size_t src_len, char *dst, size_t dst_len);
static QString getFileContents(QString filename);
#endif
