#include "manual_router.h"

// 목적지 주소에 따른 다음 링크를 설정한다.
void ManualRouter::addRoutingEntry(const Address &destination, Link *nextLink){
    routingTable_.emplace_back(RoutingEntry {destination, nextLink});
}