#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "packet.h"
#include <vector>

class Link;

class Node :public Object{
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;
  virtual std::string name();
  
protected:
  std::vector<Link*> links_;

public:
  virtual ~Node();
  Node() : id_(nextId_++) {}
  int id() const { return id_; }
  virtual void send(Packet* packet);
};

#endif