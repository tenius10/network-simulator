
#include "link.h"
#include "node.h"

void Link::onReceive(Node* srcNode, Packet* packet){
    Node* destNode=other(srcNode);

    log("packet in: "+packet->toString()+" from "+srcNode->toString());
    log("packet out: "+packet->toString()+" to "+destNode->toString());
    
    // 다음 노드에 패킷 전달
    destNode->send(packet);
}
