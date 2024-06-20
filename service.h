#ifndef SERVICE_H
#define SERVICE_H

#include "node.h"

class Host;

class Service : public Object {
  friend class ServiceInstaller;

protected:
  // 서비스가 설치된 호스트
  Host *host_;

  // 서비스가 사용하는 포트
  short port_;

  Service(Host *host, int port) : host_(host), port_(port) {}

public:
  virtual ~Service(){}

  short port(){ return port_; }

  // transport layer로부터 packet을 수신한다.
  virtual void onReceive(Packet* packet);
  
  // 애플리케이션 포트를 설정한다.
  virtual void initialize(int port);
};

#endif