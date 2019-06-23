/*
                    GNU GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

 Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
*/
//GuzalAida.c  Copyright (C) 2019  Mardan
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>

void EXIT(int signo);
void logo();


int main(int argc, char const *argv[]){
	openlog("GuzalAida",LOG_CONS | LOG_PID,LOG_LOCAL0);
	syslog(LOG_INFO,"启动GuzalAida状态:[ %s ]","OK");
	logo();
	signal(SIGINT,EXIT);
	while(1){
		sleep(1);
	}
	closelog();
	return 0;
}

void EXIT(int signo) {
    syslog(LOG_INFO,"退出GuzalAida状态:[ %s ]","OK");
    _exit(0);
}

void logo(){
printf("\t\t***********------> 参与贡献人员： Mardan & 1101@418 <------***********\n\
\t\t********---> Particpating Contributors: Mardan & 1101@418 <---********\n\n\
\t\t\t  -----> Michael\'s Blog: www.michaeltan9999.com <-----\n\
\t\t\t     -----> LJIJCJ\'s Blog: www.LJIJCJ.top <-----\n\
\t\t\t\t-----> https://www.mardan.wiki <-----\n\n\
                                          ,,                    ,,        ,,           \n\
  .g8\"\"\"bgd                             `7MM          db        db      `7MM            \n\
.dP'     `M                               MM         ;MM:                 MM            \n\
dM'       ``7MM  `7MM  M\"\"\"MMV  ,6\"Yb.    MM        ,V^MM.    `7MM   ,M\"\"bMM   ,6\"Yb.   \n\
MM           MM    MM  '  AMV  8)   MM    MM       ,M  `MM      MM ,AP    MM  8)   MM   \n\
MM.    `7MMF'MM    MM    AMV    ,pm9MM    MM mmmmm AbmmmqMA     MM 8MI    MM   ,pm9MM   \n\
`Mb.     MM  MM    MM   AMV  , 8M   MM    MM      A'     VML    MM `Mb    MM  8M   MM   \n\
  `\"bmmmdPY  `Mbod\"YML.AMMmmmM `Moo9^Yo..JMML.  .AMA.   .AMMA..JMML.`Wbmd\"MML.`Moo9^Yo. \n\
\n\n\t\t*************************---> GuzalAida <---*************************\n\n");
}
