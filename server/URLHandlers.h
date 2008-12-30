/*
 *  URLHandlers.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/6/08.
 *
 */
#ifndef URLHANDLERS
#define URLHANDLERS
static void m_showIndex(struct mg_connection *conn, const struct mg_request_info *ri,	 void *user_data);
static void m_showVersion(struct mg_connection *conn, const struct mg_request_info *ri,	 void *user_data);
static void m_showConfig(struct mg_connection *conn, const struct mg_request_info *ri,	 void *user_data);
static void m_receiveCommand(struct mg_connection *conn, const struct mg_request_info *ri,	 void *user_data);


#endif