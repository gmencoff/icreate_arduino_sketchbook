/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

// Use the following line if you have a Leonardo or MKR1000 
//#define USE_USBCON 

#include <ros.h>
#include <Wire.h>
#include <LIDARLite.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <EEPROM.h>
#include <handheld_device/handheld_device_data.h>
#include <std_msgs/String.h>

//Set the delay rate between fresh samples
#define BNO055_SAMPLERATE_DELAY_MS (100)

//Initialize the sensors
LIDARLite myLidarLite;
Adafruit_BNO055 bno = Adafruit_BNO055(55);

// store Lidar Reading and lidar reading count
int LidarDistance;
int LidarReadingCount=0;

// store IMU quaternion and accel vector
imu::Quaternion imuQuat;
imu::Vector<3> imuAccel;

//Store Switch Sensor
int laserSwitch=2;

//Create a ros node handle and publish to the desired topic
ros::NodeHandle nh;
handheld_device::handheld_device_data handheld_device_data;
ros::Publisher Handheld_device("Handheld_device",&handheld_device_data);

void displayCalStatus(void)
{
    /* Get the four calibration values (0..3) */
    /* Any sensor data reporting 0 should be ignored, */
    /* 3 means 'fully calibrated" */
    uint8_t system, gyro, accel, mag;
    system = gyro = accel = mag = 0;
    bno.getCalibration(&system, &gyro, &accel, &mag);

    /* The data should be ignored until the system calibration is > 0 */
    //Serial.print("\t");
    if (!system)
    {
        //Serial.print("! ");
    }

    /* Display the individual values */
    //Serial.print("Sys:");
    //Serial.print(system, DEC);
    //Serial.print(" G:");
    //Serial.print(gyro, DEC);
    //Serial.print(" A:");
    //Serial.print(accel, DEC);
    //Serial.print(" M:");
    //Serial.print(mag, DEC);
}

void setup()
{
  Serial.begin(57600);
  
  nh.initNode();
  nh.advertise(Handheld_device);
  
  myLidarLite.begin(0,false);
  
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    //Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  int eeAddress = 0;
  long bnoID;
  bool foundCalib = false;

  EEPROM.get(eeAddress, bnoID);

  adafruit_bno055_offsets_t calibrationData;
  sensor_t sensor;
  
  bno.getSensor(&sensor);
  if (bnoID != sensor.sensor_id)
  {
      //Serial.println("\nNo Calibration Data for this sensor exists in EEPROM");
      delay(500);
  }
  else
  {
      //Serial.println("\nFound Calibration for this sensor in EEPROM.");
      eeAddress += sizeof(long);
      EEPROM.get(eeAddress, calibrationData);

      //Serial.println("\n\nRestoring Calibration data to the BNO055...");
      bno.setSensorOffsets(calibrationData);

      //Serial.println("\n\nCalibration data loaded into BNO055");
      foundCalib = true;
  }
  
  //Crystal must be configured AFTER loading calibration data into BNO055.
  bno.setExtCrystalUse(true);
  
  sensors_event_t event;
  bno.getEvent(&event);
  if (foundCalib){
      //Serial.println("Move sensor slightly to calibrate magnetometers");
      while (!bno.isFullyCalibrated())
      {
          bno.getEvent(&event);
          delay(BNO055_SAMPLERATE_DELAY_MS);
      }
  }
  else
  {
      //Serial.println("Please Calibrate Sensor: ");
      while (!bno.isFullyCalibrated())
      {
          bno.getEvent(&event);

          //Serial.print("X: ");
          //Serial.print(event.orientation.x, 4);
          //Serial.print("\tY: ");
          //Serial.print(event.orientation.y, 4);
          //Serial.print("\tZ: ");
          //Serial.print(event.orientation.z, 4);

          /* Optional: Display calibration status */
          displayCalStatus();

          /* New line for the next sample */
          //Serial.println("");

          /* Wait the specified delay before requesting new data */
          delay(BNO055_SAMPLERATE_DELAY_MS);
      }
  }
  
  adafruit_bno055_offsets_t newCalib;
  bno.getSensorOffsets(newCalib);

  //Serial.println("\n\nStoring calibration data to EEPROM...");

  eeAddress = 0;
  bno.getSensor(&sensor);
  bnoID = sensor.sensor_id;

  EEPROM.put(eeAddress, bnoID);

  eeAddress += sizeof(long);
  EEPROM.put(eeAddress, newCalib);
  //Serial.println("Data stored to EEPROM.");

  //Serial.println("\n--------------------------------\n");
  
    //set switch pin to input
  pinMode(laserSwitch, INPUT);
  

  
  delay(500);
  
  
}

void loop()
{
  if(LidarReadingCount%100==0){
    LidarDistance=myLidarLite.distance(); //read with reciever bias correction
    LidarReadingCount=1;
  }
  else{
    LidarDistance=myLidarLite.distance(false); //read without reciever bias correction
    LidarReadingCount=LidarReadingCount+1;
  }
  
  delay(BNO055_SAMPLERATE_DELAY_MS);
  
  // read the IMU quaternion and acceleration information, with gravity removed
  //imuQuat=bno.getQuat();
  //imuAccel=bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
  
  //delay(BNO055_SAMPLERATE_DELAY_MS);
  
  //read switch state
  //int switchState=digitalRead(laserSwitch);
  
  Handheld_device.publish(&handheld_device_data);
  nh.spinOnce();
  delay(1000);
}
