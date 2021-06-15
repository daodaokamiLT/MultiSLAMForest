#pragma once

#include "../forest/multislamnode.h"

namespace msf_manager{
    template <class T, class D>
    class ForestPool{
        public:
            
        protected:
            std::vector<msf::MultiSlam_Forest<T, D>> multislam_forest_; 
    };
}