#pragma once

// use the array to manage the lockedsize array
#include <vector>

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

        int size();
        bool push(T &t);
        T &top();  

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


/**
 * 
 * #pragma once

#include <array>
#include <iostream>
#include <string>

template <class T, size_t N>
class ArrQue
{
private:
    std::array<T, N> datas_;
    int size_ = N;
    int start_index_ = 0;
    int end_index_ = 0;
    bool is_init = false;
    T t_nan;
public:
    ArrQue() = default;
    int size()
    {
        if (end_index_ + 1 % size_ == start_index_)
        {
            return size_ - 1;
        }
        else if (end_index_ == start_index_)
        {
            // 要么初始化要么full
            if (is_init)
            {
                printf("has initied. will not ocurred this state.\n");
                exit(-1);
            }
            return 0;
        }
        else
        {
            if (end_index_ > start_index_)
            {
                return end_index_ - start_index_;
            }
            else
            {
                int s0 = size_ - start_index_;
                int s1 = end_index_;
                return s0 + s1;
            }
        }
    }

    bool push(T &t)
    {
        if (!is_init)
        {
            datas_[end_index_] = t;
            ++end_index_;
            is_init = true;
            // printf("inited and start index is %d. end index is %d.\n", start_index_, end_index_);
            return true;
        }
        if (size() == size_ - 1)
        {
            // printf("the vecque is fulled.\n");
            return false;
        }

        datas_[end_index_] = t;
        end_index_ = (end_index_ + 1) % size_;
        // printf("start index is %d. end index is %d.\n", start_index_, end_index_);
        return true;
    }

    T &top()
    {
        if (size() == 0)
        {
            // printf("the vecque is empty.\n");
            // exit(-1);
            return t_nan;
        }
        return datas_[start_index_];
    }

    
    T &tail()
    {
        if (size() == 0)
        {
            // printf("the vecque is empty.\n");
            // exit(-1);
            T t;
            return t_nan;
        }
        int temp_end_index = (end_index_ - 1 + size_) % size_;
        return datas_[temp_end_index];
    }

    
    bool pop_front()
    {
        top();
        if (size() == 1)
        {
            clear();
            return true;
        }
        else
        {
            int temp_start_index = (start_index_ + 1) % size_;
            start_index_ = temp_start_index;
        }
        return true;
    }

    
    bool pop_back()
    {
        tail();
        // printf("start index %d, end index %d.\n", start_index_, end_index_);
        if (size() == 1)
        {
            clear();
            return true;
        }
        else
        {
            int temp_end_index = (end_index_ - 1 + size_) % size_;
            end_index_ = temp_end_index;
            return true;
        }
    }

    void clear()
    {
        // printf("clearing...\n");
        start_index_ = end_index_ = 0;
        is_init = false;
    }

    std::string toString()
    {
        std::string str = "";
        if (size() == 0)
        {
            return str + "empty";
        }
        int counter = size();
        int temp_index = start_index_;
        int count = 0;
        while (true)
        {
            T &t = datas_[temp_index];
            str += t.toString();
            str += "\n";
            if(temp_index + 1 > size_){
                temp_index = temp_index - size_;
                if(temp_index < 0){
                    // printf("temp index is error.\n")
                    exit(-1);
                }
            }
            else{
                temp_index = temp_index + 1;
            }
            
            if (count == counter - 1)
            {
                break;
            }
            count++;
        }
        return str;
    }

    T &index(int i)
    {
        int counter = size();
        if (i >= counter)
        {
            // printf("index i bigger than contained size.\n");
            exit(-1);
        }
        int temp_index = start_index_;
        int count = 0;
        while (true)
        {
            T &t = datas_[temp_index];
            temp_index = (temp_index + 1) % size_;
            if (count == i)
            {
                return t;
            }
            count++;
            if (count >= counter)
            {
                // printf("error. the count is error");
                exit(-1);
            }
        }
    }

    bool popVecUntil(int i){
        T& t = index(i);
        int count = 0;
        for(; count<i; count++){
            pop_front();
        }
        if(&top() == &t)
            return true;
        else{
            // printf("pop until is error.\n");
            exit(-1);
        }
    }

};
 * 
*/