/*
   Caesar Cipher (Encryption):

   transform formula: Y = (A*X + B) mod 26

   X : input character (a~z , A~Z , white space , 0~9 , dot , marks...)
   Y : output cipher character (a~z , A~Z , white space , 0~9 , dot , marks...)
   A : positive number ( A ��2n , A ��13n , n = 1,2,3~ )
   B : positive number 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {                      // ����[�K main function

	int input_parameter_A;        // �Ѽ�A,�����,A����2��13������
	int input_parameter_B;        // �Ѽ�B,�����      
	char* input_data_matrix = 0;  // ��l��,�ū���,�ثe�����V����O����Ŷ�,�ǳƫ��V��J����}�C
	int data_length = 0;          // �_�l����}�C���׬� 0
	char input_detect;            // ��J����

	printf("Please type parameter A.(Numbers) (A ��2n , A ��13n) Then press 'Enter'.\n");
	scanf("%d", &input_parameter_A);                                         // ���w�Ѽ�A
	printf("Please type parameter B.(Numbers). Then press 'Enter'.\n");
	scanf(" %d", &input_parameter_B);                                        // ���w�Ѽ�B
	printf("Please type Message letters. Then press 'Enter'.\n");
	getchar();
	printf("\n");

	while (scanf("%c", &input_detect) == 1) {                                // Ū���C�ӿ�J�r��
		if (input_detect == '\n') break;                                     // �פ���� : ��J 'Enter'

		input_data_matrix = realloc(input_data_matrix, sizeof(char) * (data_length + 1));   
		// ���s����J�r����,�s�إB�X�jinput_data_matrix,�ǳƩ�J�s�r��
		// data_length +1(�쥻�������+1),�s�}�C�Ŷ��W�j�@��char,1 byte = 8 bits
		// �N�°}�C���,�ƻs��s�}�C�Ŷ�
		// �����°}�C,�k�٥��ϥΪ��O����
		// ���� ( char*input_data_matrix ) ���V�s�}�C

		input_data_matrix[data_length] = input_detect;              // �N�s��J���r��,��binput_data_matrix���̫�@�Ӧ�m
		data_length++;	                                            // �������+1,�N��ثe��J�F�h�֭Ӧr��
	}

	printf("\n");
	printf(" parameter A : %d\n ", input_parameter_A);                       // �L�X�Ѽ�A
	printf("parameter B : %d\n ", input_parameter_B);                        // �L�X�Ѽ�B
	printf("\n\n");

	printf("Input Message :");                                               // �L�X��J����r,�Ÿ�,�Ů�
	for (int i = 0; i < data_length; i++) {
		printf("%c", input_data_matrix[i]);
	}
	printf("\n\n");


	printf("Plaintext : ");                                                  // �L�X����,�����p�g�r��,�Ů�; ���L�X�Ÿ�
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] == ' ') {                                   // �L�X�Ů�
			printf(" ");
		}

		if (input_data_matrix[i] >= 'A' && input_data_matrix[i] <= 'Z') {    // �r���j�p�g�ഫ
			input_data_matrix[i] = input_data_matrix[i] - 'A' + 'a';
		}
		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {    // �H�p�g,�L�X����
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
		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {     // �L�X�p�g�r���� ASCII ( a~z : 1~26 )
			input_data_matrix[i] = (int)input_data_matrix[i] - 96;
			printf("%d ", input_data_matrix[i]);
		}
	}
	printf("\n\n");

	printf("2nd Transform Number Sequence : ");                               // stage2. Caesar Cipher (Encryption) : transform formula: Y = (A*X + B) mod 26
	for (int i = 0; i < data_length; i++) {
		if (input_data_matrix[i] == ' ') {                                    // �O�d�Ů�,���ഫ
			printf(" ");
		}
		if (input_data_matrix[i] >= 0 && input_data_matrix[i] <= 26) {        // �u�ഫ  ( a~z : 1~26 )

			input_data_matrix[i] = (input_parameter_A * input_data_matrix[i] + input_parameter_B) % 26;     // Y = (A * X + B) mod 26 ,  X:����; Y:�K�� (0~25)

			printf("%d ", input_data_matrix[i]);                              // �L�X mod 26 �����G (0~25)

			input_data_matrix[i] = input_data_matrix[i] + 96;                 // �K�� ASCII (0~25) + 96 ,�����s�� ASCII, �����r�� (a~z)
			printf("%d ", input_data_matrix[i]);                              // �L�X�K��p�g�r���� ASCII
		}
	}
	printf("\n\n");

	printf("=======================================\n\n");

	printf("Ciphertext : ");                                                  // �L�X�K��, �����p�g�r��,�Ů�,�Ÿ�
	for (int i = 0; i < data_length; i++) {
		if (input_data_matrix[i] == 96) {
			(char)input_data_matrix[i] = 'z';
		}
		if (input_data_matrix[i] == ' ') {                                    // �L�X�Ů�
			printf(" ");
		}
		else
			printf("%c", input_data_matrix[i]);                               // �L�X�Ů�H�~�����
	}
	printf("\n\n");

	printf("Processing is over.\n");                                          // �[�K����
	while (1) { ; }
	return 0;
}
