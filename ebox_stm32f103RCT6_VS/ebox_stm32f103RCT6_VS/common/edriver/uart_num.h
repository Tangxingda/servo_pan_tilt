#ifndef __UART_NUM
#define __UART_NUM

#include "ebox.h"

//#define __UART_NUM_DEBUG

#define UART_NUM_BUF_SIZE_CHAR 4
#define UART_NUM_BUF_SIZE_NUM 10

class UartNum
{
	Uart *uart;
	//���ڴ洢��������λ��ת��Ϊ����
	union num
	{
		float f;
		unsigned char c[UART_NUM_BUF_SIZE_CHAR];
	}charsBuf;

	int charBufIndex;//��������λ��index
	int numBufIndex;//�������ֵ�index
	bool isTrans;//��־��һ���Ƿ���ת���ַ�
	
	//bool isBusy;//��־�Ƿ����ڽ���
	bool isBegin;//��־�Ƿ���֡ͷ

	void rxEvent();
public:
	float numsBuf[UART_NUM_BUF_SIZE_NUM];//���ڴ洢���յ�����
	int recievedNum;
	//��������uartX��UartNum��
	UartNum(Uart *uartX);
	//��ʼ��uart�����жϺ���
	void begin(uint32_t baud_rate, uint8_t _use_dma = 1);
	//��ʼ��uart�����жϺ���
	void begin(uint32_t baud_rate, uint8_t data_bit, uint8_t parity, float stop_bit, uint8_t _use_dma);
	void printf(const char *fmt, ...);
	////��ȡ��������
	//void getNums(float* nums)
	//{
	//	for (int i = 0; i < recievedNum; i++)
	//	{
	//		nums[i] = numsBufOld[i];
	//	}
	//}
	////����Ϊ���ڽ���
	//void setBusy()
	//{
	//	isBusy = true;
	//}
	////�Ƿ����ڽ���
	//bool busy()
	//{
	//	return isBusy;
	//}
};

#endif