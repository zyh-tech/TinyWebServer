/*
 * @Author       : mark
 * @Date         : 2020-06-18
 * @copyleft Apache 2.0
 */ 
#include <unistd.h>
#include "server/webserver.h"

int main() {

    /* 开启服务器服务，守护进程 后台运行 */
    //daemon(1, 0); 

    //服务器基础参数配置
    int port = 1316;                //端口
    int trigMode = 3;               //ET模式
    int timeoutMS = 60000;          //超时时间(单位ms)
    bool OptLinger = false;         //优雅退出选项

    /* Mysql配置 */
    int sqlPort = 3306;             
    const char* sqlUser = "root";     
    const  char* sqlPwd = "root";
    const char* dbName = "webserver";

    int connPoolNum = 12;           //连接池数量
    int threadNum = 6;              //线程池数量
    bool openLog = true;            //日志开关
    int logLevel = 1;               //日志等级
    int logQueSize = 1024;          //日志异步队列容量

    WebServer server(
        port, trigMode, timeoutMS, OptLinger,             
        sqlPort, sqlUser, sqlPwd, dbName,
        connPoolNum, threadNum, openLog, logLevel, logQueSize); 
    
    server.Start();
} 
  