#pragma once

namespace msf_basic{
typedef double slamres_number_t; 
class SlamModel{
    virtual bool ProcessDatas() = 0;
    virtual bool RegistResultCallback() = 0;
    virtual void UnregistCallback() = 0; 
};


}
