/*
   Caesar Cipher (Decryption):

   transform formula: Y = (A*X + B) mod 26

   X = ( Y - B + 26*j) / A ; j = 1,2,3....,n ; X = 0~25
   select j value from [1,2,3...,n] when ( Y - B + 26*j ) mod A = 0

   X : input cipher character (a~z , A~Z , white space , 0~9 , dot , marks...)
   Y : output plaintext character (a~z , A~Z , white space , 0~9 , dot , marks...)
   A : any positive number ( A ≠2n , A ≠13n , n = 1,2,3~ )
   B : any positive number 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {                         // 密文解密 main function

	int input_parameter_A;           // 參數A,正整數,A不為2或13的倍數
	int input_parameter_B;           // 參數B,正整數  ( A,B 需與加密使用的參數相同 )  
	char* input_data_matrix = 0;     // 初始化,空指標,目前為指向任何記憶體空間,準備指向輸入密文陣列
	int data_length = 0;             // 起始密文陣列長度為 0
	char input_detect;               // 輸入密文

	printf("Please type parameter A.(Numbers) (A ≠2n , A ≠13n) Then press 'Enter'.\n");
	
	scanf("%d", &input_parameter_A);                                       // 指定參數A
	printf("Please type parameter B.(Numbers). Then press 'Enter'.\n");
	scanf(" %d", &input_parameter_B);                                      // 指定參數B
	printf("Please type Ciphertext letters. Then press 'Enter'.\n");
	getchar();
	printf("\n");

	while (scanf("%c", &input_detect) == 1) {                               // 讀取每個輸入字母
		if (input_detect == '\n') break;                                    // 終止條件 : 輸入 'Enter'

		input_data_matrix = realloc(input_data_matrix, sizeof(char) * (data_length + 1));
		// 有新的輸入字母時,新建且擴大input_data_matrix,準備放入新字母
		// data_length +1(原本明文長度+1),新陣列空間增大一個char,1 byte = 8 bits
        // 將舊陣列資料,複製到新陣列空間
        // 移除舊陣列,歸還未使用的記憶體
        // 指標 ( char*input_data_matrix ) 指向新陣列

		input_data_matrix[data_length] = input_detect;                 // 將新輸入的字母,放在input_data_matrix的最後一個位置
		data_length++;                                                 // 密文長度+1,代表目前輸入了多少個字母
	}

	printf("\n");
	printf(" parameter A : %d\n ", input_parameter_A);                 // 印出參數A
	printf("parameter B : %d\n ", input_parameter_B);                  // 印出參數B
	printf("\n\n");

	printf("Input Message :");                                         // 印出輸入的文字,符號,空格
	for (int i = 0; i < data_length; i++) {
		printf("%c", input_data_matrix[i]);
	}
	printf("\n\n");


	printf("Ciphertext : ");                                           // 印出密文,全為小寫字母,空格; 不印出符號
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] == ' ') {                             // 印出空格
			printf(" ");
		}

		if (input_data_matrix[i] >= 'A' && input_data_matrix[i] <= 'Z') {    // 字母大小寫轉換
			input_data_matrix[i] = input_data_matrix[i] - 'A' + 'a';
		}
		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {    // 以小寫,印出密文
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
		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {     // 轉換小寫字母的 ASCII ( a~y : 1~25, z = 0 )
			input_data_matrix[i] = (int)input_data_matrix[i] - 96;
			if (input_data_matrix[i] == 26) {
				input_data_matrix[i] = 0;                                     // z 的 ASCII 設定為 0,準備用來解密換算
				printf("%d ", input_data_matrix[i]);
			}
			else { printf("%d ", input_data_matrix[i]); }                     // 印出小寫字母的 ASCII ( a~y : 1~25, z = 0 )
		}
	}
	printf("\n\n");

	printf("2nd Transform Number Sequence : ");                               // stage2. Caesar Cipher (Decryption) : transform formula: Y = (A*X + B) mod 26
	for (int i = 0; i < data_length; i++) {                                   // try to reverse the formula and find X
		if (input_data_matrix[i] == ' ') {                                    // 保留空格,不轉換
			printf(" ");
		}

		// X = ( Y - B + 26*j) / A ; j = 1,2,3....,n ; X = 0~25
		// select j value from [1,2,3...,n] when ( Y - B + 26*j ) mod A = 0

		if (input_data_matrix[i] != ' ' && input_data_matrix[i] >= 0 && input_data_matrix[i] <= 26) {        // 只轉換 ( a~y : 1~25, z = 0 )
			for (int j = 0; j < (input_parameter_A * 1.5); j++) {                                            // 執行迴圈,為了找到 j 值(要加幾倍的26)
				if ((input_data_matrix[i] - input_parameter_B + 26 * j) % input_parameter_A == 0 \
					&& (input_data_matrix[i] - input_parameter_B + 26 * j) > 0 \
					&& ((input_data_matrix[i] - input_parameter_B + 26 * j) / input_parameter_A) <= 26) {
					input_data_matrix[i] = (input_data_matrix[i] - input_parameter_B + 26 * j) / input_parameter_A;  //  X = ( Y - B + 26*j) / A

					// 上述 if 括號內,為找到 j 值(要加幾倍的26),跳出迴圈的條件設定
					// ( Y - B + 26*j ) mod A = 0 , 算式整除,意即找到的 j 值,使 X 值為整數,準備轉換為 a~z 的 ASCII
					// 且 分子( Y - B + 26*j )大於0, 且 X 的結果介於 [0,25]
				   
					printf("%d ", input_data_matrix[i]);   // 印出轉換後的明文 ASCII (0~25)
					break;                                 // 一找到 mod A = 0 的 j,立刻跳出迴圈
				}
			}
		}
	}
	printf("\n\n");

	printf("3rd Transform Number Sequence : ");                      // stage3. Caesar Cipher (Decryption) :  (a~z) ASCII
	for (int i = 0; i < data_length; i++) {
		if (input_data_matrix[i] == ' ') {                           // 印出空格
			printf(" ");
		}
		if (input_data_matrix[i] != ' ' && input_data_matrix[i] >= 0 && input_data_matrix[i] <= 26) { 
			                                                         // 只轉換 ASCII(0~25),保留空格,不轉換
			input_data_matrix[i] = input_data_matrix[i] + 96;        // 明文 ASCII(0~25) + 96, 換為新的 ASCII, 對應字母(a~z)
			printf("%d ", input_data_matrix[i]);                     // 印出明文轉換成字母 (a~z) 的 ASCII
		}
	}
	printf("\n\n");
	printf("=======================================\n\n");

	printf("Plaintext : ");                                          // 印出明文, 全為小寫字母,空格,符號
	for (int i = 0; i < data_length; i++) {

		printf("%c", input_data_matrix[i]);
	}
	printf("\n\n");

	printf("Processing is over.\n");                                  // 解密結束   
	while (1) { ; }
	return 0;
}

