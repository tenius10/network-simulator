
#include <iostream>
#include "link.h"
using namespace std;

void Link::flow(Node* srcNode, Packet* packet){
    Node* destNode=other(srcNode);
    int srcId=srcNode->id();
    int destId=destNode->id();

    cout<<"Link: forwarding packet from node #"<<srcId<<", to node #"<<destId<<"\n";
    
    // 라우터에게 패킷 전달
    destNode->send(packet);
}
