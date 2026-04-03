#include<time.h>
#include"tool.h"
#include<string.h>

//将time_t类型转换为字符串，字符串格式为“年-月-日 时：分”
void timeToString(time_t t, char* pBuf) {
	struct tm pTimeInfo;
	localtime_s(&pTimeInfo,&t);
	strftime(pBuf, 20, "%Y-%m-%d %H:%M", &pTimeInfo);
}