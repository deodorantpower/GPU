/**
* @file main.cpp
* @brief �i�b�v�T�b�N���̉���
* @author ���J��@�E��
* @date 2019/05/01
*/

#include "main.h"

/**
* @fn void main(void)
* @brief �����_���ŏd�݂ɉ��l�����]�����Ă����A
         ��ʂ̊|�����킹�ɂ���čœK�����Z�o����
* @param (void) �Ȃ�
* @return void  �Ȃ�
* @detail �����i�[�Arank�t���A�\�[�g�A�|�����킹�A�ˑR�ψق̊֐��Ăяo��
* @date 2019/05/01
*/
void main(void) {

	//! �\���̎��̐���
	data mydata[ARRAY];			

	//������
	reset(mydata);	
	// �����i�[
	i_ran(mydata);			

	for (int i = 0; i < 1000; i++) {
		//! �ˑR�ψٗ���
		srand((unsigned)time(NULL));
		// rank�t��
		rank(mydata);
		// �o�u���\�[�g
		sort(mydata);
	
		// �|�����킹
		change(mydata);
	
		if (rand() % 30 == 1) {
			mutation(mydata);
		}
	}

	//��ʂQ�o��
	view(mydata);

	system("pause");
}

/**
* @fn void view(data* mydata)
* @brief ���ʂ̕\��
* @return void �Ȃ�
* @details �\���̂̕\��
* @date 2019/05/01
*/
void view(data* mydata) {

	for (int i = 0; i < ARRAY/2; i++) {
		printf("rank:%d val:%05d�F", mydata[i].rank, mydata[i].val);
		for (int j = 0; j < TYPE; j++) {
			printf("%d", mydata[i].t_data[j]);
		}
		printf("\n");
	}
}

/**
* @fn void reset(data* mydata)
* @brief �\���̏�����
* @return void �Ȃ�
* @date 2019/05/01
*/
void reset(data* mydata) {

	//! �񎟌��z��̏�����
	for (int i = 0; i < (sizeof(mydata) / sizeof(mydata[0])); i++)
	{
		mydata[i].rank = 0;
		mydata[i].val = 0;
		for (int j = 0; j < TYPE; j++) {
			mydata[i].t_data[j] = 0;
		}
	}

}

/**
* @fn void i_ran(data* mydata)
* @brief �������\���̂Ɋi�[
* @return void �Ȃ�
* @date 2019/05/01
*/
void i_ran(data* mydata) {
	//����
	srand((unsigned)time(NULL));

	//�����i�[
	for (int i = 0; i < ARRAY; i++) {
		for (int j = 0; j < TYPE; j++) {
			mydata[i].t_data[j] = rand() % 2;
		}
	}
}

/**
* @fn void rank(data* mydata)
* @brief �����N�t��
* @return void �Ȃ�
* @detail �d�݂Ɖ��l�ɑ΂���]�����s���B
*         �d�݂����~�b�g���ł���Ώd�݁~���l��]���Ƃ���B
* @date 2019/05/03
*/
void rank(data* mydata) {

	//! �d�݂Ɖ��l�z��@
	int weight[TYPE] = { 2,  4, 6,   1,   8,   9,  10,   1 };
	int price[TYPE] = { 100, 10, 5, 100, 200, 150, 300, 500 };

	//! �d�݂Ɖ��l�̈ꎞ�i�[
	int w_temp = 0;			
	int p_temp = 0;			

	for (int i = 0; i < ARRAY; i++) {
		for (int j = 0; j < TYPE; j++) {

			// �d�݂̏W�v
			w_temp += mydata[i].t_data[j] * weight[j];

			// �d�݂Ɖ��l�̎Z�o
			if (mydata[i].t_data[j] == 1) {
				p_temp += weight[j] * price[j];
			}
		}
		// �d�݂̃��~�b�g����
		if (w_temp > LIMIT) {
			mydata[i].val = 0;
		}
		mydata[i].val = p_temp;

		// ���Z�b�g
		p_temp = 0;
		w_temp = 0;
	}
}

/**
* @fn void sort(data* mydata)
* @brief �����N�̃\�[�g
* @return void �Ȃ�
* @date 2019/05/03
*/
void sort(data* mydata) {

	//! �ꎞ�i�[
	data temp;

	for (int i = 0; i< ARRAY; i++) {
		for (int j = ARRAY - 1; j > i; j--) {
			if (mydata[j].val > mydata[j - 1].val) {
				memcpy(&temp, &mydata[j], sizeof(data));
				memcpy(&mydata[j], &mydata[j-1], sizeof(data));
				memcpy(&mydata[j-1], &temp, sizeof(data));
			}
		}
	}
	for (int i = 0; i < ARRAY; i++) {
		mydata[i].rank = i+1;
	}
}

/**
* @fn void change(data* mydata)
* @brief �|�����킹
* @return void �Ȃ�
* @detail ��ʓ�̃f�[�^���|�����킹�Q�̎q�쐬���A���ʓ�ɏ���������B
* @date 2019/05/05
*/
void change(data* mydata) {

	for (int i = 0; i < TYPE/2; i++) {
		mydata[2].t_data[i] = mydata[0].t_data[i];
		mydata[3].t_data[i] = mydata[1].t_data[i];
	}
	for (int i = TYPE - 1; i >= TYPE / 2; i--) {
		mydata[2].t_data[i] = mydata[1].t_data[i];
		mydata[3].t_data[i] = mydata[0].t_data[i];
	}

}

/**
* @fn void mutation(data* mydata)
* @brief �ˑR�ψ�
* @return void �Ȃ�
* @detail �����_���ŏ�ʂ̃f�[�^�����ւ���B
* @date 2019/05/13
*/
void mutation(data* mydata) {

	for (int i = 0; i < TYPE / 2; i++) {
		mydata[0].t_data[TYPE-i] = mydata[0].t_data[i];
		mydata[1].t_data[TYPE-i] = mydata[1].t_data[i];
	}
}