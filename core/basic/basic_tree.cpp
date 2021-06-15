#include "basic_tree.h"

namespace msf_basic
{
    template <class T, class D>
    bool Tree<T, D>::Visited_byQue(Node<T> *node_ptr)
    {
        return true;
    }

    template <class T, class D>
    bool Tree<T, D>::Visited_byStack(Node<T> *node_ptr)
    {
        return true;
    }

    template <class T, class D>
    bool Tree<T, D>::Visited_exbyQue(Node<T> *node_ptr)
    {
        return true;
    }

    template <class T, class D>
    bool Tree<T, D>::Visited_exbyStack(Node<T> *node_ptr)
    {
        return true;
    }
    template <class T, class D>
    void Tree<T, D>::Clear(){
        printf("clear tree start.\n");
        // print clear local trees. if wanted to delete global trees, should at forest.
        
    }
}