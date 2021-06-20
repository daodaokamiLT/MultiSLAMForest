#include <iostream>
#include "../basic/basic_node.h"
#include "../basic/basic_tree.h"
#include "../basic/basic_quadtree.h"

int main(int argc, char* argv[]){
    msf_basic::QuadTree2D quadtree;
    std::vector<msf_basic::point2d_t> points;
    points.emplace_back(msf_basic::point2d_t(0,0));

    quadtree.CreateQuadTree(points, points);
    return 0;
}