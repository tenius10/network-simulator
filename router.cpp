#include "router.h"
using namespace std;

void Router::send(Packet* packet){
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
        cout<<"Router #"<<this->id()<<": forwarding "<<packet->toString()<<"\n";
        nextLink->flow(this, packet);
    }
    else{
        // 목적지로 향하는 링크가 없다면
        cout<<"Router #"<<this->id()<<": no route for "<<packet->toString()<<"\n";
        delete packet;
    }
}