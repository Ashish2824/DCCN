#include <stdio.h>
#include <math.h>
int input[32];
int code[32];
int ham_calc(int,int);
int main()
{
	int n,i,p_n = 0,c_l,j,k;
	printf("Please enter the length of the Data Word (Message Size) --> ");
	scanf("%d",&n);
	printf("Please enter the Data Word --> \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&input[i]);
	}

	i=0;
	while(n>(int)pow(2,i)-(i+1))
	{
		p_n++;
		i++;
	}
		
	c_l = p_n + n;

	j=k=0;
	for(i=0;i<c_l;i++)
	{
		
		if(i==((int)pow(2,k)-1))
		{
			code[i]=0;
			k++;
		}
		else
		{
			code[i]=input[j];
			j++;
		}
	}
	for(i=0;i<p_n;i++)
	{
		int position = (int)pow(2,i);
		int value = ham_calc(position,c_l);
		code[position-1]=value;
	}
	printf("\nThe calculated Code Word is --> ");
	for(i=0;i<c_l;i++)
		printf("%d",code[i]);
	printf("\n");
	printf("Please enter the received Code Word --> \n");
	for(i=0;i<c_l;i++)
		scanf("%d",&code[i]);

	int error_pos = 0;
	for(i=0;i<p_n;i++)
	{
		int position = (int)pow(2,i);
		int value = ham_calc(position,c_l);
		if(value != 0)
			error_pos+=position;
	}
	if(error_pos == 1)
		printf("The received Code Word is correct...!\n");
	else
		printf("Error at bit position --> %d\n",error_pos);
}
int ham_calc(int position,int c_l)
{
	int count=0,i,j;
	i=position-1;
	while(i<c_l)
	{
		for(j=i;j<i+position;j++)
		{
			if(code[j] == 1)
				count++;
		}
		i=i+2*position;
	}
	if(count%2 == 0)
		return 0;
	else
		return 1;
}
























//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//
//int main()
//{
//	printf("BIT INDEXING STARTS FROM (RIGHT TO LEFT), Just like in Textbook!\n\n");
//	int msg_size, rbit=0, msg_arr[50], data[75], i, j, k;
//	printf("ENTER MESSAGE SIZE --> ");
//	scanf("%d", &msg_size);
//	
//	//calculating no of rbit(redundent bits) : 2^rbit >= msg_size + rbit + 1
//	while(1)
//	{
//		if((msg_size + rbit + 1) <= (int)pow(2,rbit))
//		 break;
//		rbit++;
//	}
//	printf("ENTER MESSAGE BITS --> ");
//	for(i=msg_size; i>=1; i--)
//	{
//		scanf("%d",&msg_arr[i]);
//	}
//	k = 0;	// for 2^k
//	j = 1;	//for positioning of message
//	for(i=1; i<=(msg_size + rbit); i++)
//	{
//		if(i==(int)pow(2,k))
//		{
//			data[i]=5;
//			k++;
//		}
//		else
//		{
//			data[i] = msg_arr[j];
//			j++;
//		}
//	}
//	
//	for(i=1; i<=(msg_size + rbit); i++)
//	{
//		if(data[i] == 5)
//		{
//			data[i] = 0;
//			int count = 0;
//			for(j=i; j<=(msg_size + rbit); j++)
//			{
//				for(k=0; k<i; k++)
//				{
//					if(data[j]==1)
//					{
//						count++;
//					}
//					j++;
//				}
//				j = j+i-1;
//			}
//			if (count%2 == 0)
//			{
//				data[i] = 0;
//			}
//			else
//			{
//				data[i] = 1;
//			}
//		}
//	}
//	
//	printf("Genrated CODEWORD is --> ");
//	for(i=(msg_size + rbit); i>1; i--)
//		printf("%d", &data[i]);
//	printf("\n****************************************\n");
//	printf("ENTER RECEIVED DATA --> ");
//	for(i=(msg_size+rbit); i>1; i++)
//		scanf("%d", &data[i]);
//		
//	int c=0;
//	
//	// C1 C2 C3  {redundent bits}
//	// D1 D2 D3
//	// 0  1  0   ->  error is at 2nd position
//	// 0  0  0   ->  valid
//	// XOR should be 0 for no error
//	
//	
//	int *parities = (int *)calloc(rbit, sizeof(int));		//parities will be containing result of XOR
//	for(i=1; i<=(msg_size+rbit); i++)
//	{
//		if(i==(int)pow(2,c))
//		{
//			int count = 0;
//			for(j=i; j<=(msg_size+rbit); j++)
//			{
//				for(k=0; k<i; k++)
//				{
//					if(data[j]==1)
//					{
//						count++;
//					}		
//					j++;
//				}
//				j=j+i-1;
//			}
//			if(data[i]==1)
//			{
//				count--;
//			}	
//			if(count%2 == data[i])
//			{
//				parities[c]=0;
//			}
//			else if(count%2 != data[i])
//			{
//				parities[c]=1;
//			}
//			c++;
//		}
//	}
//	c=0;
//	for(int i=0; i<rbit; i++)
//	{
//		c+=parities[i]*((int)pow(2,i));
//	}
//	if(c==0)
//	{
//		printf("THERE IS NO ERROR!!\n");
//		exit(0);
//	}
//	
//	printf("ERROR is at position --> %d\n", c);
//	data[c] = data[c] == 0 ? 1 : 0;		//changing 1 to 0 or 0 to 1 
//	printf("CODE after ERROR CORRECTION is --> ");
//	for(i=(msg_size + rbit); i>=1; i--)
//		printf("%d", data[i], "\n");
//	
//	return 0;
//}
