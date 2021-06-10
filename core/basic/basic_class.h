#pragma once

#include <vector>
#include <memory>
#include "basic_type.h"
#include <functional>

namespace msf_basic{
typedef double slamres_number_t; 


class slammodel_t{
    virtual bool ProcessDatas(std::shared_ptr<hard_device>& data) = 0; // device process data by the data.device_type switch device_type: case 0, case 1 ....
    // return data by callback
    virtual bool RegistResultCallback() = 0;
    virtual void UnregistCallback() = 0;

};


}
