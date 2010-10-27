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
#include "mushirequest.h"
static void m_showIndex(MushiRequest &request);
static void m_showVersion(MushiRequest &request);
static void m_showConfig(MushiRequest &request);
static void m_receiveCommand(MushiRequest &request);
static void m_script(MushiRequest &request);
static void m_pluginWebRequest(MushiRequest &request);
static size_t url_decode(MushiRequest &request);

#endif
