// ConsoleApplication13.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "stdio.h"
#include"stdlib.h"
#include <time.h>


static int all; //���I�ɎQ������l��
static int winner; //���I����l��

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

//�S�̂̐�����͂���
int AllNum() {
	printf("�S�̂̐��͉��l�ł����H\n");
	scanf_s("%d", &all);
	printf("%d�l�̒�����", all);

	return all;
}

//���I�ł����鐔����͂���
int WinnerNum() {
	printf("������͉��l�ł����H\n");
	scanf_s("%d", &winner);
	//printf("%d�l\n", chose);

	return winner;
}


/*�N�������邩�����m�肽���ꍇ(���ׂē����i�i�̏ꍇ)*/
/*void lottery(int all, int winner) {
	
	int i;
	int a[100] = { 0 };

	//�z��̒��ɐ�������
	
	for (i = 0; i < all; i++) {
		a[i] = i + 1;
		
}
	

	//�����𒲂ׂ�
	for (i = 0; i < winner; ) {

		int num= rand() % all + 1;

		if (a[num-1] == num) {

			printf("%d�Ԗڂ̐l��������ł�\n", num);
			//all = all - 1;
			a[num - 1] = 0;
			i++;
		}
		else {

		}
	}

}*/

/*���ʂ��������ꍇ*/
void lottery(int all, int winner) {
	int i = 0;
	int win = 1;                    //���I�ҏ��ʂ�����ϐ�

	int a[100] = { 0 };             //0�ŏ����������傫�Ȕz�������

	for (win = 1; win <= winner;) {  //���I�\��l�����A�����ł�������o��

		srand(time(NULL));

		int num = rand() % all + 1; //���I�҂̔ԍ��𗐐��Ō���A����������ϐ���num�Ƃ���

		if (a[num - 1] == 0) {      //�����̂ЂƂ����������̔z��̉ӏ���0�������Ă���ꍇ
			a[num - 1] = num;       //���̒l���i�[����
			printf("%d���@%d��\n", win, num);
			win += 1;               //���I���ʂ��J�E���g�A�b�v
		}
	}
}