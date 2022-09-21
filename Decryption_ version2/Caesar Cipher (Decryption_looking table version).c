#include <stdio.h>
#include <stdlib.h>

int main() {                         // 密文解密 main function

	char encryption_table[26] = { 0 }; // 初始化,解密對照表
	char decryption_table[26] = { 0 };

	int input_parameter_A;           // 參數A,正整數,A不為2或13的倍數
	int input_parameter_B;           // 參數B,正整數  ( A,B 需與加密使用的參數相同 )  
	char* input_data_matrix = 0;     // 初始化,空指標,目前為指向任何記憶體空間,準備指向輸入密文陣列
	int data_length = 0;             // 起始密文陣列長度為 0
	char input_detect;               // 輸入密文

	printf("Please type parameter A.(Numbers) (A ≠2n , A ≠13n) Then press 'Enter'.\n");

	scanf("%d", &input_parameter_A);                                       // 指定參數A
	printf("Please type parameter B.(Numbers). Then press 'Enter'.\n");
	scanf(" %d", &input_parameter_B);                                      // 指定參數B

	printf("\n\n");
	for (int i = 0; i < 26; i++) {                                          // encryption_table 依序填入 1~26
		encryption_table[i] = i + 1;
	}

	for (int i = 0; i < 26; i++) {
		encryption_table[i] = (input_parameter_A * encryption_table[i] + input_parameter_B) % 26;  // encryption_table 轉換為 0~25
		                                                                                           // Y = ( A * X + B ) % 26
		//printf("%d ", encryption_table[i]);                                                        // 印出 encryption_table 0~25
	}
	printf("\n\n");

	for (int i = 0; i < 26; i++) {

		if (encryption_table[i] == 0) {
			encryption_table[i] = 26 + 96;                                                          // encryption_table [ ] = 0 = z
		}
		else {
			encryption_table[i] = encryption_table[i] + 96;                                         // ASCII 1~25 -> a~y
		}
		//printf("%c ", encryption_table[i]);                                                         // 印出encryption_table : a~z
	}
	printf("\n\n");

	for (int i = 0; i < 26; i++) {                                                                  // 建立 decryption_table                                     
		
		decryption_table[encryption_table[i] - 97] = 97 + i;                                        // encryption_table 的 value 作為  decryption_table 的位置,依序填入 a~z              
	}

	for (int i = 0; i < 26; i++) {

		//printf("%c ", decryption_table[i]);
	}

	printf("\n\n");
	printf("==============================================================\n");
	printf("\nDecryption Looking Table :\n");                                            // 印出解密對照表,密文查表,得到明文
	printf("\n");
	printf("Ciphertext\n");
	printf("| \n");
	printf("Plaintext\n");
	printf("\n");
	printf("==============================================================\n");

	for (int i = 0; i < 26; i++) {                                                       // 印出密文字母,依序 a~z
		encryption_table[i] = i + 97;
		printf("%c ", encryption_table[i]);
	}

	printf("\n");

	for (int i = 0; i < 26; i++) {
		printf("| ");
	}
	printf("\n");

	for (int i = 0; i < 26; i++) {                                                      // 印出解密對照表,依序對應密文,得到明文

		printf("%c ", decryption_table[i]);
	}
	printf("\n");
	printf("==============================================================\n");
	printf("\n\n");

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
	
	printf("==============================================================\n");

	printf("\n");
	printf("Plaintext : ");                                           // 印出密文,全為小寫字母,空格; 不印出符號
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {          // 針對小寫,進行查表
			input_data_matrix[i] = decryption_table [input_data_matrix[i] - 97];   // input_data_matrix[i] - 97 作為查表 index, 查詢 decryption_table
			printf("%c", input_data_matrix[i]);                                    // 印出小寫字母
		}

		else
			printf("%c", input_data_matrix[i]);                         // 印出符號,空格
	}
	printf("\n\n");
	printf("Processing is over.\n");                                    // 解密結束
	while (1) { ; }
	return 0;
}

