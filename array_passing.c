#include <stdio.h>
void oneDimentionalArray(int *a, int size){
	int i = 0;
	for(i = 0 ; i < size ; i++){
		printf("%d ", a[i]);
	}
}
void twoDimentionalArray(int **a , int x_size, int y_size){
	int i = 0 , j = 0;
	for(i = 0 ; i < x_size ; i++){
		for(j = 0 ; j < y_size ; j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
int main(){
	int one_dimentional_array[5] = {1 , 2, 3 , 4 , 5};
	int two_dimentional_array[2][5] = {{1 , 2, 3 , 4 , 5},
										{10 , 20, 30 , 40 , 50}};
	oneDimentionalArray(one_dimentional_array , 5);
	twoDimentionalArray(two_dimentional_array , 2 , 5);
	return 0;
}