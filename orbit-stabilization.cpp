/*
* orbit-stabilization.cpp
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

#include "modules/light-sensor.h"
#include "modules/gyro.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <ctime>//timer
#include <cstdlib>//timer

using namespace std;

int main(int argc, char *argv[]){

	char *bus1 = (char*)"/dev/i2c-1";
	char *bus2 = (char*)"/dev/i2c-2";
	char *bus3 = (char*)"/dev/i2c-3";

	clock_t startTime = clock(); //Start timer
	double secondsPassed;
	double secondsToDelay = 5000;

	cout << "Orbit Stabilization Started" << endl;
	/*
	 * Initialize sensors
	*/
	LightSensor lightSensor1(bus1, 0x00);
	LightSensor lightSensor2(bus1, 0x10);
	LightSensor lightSensor3(bus1, 0x20);
	LightSensor lightSensor4(bus1, 0x30);
	LightSensor lightSensor5(bus1, 0x40);
	LightSensor lightSensor6(bus1, 0x50);
	LightSensor lightSensor7(bus1, 0x60);
	LightSensor lightSensor8(bus1, 0x70);
	Gyro gyro(bus1);

	/*
	 * Main loop
	*/
	std::chrono::milliseconds interval(1000);
	while (1) {
		gyro.getData();
		// lightSensor1.getData();
		// lightSensor2.getData();
		// lightSensor3.getData();
		// lightSensor4.getData();
		// lightSensor5.getData();
		// lightSensor6.getData();
		// lightSensor7.getData();
		// lightSensor8.getData();
		//std::this_thread::sleep_for( interval ) ;
	}

	return 0;
}
