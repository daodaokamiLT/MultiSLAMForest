#pragma once

// use the array to manage the lockedsize array
#include <vector>
#include <string>
// cannot use ptr
// forbiden to use a array ptr as T
namespace msf_basic{
template <class T>
class FunctionalVector{
    public:
        FunctionalVector(const int containedSize = 100):datas_(containedSize+1){
            if(is_ptr_){
                nan_ = nullptr;   
            }
        }
        ~FunctionalVector(){
            if(is_ptr_){
                for(auto& d : datas_){
                    delete d;
                }
            }
            datas_.clear();
            start_index_ = 0;
            end_index_ = 0;
        }
        int Size();      // return currnt valid size
        bool Push(T &t); // push data in
        const T& Top();  // return a shallow copu
        T Top();         // return a depth copy

        const T& Tail();
        T Tail();
        void Pop_Front();
        void Pop_Tail();
        void Clear();
        const T& Index(int id);
        T Index(int id);

        std::string ToString();

    private:
        std::vector<T> datas_;
        int start_index_ = 0;
        int end_index_ = 0;
        // start_index + 1 == end_index is full
        // start_index == end_index no data
        T nan_; // 只要默认构造函数的都可以判断
        bool is_ptr_ = std::is_pointer(T);
};
}

#include "functional_vector.cpp"

