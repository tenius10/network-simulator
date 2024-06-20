#include "packet_sink_service.h"

PacketSinkService::PacketSinkService(Host *host, short port):Service(host, port){}

void PacketSinkService::onReceive(Packet* packet){
    log("received total "+std::to_string(totalByte_)+" bytes");
}

void PacketSinkService::initialize(int port){
    port_=port;
    totalByte_=0;
}