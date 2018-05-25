// ConsoleApplication13.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "stdio.h"
#include"stdlib.h"
#include <time.h>


static int all; //抽選に参加する人数
static int winner; //当選する人数

int AllNum();
int WinnerNum();
void lottery(int all, int winner);

int main()
{
	all = AllNum();
	winner = WinnerNum();

	lottery(all, winner);

    return 0;
}

//全体の数を入力する
int AllNum() {
	printf("全体の数は何人ですか？\n");
	scanf_s("%d", &all);
	printf("%d人の中から", all);

	return all;
}

//抽選であたる数を入力する
int WinnerNum() {
	printf("当たりは何人ですか？\n");
	scanf_s("%d", &winner);
	//printf("%d人\n", chose);

	return winner;
}


/*誰が当たるかだけ知りたい場合(すべて同じ景品の場合)*/
/*void lottery(int all, int winner) {
	
	int i;
	int a[100] = { 0 };

	//配列の中に数を入れる
	
	for (i = 0; i < all; i++) {
		a[i] = i + 1;
		
}
	

	//乱数を調べる
	for (i = 0; i < winner; ) {

		int num= rand() % all + 1;

		if (a[num-1] == num) {

			printf("%d番目の人が当たりです\n", num);
			//all = all - 1;
			a[num - 1] = 0;
			i++;
		}
		else {

		}
	}

}*/

/*順位をつけたい場合*/
void lottery(int all, int winner) {
	int i = 0;
	int win = 1;                    //当選者順位を入れる変数

	int a[100] = { 0 };             //0で初期化した大きな配列をつくる

	for (win = 1; win <= winner;) {  //当選予定人数分、乱数であたりを出す

		srand(time(NULL));

		int num = rand() % all + 1; //当選者の番号を乱数で決定、乱数を入れる変数をnumとする

		if (a[num - 1] == 0) {      //乱数のひとつ小さい数字の配列の箇所に0が入っている場合
			a[num - 1] = num;       //その値を格納する
			printf("%d等　%d番\n", win, num);
			win += 1;               //当選順位をカウントアップ
		}
	}
}