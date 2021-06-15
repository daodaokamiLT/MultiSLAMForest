#pragma once

#include <string>
#include <array>

/**
 * 
 * these params must has a common body coordiante.
 * body, camera, imu ... and so on.
 * also has a system timestamp, 
 * the cam timestmap is 100000000, offset_timestamp is 100, so the camera_timestamp = 100000000 + 100;
 *                                                      or -50 so the camera_timestamp = 100000000 - 50;    
*/
namespace msf_basic{

typedef double basic_number_t;

struct Object{
    Object() = default;
    Object(bool sd):shallowdelete(sd){}
    void Deny(){shallowdelete = false;}
    void Grant(){shallowdelete = true;}
    bool shallowdelete = false;
};
enum DEVICE_TYPE{
    UNSure_Dev = -1,
    Cam = 0,
    Imu = 1
    // Odom = 2
    // and so on ...
};

enum CAM_MODEL{
    UNSure_Cam = -1,
    RadiaTan = 0,
    Equi = 1, // also means kb4
    DoubleShpere = 2
};

enum IMU_MODEL{
    UNSure_Imu = -1,
    Mems = 0
};

struct hard_device_t : Object{
    int device_type = -1;
    int set_id = -1;
    int device_id = -1;
    unsigned long long timestamp = 0ll;
    long long offset_timestamp = 0ll; // may +1 or -1
    hard_device_t() = default;
    hard_device_t(bool shallowdel):Object(shallowdel){}  
    
};

struct hard_device_params_t{
    std::string device_name = "";
    std::string infos = ""; 
};
// notice that the image data should change image to other struct, like cv::Mat, can we change the controller from the cam_t to a single image.
struct cam_params_t : hard_device_params_t{
    int width = 0, height = 0;
    CAM_MODEL model;
    // RadiaTan: fx, fy, cx, cy, d0, d1, d2, d3, d4
    // Equi: fx, fy, cx, cy, d0, d1, d2, d3
    // DoubleShpere: fx, fy, cx, cy, xi, alpha
    std::array<basic_number_t, 9> params;
    std::array<basic_number_t, 7> T_bc;
};


struct cam_t : public hard_device_t{
    unsigned char* image = nullptr;
    cam_params_t*  params_ptr = nullptr;
    cam_t(bool shallowdel):hard_device_t(shallowdel){}
    ~cam_t(){
        if(!shallowdelete){
            if(image)
                delete[] image;
            if(params_ptr)
                delete[] params_ptr;
        }
            
        image = nullptr;
        params_ptr = nullptr;
    }
};

struct imu_params_t : hard_device_params_t{
    std::array<basic_number_t, 3> gyro_bias;
    std::array<basic_number_t, 3> accl_bias;
    std::array<basic_number_t, 3> magi_bias;
    std::array<basic_number_t, 5> temperature_model;
    std::array<basic_number_t, 7> T_bi;
    std::array<basic_number_t, 4> sigma;
};

struct imu_t : public hard_device_t{
    imu_params_t* params_ptr = nullptr;
    std::array<basic_number_t, 9> gyro_calib_matrix;
    std::array<basic_number_t, 9> accl_calib_matrix;
    std::array<basic_number_t, 9> magi_calib_matrix;
    imu_t(bool shallowdel):hard_device_t(shallowdel){}
    ~imu_t(){
        if(!shallowdelete){
            if (params_ptr)
                delete params_ptr;
        }
        params_ptr = nullptr;
    }    
};


enum LINK_TYPE{
    Isolate = -1,
    Weak = 0,
    Strong = 1,
    Constant = 2,
    Adaptor = 3
};



class msf_element_t{
    protected:
        unsigned long long uni_id_ = 0ll;
};


template <class T>
struct nodelink_t : Object{
    LINK_TYPE link_type = LINK_TYPE::Isolate;
    T* node_ptr = nullptr;
    nodelink_t() = default;
    nodelink_t(bool shallowdel):Object(shallowdel){}
    nodelink_t(T* n, LINK_TYPE& type, bool shallowdel):node_ptr(n), link_type(type), Object(shallowdel){}
    ~nodelink_t(){
        if(!shallowdelete){
            if(node_ptr)
                delete node_ptr;
        }
        node_ptr = nullptr;
    }
};
/**------------------            the high level dataclass           --------------------**/
typedef double slamres_number_t; 
class slammodel_t{
    virtual bool ProcessDatas(hard_device_t* data) = 0; // device process data by the data.device_type switch device_type: case 0, case 1 ....
    // return data by callback
    virtual bool RegistResultCallback() = 0;
    virtual void UnregistCallback() = 0;
};
}