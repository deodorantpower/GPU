/**
* @file main.cpp
* @brief ナップサック問題の解決
* @author 長谷川　勇太
* @date 2019/05/01
*/

#include "main.h"

/**
* @fn void main(void)
* @brief ランダムで重みに価値をつけ評価していき、
         上位の掛け合わせによって最適解を算出する
* @param (void) なし
* @return void  なし
* @detail 乱数格納、rank付け、ソート、掛け合わせ、突然変異の関数呼び出し
* @date 2019/05/01
*/
void main(void) {

	//! 構造体実体生成
	data mydata[ARRAY];			

	//初期化
	reset(mydata);	
	// 乱数格納
	i_ran(mydata);			

	for (int i = 0; i < 1000; i++) {
		//! 突然変異乱数
		srand((unsigned)time(NULL));
		// rank付け
		rank(mydata);
		// バブルソート
		sort(mydata);
	
		// 掛け合わせ
		change(mydata);
	
		if (rand() % 30 == 1) {
			mutation(mydata);
		}
	}

	//上位２つ出力
	view(mydata);

	system("pause");
}

/**
* @fn void view(data* mydata)
* @brief 結果の表示
* @return void なし
* @details 構造体の表示
* @date 2019/05/01
*/
void view(data* mydata) {

	for (int i = 0; i < ARRAY/2; i++) {
		printf("rank:%d val:%05d：", mydata[i].rank, mydata[i].val);
		for (int j = 0; j < TYPE; j++) {
			printf("%d", mydata[i].t_data[j]);
		}
		printf("\n");
	}
}

/**
* @fn void reset(data* mydata)
* @brief 構造体初期化
* @return void なし
* @date 2019/05/01
*/
void reset(data* mydata) {

	//! 二次元配列の初期化
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
* @brief 乱数を構造体に格納
* @return void なし
* @date 2019/05/01
*/
void i_ran(data* mydata) {
	//乱数
	srand((unsigned)time(NULL));

	//乱数格納
	for (int i = 0; i < ARRAY; i++) {
		for (int j = 0; j < TYPE; j++) {
			mydata[i].t_data[j] = rand() % 2;
		}
	}
}

/**
* @fn void rank(data* mydata)
* @brief ランク付け
* @return void なし
* @detail 重みと価値に対する評価を行う。
*         重みがリミット内であれば重み×価値を評価とする。
* @date 2019/05/03
*/
void rank(data* mydata) {

	//! 重みと価値配列　
	int weight[TYPE] = { 2,  4, 6,   1,   8,   9,  10,   1 };
	int price[TYPE] = { 100, 10, 5, 100, 200, 150, 300, 500 };

	//! 重みと価値の一時格納
	int w_temp = 0;			
	int p_temp = 0;			

	for (int i = 0; i < ARRAY; i++) {
		for (int j = 0; j < TYPE; j++) {

			// 重みの集計
			w_temp += mydata[i].t_data[j] * weight[j];

			// 重みと価値の算出
			if (mydata[i].t_data[j] == 1) {
				p_temp += weight[j] * price[j];
			}
		}
		// 重みのリミット判定
		if (w_temp > LIMIT) {
			mydata[i].val = 0;
		}
		mydata[i].val = p_temp;

		// リセット
		p_temp = 0;
		w_temp = 0;
	}
}

/**
* @fn void sort(data* mydata)
* @brief ランクのソート
* @return void なし
* @date 2019/05/03
*/
void sort(data* mydata) {

	//! 一時格納
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
* @brief 掛け合わせ
* @return void なし
* @detail 上位二つのデータを掛け合わせ２つの子作成し、下位二つに書き換える。
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
* @brief 突然変異
* @return void なし
* @detail ランダムで上位のデータを入れ替える。
* @date 2019/05/13
*/
void mutation(data* mydata) {

	for (int i = 0; i < TYPE / 2; i++) {
		mydata[0].t_data[TYPE-i] = mydata[0].t_data[i];
		mydata[1].t_data[TYPE-i] = mydata[1].t_data[i];
	}
}