
#include "basic_quadtree.h"
#include <algorithm>

namespace msf_basic{

    template <class T, class D>
    QuadTree<T, D>::QuadTree(const std::vector<point2_t<D>>& point2ds){
        Preordered();
        CreateQuadTree();
    }


    template <class T, class D>
    void QuadTree<T, D>::Preordered(const std::vector<point2_t<D>>& point2ds){
        if(point2ds.empty()){
            printf("error, point2d is empty.\n");
            exit(-1);
        }
        int pointsize = point2ds.size();
        
        this->contained_points_xminpreordered_.clear();
        this->contained_points_yminpreordered_.clear();
        contained_points_xminpreordered_.assign(point2ds.begin(), point2ds.end());
        contained_points_yminpreordered_.assign(point2ds.begin(), point2ds.end());
        std::sort(contained_points_xminpreordered_.begin(), contained_points_xminpreordered_.end(), Compare_XMinPreOrdered2);
        std::sort(contained_points_yminpreordered_.begin(), contained_points_yminpreordered_.end(), Compare_YMinPreOrdered2);
        max_range_.x_max = contained_points_xminpreordered_[pointsize - 1];
        max_range_.x_min = contained_points_xminpreordered_[0];

        max_range_.y_max = contained_points_yminpreordered_[pointsize -1];
        max_range_.y_min = contained_points_yminpreordered_[0];
    }

    template <class T, class D>
    void QuadTree<T, D>::CreateQuadTree(){
        std::array<range2d_t<D>, 4> subranges;
        max_range_.Split2FourRange(subranges);
    }

    template <class T, class D>
    void QuadTree<T, D>::CreateQuadTree(std::vector<point2_t<D>>& xmin_preorder, std::vector<point2_t<D>>& ymin_preorder){
        if(xmin_preorder.size() != ymin_preorder.size() || xmin_preorder.empty()){
            printf("error, cannot create any thing, please make the two params is same size and not empty.\n");
            exit(-1);
        }
        ClearQuadTree();
        contained_points_xminpreordered_.assign(xmin_preorder.begin(), xmin_preorder.end());
        contained_points_yminpreordered_.assign(ymin_preorder.begin(), ymin_preorder.end());
        int pointsize = xmin_preorder.size();

        max_range_.x_max = contained_points_xminpreordered_[pointsize - 1].x;
        max_range_.x_min = contained_points_xminpreordered_[0].x;

        max_range_.y_max = contained_points_yminpreordered_[pointsize -1].y;
        max_range_.y_min = contained_points_yminpreordered_[0].y;
        
        CreateQuadTree();
    }
    
    template <class T, class D>
    void QuadTree<T, D>::ClearQuadTree(){
        contained_points_xminpreordered_.clear();
        contained_points_yminpreordered_.clear();
        // note that here created datas should be managed as a vector to make manger easily.
        this->Grant();
        this->Clear();
        this->Deny();
    }

}