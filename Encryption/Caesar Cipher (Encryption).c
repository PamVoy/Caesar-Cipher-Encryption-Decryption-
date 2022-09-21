/*
   Caesar Cipher (Encryption):

   transform formula: Y = (A*X + B) mod 26

   X : input character (a~z , A~Z , white space , 0~9 , dot , marks...)
   Y : output cipher character (a~z , A~Z , white space , 0~9 , dot , marks...)
   A : positive number ( A ≠2n , A ≠13n , n = 1,2,3~ )
   B : positive number 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {                      // 明文加密 main function

	int input_parameter_A;        // 參數A,正整數,A不為2或13的倍數
	int input_parameter_B;        // 參數B,正整數      
	char* input_data_matrix = 0;  // 初始化,空指標,目前為指向任何記憶體空間,準備指向輸入明文陣列
	int data_length = 0;          // 起始明文陣列長度為 0
	char input_detect;            // 輸入明文

	printf("Please type parameter A.(Numbers) (A ≠2n , A ≠13n) Then press 'Enter'.\n");
	scanf("%d", &input_parameter_A);                                         // 指定參數A
	printf("Please type parameter B.(Numbers). Then press 'Enter'.\n");
	scanf(" %d", &input_parameter_B);                                        // 指定參數B
	printf("Please type Message letters. Then press 'Enter'.\n");
	getchar();
	printf("\n");

	while (scanf("%c", &input_detect) == 1) {                                // 讀取每個輸入字母
		if (input_detect == '\n') break;                                     // 終止條件 : 輸入 'Enter'

		input_data_matrix = realloc(input_data_matrix, sizeof(char) * (data_length + 1));   
		// 有新的輸入字母時,新建且擴大input_data_matrix,準備放入新字母
		// data_length +1(原本明文長度+1),新陣列空間增大一個char,1 byte = 8 bits
		// 將舊陣列資料,複製到新陣列空間
		// 移除舊陣列,歸還未使用的記憶體
		// 指標 ( char*input_data_matrix ) 指向新陣列

		input_data_matrix[data_length] = input_detect;              // 將新輸入的字母,放在input_data_matrix的最後一個位置
		data_length++;	                                            // 明文長度+1,代表目前輸入了多少個字母
	}

	printf("\n");
	printf(" parameter A : %d\n ", input_parameter_A);                       // 印出參數A
	printf("parameter B : %d\n ", input_parameter_B);                        // 印出參數B
	printf("\n\n");

	printf("Input Message :");                                               // 印出輸入的文字,符號,空格
	for (int i = 0; i < data_length; i++) {
		printf("%c", input_data_matrix[i]);
	}
	printf("\n\n");


	printf("Plaintext : ");                                                  // 印出明文,全為小寫字母,空格; 不印出符號
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] == ' ') {                                   // 印出空格
			printf(" ");
		}

		if (input_data_matrix[i] >= 'A' && input_data_matrix[i] <= 'Z') {    // 字母大小寫轉換
			input_data_matrix[i] = input_data_matrix[i] - 'A' + 'a';
		}
		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {    // 以小寫,印出明文
			printf("%c", input_data_matrix[i]);
		}
	}
	printf("\n\n");

	printf("=======================================\n\n");

	printf("1st Transform Number Sequence : ");                               // stage1. characters ASCII transform, then print ASCII of each character.
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] == ' ') {                                    // 保留空格,不轉換
			printf(" ");
		}

		if (input_data_matrix[i] >= 'A' && input_data_matrix[i] <= 'Z') {     // 字母大小寫, ASCII 轉換
			input_data_matrix[i] = input_data_matrix[i] - 'A' + 'a';
		}
		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {     // 印出小寫字母的 ASCII ( a~z : 1~26 )
			input_data_matrix[i] = (int)input_data_matrix[i] - 96;
			printf("%d ", input_data_matrix[i]);
		}
	}
	printf("\n\n");

	printf("2nd Transform Number Sequence : ");                               // stage2. Caesar Cipher (Encryption) : transform formula: Y = (A*X + B) mod 26
	for (int i = 0; i < data_length; i++) {
		if (input_data_matrix[i] == ' ') {                                    // 保留空格,不轉換
			printf(" ");
		}
		if (input_data_matrix[i] >= 0 && input_data_matrix[i] <= 26) {        // 只轉換  ( a~z : 1~26 )

			input_data_matrix[i] = (input_parameter_A * input_data_matrix[i] + input_parameter_B) % 26;     // Y = (A * X + B) mod 26 ,  X:明文; Y:密文 (0~25)

			printf("%d ", input_data_matrix[i]);                              // 印出 mod 26 的結果 (0~25)

			input_data_matrix[i] = input_data_matrix[i] + 96;                 // 密文 ASCII (0~25) + 96 ,換為新的 ASCII, 對應字母 (a~z)
			printf("%d ", input_data_matrix[i]);                              // 印出密文小寫字母的 ASCII
		}
	}
	printf("\n\n");

	printf("=======================================\n\n");

	printf("Ciphertext : ");                                                  // 印出密文, 全為小寫字母,空格,符號
	for (int i = 0; i < data_length; i++) {
		if (input_data_matrix[i] == 96) {
			(char)input_data_matrix[i] = 'z';
		}
		if (input_data_matrix[i] == ' ') {                                    // 印出空格
			printf(" ");
		}
		else
			printf("%c", input_data_matrix[i]);                               // 印出空格以外的資料
	}
	printf("\n\n");

	printf("Processing is over.\n");                                          // 加密結束
	while (1) { ; }
	return 0;
}
