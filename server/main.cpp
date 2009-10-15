

#ifdef _WIN32
#include <windows.h>
#include <winsvc.h>
#define DIRSEP			'\\'
#define	snprintf		_snprintf
#if !defined(__LCC__)
#define	strdup(x)		_strdup(x)
#endif /* !MINGW */
#define	pause()			Sleep(INT_MAX)
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




#ifdef _WIN32
static SERVICE_STATUS		ss; 
static SERVICE_STATUS_HANDLE	hStatus; 
static char			service_name[20];

static void WINAPI
ControlHandler(DWORD code) 
{ 
	if (code == SERVICE_CONTROL_STOP || code == SERVICE_CONTROL_SHUTDOWN) {
		ss.dwWin32ExitCode = 0; 
		ss.dwCurrentState = SERVICE_STOPPED; 
	} 
	
	SetServiceStatus(hStatus, &ss);
}

static void WINAPI
ServiceMain(void) 
{
	char path[MAX_PATH], *p, *av[] = {"mushiServer", NULL, NULL};
	struct mg_context *ctx;
	
	av[1] = path;
	
	ss.dwServiceType      = SERVICE_WIN32; 
	ss.dwCurrentState     = SERVICE_RUNNING; 
	ss.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
	
	hStatus = RegisterServiceCtrlHandler(service_name, ControlHandler);
	SetServiceStatus(hStatus, &ss); 
	
	GetModuleFileName(NULL, path, sizeof(path));
	
	if ((p = strrchr(path, DIRSEP)) != NULL)
		*++p = '\0';
	
	strcat(path, CONFIG_FILE);	/* woo ! */
	
	Sleep(3000);
	if ((ctx = mg_start()) != NULL) {
		process_command_line_arguments(ctx, av);
		
		while (ss.dwCurrentState == SERVICE_RUNNING)
			Sleep(1000);
		mg_stop(ctx);
	}
	
	ss.dwCurrentState  = SERVICE_STOPPED; 
	ss.dwWin32ExitCode = (DWORD) -1; 
	SetServiceStatus(hStatus, &ss); 
}

static void
try_to_run_as_nt_service(void)
{
	static SERVICE_TABLE_ENTRY service_table[] = {
		{service_name, (LPSERVICE_MAIN_FUNCTION) ServiceMain},
		{NULL, NULL}
	};
	
	if (StartServiceCtrlDispatcher(service_table))
		exit(EXIT_SUCCESS);
}
#endif /* _WIN32 */





int main(int argc, char *argv[])
{
QCoreApplication application(argc,argv);
#if defined(_WIN32)
	(void) sprintf(service_name, "%s %s",MUSHI_SERVER_NAME, MUSHI_SERVER_VERSION);
	try_to_run_as_nt_service();


	//set up signal handlers

#endif /* _WIN32 */
	
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
		sleep(500);
	}
	/* Probably unreached, because we will be killed by a signal */
	
	return (EXIT_SUCCESS);
}
