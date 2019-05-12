#pragma once

#ifndef __main__
#define __main__
#endif
#define _CRT_SECURE_NO_WARNINGS 

/** @def
* ARRAY    子の生成個数
* TYPE     dataの要素数
* LIMIT    今回の重みの限界値
*/
#define ARRAY	 4
#define TYPE	 8
#define LIMIT	15


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** @struct
* rank            順位
* val             評価
* t_data[TYPE]    評価データ
*/
typedef struct {
	int rank;
	int val;
	int t_data[TYPE];
} data;

void reset(data* mydata);		// 構造体初期化
void i_ran(data* mydata);		// 乱数格納
void rank(data* mydata);		// val付け
void sort(data* mydata);		// valのソート（降順）
void change(data* mydata);		// 掛け合わせ
void view(data* mydata);		// 出力
void mutation(data* mydata);	// 突然変異
