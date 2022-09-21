#include <stdio.h>
#include <stdlib.h>

int main() {                         // �K��ѱK main function

	char encryption_table[26] = { 0 }; // ��l��,�ѱK��Ӫ�
	char decryption_table[26] = { 0 };

	int input_parameter_A;           // �Ѽ�A,�����,A����2��13������
	int input_parameter_B;           // �Ѽ�B,�����  ( A,B �ݻP�[�K�ϥΪ��ѼƬۦP )  
	char* input_data_matrix = 0;     // ��l��,�ū���,�ثe�����V����O����Ŷ�,�ǳƫ��V��J�K��}�C
	int data_length = 0;             // �_�l�K��}�C���׬� 0
	char input_detect;               // ��J�K��

	printf("Please type parameter A.(Numbers) (A ��2n , A ��13n) Then press 'Enter'.\n");

	scanf("%d", &input_parameter_A);                                       // ���w�Ѽ�A
	printf("Please type parameter B.(Numbers). Then press 'Enter'.\n");
	scanf(" %d", &input_parameter_B);                                      // ���w�Ѽ�B

	printf("\n\n");
	for (int i = 0; i < 26; i++) {                                          // encryption_table �̧Ƕ�J 1~26
		encryption_table[i] = i + 1;
	}

	for (int i = 0; i < 26; i++) {
		encryption_table[i] = (input_parameter_A * encryption_table[i] + input_parameter_B) % 26;  // encryption_table �ഫ�� 0~25
		                                                                                           // Y = ( A * X + B ) % 26
		//printf("%d ", encryption_table[i]);                                                        // �L�X encryption_table 0~25
	}
	printf("\n\n");

	for (int i = 0; i < 26; i++) {

		if (encryption_table[i] == 0) {
			encryption_table[i] = 26 + 96;                                                          // encryption_table [ ] = 0 = z
		}
		else {
			encryption_table[i] = encryption_table[i] + 96;                                         // ASCII 1~25 -> a~y
		}
		//printf("%c ", encryption_table[i]);                                                         // �L�Xencryption_table : a~z
	}
	printf("\n\n");

	for (int i = 0; i < 26; i++) {                                                                  // �إ� decryption_table                                     
		
		decryption_table[encryption_table[i] - 97] = 97 + i;                                        // encryption_table �� value �@��  decryption_table ����m,�̧Ƕ�J a~z              
	}

	for (int i = 0; i < 26; i++) {

		//printf("%c ", decryption_table[i]);
	}

	printf("\n\n");
	printf("==============================================================\n");
	printf("\nDecryption Looking Table :\n");                                            // �L�X�ѱK��Ӫ�,�K��d��,�o�����
	printf("\n");
	printf("Ciphertext\n");
	printf("| \n");
	printf("Plaintext\n");
	printf("\n");
	printf("==============================================================\n");

	for (int i = 0; i < 26; i++) {                                                       // �L�X�K��r��,�̧� a~z
		encryption_table[i] = i + 97;
		printf("%c ", encryption_table[i]);
	}

	printf("\n");

	for (int i = 0; i < 26; i++) {
		printf("| ");
	}
	printf("\n");

	for (int i = 0; i < 26; i++) {                                                      // �L�X�ѱK��Ӫ�,�̧ǹ����K��,�o�����

		printf("%c ", decryption_table[i]);
	}
	printf("\n");
	printf("==============================================================\n");
	printf("\n\n");

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
	
	printf("==============================================================\n");

	printf("\n");
	printf("Plaintext : ");                                           // �L�X�K��,�����p�g�r��,�Ů�; ���L�X�Ÿ�
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {          // �w��p�g,�i��d��
			input_data_matrix[i] = decryption_table [input_data_matrix[i] - 97];   // input_data_matrix[i] - 97 �@���d�� index, �d�� decryption_table
			printf("%c", input_data_matrix[i]);                                    // �L�X�p�g�r��
		}

		else
			printf("%c", input_data_matrix[i]);                         // �L�X�Ÿ�,�Ů�
	}
	printf("\n\n");
	printf("Processing is over.\n");                                    // �ѱK����
	while (1) { ; }
	return 0;
}

