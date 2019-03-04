# Smart-Enivironment-Monitoring-Device-Using-Beaglebone-Green
In this project I will be designing and implementing a “smart” environment monitoring device using the BeagleBone Green development board along with two offboard sensors. An example of the sensor’s application would be a refrigerator where the purpose is to monitor for out-of-bounds conditions such as an exterior door left open via a light sensor or the internal storage temperature rising too high for properly preserving food.

The Main Task is the parent thread, implemented using asynchronous threading strategy to manage child threads. The Main Task performs following functions - 
-	Child Thread Management Function
-	LED Task
The main task creates threads that perform the following functions –
-	Temperature Sensor Task
-	Light Sensor Task
-	Synchronized Logger Task
-	Remote Request Socket Task

CHILD THREAD MANAGEMENT FUNCTION
>	The parent thread keeps the track of children tasks to check if they are alive and running on specified time intervals or dead and stuck for a specific timeout.
>	This can be achieved by using Heartbeat notification from all child threads to the parent thread using request response mechanism.
>	When requested to stop the task, the main task should clean up everything, issue exit commands to the child threads and terminate gracefully.

LED TASK
>	This task is concerned notifying the user of error conditions encountered during the execution of the program (Example, missing sensor, abnormal child thread behaviour etc)
>	The error is reported on the console and indicated using USR LED

TEMPERATURE SENSOR TASK
>	This task is concerned with the Temperature Sensor TMP102 with I2C. It wakes up at a regular intervals to collect data from the sensor.
>	It consists of read and write functions for sensor registers and modify configuration registers.
>	Temperature data is available in binary format. This task performs conversion to decimal format. The temperature is to be made available in Celsius, Kelvin and Fahrenheit.

LIGHT SENSOR TASK
>	This task is concerned with the Light Sensor APDS-9301 Light Sensor. It wakes up at regular intervals to collect data from the sensor.
>	Interfaces are created for read and write for registers in 8-bit and 16-bit mode. This includes Read/Write functions for registers, modify Control Registers and read LUX values. Based on the LUX value, the task decides if the state is LIGHT or DARK.
>	The task includes equations to read the actual Luminosity from the LUX Data ADC. It reads two types of light data – Visible Light and IR Light using Channels 0 & 1 correspondingly

SYNCHRONIZED LOGGER TASK
>	This task is concerned with logging data from various on-board sources. As this interface is going to be accessed by multiple sources, synchronization is needed to maintain data consistency. In this project, data protection is achieved using Message Queue. 
>	The log file path and file name are configurable. This is accomplished using command line options. 
>	Once the process is requested/forced to close, it should close all file handles and terminate gracefully.
>	 Each log entry contains the following information: timestamp, log level, logger source ID, Log Message

REMOTE REQUEST SOCKET TASK
>	This task acts as an interface to external programs and enables them to request sensor data. 
>	The Remote Request Socket Task accepts socket request from another process/task and makes API calls to sensor tasks for data.
>	A second process is created to create a socket connection with this task to make remote requests.

BUILT-IN SELF TESTS(BIST)
Once a task is started, a few tests need to be performed to verify if the hardware and software are working. Tests include 
>	Temperature Sensor BIST to ensure correct working of I2C and hardware
>	Light Sensor BIST to ensure correct working of I2C and hardware
>	Child Thread BIST to ensure child threads are up and running correctly
After successful completion of each BIST, log message needs to be sent to the logger. If any test fails, error code is logged and USR LED is turned on.

UNIT TESTS
Software must be tested using CUnit Unit Test Framework for functions like –
>	Inter thread communication
>	Logger
>	Temperature conversions
>	Light Sensor conversions


