#ifndef __MPU9250_H
#define __MPU9250_H

/***************************************************

*�ļ�����:
*         ���ݹٷ�DMP����MPU9250����̬
���ΪYaw,pitch,Rollֵ���Ƕ�ֵ��
�ο����ϲ��ִ���
*Author:
*         ��ܰ @ UESTC
*Time:
*					2015.3.30
*version:
*         v1.0
***************************************************/

#include "stm32f10x.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "inv_mpu.h"
#include "math.h"
#include "stm32_iic.h"
#include "ebox.h"




/* These next two functions converts the orientation matrix (see
* gyro_orientation) to a scalar representation for use by the DMP.
* NOTE: These functions are borrowed from Invensense's MPL.
*/
static  unsigned short inv_row_2_scale(const signed char *row);



static  unsigned short inv_orientation_matrix_to_scalar(const signed char *mtx);

/*�Լ캯��*/
static void run_self_test(void);


void mpu9250Init(void);

void mpu9250Read(float &Pitch, float  &Roll, float  &Yaw);






#endif
