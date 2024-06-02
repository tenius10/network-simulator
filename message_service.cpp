#include "message_service.h"

// 메시지를 전송한다
void MessageService::send(std::string message){
    // transport layer에서 packet을 생성해서 network layer로 내려보냄
    Packet* packet=new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(packet);   
}

void MessageService::receive(Packet* packet){
    std::cout<<"MessageService: received \""<<packet->dataString()<<"\" from "<<packet->srcAddress().toString()<<":"<<std::to_string(packet->srcPort())<<"\n";
    delete packet;
}

// 포트를 설정한다.
void MessageService::initialize(int port){
    port_=port;
}

