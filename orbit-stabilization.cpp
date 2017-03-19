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
	LightSensor lightSensor(bus1, 0x07);

	/*
	 * Main loop
	*/
	std::chrono::seconds interval(1) ; // 10 seconds
	while (1) {
		lightSensor.getData();
		std::this_thread::sleep_for( interval ) ;
	}

	return 0;
}
