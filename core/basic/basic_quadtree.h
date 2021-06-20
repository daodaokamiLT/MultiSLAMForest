#pragma once
/**
 * 
 * @brief this class cannot managed by pool at first should create a here, and than send managed authur to pool. 
 * 
 * **/
#include "basic_space_geo.h"
#include "basic_node.h"
#include "basic_tree.h"
namespace msf_basic{
    // split space face to quad
    // the range design is [a, b)
    template <class T>
    class QuadNode : public Node<T>{
        public:
            // here has diff with the origin Node type, it has submodule and brothers, we need add method to visited brothers
            // shouldn't set this type interface, we cannot create by ourselves. we should use a point queue to make a tree.
            /*void SetNeighbors(){
                if(!this->neighbors_.empty()){
                    printf("the neighbors is not empty, is it has been setted ? \n");
                    return;
                }
                if(!father_){
                    printf("error, the father hasn't set, is still nullptr.\n");
                    exit(-1);
                }
                if(node_type_ == -1){
                    printf("error, current node_type hasn't decided...\n");
                    exit(-1);
                }
                const final int neighb_size = 4; 
                neighbors_.reserve(neighb_size);
                double x_mid = father_->max_range_.GetMidX();
                double y_mid = father_->max_range_.GetMidY();
                double x_len = father_->max_range_.GetLenX();
                double y_len = father_->max_range_.GetLenY();
                double subx_mid_values[4] = {x_mid - x_len / 2.0, x_mid + x_len / 2.0, x_mid - x_len / 2.0, x_mid + x_len /2.0 };
                double suby_mid_values[4] = {y_mid - y_len / 2.0, y_mid - y_len / 2.0, y_mid + y_len / 2.0, y_mid + y_len /2.0 };
                for(int i=0; i<neighb_size; ++i){
                    subx_mid_values[i], 
                }
            }*/
        protected:
            // the father is unique element, every element must just has one father element.
            QuadNode* father_ = nullptr;
            range2dd_t max_range_;
            // char must be 0, 1
            //              2, 3
            // 4 means the node is root, no brother
            // -1 means hasn't init
            char node_type_ = -1;
            std::vector<int> containedpoint_indexes_;
    };

    typedef class QuadNode<range2dd_t> QuadNode2D;

    template <class T, class D>
    class QuadTree : Tree<QuadNode<T>, QuadNode<T>>{
        public:
            // this points should ordered, first.
            QuadTree() = default;
            QuadTree(const std::vector<point2_t<D>>& point2ds);
            void CreateQuadTree(std::vector<point2_t<D>>& xmin_preorder, std::vector<point2_t<D>>& ymin_preorder);
            void CreateQuadTree();
        protected:
            range2dd_t max_range_; // the range is the [min_point_x, max_point_x) and [min_point_x, max_point_x)  
            range2dd_t mini_range_;// min range is mini cell should be.
            std::vector<point2_t<D>> contained_points_xminpreordered_;
            std::vector<point2_t<D>> contained_points_yminpreordered_;
        private:
            void Preordered(const std::vector<point2_t<D>>& point2ds);
            void ClearQuadTree();
            
    };
    typedef QuadTree<range2dd_t, float> QuadTree2D;
}

#include "basic_quadtree.cpp"