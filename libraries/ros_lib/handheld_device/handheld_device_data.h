#ifndef _ROS_handheld_device_handheld_device_data_h
#define _ROS_handheld_device_handheld_device_data_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Accel.h"

namespace handheld_device
{

  class handheld_device_data : public ros::Msg
  {
    public:
      typedef int64_t _device_distance_type;
      _device_distance_type device_distance;
      typedef geometry_msgs::Quaternion _device_quat_type;
      _device_quat_type device_quat;
      typedef geometry_msgs::Accel _device_accel_type;
      _device_accel_type device_accel;
      typedef int64_t _device_switch_type;
      _device_switch_type device_switch;

    handheld_device_data():
      device_distance(0),
      device_quat(),
      device_accel(),
      device_switch(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_device_distance;
      u_device_distance.real = this->device_distance;
      *(outbuffer + offset + 0) = (u_device_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_device_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_device_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_device_distance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_device_distance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_device_distance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_device_distance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_device_distance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->device_distance);
      offset += this->device_quat.serialize(outbuffer + offset);
      offset += this->device_accel.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_device_switch;
      u_device_switch.real = this->device_switch;
      *(outbuffer + offset + 0) = (u_device_switch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_device_switch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_device_switch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_device_switch.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_device_switch.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_device_switch.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_device_switch.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_device_switch.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->device_switch);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_device_distance;
      u_device_distance.base = 0;
      u_device_distance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_device_distance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_device_distance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_device_distance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_device_distance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_device_distance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_device_distance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_device_distance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->device_distance = u_device_distance.real;
      offset += sizeof(this->device_distance);
      offset += this->device_quat.deserialize(inbuffer + offset);
      offset += this->device_accel.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_device_switch;
      u_device_switch.base = 0;
      u_device_switch.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_device_switch.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_device_switch.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_device_switch.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_device_switch.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_device_switch.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_device_switch.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_device_switch.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->device_switch = u_device_switch.real;
      offset += sizeof(this->device_switch);
     return offset;
    }

    const char * getType(){ return "handheld_device/handheld_device_data"; };
    const char * getMD5(){ return "894e9b259d1d4e8448e9e2d9ffed9851"; };

  };

}
#endif
