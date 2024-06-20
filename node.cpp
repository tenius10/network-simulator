
#include "node.h"

int Node::nextId_=0;

Node::~Node(){}

std::string Node::name(){ return "Node"; }

void Node::send(Packet* packet){}