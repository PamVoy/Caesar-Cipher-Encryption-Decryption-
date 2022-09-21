# Caesar-Cipher-Encryption-Decryption-
Caesar Cipher for string encryption and decryption. ( C language )

Encryption: 先輸入兩個數字A,B; 再輸入欲加密的英文字串,得到密文

Decryption: 輸入Encryption使用的兩個數字A,B; 再輸入欲解密的密文,得到原始明文


   Caesar Cipher (Encryption):
   
   加密方程式:
   transform formula: Y = (A*X + B) mod 26

   X : input character (a~z , A~Z , white space , 0~9 , dot , marks...)
   Y : output cipher character (a~z , A~Z , white space , 0~9 , dot , marks...)
   A : positive number ( A ≠2n , A ≠13n , n = 1,2,3~ )
   A 不可為偶數,不可為2或13的倍數 
   
   B : positive number 



