#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <ros.h>
#include <sensor_msgs/Imu.h>
#include <handheld_device/handheld_device_data.h>
#include <std_msgs/String.h>

#define BNO055_SAMPLERATE_DELAY_MS (10)

ros::NodeHandle nh;
handheld_device::handheld_device_data handheld_device_data;
ros::Publisher Handheld_device("Handheld_device",&handheld_device_data);
Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup(void)
{ 
  nh.initNode(); 
  nh.advertise(Handheld_device);
  Serial.begin(57600);
  //Serial.println("Orientation Sensor Test");
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print(F("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!"));
    while(1);
  }
  delay(500);
}
void loop(void)
{
  imu::Quaternion quat = bno.getQuat();
  imu::Vector<3> linaccel = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
  handheld_device_data.device_quat.x = quat.x();
  handheld_device_data.device_quat.y = quat.y();
  handheld_device_data.device_quat.z = quat.z();
  handheld_device_data.device_quat.w = quat.w();
  handheld_device_data.device_accel.linear.x = linaccel(0);
  handheld_device_data.device_accel.linear.y = linaccel(1);
  handheld_device_data.device_accel.linear.z = linaccel(2);
  
  Handheld_device.publish(&handheld_device_data);
  nh.spinOnce();
  delay(BNO055_SAMPLERATE_DELAY_MS);
  //Serial.print("In Loop");
}
