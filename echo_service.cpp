#include <iostream>
#include <string>
#include "echo_service.h"

void EchoService::receive(Packet* packet){
    // 패킷을 받아서 출력하고 다시 돌려보냄
    std::cout<<"EchoService: received \""<<packet->dataString()<<"\" from "<<packet->srcAddress().toString()<<":"<<std::to_string(packet->srcPort())<<", send reply with same data\n";
    
    Packet* newPacket=new Packet(packet->destAddress(), packet->srcAddress(), packet->destPort(), packet->srcPort(), packet->data());
    // pakcet을 전달받은 서비스 측에서 메모리 해제
    delete packet;

    host_->send(newPacket);
}

// 포트를 설정한다.
void EchoService::initialize(int port){
    port_=3000;
}