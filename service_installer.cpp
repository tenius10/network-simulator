#include "service_installer.h"

// 호스트와 서비스 사이의 관계를 설정한다.
void ServiceInstaller::install(Host *host, Service *service){
    // 호스트의 서비스 목록에 새 서비스를 등록
    host->services_.emplace_back(service);
}