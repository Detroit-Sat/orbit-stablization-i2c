/*
 * gyro.cpp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gyro.h"
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>//Needed for I2C port
#include <sys/ioctl.h>//Needed for I2C port

#include <linux/i2c-dev.h>//Needed for I2C port
Gyro::Gyro(char *bus)
{
  printf("%s \n","Initializing Gyro");
  filename = bus;
};

unsigned char Gyro::getData(){
	if ((file_i2c = open(filename, O_RDWR)) < 0)
	{
		//ERROR HANDLING: you can check errno to see what went wrong
		printf("Failed to open the i2c bus");
	}

	if (ioctl(file_i2c, I2C_SLAVE, 0x68) < 0)
	{
		printf("Failed to acquire bus access and/or talk to slave.\n");
    sleep(1);
		//ERROR HANDLING; you can check errno to see what went wrong
	}
	// Read 2 bytes of data
	// raw_adc msb, raw_adc lsb
	char data[3] = {0};
	if(read(file_i2c, data, 3) < 0)
	{
		 /* ERROR HANDLING: i2c transaction failed */
  //  printf("Failed to read from the i2c bus.\n");
	}
	else
	{
		// Convert the data to 12-bits
		int raw_adc = ((data[0] & 0x0F) * 256 + data[1]);

		// Output data to screen
		printf("Raw value from Gyro %d \n", raw_adc);
  }
  close (file_i2c);
	return 0;
}
