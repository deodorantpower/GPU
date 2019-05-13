#pragma once

#ifndef __main__
#define __main__
#endif
#define _CRT_SECURE_NO_WARNINGS 

/** @def
* ARRAY    �q�̐�����
* TYPE     data�̗v�f��
* LIMIT    ����̏d�݂̌��E�l
*/
#define ARRAY	 2200
#define TYPE	  64
#define LIMIT	  30
#define ANSER   10000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** @struct
* rank            ����
* val             �]��
* t_data[TYPE]    �]���f�[�^
*/
typedef struct {
	int rank;
	int val;
	float weight;
	int t_data[TYPE];
} data;

void reset(data* mydata);		// �\���̏�����
void i_ran(data* mydata);		// �����i�[
void rank(data* mydata);		// val�t��
void sort(data* mydata);		// val�̃\�[�g�i�~���j
void change(data* mydata);		// �|�����킹
void view(data* mydata);		// �o��
void mutation(data* mydata);	// �ˑR�ψ�
