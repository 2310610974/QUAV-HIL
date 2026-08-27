Introduction
QUAV-HIL is a complete hardware-in-the-loop (HIL) experimental project for quadrotor UAVs based on the ESP32-S3 platform. This project adopts adaptive control algorithm as the core control scheme, realizes the joint simulation of embedded flight control firmware and Simulink dynamic model, and is dedicated to the verification, parameter optimization and iterative improvement of quadrotor attitude and position adaptive control strategies.
Traditional pure simulation lacks real hardware operation characteristics, while physical flight test has high risk and low repeatability. This HIL scheme effectively bridges the gap between offline simulation and real flight, providing a safe, efficient and reproducible verification platform for UAV control algorithms.
Project Architecture
The project adopts the classic upper-computer simulation + lower-computer real hardware HIL architecture:
•	Lower computer (Hardware): ESP32-S3 microcontroller, running self-written flight control algorithm, responsible for attitude solving, control loop calculation and data interaction
•	Upper computer (Simulation): MATLAB/Simulink, building quadrotor dynamic model, completing state solving, sensor data simulation and real-time data transmission
•	Data interaction: Real-time communication between ESP32-S3 and Simulink to form a closed-loop hardware-in-the-loop control system
File Description
The core files and functions of the repository are as follows:
File Name	Function Description
sketch_jan21a/	ESP32-S3 main program folder, including flight control algorithm, data transceiver, attitude calculation and other core firmware codes
sketch_jan21a.zip	Compressed package of the complete ESP32-S3 firmware project, convenient for one-click import and compilation
controller.slx	Simulink control algorithm simulation model, which can be used for offline debugging of control parameters
x1UAVx20260119.slx	Quadrotor full dynamic HIL simulation model, matching ESP32-S3 hardware for closed-loop experiment
Environment Requirements
Hardware Environment
•	Main control board: ESP32-S3 development board
•	Communication tool: USB data cable (supports serial port communication)
•	Upper computer: PC (supports MATLAB/Simulink operation)
Software Environment
•	Embedded compilation: Arduino IDE / PlatformIO (adapted to ESP32-S3 core library)
•	Simulation software: MATLAB R2023a (with Simulink toolbox, fully adapted to the project model and adaptive control module)
•	Driver: ESP32 serial port driver (CP210x)
Quick Start
1. Firmware Burning
1.	Open the sketch_jan21a project through Arduino IDE or PlatformIO
2.	Select the development board model as ESP32S3 Dev Module, and configure the corresponding serial port
3.	Compile and upload the firmware to the ESP32-S3 development board
2. Simulink Model Configuration
1.	Open x1UAVx20260119.slx quadrotor dynamic model
2.	Configure the serial port communication parameters to be consistent with ESP32-S3 firmware (baud rate, data bit, parity check, etc.)
3.	Check the model running parameters to ensure real-time simulation accuracy
3. HIL Closed-Loop Experiment
1.	Connect ESP32-S3 to PC via USB and open the serial port monitoring
2.	Run the Simulink simulation model to realize real-time data interaction between hardware and simulation
3.	Observe UAV attitude, angular velocity and control output data, and complete algorithm verification and parameter tuning
Core Functions
•	Quadrotor attitude and position closed-loop control based on adaptive control algorithm (replacing traditional PID, with stronger anti-interference and parameter self-tuning ability)
•	Real-time data interaction between ESP32-S3 and Simulink
•	Hardware-in-the-loop closed-loop simulation verification
•	Support control parameter online tuning and algorithm iteration
Common Problems
•	Serial port communication failure: Check whether the serial port driver is installed correctly, and ensure that the serial port number and baud rate of the upper and lower computers are consistent
•	Model simulation stuck: Reduce the simulation step size appropriately and check the real-time synchronization status of hardware and simulation
•	Firmware compilation / adaptive control module error: Update the ESP32-S3 core library to the latest version, confirm the development board configuration is correct; if the adaptive control parameter iteration is abnormal, check the Simulink R2023a module compatibility and real-time solving configuration
Contributor
2310610974-jpg (Liu1212)
License
This project is open source for academic research and engineering learning. Please indicate the source for secondary development and reprinting.

QUAV-HIL 四旋翼无人机自适应控制硬件在环实验项目
项目简介
QUAV-HIL 是一套基于 ESP32-S3 嵌入式平台的四旋翼无人机硬件在环（HIL）实验系统。本项目核心采用自适应控制算法，替代传统 PID 控制，通过下位机硬件实时运算控制律、上位机 MATLAB/Simulink 仿真无人机动力学模型，实现软硬件闭环联合仿真，用于四旋翼姿态与位置自适应控制算法的验证、参数整定与迭代优化。
纯离线仿真无法体现真实硬件的运算延迟与嵌入式特性，而真机试飞风险高、可重复性差。本硬件在环方案有效弥补了仿真与实际飞行之间的差距，为无人机自适应控制算法提供了安全、高效、可复现的验证环境。
项目架构
本项目采用经典的上位机仿真 + 下位机真实硬件硬件在环闭环架构：
- 下位机（硬件端）：ESP32-S3 主控芯片，运行自主编写的嵌入式自适应控制程序，完成姿态解算、自适应控制律计算、数据收发与闭环控制运算。
- 上位机（仿真端）：基于 MATLAB R2023a / Simulink 搭建四旋翼完整动力学模型，模拟无人机姿态、角速度、位置状态与传感器数据，实现仿真状态实时更新。
- 数据交互闭环：ESP32-S3 与 Simulink 串口实时通信，硬件输出控制量驱动仿真模型，仿真反馈状态数据给硬件控制器，形成完整硬件在环闭环控制系统。
文件说明
本仓库核心文件及功能说明如下：
文件名
功能说明
sketch_jan21a/
ESP32-S3 主控程序文件夹，包含自适应控制算法、姿态解算、串口数据收发、闭环控制运算等全部嵌入式核心固件代码。
sketch_jan21a.zip
完整 ESP32-S3 工程压缩包，可直接导入编译，快速部署固件。
controller.slx
Simulink 控制算法仿真模型，用于自适应控制参数离线调试、算法预验证。
x1UAVx20260119.slx
四旋翼完整动力学仿真模型，适配 ESP32-S3 硬件，用于硬件在环闭环实验。
运行环境要求
硬件环境
- 主控设备：ESP32-S3 开发板
- 通信设备：USB 数据线（支持串口通信）
- 运行主机：Windows 电脑（支持 MATLAB 仿真运行）
软件环境
- 嵌入式编译工具：Arduino IDE / PlatformIO（适配 ESP32-S3 核心库）
- 仿真软件：MATLAB R2023a（搭载 Simulink 工具箱，完美适配本项目自适应控制模块与动力学模型）
- 驱动程序：ESP32 串口驱动（CP210x）
快速运行教程
1. 下位机固件烧录
1. 通过 Arduino IDE 或 PlatformIO 打开 sketch_jan21a 工程文件。
2. 选择开发板型号为 ESP32S3 Dev Module，匹配电脑对应串口。
3. 编译代码并上传固件至 ESP32-S3 开发板。
2. Simulink 模型配置
1. 使用 MATLAB R2023a 打开四旋翼动力学模型 x1UAVx20260119.slx。
2. 配置串口通信参数，与 ESP32-S3 固件波特率、数据位、校验位保持一致。
3. 核对仿真步长、求解器配置，保证实时仿真精度与硬件同步性。
3. 硬件在环闭环实验
1. 通过 USB 将 ESP32-S3 连接电脑，开启串口监视器。
2. 运行 Simulink 仿真模型，实现硬件控制器与仿真模型实时数据交互。
3. 观测无人机姿态、角速度、控制输出等数据，完成自适应控制算法验证与参数整定。
项目核心功能
- 基于自适应控制算法的四旋翼姿态、位置闭环控制，相较于传统 PID 具备更强的抗干扰能力与参数自整定能力，适配无人机模型参数摄动场景。
- ESP32-S3 嵌入式硬件与 Simulink 仿真模型实时双向数据通信。
- 完整四旋翼无人机硬件在环闭环仿真验证体系。
- 支持自适应控制参数在线调试、算法迭代与性能对比实验。
常见问题与解决方案
- 串口通信失败：检查 CP210x 串口驱动是否正常安装，确认上位机与下位机串口编号、波特率参数完全一致，关闭占用串口的其他软件。
- Simulink 仿真卡顿、不同步：适当调低仿真步长，检查求解器设置，确保仿真实时性，匹配硬件运算频率。
- 固件编译报错 / 自适应控制运算异常：更新 ESP32-S3 核心库至最新版本，核对开发板配置；若出现自适应参数迭代异常，检查 MATLAB R2023a 模块兼容性与仿真求解配置。
项目贡献者
2310610974-jpg（Liu1212）
开源协议
本项目仅用于学术研究与工程学习开源使用，二次开发、转载请注明项目来源。
