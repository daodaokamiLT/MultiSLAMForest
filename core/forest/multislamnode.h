#pragma once

#include "../basic/basic_type.h"
#include <memory>
#include <vector>
#include "../basic/basic_node.h"
namespace msf{
    class MultiSlam_Node : public msf_basic::Node<msf_basic::hard_device_t>{
        private: 
            unsigned long long multislam_node_id_;
    };

    
}