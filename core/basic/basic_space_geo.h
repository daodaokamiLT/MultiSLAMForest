#pragma once
#include <string>
#include <array>
#include <memory>

namespace msf_basic{
typedef float basicgeo_number_t;

template <class T>
struct point2_t{
    point2_t() = default;
    point2_t(T xx, T yy):x(xx), y(yy){}
    T x, y;
    unsigned long long p_2did = 0ll;
};
typedef point2_t<basicgeo_number_t> point2d_t;

template <class T>
struct point3_t{
    point3_t() = default;
    point3_t(T xx, T yy, T zz):x(xx), y(yy), z(zz){}
    T x, y, z;
    unsigned long long p_3did = 0ll;
};

template struct point3_t<basicgeo_number_t>;
typedef point3_t<basicgeo_number_t> point3d_t;


template <class T> 
struct range2d_t{
    T x_min, y_min;
    T x_max, y_max;
    T GetMidX(){
        return (T)((x_max + x_min)/2.0);
    }
    T GetMidY(){
        return (T)((y_max + y_min)/2.0);
    }
    T GetLenX(){// if max = 10, min = 1, len = 10 - 1 = 9
        return (T)(x_max - x_min);
    }
    T GetLenY(){
        return (T)(y_max - y_min);
    }
    void Split2FourRange(std::array<range2d_t<T>, 4>& subrange){
        T x_mid = GetMidX();
        T y_mid = GetMidY();
        // range ordered by 0, 1, 
        //                  2, 3
        T xflag_values[8] = {x_min, x_mid, x_mid, x_max, x_min, x_mid, x_mid, x_max};
        T yflag_values[8] = {y_min, y_mid, y_min, y_mid, y_mid, y_max, y_mid, y_max};
        for(int i=0; i<4; ++i){
            subrange[i].x_min = xflag_values[2*i];
            subrange[i].x_max = xflag_values[2*i+1];
            subrange[i].y_min = yflag_values[2*i];
            subrange[i].y_max = yflag_values[2*i+1];
        }
    } 
};

template struct range2d_t<basicgeo_number_t>;
typedef range2d_t<basicgeo_number_t> range2dd_t;
template struct range2d_t<int>;
typedef range2d_t<int> range2di_t;

template <class T> 
struct range3d_t{
    T x_min, y_min, z_min;
    T x_max, y_max, z_max;

    T GetMidX(){
        return (T)((x_max + x_min)/2.0);
    }
    T GetMidY(){
        return (T)((y_max + y_min)/2.0);
    }
    T GetMidZ(){
        return (T)((z_max + z_min)/2.0);
    }
    T GetLenX(){
        return (T)(x_max - x_min);
    }
    T GetLenY(){
        return (T)(y_max - y_min);
    }
    T GetLenZ(){
        return (T)(z_max - z_min);
    }
};

template struct range3d_t<basicgeo_number_t>;
typedef range3d_t<basicgeo_number_t> range3dd_t;
template struct range3d_t<int>;
typedef range3d_t<int> range3di_t;

template<class T>
bool Compare_XMinPreOrdered2(const point2_t<T>& p0, const point2_t<T>& p1){
    return p0.x < p1.x;
}
template<class T>
bool Compare_YMinPreOrdered2(const point2_t<T>& p0, const point2_t<T>& p1){
    return p0.y < p1.y;
}
template<class T>
bool Compare_XMaxPreOrdered2(const point2_t<T>& p0, const point2_t<T>& p1){
    return p0.x > p1.x;
}
template<class T>
bool Compare_YMaxPreOrdered2(const point2_t<T>& p0, const point2_t<T>& p1){
    return p0.y > p1.y;
}
template<class T>
bool Compare_ZMinPreOrdered2(const point3_t<T>& p0, const point2_t<T>& p1){
    return p0.z < p0.z;
}

template<class T>
bool Compare_XMinPreOrdered3(const point3_t<T>& p0, const point3_t<T>& p1){
    return p0.x < p1.x;
}
template<class T>
bool Compare_YMinPreOrdered3(const point3_t<T>& p0, const point3_t<T>& p1){
    return p0.y < p1.y;
}
template<class T>
bool Compare_XMaxPreOrdered3(const point3_t<T>& p0, const point3_t<T>& p1){
    return p0.x > p1.x;
}
template<class T>
bool Compare_YMaxPreOrdered3(const point3_t<T>& p0, const point3_t<T>& p1){
    return p0.y > p1.y;
}
template<class T>
bool Compare_ZMinPreOrdered3(const point3_t<T>& p0, const point3_t<T>& p1){
    return p0.z < p0.z;
}
template<class T>
bool Compare_ZMaxPreOrdered3(const point3_t<T>& p0, const point2_t<T>& p1){
    return p0.z > p1.z;
}

}