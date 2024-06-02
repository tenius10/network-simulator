#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "packet.h"
#include <vector>

class Link;

class Node {
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;
  
protected:
  std::vector<Link*> links_;

public:
  virtual ~Node(){}
  
  Node() : id_(nextId_++) {}
  int id() const { return id_; }
  virtual void send(Packet* packet){}
};

#endif