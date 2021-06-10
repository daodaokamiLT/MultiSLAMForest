#pragma once
#include <string>
#include <array>
#include <memory>

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

enum DEVICE_TYPE{
    UnSure = -1,
    Cam = 0,
    Imu = 1
    // Odom = 2
    // and so on ...
};

enum CAM_MODEL{
    UnSure = -1,
    RadiaTan = 0,
    Equi = 1, // also means kb4
    DoubleShpere = 2
};

enum IMU_MODEL{
    UnSure = -1,
    Mems = 0
};

struct hard_device{
    int device_type = -1;
    int set_id = -1;
    int device_id = -1;
    unsigned long long timestamp = 0ll;
    long long offset_timestamp = 0ll; // may +1 or -1
};

struct hard_device_params{
    std::string device_name = "";
    std::string infos = ""; 
};
// notice that the image data should change image to other struct, like cv::Mat, can we change the controller from the cam_t to a single image.
struct cam_t : public hard_device{
    std::shared_ptr<unsigned char> image = nullptr;
    std::shared_ptr<cam_params_t>  sparams_ptr = nullptr;
};

struct cam_params_t : hard_device_params{
    int width = 0, height = 0;
    CAM_MODEL model;
    // RadiaTan: fx, fy, cx, cy, d0, d1, d2, d3, d4
    // Equi: fx, fy, cx, cy, d0, d1, d2, d3
    // DoubleShpere: fx, fy, cx, cy, xi, alpha
    std::array<basic_number_t, 9> params;
    std::array<basic_number_t, 7> T_bc;
};

struct imu_t : public hard_device{
    std::shared_ptr<imu_params_t> sparams_ptr = nullptr;
    std::array<basic_number_t, 9> gyro_calib_matrix;
    std::array<basic_number_t, 9> accl_calib_matrix;
    std::array<basic_number_t, 9> magi_calib_matrix;
};

struct imu_params_t : hard_device_params{
    std::array<basic_number_t, 3> gyro_bias;
    std::array<basic_number_t, 3> accl_bias;
    std::array<basic_number_t, 3> magi_bias;
    std::array<basic_number_t, 5> temperature_model;
    std::array<basic_number_t, 7> T_bi;
    std::array<basic_number_t, 4> sigma;
};

}