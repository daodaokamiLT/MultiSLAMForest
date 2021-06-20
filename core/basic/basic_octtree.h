#pragma once

#include "basic_node.h"
#include "basic_tree.h"
#include "basic_space_geo.h"

namespace msf_basic{
    // can used for 2d or 3d    
    // split space to cube
    template <class T>
    class OctNode : public Node<T>{
        public:

        protected:
            std::vector<unsigned long long> containedpoint_indexes_; // or has the index of earch nodes, just visited by the rootcontained index  
    };
    // the range3dd_t is every node space, points should add to this 
    typedef OctNode<range3dd_t> OctNode3D;

    template <class T, class D>
    class OctTree : Tree<OctNode<T>, OctNode<T>>{
        public:
            
        protected:
            // T should change to has the data type to has range.
            range3dd_t mini_range_;// the mini space in the octNode.
            std::vector<point3_t<D>> contained_points_;
    };

    typedef OctTree<range3dd_t, float> OctTree3D;
}   

#include "basic_octtree.cpp"