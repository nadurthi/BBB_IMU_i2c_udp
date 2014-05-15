
///////////////////////////////////////////////////////////////////////////////
/*
*By Nagavenkat Adurthi
*Regular License:
*Do what ever you want with this code, I am not responsible for anything.
*This code runs on your BBB. I call it the onboard. My ground station IP is 10.0.0.3
*So I send data over a udp connection to this IP address with port 1234.
*/ 
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stropts.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include<limits>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <fstream>
#include <cmath>



#include "SimpleTimer.h"

using namespace std;



#include "udpPort.h"

#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 AccelGyroSensor;

SimpleTimer OnboardTimer;

udpPort TxUDP;



int main() {

//Setup UDP connection
	char addressTx[30]="10.0.0.3";  //my pc has this ip address    
	TxUDP.OpenPort_write(addressTx,1234); //open the same port specified on ground station


	OnboardTimer.SetTsec(0.005); // send data every 0.005 seconds


//initialize the imu
AccelGyroSensor.initialize();   // initialize the imu... ACC is m/s^2 and Ang rate is rad/s


double Data_imu[7];
char txbuffer[100];

    while(1){
    	OnboardTimer.ResetTimer();



            // Update IMU measurement... data is time stamped with first entry as times
    				AccelGyroSensor.getScaledaccgyro_timestamped(Data_imu);
    				snprintf(txbuffer,100,"%f %f %f %f %f %f %f\n",Data_imu[0],Data_imu[1],Data_imu[2],Data_imu[3],Data_imu[4],Data_imu[5],Data_imu[6]);
    				TxUDP.write(txbuffer,100); //write the data to udp connection

    	while(OnboardTimer.CheckTimer()){} //just wait for 0.005 seconds to get over

    } //while eternal

    return 1;
}
