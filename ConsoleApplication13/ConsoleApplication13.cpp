// ConsoleApplication13.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "stdio.h"
#include"stdlib.h"
#include <time.h>

//���I�ɎQ������l��
static int all; 
//���I����l��
static int winner; 

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
/*void lottery(int all, int winner) {
	int i = 0;
	//���I�ҏ��ʂ�����ϐ�
	int win = 1;                    

	//0�ŏ����������傫�Ȕz�������
	int a[100] = { 0 };             
	
	//���I�\��l�����A�����ł�������o��
	for (win = 1; win <= winner;) {  
		srand(time(NULL));

		//���I�҂̔ԍ��𗐐��Ō���A����������ϐ���num�Ƃ���
		int num = rand() % all + 1; 

		//�����̂ЂƂ����������̔z��̉ӏ���0�������Ă���ꍇ
		if (a[num - 1] == 0) {      
			a[num - 1] = num;       //���̒l���i�[����
			printf("%d���@%d��\n", win, num);
			win += 1;               //���I���ʂ��J�E���g�A�b�v
		}
	}
}*/

void lottery(int all, int winner) {
	//�z��ɐ���������Ƃ��J�E���g�A�b�v�ɂ����ϐ�
	int i = 0;
	//�\�[�g����񐔂𐔂���ϐ�
	int a; 
	int ary[100]; 
	int ary2 = 0; //�\�[�g���邽�߂̕ϐ�

	for (; i < all; i++) {
		ary[i] = i + 1;
	}

	srand((unsigned)time(NULL)); //�����̏�����

	//�\�[�g����
	for (a = 0; a < all; a++) {
		
		int num = rand() % all + 1;
		ary2 = ary[a];
		ary[a] = ary[num];
		ary[num] = ary2;
	}

	for (i = 0; i < winner; i++) {
		printf("%d���@%d��\n", i+1, ary[i]);
	}

}