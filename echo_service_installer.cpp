#include "echo_service_installer.h"

// 호스트에 EchoService를 설치한다.
EchoService* EchoServiceInstaller::install(Host *host){
    EchoService* echoService=new EchoService(host, listenPort_);
    ServiceInstaller::install(host, echoService);    
    return echoService;
}