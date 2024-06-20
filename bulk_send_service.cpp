#include "bulk_send_service.h"
#include <vector>

BulkSendService::BulkSendService(Host *host, Address destAddress, short destPort,
    double delay, double startTime, double stopTime)
        :Service(host, 0), destAddress_(destAddress), destPort_(destPort), delay_(delay), startTime_(startTime), stopTime_(stopTime){}

void BulkSendService::send(){
    log("sending data");
    std::vector<char> message(PACKET_SIZE, 'A');
    Packet* packet=new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(packet);
}

// 스케줄 등록
void BulkSendService::initialize(int port){
    port_=port;
    Simulator::schedule(1.23, [this]() { this->send(); });
    Simulator::schedule(1.36, [this]() { this->send(); });
    Simulator::schedule(1.48, [this]() { this->send(); });
    Simulator::schedule(1.60, [this]() { this->send(); });
    Simulator::schedule(1.73, [this]() { this->send(); });
    Simulator::schedule(1.85, [this]() { this->send(); });
    Simulator::schedule(1.97, [this]() { this->send(); });
    Simulator::schedule(2.09, [this]() { this->send(); });
    Simulator::schedule(2.22, [this]() { this->send(); });
    Simulator::schedule(2.34, [this]() { this->send(); });
}
