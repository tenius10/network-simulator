#include "message_service_installer.h"

// 호스트에 MessageService를 설치한다
MessageService* MessageServiceInstaller::install(Host *host){
    MessageService* messageService=new MessageService(host, 0, destAddress_, destPort_);
    ServiceInstaller::install(host, messageService);
    return messageService;
}