#ifndef PACKET_SINK_SERVICE_H
#define PACKET_SINK_SERVICE_H

#include "service.h"
#include <string>

class PacketSinkService : public Service {
  friend class PacketSinkServiceInstaller;

private:
  int totalByte_;

  PacketSinkService(Host *host, short port);

  std::string name(){ return "PacketSinkService"; }

public:
  ~PacketSinkService(){}

  void onReceive(Packet* packet);

  // 포트를 설정한다.
  void initialize(int port);
};

#endif