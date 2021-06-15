#pragma once

#include "multislamtree.h"
#include "../basic/basic_tree.h"

namespace msf{

template <class T, class D>
class MultiSlam_Forest : public msf_basic::Tree<MultiSlam_Tree<T>, MultiSlam_Tree<D>>{
    private: 
        unsigned long long multislam_forest_id_ = 0ll;
};

}

#include "multislamforest.cpp"