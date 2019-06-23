/*
                    GNU GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

 Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
*/
//guzald.c  Copyright (C) 2019  Mardan

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <pthread.h>
#include <sys/wait.h>

#define PID_FILE "/var/run/guzald.pid"

int guzald_running(){
	FILE * pidfile = fopen(PID_FILE,"r");
	pid_t pid;
	int ret ;
	if(!pidfile){
		return 0;
	}
	ret = fscanf(pidfile,"%d",&pid);
	if (ret == EOF && ferror(pidfile) != 0){
		syslog(LOG_INFO,"Error open pid file: %s",PID_FILE);
	}
	fclose(pidfile);
	// 检测进程是否存在
	if (kill(pid,0)){
		syslog(LOG_INFO,"Remove a zombie pid file %s", PID_FILE);
		unlink(PID_FILE);
		return 0;
	}
	return pid;
}

int main(int argc, char const *argv[])
{
	int status;
	pid_t guzal_id;
	openlog("guzal",LOG_CONS | LOG_PID,LOG_LOCAL0);

	if (daemon(0,0)==-1){
		perror("打开守护进程状态");
		syslog(LOG_INFO,"打开守护进程状态");
		exit(-1);
	}
	syslog(LOG_INFO,"Guzal-Aida--->守护进程已启动[%d]",guzal_id);
	if ((guzal_id=fork())<0){
		syslog(LOG_INFO,"Guzal-Aida startup failed.");
		for (int try_count = 0; (guzal_id=fork())<0; try_count++){
			syslog(LOG_INFO,"try to restart the Guzal-Aida a %d time.",try_count);
		}

	}
	closelog();
	status = execlp("/opt/GuzalAida/bin/GuzalAida","GuzalAida",NULL);
	while(1){
		if (guzal_id == 0){
			//status = execlp("./GuzalAida","");
		}else{
			wait(&status);
			syslog(LOG_INFO,"程序状态:%d",status);
		}
	}
	closelog();
	return 0;
}
