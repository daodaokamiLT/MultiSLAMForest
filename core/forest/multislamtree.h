#pragma once
#include "multislamnode.h"
#include "../basic/basic_node.h"
namespace msf{
    template <class T>
    class MultiSlam_Tree : msf_basic::Tree<MultiSlam_Node, T>{
        private:
            unsigned long long multislam_tree_id_;
    };

}

#include "multislamtree.cpp"