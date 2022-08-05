#include <stdio.h>
#include <string.h>

// Creating Function
void bit_stuffing(int N, int arr[]){
	int brr[40];	// Stores the stuffed array

	int a, b, c;
	a = 0;
	b = 0;


	int count = 1;

	while (a < N) {

		// If the current bit is a set bit
		if (arr[a] == 1) {

			brr[b] = arr[a];

			for (c = a + 1; arr[c] == 1 && c < N && count < 5; c++) {
				b++;
				brr[b] = arr[c];
				count++;

				if (count == 5) {
					b++;
					brr[b] = 0;
				}
				a = c;
			}
		}

		else {
			brr[b] = arr[a];
		}
		a++;
		b++;
	}

	for (a = 0; a < b; a++)
		printf("%d", brr[a]);
}

int main(){

	int N = 10;
	
	int arr[] = { 1, 0, 1, 1, 1, 1, 1, 1, 0, 0};

	bit_stuffing(N, arr);

	return 0;
}

