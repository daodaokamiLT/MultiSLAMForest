#include "functional_vector.h"

namespace msf_basic
{   
    template <class T>
    int FunctionalVector<T>::Size()
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

    template <class T>
    bool FunctionalVector<T>::Push(T &t)
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

    template <class T>
    const T& FunctionalVector<T>::Top()
    {
        if (size() == 0)
        {
            // printf("the vecque is empty.\n");
            // exit(-1);
            return t_nan;
        }
        return datas_[start_index_];
    }

    template <class T>
    const T& FunctionalVector<T>::Tail()
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

    template <class T>
    void FunctionalVector<T>::Pop_Front()
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

    template <class T>
    void FunctionalVector<T>::Pop_Tail()
    {
        Tail();
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

    template <class T>
    void FunctionalVector<T>::Clear()
    {
        // printf("clearing...\n");
        start_index_ = end_index_ = 0;
        is_init = false;
    }

    template <class T>
    std::string FunctionalVector<T>::ToString()
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
            if (temp_index + 1 > size_)
            {
                temp_index = temp_index - size_;
                if (temp_index < 0)
                {
                    // printf("temp index is error.\n")
                    exit(-1);
                }
            }
            else
            {
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
    template <class T>
    const T& FunctionalVector<T>::Index(int id)
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
}