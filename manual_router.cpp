#include "manual_router.h"
#include <iostream>
using namespace std;

// 목적지 주소에 따른 다음 링크를 설정한다.
void ManualRouter::addRoutingEntry(const Address &destination, Link *nextLink){
    routingTable_.emplace_back(RoutingEntry {destination, nextLink});
}

void ManualRouter::send(Packet* packet){
    // 다음 목적지 탐색
    Link* nextLink=nullptr;
    int tableSize=routingTable_.size();
    for(int i=0;i<tableSize;i++){
        if(routingTable_[i].destination==packet->destAddress()){
            nextLink=routingTable_[i].nextLink;
            break;
        }
    }

    // 로그 출력
    if(nextLink!=nullptr){
        // 목적지로 향하는 링크가 있다면
        log("forwarding packet: "+packet->toString()+" to "+nextLink->toString());
        nextLink->onReceive(this, packet);
    }
    else{
        // 목적지로 향하는 링크가 없다면
        log("no route for packet: "+packet->toString());
        delete packet;
    }
}