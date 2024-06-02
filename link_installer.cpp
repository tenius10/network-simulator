#include "link_installer.h"

// 노드 a, b 사이에 링크를 설치하고 반환한다.
Link* LinkInstaller::install(Node *a, Node *b){
    Link* link=new Link(a, b);
    a->links_.emplace_back(link);
    b->links_.emplace_back(link);
    return link;
}
