#ifndef ECHO_SERVICE_H
#define ECHO_SERVICE_H

#include "host.h"
#include "service.h"
#include <iostream>
#include <string>

// 수신한 패킷을 전송자에게 다시 전송하는 서비스
class EchoService : public Service {
  friend class EchoServiceInstaller;

private:
  // 출발지 포트
  short srcPort_;

  EchoService(Host *host, short port) : Service(host, port) {}

public: 
  void receive(Packet* packet);

  // 포트를 설정한다.
  void initialize(int port);
};

#endif