#pragma once
/**
 * 
 * @brief to these created by config files, we can know the number of the nodes, 
 * so the create should be at pool.
 * 
 * 
 * 
*/

// tree he forest hasn't different, just for element scale.
#include <iostream>
#include "basic_node.h"
#include <queue>
#include <stack>

namespace msf_basic{

    // always the root link the next tree, that create a forest
    // Node<Tree<T, D>> use error, Node Tree<T, D>
    template <class T, class D>
    class Tree :public Node<Tree<T, D>>{
        public:
            // can link same type tree
            Tree(){}
            // visited the tree and nodes
            
            //AddLinkedNode extend by the class Node 

            void AddExLinkedNode(nodelink_t<D>* linked_extree){
                exneighbors_.emplace_back(linked_extree);
            }

            void GetExNeighbors(std::vector<D*> exneighbors, const msf_basic::LINK_TYPE& filter_linktype){
                if(!exneighbors.empty()){
                    printf("warning !!! the neighbors isnot empty (%d).\n", exneighbors.size());
                    exneighbors.clear();
                    printf("shallow clear the neighbors.\n");
                }
                if(filter_linktype == msf_basic::LINK_TYPE::Adaptor){
                    exneighbors.assign(exneighbors_.begin(), exneighbors_.end());
                }
                else{
                    for (auto node : exneighbors_)
                    {
                        if (node.link_type == filter_linktype)
                        {
                            exneighbors.emplace_back(node.node_ptr);
                        }
                    }
                }    
            }

            void Clear();
            bool Visited_byQue(Node<T>* node_ptr);
            bool Visited_byStack(Node<T>* node_ptr);
            bool Visited_exbyQue(Node<T>* node_ptr);
            bool Visited_exbyStack(Node<T>* node_ptr);

            void ReturnRoot(){
                ReturnQueRoot();
                ReturnStackRoot();
            }
            void ReturnQueRoot(){
                que_curr_nodeptr = root_ptr_;
            }
            void ReturnStackRoot(){
                stack_curr_nodeptr = root_ptr_;
            }
        public:
        // link other tree method.
            std::stack<Node<T>*> nodesptr_stack;
            std::queue<Node<T>*> nodesptr_que;

            std::stack<Tree<T, D>*> treeptr_stack;
            std::queue<Tree<T, D>*> treeptr_que;

            Node<T>* stack_curr_nodeptr;
            Node<T>* que_curr_nodeptr;
            Tree<T, D>* stack_curr_treeptr;
            Tree<T, D>* que_curr_tree_ptr;

        protected:
            int node_size_ = 0;
            int height_ = 0;
            int width_ = 0;
            bool is_minispainingtree_ = false;
            Node<T>* root_ptr_ = nullptr;

        protected:
            // link other type tree
            std::vector<nodelink_t<D>*> exneighbors_;
            bool manage_permission_ = false;
            void Grant(){manage_permission_ = true;}
            void Deny(){manage_permission_ = false;}
    };
}

#include "basic_tree.cpp"