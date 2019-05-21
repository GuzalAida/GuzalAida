#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <syslog.h>
#include <sys/stat.h>


int main(int argc, char const *argv[])
{
	if (daemon(0,0)==-1){
		perror("打开守护进程状态");
		syslog(LOG_INFO,"打开守护进程状态");
		exit(-1);
	}
	syslog(LOG_INFO,"Guzal-Aida--->守护进程已启动");
	while(1){
		sleep(1);
	}
	return 0;
}

int guard(void){
	umask(0);
	perror("重设文件权限掩码");
	pid_t id=fork();
	if (id<0){
		perror("打开守护进程状态");
		exit(-1);
	}else if(id>0){perror("打开守护进程状态");exit(0);}

	setsid();
	signal(SIGCHLD,SIG_IGN);
	if(chdir("/")<0){
		perror("改变为根目录");
		exit(-1);
	}
	close(0);
	close(1);
	close(2);
	// /var/log/syslog
	syslog(LOG_INFO,"Guzal-Aida--->守护进程已启动");
	return 0;
}