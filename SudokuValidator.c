#include <stdio.h>
#include <sys/syscall.h>
#include <fcntl.h>

//Metodo para chequear columnas
int checkColumn(int arr[9][9])
{
	//Inicializamos las variables a utilizar en el metodo 
	int i,j;

	//Iteramos el numero de columnas que tiene nuestro array multidimensional
	for(i=0;i<9;i+=1){
		int *ptr = &arr[0][i];
		//Iteramos el numero de filas que tiene nuestro array multidimensional
		for(j=0;j<9;j+=1){
			//Multiplicamos la cantidad de filas por el numero de columnas para movernos en el puntero hacia la direccion de memoria correcta
			int multi = j*3;
			//Movemos el puntero sobre la columna i
			int valor = *(ptr+multi);
			//Comprobamos que el valor sea alguno de los necesitados, si no, return 0 (false)
			switch(valor) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4: 
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					break;
				default:
					return 0;
			}
		}
		
		
	}

	//Si todas las columnas cumplen con los numeros necesitados retornamos 1 (true)
	return 1;
}

int checkRow(int arr[9][9])
{
	//Inicializamos las variables a utilizar en el metodo 
	int i,j;
	//int[9] solution;

	//Iteramos el numero de filas que tiene nuestro array multidimensional
	for(i=0;i<9;i+=1){
		int *ptr = &arr[i][0];
		//Iteramos el numero de columnas que tiene nuestro array multidimensional
		for(j=0;j<9;j+=1){
			//Multiplicamos la cantidad de filas por el numero de columnas para movernos en el puntero hacia la direccion de memoria correcta
			//Movemos el puntero sobre la columna i
			int valor = *(ptr+j);
			//solution[i+j] = valor;
			//Comprobamos que el valor sea alguno de los necesitados, si no, return 0 (false)
			switch(valor) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4: 
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					break;
				default:
					return 0;
			}
		}
		
		
	}

	//Si todas las columnas cumplen con los numeros necesitados retornamos 1 (true)
	return 1;

}

int checkSubsec(int arr[9][9], int col, int row)
{
	//Inicializamos las variables a utilizar en el metodo 
	int i,j,col_new,row_new,num;
	int *ptr;

	if (col<3 && row<3){
		ptr = &arr[0][0]-1;
		col_new = 0;
		row_new = 0;
	}else if (col<3 && row>2 && row<6){
		ptr = &arr[3][0]-1;
		col_new = 0;
		row_new = 3;
	}else if (col<3 && row>5){
		ptr = &arr[6][0]-1;
		col_new = 0;
		row_new = 6;
	}else if (col>3 && col<6 && row<3){
		ptr = &arr[0][3]-1;
		col_new = 3;
		row_new = 0;
	}else if (col>3 && col<6 && row>2 && row<6){
		ptr = &arr[3][3]-1;
		col_new = 3;
		row_new = 3;
	}else if (col>3 && col<6 && row>5){
		ptr = &arr[6][3]-1;
		col_new = 3;
		row_new = 6;
	}else if (col>5 && row<3){
		ptr = &arr[0][6]-1;
		col_new = 6;
		row_new = 0;
	}else if (col>5 && row>2 && row<6){
		ptr = &arr[3][6]-1;
		col_new = 6;
		row_new = 3;
	}else if (col>5 && row>5){
		ptr = &arr[6][6]-1;
		col_new = 6;
		row_new = 6;
	}else {
		return 100;	
	}

	//printf("valor: %d\n",*(ptr+3));

	for (i=0; i<3; i+=1){
		int new_please = col_new + i;
		ptr = &arr[row_new][new_please];
		for(j=0; j<3;j+=1){
			num = *(ptr + (j*9));
			printf("valor: %d\n",num);
		switch(num) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4: 
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					break;
				default:
					return num;
			}
		}
		
	}

	//Si todas las columnas cumplen con los numeros necesitados retornamos 1 (true)
	return 1;

}

int main(int argc, char* argv[])
{
	int temp[81];
	int opened = open(argv[1], O_RDWR);
	write("prueba.txt",opened,81);
//	int open
	int matrix[9][9] = {{1,2,3,4,5,6,7,8,9},
				{1,2,3,4,5,6,7,8,9},
				{1,2,3,4,5,6,7,8,9},
				{1,2,3,4,5,6,7,8,9},
				{1,2,3,4,5,6,7,8,9},
				{1,2,3,4,5,6,7,8,9},
				{1,2,3,1,2,3,7,8,9},
				{1,2,3,4,5,6,7,8,9},
				{1,2,3,7,8,6,7,8,9}};
/*	
	int i;

	int *ptr = &matrix[0][0];
	for(i=0;i<27;i+=1){
		printf("%d\n",*(ptr+i));
	}
*/
	int test = checkSubsec(matrix,5,7);
	printf("valor del test: %d\n",test);
}
