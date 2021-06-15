#pragma once

#include <vector>
#include "../forest/multislamnode.h"

namespace msf_manager{
    class NodePool{
        public:
            
        protected:
            std::vector<msf::MultiSlam_Node> multislam_nodes_; 
    };
}