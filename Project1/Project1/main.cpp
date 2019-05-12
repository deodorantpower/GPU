#include "main.h"

typedef struct {
	int rank;
	int val;
	int t_data[TYPE];
} data;

void reset(data* mydata);		//! \‘¢‘Ì‰Šú‰»
void i_ran(data* my_data);		//! —”Ši”[
void rank(data* my_data);		//! val•t‚¯
void sort(data* my_data);		//! val‚Ìƒ\[ƒgi~‡j
void change(data* my_data);		//! Š|‚¯‡‚í‚¹

void main(void) {

	data mydata[ARRAY];			//! \‘¢‘ÌÀ‘Ì¶¬

	reset(mydata);				//! ‰Šú‰»
	
	i_ran(mydata);				//! —”Ši”[

	for (int loop = 0; loop < 200; loop++) {

		rank(mydata);				//! rank•t‚¯
		sort(mydata);				//! ƒ\[ƒg

/*		for (int i = 0; i < ARRAY; i++) {
			printf("rank:%d val%02dF", mydata[i].rank, mydata[i].val);
			for (int j = 0; j < TYPE; j++) {
				printf("%d", mydata[i].t_data[j]);
			}
			printf("\n");
		}*/

		change(mydata);				//! Š|‚¯‡‚í‚¹
	}

	for (int i = 0; i < ARRAY; i++) {
		printf("rank:%d val:%04dF", mydata[i].rank, mydata[i].val);
		for (int j = 0; j < TYPE; j++) {
			printf("%d", mydata[i].t_data[j]);
		}
		printf("\n");
	}

	system("pause");

}

/** \‘¢‘Ì‰Šú‰»
*/
void reset(data* mydata) {

	//! “ñŸŒ³”z—ñ‚Ì‰Šú‰»
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
* @fn void i_ran()
* @brief —”‚ğ“ñŸŒ³”z—ñ‚ÑŠi”[
* @return void ‚È‚µ
* @details —”‚ÌŠi”[
*/
void i_ran(data* my_data) {
	//—”
	srand((unsigned)time(NULL));

	//—”Ši”[
	for (int i = 0; i < ARRAY; i++) {
		for (int j = 0; j < TYPE; j++) {
			my_data[i].t_data[j] = rand() % 2;
		}
	}
}

void rank(data* my_data) {

	//! d‚İ‚Æ‰¿’l”z—ñ@
	int weight[TYPE] = { 2,  4, 6,   1,   8,   9,  10,   1 };
	int price[TYPE] = { 100, 10, 5, 100, 200, 150, 300, 500 };

	//!d‚³ƒŠƒ~ƒbƒg”äŠr
	int w_temp = 0;
	int p_temp = 0;

	for (int i = 0; i < ARRAY; i++) {
		for (int j = 0; j < TYPE; j++) {
			w_temp += my_data[i].t_data[j] * weight[i];
			if (my_data[i].t_data[j] == 1) {
				p_temp += weight[i] * price[i];
			}
		}
		if (w_temp < LIMIT) {
			my_data[i].val = p_temp;
		}
		else {
			my_data[i].val = 0;
		}
		w_temp = 0;
	}
}

void sort(data* my_data) {

	data temp;

	for (int i = 0; i< ARRAY; i++) {
		for (int j = ARRAY - 1; j > i; j--) {
			if (my_data[j].val > my_data[j - 1].val) {
				memcpy(&temp, &my_data[j], sizeof(data));
				memcpy(&my_data[j], &my_data[j-1], sizeof(data));
				memcpy(&my_data[j-1], &temp, sizeof(data));
			}
		}
	}
	for (int i = 0; i < ARRAY; i++) {
		my_data[i].rank = i+1;
	}
}

void change(data* my_data) {

		//! rank1ˆÊ‚Ærank2ˆÊ‚ÌãˆÊ‚Æ‰ºˆÊrank3ˆÊ‚ÉŠi”[
	for (int i = 0; i < TYPE/2; i++) {
		my_data[2].t_data[i] = my_data[0].t_data[i];
		my_data[3].t_data[i] = my_data[1].t_data[i];
	}
	for (int i = TYPE - 1; i >= TYPE / 2; i--) {
		my_data[2].t_data[i] = my_data[1].t_data[i];
		my_data[3].t_data[i] = my_data[0].t_data[i];
	}

}
