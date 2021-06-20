#pragma once

#include "../forest/multislamtree.h"

namespace msf_manager{
    template <class T>
    class TreePool{
        public:

        protected:
            std::vector<msf::MultiSlam_Tree<T>> multislam_trees_; 
    };
}