#ifndef _ROS_handheld_device_handheld_device_data_h
#define _ROS_handheld_device_handheld_device_data_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace handheld_device
{

  class handheld_device_data : public ros::Msg
  {
    public:
      typedef int16_t _device_distance_type;
      _device_distance_type device_distance;
      typedef float _quatx_type;
      _quatx_type quatx;
      typedef float _quaty_type;
      _quaty_type quaty;
      typedef float _quatz_type;
      _quatz_type quatz;
      typedef float _quatw_type;
      _quatw_type quatw;
      typedef float _accelx_type;
      _accelx_type accelx;
      typedef float _accely_type;
      _accely_type accely;
      typedef float _accelz_type;
      _accelz_type accelz;
      typedef int8_t _device_switch_type;
      _device_switch_type device_switch;

    handheld_device_data():
      device_distance(0),
      quatx(0),
      quaty(0),
      quatz(0),
      quatw(0),
      accelx(0),
      accely(0),
      accelz(0),
      device_switch(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_device_distance;
      u_device_distance.real = this->device_distance;
      *(outbuffer + offset + 0) = (u_device_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_device_distance.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->device_distance);
      union {
        float real;
        uint32_t base;
      } u_quatx;
      u_quatx.real = this->quatx;
      *(outbuffer + offset + 0) = (u_quatx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quatx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_quatx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_quatx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quatx);
      union {
        float real;
        uint32_t base;
      } u_quaty;
      u_quaty.real = this->quaty;
      *(outbuffer + offset + 0) = (u_quaty.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quaty.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_quaty.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_quaty.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quaty);
      union {
        float real;
        uint32_t base;
      } u_quatz;
      u_quatz.real = this->quatz;
      *(outbuffer + offset + 0) = (u_quatz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quatz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_quatz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_quatz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quatz);
      union {
        float real;
        uint32_t base;
      } u_quatw;
      u_quatw.real = this->quatw;
      *(outbuffer + offset + 0) = (u_quatw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quatw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_quatw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_quatw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quatw);
      union {
        float real;
        uint32_t base;
      } u_accelx;
      u_accelx.real = this->accelx;
      *(outbuffer + offset + 0) = (u_accelx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accelx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accelx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accelx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accelx);
      union {
        float real;
        uint32_t base;
      } u_accely;
      u_accely.real = this->accely;
      *(outbuffer + offset + 0) = (u_accely.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accely.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accely.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accely.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accely);
      union {
        float real;
        uint32_t base;
      } u_accelz;
      u_accelz.real = this->accelz;
      *(outbuffer + offset + 0) = (u_accelz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accelz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accelz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accelz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accelz);
      union {
        int8_t real;
        uint8_t base;
      } u_device_switch;
      u_device_switch.real = this->device_switch;
      *(outbuffer + offset + 0) = (u_device_switch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->device_switch);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_device_distance;
      u_device_distance.base = 0;
      u_device_distance.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_device_distance.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->device_distance = u_device_distance.real;
      offset += sizeof(this->device_distance);
      union {
        float real;
        uint32_t base;
      } u_quatx;
      u_quatx.base = 0;
      u_quatx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quatx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_quatx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_quatx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->quatx = u_quatx.real;
      offset += sizeof(this->quatx);
      union {
        float real;
        uint32_t base;
      } u_quaty;
      u_quaty.base = 0;
      u_quaty.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quaty.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_quaty.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_quaty.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->quaty = u_quaty.real;
      offset += sizeof(this->quaty);
      union {
        float real;
        uint32_t base;
      } u_quatz;
      u_quatz.base = 0;
      u_quatz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quatz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_quatz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_quatz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->quatz = u_quatz.real;
      offset += sizeof(this->quatz);
      union {
        float real;
        uint32_t base;
      } u_quatw;
      u_quatw.base = 0;
      u_quatw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quatw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_quatw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_quatw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->quatw = u_quatw.real;
      offset += sizeof(this->quatw);
      union {
        float real;
        uint32_t base;
      } u_accelx;
      u_accelx.base = 0;
      u_accelx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accelx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accelx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accelx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accelx = u_accelx.real;
      offset += sizeof(this->accelx);
      union {
        float real;
        uint32_t base;
      } u_accely;
      u_accely.base = 0;
      u_accely.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accely.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accely.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accely.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accely = u_accely.real;
      offset += sizeof(this->accely);
      union {
        float real;
        uint32_t base;
      } u_accelz;
      u_accelz.base = 0;
      u_accelz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accelz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accelz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accelz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accelz = u_accelz.real;
      offset += sizeof(this->accelz);
      union {
        int8_t real;
        uint8_t base;
      } u_device_switch;
      u_device_switch.base = 0;
      u_device_switch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->device_switch = u_device_switch.real;
      offset += sizeof(this->device_switch);
     return offset;
    }

    const char * getType(){ return "handheld_device/handheld_device_data"; };
    const char * getMD5(){ return "5f3fc4e797e13ce34dcd40452711b663"; };

  };

}
#endif
