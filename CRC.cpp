#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	int i,j,key_len,msg_len;
	char input[100], key[30],temp[30],quot[100],rem[30],key1[30];

	printf("Enter your Data (dividend)--> ");
	gets(input);
	printf("Enter Key (divisor) --> ");
	gets(key);
	
	key_len = strlen(key);
	msg_len = strlen(input);
	strcpy(key1, key);
	for (i=0; i<key_len-1; i++) {
		input[msg_len + i]='0';
	}
	for (i=0; i<key_len; i++)
	 temp[i] = input[i];
	for (i=0; i<msg_len; i++) {
		quot[i] = temp[0];
		if(quot[i] == '0')
		 for (j=0; j<key_len; j++)
		 key[j] = '0'; else
		 for (j=0; j<key_len; j++)
		 key[j] = key1[j];
		for (j=key_len-1; j>0; j--) {
			if(temp[j] == key[j])
			 rem[j-1] = '0'; 
			 else
			 rem[j-1]='1';
		}
		rem[key_len-1] = input[i+key_len];
		strcpy(temp, rem);
	}
	
	strcpy(rem, temp);
	printf("\n*******************************************");
	printf("\nQuotient is : ");
	for (i=0; i<msg_len; i++)
	 printf("%c", quot[i]);
	printf("\nRemainder is : ");
	for (i=0; i<key_len-1; i++)
	 printf("%c", rem[i]);
	printf("\nFinal Data is : ");
	for (i=0; i<msg_len; i++)
	 printf("%c",input[i]);
	for (i=0; i<key_len-1; i++)
	 printf("%c", rem[i]);
	 
	getch();
}












//#include <stdio.h>
//#include <string.h>
//
//int main() {
//	int i, j, key_len, msg_len, flag=0;
//	char input[100], key[30], temp[30], quot[100], rem[30], key1[30];
//	
//	printf("ENTER YOU DATA --> ");
//	scanf("%s", input);
//	printf("ENTER KEY --> ");
//	scanf("%s", key);
//	
//	key_len = strlen(key);
//	msg_len = strlen(input);
//	strcpy(key1, key);
//	
//	for(i = 0; i < key_len - 1; i++) {
//		input[msg_len + i] = '0';
//	}
//	
//	for(i = 0; i < key_len; i++) 
//		temp[i] = input[i];
//	for(i = 0; i < msg_len; i++){
//		quot[i] = temp[0];
//		if(quot[i] == '0')
//		 for (j = 0; j < key_len; j++)
//		 key[j] = '0'; else
//		 for (j = 0; j < key_len; j++)
//		 key[j] = key[j];
//		for (j = key_len - 1; j > 0; j--) {
//			if(temp[j] == key[j])
//			  rem[j-1] = '0'; else
//			  rem[j-1] = 1;
//		}
//		rem[key_len - 1] = input[i +key_len];
//		strcpy(temp, rem);
//	}
//	strcpy(rem, temp);
//	printf("\nQuotient is - ");
//}












