/*
 *  search_test.c
 *  Created on: 2018-7-19
 *  Author: MK
 *  usage:�����ַ���ƥ���㷨��ʵ�֣�Sunday��KMP��Boyer-Moore��horspool���Ĳ���
 */
#include "search_string.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#ifdef WIN32
#include<time.h>
#else
#include <sys/time.h>
#endif
#ifdef WIN32
#include<windows.h>
#else
#include <unistd.h>
#endif
#define My_TXTMAX 1000
#define times 10000000  //���д���
#define MAXCH 256
#define lenp 14

static const unsigned __int64 epoch = 116444736000000000L;

 int gettimeofday(struct timeval* tp, void* tzp)
{
	FILETIME    file_time;
	SYSTEMTIME  system_time;
	ULARGE_INTEGER ularge;

	GetSystemTime(&system_time);
	SystemTimeToFileTime(&system_time, &file_time);
	ularge.LowPart = file_time.dwLowDateTime;
	ularge.HighPart = file_time.dwHighDateTime;

	tp->tv_sec = (long)((ularge.QuadPart - epoch) / 10000000L);
	tp->tv_usec = (long)(system_time.wMilliseconds * 1000);

	return 0;
}

int main()
{	//��ʼ��һЩ����
	char* pattern = "MY_TEST_string";//ģʽ��
	int  len_txt;
	//lenp = 14; // strlen(pattern);
	len_txt = strlen(My_TXT);//My_TXTΪ�ı���������������"search_character.h"��
	int sun_shift[MAXCH];//Sunday��������
	int KMP_next[lenp];//KMP��������
	int bmBc[MAXCH];//BM���ַ�����
	int bmGs[lenp];//BM�ú�׺����
	int hors_d[MAXCH];//horspool��������
	struct timeval start, end;//������¼ʱ��
	long dif_sec, dif_usec;//�洢ʱ���
	int i;
	char* temp[5], test[5][256];
	//�����㷨��Ԥ������
	SundayPre(sun_shift, pattern, lenp);
	KMPPre(pattern, KMP_next);
	PreBmBc(pattern, lenp, bmBc);
	PreBmGs(pattern, lenp, bmGs);
	horspoolPre(hors_d, pattern, lenp);
	//���Կ�ʼ
	///////////KmpSearch///////////
	gettimeofday(&start, NULL);//��ʼʱ��
	for (i = 0; i < times; i++) {//Ϊ���д���
		if (i == 0) {
			temp[0] = KmpSearch(My_TXT, len_txt, pattern, lenp, KMP_next);//���ؽ������������֤�Ƿ�����ҵ���ģʽ��pattern����λ��
		}
		else
			KmpSearch(My_TXT, len_txt, pattern, lenp, KMP_next);//ѭ������
	}
	gettimeofday(&end, NULL);//����ʱ��
	dif_sec = end.tv_sec - start.tv_sec;//��������
	dif_usec = end.tv_usec - start.tv_usec;//����΢����
	printf("KMP running time  is %ld �� (%ld ΢��)\n", dif_sec, dif_sec * 1000000 + dif_usec);//����ʱ�任�㣬��֪���������в�ѯ�ṹ��struct timeval

	////////////BM//////////////
	gettimeofday(&start, NULL);
	for (i = 0; i < times; i++) {
		if (i == 0) {
			temp[1] = BoyerMoore(My_TXT, len_txt, pattern, lenp, bmBc, bmGs);
		}
		else
			BoyerMoore(My_TXT, len_txt, pattern, lenp, bmBc, bmGs);
	}
	gettimeofday(&end, NULL);
	dif_sec = end.tv_sec - start.tv_sec;
	dif_usec = end.tv_usec - start.tv_usec;
	printf("BM running time  is %ld �� (%ld ΢��)\n", dif_sec, dif_sec * 1000000 + dif_usec);

	////////////Sunday//////////////
	gettimeofday(&start, NULL);
	for (i = 0; i < times; i++) {
		if (i == 0) {
			temp[2] = Sunday(My_TXT, len_txt, pattern, lenp, sun_shift);
		}
		else
			Sunday(My_TXT, len_txt, pattern, lenp, sun_shift);
	}
	gettimeofday(&end, NULL);
	dif_sec = end.tv_sec - start.tv_sec;
	dif_usec = end.tv_usec - start.tv_usec;
	printf("Sunday running time  is %ld �� (%ld ΢��)\n", dif_sec, dif_sec * 1000000 + dif_usec);

	///////////horspool//////////////
	gettimeofday(&start, NULL);
	for (i = 0; i < times; i++) {
		if (i == 0) {
			temp[3] = horspool(My_TXT, len_txt, pattern, lenp, hors_d);
		}
		else
			horspool(My_TXT, len_txt, pattern, lenp, hors_d);
	}
	gettimeofday(&end, NULL);
	dif_sec = end.tv_sec - start.tv_sec;
	dif_usec = end.tv_usec - start.tv_usec;
	printf("horspool running time  is %ld �� (%ld ΢��)\n", dif_sec, dif_sec * 1000000 + dif_usec);

	////////////strstr//////////////
	gettimeofday(&start, NULL);
	for (i = 0; i < times; i++) {
		if (i == 0) {
			temp[4] = strstr(My_TXT, pattern);
		}
		else {
			strstr(My_TXT, pattern);
		}
	}
	gettimeofday(&end, NULL);
	dif_sec = end.tv_sec - start.tv_sec;
	dif_usec = end.tv_usec - start.tv_usec;
	printf("strstr running time  is %ld �� (%ld ΢��)\n", dif_sec, dif_sec * 1000000 + dif_usec);
	/////��ӡ��֤����Ƿ���ȷ///////////////
	printf("*********************\n");
	if (temp[0]) {
		strncpy(test[0], temp[0], lenp + 1);//ֻ���ƹؼ��ʵĲ���
		test[0][lenp] = '\0';             //�ֶ����Ͻ�����
		printf("KMP: %s\n", test[0]); //��ӡ
	}
	if (temp[1]) {
		strncpy(test[1], temp[1], lenp + 1);
		test[1][lenp] = '\0';
		printf("BM: %s\n", test[1]);
	}
	if (temp[2]) {
		strncpy(test[2], temp[2], lenp + 1);
		test[2][lenp] = '\0';
		printf("Sunday: %s\n", test[2]);
	}
	if (temp[3]) {
		strncpy(test[3], temp[3], lenp + 1);
		test[3][lenp] = '\0';
		printf("Horspool: %s\n", test[3]);
	}
	if (temp[4]) {
		strncpy(test[4], temp[4], lenp + 1);
		test[4][lenp] = '\0';
		printf("strstr: %s\n", test[4]);
	}
	printf("*********************\n");
	return 0;
}