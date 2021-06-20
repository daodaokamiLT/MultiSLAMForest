#pragma once

#include <vector>
#include "basic_type.h"
/***
 * 
 * design: all ptr is shallowcopy copy
 * in the node or tree, all ptr is shallow copy, 
 * never copy data and manager the elemnt
 * 
 * */ 
namespace msf_basic{
    template <class T>
    class Node{
        public:
            Node() = default;
            Node(T* n):node_ptr_(n){}
            ~Node(){
                for (auto &n : neighbors_)
                {
                    if (n && !shallowdelete_)
                    {
                        delete n;
                    }
                    n = nullptr;
                }
                neighbors_.clear();
                if(!shallowdelete_){
                    if(node_ptr_)
                        delete node_ptr_;
                }
                node_ptr_ = nullptr;
            }

            void AddLinkedNode(nodelink_t<T>* newlink){
                // if(shallowcopy_)
                    neighbors_.emplace_back(newlink);
            }

            void GetNeighbors(std::vector<nodelink_t<T>*>& neighbors){
                if(!neighbors.empty()){
                    printf("warning !!! the neighbors isnot empty (%d).\n", neighbors.size());
                    neighbors.clear();
                    printf("shallow clear the neighbors.\n");
                }
                // if(shallowcopy_)
                    neighbors.assign(neighbors_.begin(), neighbors_.end());
            }
            void GetNeighbors(std::vector<nodelink_t<T>*>& neighbors, const msf_basic::LINK_TYPE& filter_linktype){
                if(!neighbors.empty()){
                    printf("warning !!! the neighbors isnot empty (%d).\n", neighbors.size());
                    neighbors.clear();
                    printf("shallow clear the neighbors.\n");
                }
                // if(shallowcopy_){
                    neighbors.reserve(neighbors_.size());
                    if (filter_linktype == msf_basic::LINK_TYPE::Adaptor)
                    {
                        neighbors.resize(neighbors_.size());
                        for (size_t count_node = 0; count_node < neighbors_.size(); ++count_node)
                        {
                            neighbors[count_node] = neighbors_[count_node]->node_ptr;
                        }
                    }
                    else
                    {
                        for (auto node : neighbors_)
                        {
                            if (node.link_type == filter_linktype)
                            {
                                neighbors.emplace_back(node->node_ptr);
                            }
                        }
                    }
                // }
            }
        protected:
            T* node_ptr_ = nullptr;
            // save the link as ptr, data is not too big.
            std::vector<nodelink_t<T>*> neighbors_;            
            // const final bool shallowcopy_ = true;
            bool shallowdelete_ = true;
    };
}