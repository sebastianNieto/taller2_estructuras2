/* Ejercicios que implementan punteros a matrices
*  Fecha 03/09/2017
*  Elaborado por: John Sebastian Nieto gil 
*  Elaborado por: Ricardo Andres Villalobos
*/

void obtener_datos_matriz(int *);
void matriz_valores(int *);
void completar_matriz_automatica(int *);
void matriz(int *);
void obtener_primos(int *);
int numPrimo(int);

//Obtener los datos del usuario para la primer matriz
void obtener_datos_matriz(int *pMatriz)
{
	int z = 0;
	for(int i=0;i<3;i++)
	{
		gotoxy(23,4);printf("Ingrese los datos de la %d fila ", i+1);
		
		for(int j=0;j<=2;j++)
		{
			gotoxy(23,6+j);scanf("%d", (pMatriz+z));
			z++;
		}
		
		system("cls");
		dibujaRectangulo(1,1,78,24);
	}
}

//Imprime matriz 3X3 (Valores ingresados por el usuario) y la suma de los valores de la suma de sus posiciones
void matriz_valores(int *pMatriz)
{
	short k, posicion, l, z;
	short* pPosicion = &posicion;
	
	k = 1;
	z = 0;
	posicion = 0;
	
	for(int i=0;i < 3;i++)
	{
		l=23;
		for(int j=0;j<3;j++)
		{
			gotoxy(l,6+i);printf("%d", *(pMatriz+z));
			*pPosicion = posicion+*(pMatriz+z);
			l += 5;
			k++;
			z++;
		}
	}
	
	gotoxy(23,16);printf("la suma de las posiciones es %d ", posicion);
}

//Ingresa valores aleatorios de 0 a 100 automaticamente
void completar_matriz_automatica(int *pMatriz)
{
	int aleatorio, z=0;
	int* pAleatorio = &aleatorio;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			*pAleatorio = rand()%101;
			*(pMatriz+z) = *pAleatorio;
			z++;
		}
	}
}

//Imprimer matriz 3X3
void matriz(int *pMatriz)
{
	unsigned short k, z=0;
	
	for(int i=0;i<3;i++)
	{
		k=23;
		for(int j=0;j<=2;j++)
		{
			gotoxy(k,6+i);printf("%d", *(pMatriz+z));
			k+=5;
			z++;
		}
	}
}

//Completa la matriz con los numeros primos automaticamente
void obtener_primos(int *pMatriz)
{
	unsigned short k = 2, z = 0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			*(pMatriz+z) = numPrimo(k);
			k = *(pMatriz+z)+1;
			z++;
		}
		
	}
}

//retorna un numero primo iniciando desde el numero ingresado por parametro
int numPrimo(int num)
{
	int cont, *pCont = &cont, *pNum = &num;
	bool esPrimo, *pEsPrimo = &esPrimo;
	
	do
	{
		*pEsPrimo = true;
		*pCont = 0;
		for(int i=1;i<=*pNum;i++)
		{
			if(*pNum%i == 0)
			{
				(*pCont)++;
			}
			if(*pCont > 2)
			{
				break;
			}
		}
		
		if(*pCont != 2)
		{
			*pEsPrimo = false;
			(*pNum)++;
		}
	}
	while(!*pEsPrimo);
	return *pNum;
}
