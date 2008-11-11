/*
 *  URLHandlers.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/6/08.
 *
 */
#ifndef URLHANDLERS
#define URLHANDLERS
void m_showIndex(struct shttpd_arg *);
void m_showVersion(struct shttpd_arg *arg);
void m_showConfig(struct shttpd_arg *arg);
void m_receiveCommand(struct shttpd_arg *arg);


#endif