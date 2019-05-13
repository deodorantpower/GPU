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

	data mydata[ARRAY];			

	//������
	reset(mydata);	
	// �����i�[
	i_ran(mydata);			

	for (int i = 0; i < ANSER; i++) {
		//! �ˑR�ψٗ���
		srand((unsigned)time(NULL));
		// rank�t��
		rank(mydata);
		// �o�u���\�[�g
		sort(mydata);

		if (rand() % 1000 == 1) {
			mutation(mydata);
		}
		// �|�����킹
		change(mydata);
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

	// ��ʓ�ʂ�\��
	for (int i = 0; i < 4; i++) {
		printf("rank:%d price:%d weight:%f:", mydata[i].rank, mydata[i].val,mydata[i].weight);
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
	float weight[TYPE] = { 
		1.042288f, 1.096132f, 0.952216f,  0.79302f, 1.046246f, 0.823767f, 0.873065f, 0.758806f,
		0.737015f, 1.028084f, 0.606415f, 0.881106f, 0.884353f, 1.290026f, 0.774216f, 1.014714f,
		1.229122f, 1.015562f, 0.964802f, 1.288146f, 1.076072f, 0.952694f, 0.704871f, 0.904247f,
		0.846266f, 0.837016f, 1.059204f, 0.699134f, 0.870344f, 0.858246f, 0.743155f, 0.800332f,
		1.160441f, 0.715929f, 1.206835f, 1.056951f, 0.898189f, 1.226303f, 1.025044f, 0.640907f,
		0.899368f, 1.225172f, 0.901907f, 1.068226f, 0.712972f, 1.055511f, 1.114367f, 0.632971f,
		1.235422f, 0.818592f, 1.277626f, 0.976713f, 0.825303f, 0.786353f, 0.904311f, 1.125975f,
		0.9002f, 0.687584f, 1.253057f, 0.609091f,  0.88333f,  0.89934f, 0.928529f, 1.195918f };

	int price[TYPE] = { 515, 802, 778, 406, 146, 914, 929, 317,
						556, 788, 438, 897, 127, 425, 909, 650,
						802, 532, 768, 524, 376, 204, 113, 627,
						256, 869, 488, 932, 229, 418, 147, 234,
						210, 290, 161, 655, 820, 981, 835, 903,
						864, 468, 908, 421, 128, 446, 298, 289,
						762, 358, 165, 636, 631, 781, 196, 421,
						446, 402, 431, 205, 511, 441, 680, 688 };

	//! �d�݂Ɖ��l�̈ꎞ�i�[
	float w_temp = 0;			
	int p_temp = 0;			

	for (int i = 0; i < ARRAY; i++) {
		for (int j = 0; j < TYPE; j++) {

			// �d�݂Ɖ��l�̎Z�o
			if (mydata[i].t_data[j] == 1) {
				p_temp += price[j];
				// �d�݂̏W�v
				w_temp +=weight[j];
			}
		}
		// �d�݂̃��~�b�g����
		if (w_temp > LIMIT) {
			w_temp = 0;
			p_temp = 0;
		}
		mydata[i].val = p_temp;
		mydata[i].weight = w_temp;
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
				memcpy(&mydata[j], &mydata[j - 1], sizeof(data));
				memcpy(&mydata[j - 1], &temp, sizeof(data));
			}
		}
	}
	for (int i = 0; i < ARRAY; i++) {
		mydata[i].rank = i + 1;
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


	for (int i = 0; i < ARRAY / 2; i = i + 4) {
		for (int j = 0; j < TYPE / 2; j++) {
			mydata[i + 2].t_data[j] = mydata[i].t_data[j];
			mydata[i + 3].t_data[j] = mydata[i + 1].t_data[j];
		}
	}
	for (int i = 0; i < ARRAY / 2; i = i + 4) {
		for (int j = TYPE - 1; j >= TYPE / 2; j--) {
			mydata[i + 2].t_data[j] = mydata[i + 1].t_data[j];
			mydata[i + 3].t_data[j] = mydata[i].t_data[j];
		}
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
		mydata[0].t_data[TYPE - i] = mydata[0].t_data[i];
		mydata[1].t_data[TYPE - i] = mydata[1].t_data[i];
	}
}