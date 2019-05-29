

#define SERVER_TIME ServerTime;
#define CONTENT_TYPE ContentType;
#define INDEXHTML "index.html"


typedef struct Requests{
	char *Url;
	char *Method;
	char *StatusCode;
	char *RemoteAddress;
}