#include <stdio.h>
#include <stdlib.h>

int main() {                         // 盞ゅ秆盞 main function

	char encryption_table[26] = { 0 }; // ﹍て,秆盞癸酚
	char decryption_table[26] = { 0 };

	int input_parameter_A;           // 把计A,タ俱计,Aぃ2┪13计
	int input_parameter_B;           // 把计B,タ俱计  ( A,B 惠籔盞ㄏノ把计 )  
	char* input_data_matrix = 0;     // ﹍て,夹,ヘ玡ヴ癘拘砰丁,非称块盞ゅ皚
	int data_length = 0;             // 癬﹍盞ゅ皚 0
	char input_detect;               // 块盞ゅ

	printf("Please type parameter A.(Numbers) (A ≮2n , A ≮13n) Then press 'Enter'.\n");

	scanf("%d", &input_parameter_A);                                       // ﹚把计A
	printf("Please type parameter B.(Numbers). Then press 'Enter'.\n");
	scanf(" %d", &input_parameter_B);                                      // ﹚把计B

	printf("\n\n");
	for (int i = 0; i < 26; i++) {                                          // encryption_table ㄌ恶 1~26
		encryption_table[i] = i + 1;
	}

	for (int i = 0; i < 26; i++) {
		encryption_table[i] = (input_parameter_A * encryption_table[i] + input_parameter_B) % 26;  // encryption_table 锣传 0~25
		                                                                                           // Y = ( A * X + B ) % 26
		//printf("%d ", encryption_table[i]);                                                        //  encryption_table 0~25
	}
	printf("\n\n");

	for (int i = 0; i < 26; i++) {

		if (encryption_table[i] == 0) {
			encryption_table[i] = 26 + 96;                                                          // encryption_table [ ] = 0 = z
		}
		else {
			encryption_table[i] = encryption_table[i] + 96;                                         // ASCII 1~25 -> a~y
		}
		//printf("%c ", encryption_table[i]);                                                         // encryption_table : a~z
	}
	printf("\n\n");

	for (int i = 0; i < 26; i++) {                                                                  // ミ decryption_table                                     
		
		decryption_table[encryption_table[i] - 97] = 97 + i;                                        // encryption_table  value   decryption_table 竚,ㄌ恶 a~z              
	}

	for (int i = 0; i < 26; i++) {

		//printf("%c ", decryption_table[i]);
	}

	printf("\n\n");
	printf("==============================================================\n");
	printf("\nDecryption Looking Table :\n");                                            // 秆盞癸酚,盞ゅ琩,眔ゅ
	printf("\n");
	printf("Ciphertext\n");
	printf("| \n");
	printf("Plaintext\n");
	printf("\n");
	printf("==============================================================\n");

	for (int i = 0; i < 26; i++) {                                                       // 盞ゅダ,ㄌ a~z
		encryption_table[i] = i + 97;
		printf("%c ", encryption_table[i]);
	}

	printf("\n");

	for (int i = 0; i < 26; i++) {
		printf("| ");
	}
	printf("\n");

	for (int i = 0; i < 26; i++) {                                                      // 秆盞癸酚,ㄌ癸莱盞ゅ,眔ゅ

		printf("%c ", decryption_table[i]);
	}
	printf("\n");
	printf("==============================================================\n");
	printf("\n\n");

	printf("Please type Ciphertext letters. Then press 'Enter'.\n");
	getchar();
	printf("\n");

	while (scanf("%c", &input_detect) == 1) {                               // 弄–块ダ
		if (input_detect == '\n') break;                                    // 沧ゎ兵ン : 块 'Enter'

		input_data_matrix = realloc(input_data_matrix, sizeof(char) * (data_length + 1));
		// Τ穝块ダ,穝耎input_data_matrix,非称穝ダ
		// data_length +1(セゅ+1),穝皚丁糤char,1 byte = 8 bits
		// 盢侣皚戈,狡籹穝皚丁
		// 簿埃侣皚,耴临ゼㄏノ癘拘砰
		// 夹 ( char*input_data_matrix ) 穝皚

		input_data_matrix[data_length] = input_detect;                 // 盢穝块ダ,input_data_matrix程竚
		data_length++;                                                 // 盞ゅ+1,ヘ玡块ぶダ
	}

	printf("\n");
	printf(" parameter A : %d\n ", input_parameter_A);                 // 把计A
	printf("parameter B : %d\n ", input_parameter_B);                  // 把计B
	printf("\n\n");

	printf("Input Message :");                                         // 块ゅ,才腹,
	for (int i = 0; i < data_length; i++) {
		printf("%c", input_data_matrix[i]);
	}
	printf("\n\n");


	printf("Ciphertext : ");                                           // 盞ゅ,糶ダ,; ぃ才腹
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] == ' ') {                             // 
			printf(" ");
		}

		if (input_data_matrix[i] >= 'A' && input_data_matrix[i] <= 'Z') {    // ダ糶锣传
			input_data_matrix[i] = input_data_matrix[i] - 'A' + 'a';
		}
		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {    // 糶,盞ゅ
			printf("%c", input_data_matrix[i]);
		}
	}
	printf("\n\n");
	
	printf("==============================================================\n");

	printf("\n");
	printf("Plaintext : ");                                           // 盞ゅ,糶ダ,; ぃ才腹
	for (int i = 0; i < data_length; i++) {

		if (input_data_matrix[i] >= 'a' && input_data_matrix[i] <= 'z') {          // 皐癸糶,秈︽琩
			input_data_matrix[i] = decryption_table [input_data_matrix[i] - 97];   // input_data_matrix[i] - 97 琩 index, 琩高 decryption_table
			printf("%c", input_data_matrix[i]);                                    // 糶ダ
		}

		else
			printf("%c", input_data_matrix[i]);                         // 才腹,
	}
	printf("\n\n");
	printf("Processing is over.\n");                                    // 秆盞挡
	while (1) { ; }
	return 0;
}

