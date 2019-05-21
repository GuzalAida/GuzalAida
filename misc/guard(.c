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