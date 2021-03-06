#ifndef __SERVO_PAN_TILT
#define __SERVO_PAN_TILT

#include "ebox.h"
#include "servo.h"
#include "uart_num.h"
#include "PID.hpp"
#include "mpu9250.h"
#include <math.h>

#define INF_FLOAT 3.402823466e+38F

#define __SERVO_PAN_TILT_DEBUG

class ServoPanTilt
{
	MPU9250 mpu;
	Servo servoY, servoP;
	Uart*  uart;
	sky::PID pidY, pidP;
	float refreshInt;
public:
	float angleY, angleP, angleR;

	ServoPanTilt(Gpio* pinServoYaw, Gpio* pinServoPitch, float refreshInterval = 0.01, Uart* uartDebug = &uart1) :
		servoY(pinServoYaw, 1/refreshInterval, 0.7, 2.3),
		servoP(pinServoPitch, 1/ refreshInterval, 0.7, 2.3),
		uart(uartDebug),
		refreshInt(refreshInterval)
	{

	}
	
	//初始化舵机和串口
	void begin()
	{
		servoY.begin();
		servoP.begin();
		servoP.setPct(9);
		uart->begin(115200);
		delay_ms(1000);

		//初始化mpu
		signed char matrix[] = { 0, 0, 1,
			1, 0, 0,
			0, 1, 0 };
		mpu.setOrientationMatrix(matrix);
		mpu.begin(200);
		mpu.calibrate();//自检时保持水平，此处会校准误差

		//初始化yawPID
		pidY.setRefreshInterval(refreshInt);
		pidY.setWeights(0.05, 0.01, 0.001);
		pidY.setOutputLowerLimit(-INF_FLOAT);
		pidY.setOutputUpperLimit(INF_FLOAT);
		pidY.setISeperateThres(4);
		pidY.setDesiredPoint(0);

		//初始化pitchPID
		pidP.setRefreshInterval(refreshInt);
		pidP.setWeights(0.05, 0.01, 0.001);
		pidP.setOutputLowerLimit(-INF_FLOAT);
		pidP.setOutputUpperLimit(INF_FLOAT);
		pidY.setISeperateThres(4);
		pidP.setDesiredPoint(0);
	}

	//刷新pid
	void refresh()
	{
		float pctY = servoY.getPct();
		float pctP = servoP.getPct();

		mpu.readDMP(angleP, angleR, angleY);

		float pidYout = pidY.refresh(angleY);
		float pidPout = pidP.refresh(angleP);

		//pidYout = pidYout > 0 ? sqrt(pidYout) : (-sqrt(-pidYout));
		//pidPout = pidPout > 0 ? sqrt(pidPout) : (-sqrt(-pidPout));
		pctY += pidYout;
		pctP += pidPout;

		servoY.setPct(pctY);
		servoP.setPct(pctP);

#ifdef __SERVO_PAN_TILT_DEBUG
		uart->printf("yaw:%.1f\tpitch:%.1f\trow:%.1f\tyawOut:%.1f\tpitchOut:%.1f\r\n",
			angleY, angleP, angleR, pctY, pctP);
#endif // __SERVO_PAN_TILT_DEBUG
	}

	//重置目标角度为当前角度
	void reset()
	{
		float angleY, angleP, angleR;

		mpu.readDMP(angleP, angleR, angleY);
		pidY.setDesiredPoint(angleY);
		pidP.setDesiredPoint(angleR);
	}
};

#endif