//
// Created by Yuqi Zhou on 2021/7/4.
//

#ifndef TOPK_DPB_POOL_H_
#define TOPK_DPB_POOL_H_
#include "../../Util/Util.h"

class OrderedList;

namespace DPB {
//static TYPE_ENTITY_LITERAL_ID INVALID_PREDICATE = -1;
struct element{
  union Identity {
    TYPE_ENTITY_LITERAL_ID node;
    OrderedList* pointer;
  };
  Identity identity;
  unsigned int index;
  double cost;
  bool operator<(const element &other) const {return this->cost < other.cost;}
};

using  Pool = std::vector<element>;

/**
 * sequence in DP-B/DP-P ,slightly different from the paper
 * it starts from zero, A initial seq in a Dynamic Trie is like '0-0-0'
 */
using  sequence =  std::vector<unsigned int>;

// For FQ heap
struct FqElement{
 public:
  sequence seq;
  double cost;
  bool operator<(const FqElement& other) const {return this->cost < other.cost;}
  FqElement() = default;
};

using  ePool = std::vector<FqElement>;
};

#endif //TOPK_DPB_POOL_H_
