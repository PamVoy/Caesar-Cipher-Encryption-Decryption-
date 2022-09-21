/*
   Caesar Cipher (Decryption):

   transform formula: Y = (A*X + B) mod 26

   X = ( Y - B + 26*j) / A ; j = 1,2,3....,n ; X = 0~25
   select j value from [1,2,3...,n] when ( Y - B + 26*j ) mod A = 0

   X : input cipher character (a~z , A~Z , white space , 0~9 , dot , marks...)
   Y : output plaintext character (a~z , A~Z , white space , 0~9 , dot , marks...)
   A : any positive number ( A ��2n , A ��13n , n = 1,2,3~ )
   B : any positive number 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {                         // �K��ѱK main function

	int input_parameter_A;           // �Ѽ�A,�����,A����2��13������
	int input_parameter_B;           // �Ѽ�B,�����  ( A,B �ݻP�[�K�ϥΪ��ѼƬۦP )  
	char* input_data_matrix = 0;     // ��l��,�ū���,�ثe�����V����O����Ŷ�,�ǳƫ��V��J�K��}�C
	int data_length = 0;             // �_�l�K��}�C���׬� 0
	char input_detect;               // ��J�K��

	printf("Please type parameter A.(Numbers) (A ��2n , A ��13n) Then press 'Enter'.\n");
	
	scanf("%d", &input_parameter_A);                                       // ���w�Ѽ�A
	printf("Please type parameter B.(Numbers). Then press 'Enter'.\n");
	scanf(" %d", &input_parameter_B);                                      // ���w�Ѽ�B
	printf("Please type Ciphertext letters. Then press 'Enter'.\n");
	getchar();
	printf("\n");

	while (scanf("%c", &input_detect) == 1) {                               // Ū���C�ӿ�J�r��
		if (input_detect == '\n') break;                                    // �פ���� : ��J 'Enter'

		input_data_matrix = realloc(input_data_matrix, sizeof(char) * (data_length + 1));
		// ���s����J�r����,�s�إB�X�jinput_data_matrix,�ǳƩ�J�s�r��
		// data_length +1(�쥻�������+1),�s�}�C�Ŷ��W�j�@��char,1 byte = 8 bits
        // �N�°}�C���,�ƻs��s�}�C�Ŷ�
        // �����°}�C,�k�٥��ϥΪ��O����
        // ���� ( char*input_data_matrix ) ���V�s�}�C

		input_data_matrix[data_length] = input_detect;                 // �N�s��J���r��,��binput_data_matrix���̫�@�Ӧ�m
		data_length++;                                                 // �K�����+1,�N��ثe��J�F�h�֭Ӧr��
	}

	printf("\n");
	printf(" parameter A : %d\n ", input_parameter_A);                 // �L�X�Ѽ�A
	printf("parameter B : %d\n ", input_parameter_B);                  // �L�X�Ѽ�B
	printf("\n\n");

	printf("Input Message :");                                         // �L�X��J����r,�Ÿ�,�Ů�
	for (int i = 0; i < data_length; i++) {
		printf("%c", input_data_matrix[i]);
	}
	printf("\n\n");


	printf("Ciphertext : ");                                           // �L�X�K��,�����p�g�r��,�Ů�; ���L�X�Ÿ�
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] == ' ') {                             // �L�X�Ů�
			printf(" ");
		}

		if (input_data_matrix[i] >= 'A' && input_data_matrix[i] <= 'Z') {    // �r���j�p�g�ഫ
			input_data_matrix[i] = input_data_matrix[i] - 'A' + 'a';
		}
		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {    // �H�p�g,�L�X�K��
			printf("%c", input_data_matrix[i]);
		}
	}
	printf("\n\n");

	printf("=======================================\n\n");

	printf("1st Transform Number Sequence : ");                               // stage1. characters ASCII transform, then print ASCII of each character.
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] == ' ') {                                    // �O�d�Ů�,���ഫ
			printf(" ");
		}
		if (input_data_matrix[i] >= 'A' && input_data_matrix[i] <= 'Z') {     // �r���j�p�g, ASCII �ഫ
			input_data_matrix[i] = input_data_matrix[i] - 'A' + 'a';
		}
		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {     // �ഫ�p�g�r���� ASCII ( a~y : 1~25, z = 0 )
			input_data_matrix[i] = (int)input_data_matrix[i] - 96;
			if (input_data_matrix[i] == 26) {
				input_data_matrix[i] = 0;                                     // z �� ASCII �]�w�� 0,�ǳƥΨӸѱK����
				printf("%d ", input_data_matrix[i]);
			}
			else { printf("%d ", input_data_matrix[i]); }                     // �L�X�p�g�r���� ASCII ( a~y : 1~25, z = 0 )
		}
	}
	printf("\n\n");

	printf("2nd Transform Number Sequence : ");                               // stage2. Caesar Cipher (Decryption) : transform formula: Y = (A*X + B) mod 26
	for (int i = 0; i < data_length; i++) {                                   // try to reverse the formula and find X
		if (input_data_matrix[i] == ' ') {                                    // �O�d�Ů�,���ഫ
			printf(" ");
		}

		// X = ( Y - B + 26*j) / A ; j = 1,2,3....,n ; X = 0~25
		// select j value from [1,2,3...,n] when ( Y - B + 26*j ) mod A = 0

		if (input_data_matrix[i] != ' ' && input_data_matrix[i] >= 0 && input_data_matrix[i] <= 26) {        // �u�ഫ ( a~y : 1~25, z = 0 )
			for (int j = 0; j < (input_parameter_A * 1.5); j++) {                                            // ����j��,���F��� j ��(�n�[�X����26)
				if ((input_data_matrix[i] - input_parameter_B + 26 * j) % input_parameter_A == 0 \
					&& (input_data_matrix[i] - input_parameter_B + 26 * j) > 0 \
					&& ((input_data_matrix[i] - input_parameter_B + 26 * j) / input_parameter_A) <= 26) {
					input_data_matrix[i] = (input_data_matrix[i] - input_parameter_B + 26 * j) / input_parameter_A;  //  X = ( Y - B + 26*j) / A

					// �W�z if �A����,����� j ��(�n�[�X����26),���X�j�骺����]�w
					// ( Y - B + 26*j ) mod A = 0 , �⦡�㰣,�N�Y��쪺 j ��,�� X �Ȭ����,�ǳ��ഫ�� a~z �� ASCII
					// �B ���l( Y - B + 26*j )�j��0, �B X �����G���� [0,25]
				   
					printf("%d ", input_data_matrix[i]);   // �L�X�ഫ�᪺���� ASCII (0~25)
					break;                                 // �@��� mod A = 0 �� j,�ߨ���X�j��
				}
			}
		}
	}
	printf("\n\n");

	printf("3rd Transform Number Sequence : ");                      // stage3. Caesar Cipher (Decryption) :  (a~z) ASCII
	for (int i = 0; i < data_length; i++) {
		if (input_data_matrix[i] == ' ') {                           // �L�X�Ů�
			printf(" ");
		}
		if (input_data_matrix[i] != ' ' && input_data_matrix[i] >= 0 && input_data_matrix[i] <= 26) { 
			                                                         // �u�ഫ ASCII(0~25),�O�d�Ů�,���ഫ
			input_data_matrix[i] = input_data_matrix[i] + 96;        // ���� ASCII(0~25) + 96, �����s�� ASCII, �����r��(a~z)
			printf("%d ", input_data_matrix[i]);                     // �L�X�����ഫ���r�� (a~z) �� ASCII
		}
	}
	printf("\n\n");
	printf("=======================================\n\n");

	printf("Plaintext : ");                                          // �L�X����, �����p�g�r��,�Ů�,�Ÿ�
	for (int i = 0; i < data_length; i++) {

		printf("%c", input_data_matrix[i]);
	}
	printf("\n\n");

	printf("Processing is over.\n");                                  // �ѱK����   
	while (1) { ; }
	return 0;
}

