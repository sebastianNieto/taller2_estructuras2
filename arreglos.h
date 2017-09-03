/* Ejercicios que implementan punteros a arreglos
*  Fecha 03/09/2017
*  Elaborado por: John Sebastian Nieto gil 
*  Elaborado por: Ricardo Andres Villalobos
*/

int potencia(int *, int);
void arreglo_decimales();
void arreglo_ceros_unos(int, int);
void mostrar_array(int *, int *, int *);
void arreglo(int *);
void arreglo_potencia(int *);

//retorna un numeros elevado al exponente ingresado
int potencia(int *pNumero, int exp)
{
	int result = 1;
	int* pResult = &result;
	for (int i = 1; i <= exp; i++)
		*pResult = *pResult * *pNumero;
	
	return *pResult;
}

//Imprime un arreglo de números decimales
void arreglo_decimales()
{
	float numeros[4] = {32.583, 11.239, 45.781, 22.237};
	float* pNumeros = numeros;
	
	for(int i=0; i<=3; i++)
	{
		gotoxy(35,i+13);printf("%.3f", *(pNumeros+i));
	}
}


//Imprime arreglo de 0 y 1, según las dimensiones especifucadas en los parametros
void arreglo_ceros_unos(int *pNumA, int *pNumB, int *pNumeros)
{
	int z = 0;
	for(int i = 0; i < *pNumA; i++)
	{
		for(int j = 0; j < *pNumB; j++)
		{
			*(pNumeros + z) =  rand()%2;
			z++;
		}
	}
	
	
}

//Muestra los datos de un arreglo
void mostrar_array(int *pNumA, int *pNumB, int *pNumeros)
{
	int k, z = 0;
	for(int i = 0; i < *pNumA; i++)
	{
		k=18;
		for(int j = 0; j < *pNumB; j++)
		{
			gotoxy(k,11+i);printf("%d ", *(pNumeros + z));
			k+=5;
			z++;
		}
	}
}

//Ingresar los valores de la primera columna para el arreglo 4X4 potencia
void arreglo(int *pMatriz)
{
	int z = 0;
	gotoxy(19,4);printf("Ingrese los valores para el arreglo");
	for(int i=0; i<4; i++)
	{
		gotoxy(19,6+i);printf("ingrese el valor %d: ", i+1);
		scanf("%d", pMatriz+z);
		z = z + 4;
	}
}

/* Imprimer un arreglo 4X4.
* Primera Columna ingresado por el usuario
* Segunda Columna el número elevado al cuadrado
* tercera Columna el número elevado al cubo
* Cuarta Columna el número elevado a la cuarta
*/
void arreglo_potencia(int *pMatriz)
{
	int z = 0, k = 0;
	for(int i = 0; i < 4 ; i++)
	{
		for(int j = 0; j < 4 ; j++)
		{
			*(pMatriz+k) = potencia((pMatriz+z),j+1);
			k++;
		}
		z = z + 4;
	}
}
