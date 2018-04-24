# Model Predictive Control
## Author: Sandeep Patil  
---

[mpc_and_referance_line]: ./sample_images/mpc_and_referance_lines.png "mpc_and_referance_line"  
[MPC_model]: ./sample_images/MPC_model.png "MPC_model"  


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![mpc_and_referance_line][mpc_and_referance_line]

### Overview 
Objective of this project is to derive good steering and acceleration values using [Model Predictive Control(MPC)](https://en.wikipedia.org/wiki/Model_predictive_control).  
In this project we create Kinematic model and added constraints on different parameters like cross track error and actuator values etc. Along with this we have used libraries like **Ipopt and CppAD** to get best actuator values for given reference trajectory.

#### Kinematic model and constraints
I have used following kinematic model and constraints.  
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![MPC_model][MPC_model]  

#### Cost of different parameters and their proportion.
To get optimal solution following cost factors were considered.  
* Cross Track Error (CTE).  
* Orientation Error.(OE)  
* Difference between actual and target velocity. (Velocity difference : VD)  
* High value of steering angle and acceleration. (Steering angle : SA, Acceleration : ACC)  
* Sudden change in sequential actuations values. (Steering angle fluctuation : SAF , Acceleration fluctuation ACCF)  

To get smooth ride we need to apply different weights for above cost variables. After doing some trial and error. I have applied following weights.

`CTE:OE:VD:ACC:SAF:ACCF`  
`50:100:1:5:5:25000:500`

We can see that we have given highest weight  for steering angle fluctuation and acceleration fluctuation, this provides very smooth ride.

#### Number of steps and time between each step.
To model projected trajectory I have used 10 number of steps and 0.1 seconds as time delta.


#### Handling lag with simulator
I have considered time lag of 0.1 second between time getting input from simulator and time when next actuation get applied. 



---

## Installations and build 

This project involves the Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases) .

This repository includes two files that can be used to set up and install [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) for either Linux or Mac systems. 

For Linux  
`./install-ubuntu.sh`

For Mac  
`./install-mac.sh`

Once the install for uWebSocketIO is complete, the main program can be built and run by doing the following from the project top directory.

### Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./mpc`.

### Communication between main.cpp (server) and simulator
Here is the main protocol that main.cpp uses for uWebSocketIO in communicating with the simulator.

INPUT: values provided by the simulator to the c++ program

* `ptsx` - The global x positions of the waypoints.
* `ptsy` - The global y positions of the waypoints. 
since y is the up-down direction.
* `psi` - The orientation of the vehicle in **radians**. 
* `x` - The global x position of the vehicle.
* `y` - The global y position of the vehicle.
* `steering_angle` (float) - The current steering angle in **radians**.
* `throttle` (float) - The current throttle value.
* `speed` (float) - The current velocity in **mph**.

Please refer [DATA.md](./DATA.md) for more details.

OUTPUT: values provided by the c++ program to the simulator  

* `steering_angle` - Steering angle in **radians**.  
* `throttle` - Throttle value for acceleration.  
* `mpc_x` - x positions of projected line in car coordinate.
* `mpc_y` - y positions of projected line in car coordinate.
* `next_x` - x positions of reference line in car coordinate.
* `next_y` - y positions of reference line in car coordinate. 


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `install-mac.sh` or `install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    
* **Ipopt and CppAD:** Please refer to [this document](./install_Ipopt_CppAD.md) for installation instructions.
* [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page). This is already part of the repo so you shouldn't have to worry about it.
* Simulator. You can download these from the [releases tab](https://github.com/udacity/self-driving-car-sim/releases).





