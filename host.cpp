#include <iostream>
#include "host.h"

#include <ctime>
#include <string>
using namespace std;



Host::~Host(){
    int size=services_.size();
    for(int i=0;i<size;i++){
        delete services_[i];
    }
    delete this;
}

// 호스트와 설치된 서비스를 전부 초기화한다.
void Host::initialize(){
    // 호스트 내의 서비스 포트 번호 설정
    int size=services_.size();
    for(int i=0;i<size;i++){
        services_[i]->initialize(nextPort_++);
    }
}

// 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
void Host::send(Packet *packet){ 
    if(packet->destAddress()==address_){
        // 현재 호스트가 패킷의 도착점이면 application layer로 데이터를 올려보냄
        Service* targetService=nullptr;
        int serviceSize=services_.size();
        for(int i=0;i<serviceSize;i++){
            if(services_[i]->port()==packet->destPort()){
                targetService=services_[i];
                break;
            }
        }

        if(targetService!=nullptr){
            // 포트에 맞는 서비스가 있다면
            cout<<"Host #"<<std::to_string(id())<<": received packet, destination port: "<<packet->destPort()<<"\n";
            targetService->receive(packet);
        }
        else{
            // 포트에 맞는 서비스가 없다면
            cout<<"Host #"<<std::to_string(id())<<": no service for "<<packet->toString()<<"\n";
            delete packet;
        }
    }
    else{
        // 현재 호스트가 패킷의 출발점이면 network layer로 패킷을 내려보냄
        if(links_.size()>0){    
            string srcAddr=packet->srcAddress().toString();
            string destAddr=packet->destAddress().toString();
            cout<<"Host #"<<std::to_string(id())<<": sending "<<packet->toString()<<"\n";

            int randIdx=rand()%links_.size();
            links_[randIdx]->flow(this, packet);
        }
    }

    
}