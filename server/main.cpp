

#ifdef _WIN32
#include <windows.h>
#include <winsvc.h>
#define DIRSEP			'\\'
#define	snprintf		_snprintf
#if !defined(__LCC__)
#define	strdup(x)		_strdup(x)
#endif /* !MINGW */
//#define	pause()			Sleep(INT_MAX)
#else
#include <sys/wait.h>
#include <unistd.h>		/* For pause() */
#define DIRSEP '/'
#endif /* _WIN32 */




#include <time.h>
#include <errno.h>
#include <signal.h>


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <QCoreApplication>
#include "../shttpd/shttpd.h"
#include "mushiServer.h"


void signalHandler(int signum){
#if !defined(_WIN32)
	if (signum == SIGCHLD) {
		do {
		} while (waitpid(-1, &signum, WNOHANG) > 0);
	} else 
#endif /* !_WIN32 */
	{	
		printf("\nExiting due to signal %d\n",signum);
		exit(EXIT_SUCCESS);
	}
}







int main(int argc, char *argv[])
{
QCoreApplication application(argc,argv);

	
#ifndef _WIN32
	(void) signal(SIGCHLD, signalHandler);
	(void) signal(SIGPIPE, SIG_IGN);
#endif /* _WIN32 */
	

	(void) signal(SIGTERM, signalHandler);
	(void) signal(SIGINT, signalHandler);
	
	
	
	
	MushiServer *server = MushiServer::getInstance();
	server->startup(argc,argv);
	
	/* Serve connections infinitely until someone kills us */
	while(1){
#ifdef _WIN32
            Sleep(500);
#else
		sleep(500);
#endif
            }
	/* Probably unreached, because we will be killed by a signal */
	
	return (EXIT_SUCCESS);
}
