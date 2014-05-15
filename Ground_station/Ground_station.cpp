///////////////////////////////////////////////////////////////////////////////
/*
*By Nagavenkat Adurthi
*Regular License:
*Do what ever you want with this code, I am not responsible for *anything.
*This code runs on your PC. I call it the ground station. My *ground station IP is 10.0.0.3
*So I send data over a udp connection to this IP address with *port 1234.
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
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <fstream>
#include <cmath>
#include "controllers.h"
#include "SimpleTimer.h"

using namespace std;
#include "udpPort.h"

SimpleTimer GroundTimer,TicToc;

udpPort RxUDP;


int main( int argc, char* argv[] )
{

   //Setup UDP connection
	char addressRx[30]="10.0.0.3";   //my PC has this IP.... change it to ur PC IP address
	RxUDP.OpenPort_write(addressRx,1234);  //open some port number such as 1234.


	//Setup the ground timer
		GroundTimer.SetTsec(0.01);   //can be ignored


		TicToc.ResetTimer();  // this keeps track of time, so I can time stamp the IMU data when i receive them


	
double Timu;
char rxbuffer[100];
int i=0,m=0;


	while(1){

// the imu program sends data that is time stamped on the BBB. 

		if(RxUDP.CheckData()>=0){   //check if udp has received any data
			Timu=TicToc.GetTime_from_T0sec(); //time stamp it on your PC
			RxUDP.ReadPort(rxbuffer,100);  //read the data
			cout<<rxbuffer;  //see what the data look like
			
		}


	

	}

return 1;

}
