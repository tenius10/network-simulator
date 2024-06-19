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
    // EchoService의 포트는 3000으로 고정.
    // 이 포트가 고정되어 있어야 클라이언트 측에서 서버에 요청을 보낼 수 있음.
    port_=3000;
}