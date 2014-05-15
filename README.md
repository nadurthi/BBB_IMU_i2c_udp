BBB_IMU_i2c_udp
===============

Send imu data to  pc over wifi using udp communication. My blog has some description of the imu i use 
http://www.nagavenkat.adurthi.com/?p=563

The IMU has to be connected with i2c with your beaglebone black(BBB). The data is recorded drom the IMU by BBB 
and sent over to your pc your pc over a udp connection. The udp connection that is there in the folder is very 
simple and very basic. The data is time stamped on the BBB and then sent to the PC where it can be time stamped 
again. 
