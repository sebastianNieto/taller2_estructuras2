/* Ejercicios con punteros
*  Fecha 03/09/2017
*  Elaborado por: John Sebastian Nieto gil 
*  Elaborado por: Ricardo Andres Villalobos
*/

struct Alumno
{
	char nombre[30];
	short edad;
	float promedio;
} student[3], *pStudent = student;

struct Etapa
{
	short horas, minutos, segundos;
}etapas[3], *pEtapas = etapas;


void par_impar(int *);
bool es_primo(int *);
void ingresar_vector(int*, int*);
void muestra_pares(int *);
int muestra_menor(int *, int *);
void ordenar_arreglo(int *, int *);
void mostrar_arreglo_ordenado(int *, int *);
bool in_array(int *, int *, int *);
int contar_vocales(char *);
void array_vocales(char *, short *);	
void mostrar_vocales(short *);
void ingresar_arreglo(int*, int*, int*);
void sumar_matriz(int*, int*, int*, int*, int*);
void mostrar_arreglo(int*, int*, int*);
void matriz_traspuesta(int*, int*, int*, int*);
void ingresar_alumno();
short mayor_promedio();
void mejor_promedio(Alumno *, short *);
int ingresar_etapas();
long calcular_tiempo();
void muestra_tiempo(long *);
	
//Muestra si un numero es par o impar y cual es su posicion en memoria
void par_impar(int *pNumero)
{
	if(*pNumero % 2 == 0){
		printf("El número es par su posion en memoria es: %p", pNumero);
	}
	else{
		printf("El número es impar su posion en memoria es: %p", pNumero);
	}
}

//Retorna Verdadero si un numero es primo
bool es_primo(int *pNumero)
{
	int i, j, cont = 0, *pCont;
	bool esPrimo = true, *pEsPrimo;
	
	pCont = &cont;
    pEsPrimo = &esPrimo;
	
	for(i = 1; i <= *pNumero; i++)
	{
		if(*pNumero%i == 0)
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
	}
	
	return *pEsPrimo;
}

//Ingresa los datos para un vector entero
void ingresar_vector(int* pNumeros, int* pCantidad)
{
	
	gotoxy(28,4);printf("Ingrese los numeros \n");
	
	for(int i = 0; i < *pCantidad; i++){
		gotoxy(32,6+i);printf("Numero %d: ", i+1);
		scanf("%d", (pNumeros+i));
	}

}

//Muestra los numeros pares de un vector entero
void muestra_pares(int *pNumeros)
{
	gotoxy(31,4);printf("Numeros pares: \n");
	for(int i = 0; i < 10; i++){
		if(*(pNumeros+i)%2 == 0){
			gotoxy(24,6+i);printf("%d - posiocion en memoria %p \n", *(pNumeros+i), (pNumeros+i));
		}
	}
}

//Muestra en numero menor de un vector entero
int muestra_menor(int *pNumeros, int *pCantidad)
{
	int menor = 0, *pMenor = &menor;
	for(int i = 0; i < *pCantidad; i++){
		if(*(pNumeros+i) < *pMenor || *pMenor == 0){
			*pMenor = *(pNumeros+i);
		}
	}
	
	return *pMenor;
}

//Ordena un arreglo
void ordenar_arreglo(int *pNumeros, int *pCantidad)
{
	
	int temp, *pTemp = &temp;
	
	for(int i = 0; i < *pCantidad-1; i++){
		for(int j = i + 1; j < *pCantidad; j++){
			if(*(pNumeros + i) > *(pNumeros + j)){
				*pTemp = *(pNumeros+i);
				*(pNumeros + i) = *(pNumeros + j);
				*(pNumeros + j) = *pTemp;
			}
		}
	}
	
}

//Muestra un vector ordenado
void mostrar_arreglo_ordenado(int *pNumeros, int *pCantidad)
{
	gotoxy(30,4);printf("Arreglo Ordenado \n");
	for(int i = 0; i < *pCantidad; i++){
		gotoxy(30,6+i);printf("%d ", *(pNumeros + i));
	}
}

//Retorna verdadero si el numero buscado se encuentra en el arreglo
bool in_array(int *pNumeros, int *pCantidad, int *pBuscar)
{
	short encontrado = 0;
	short *pEncontrado = &encontrado;
	for(int i = 0; i < *pCantidad; i++){
		if(*(pNumeros + i) == *pBuscar){
			(*pEncontrado)++;
		}
	}
	
	if(*pEncontrado > 0){
		return true;
	}
	else{
		return false;
	}
}

//Cuenta las vocales de un nombre
int contar_vocales(char *pNombre)
{
	short cantidad=0, vocales=0,*pCantidad = &cantidad, *pVocales = &vocales;
	*pCantidad = strlen(pNombre);
	
	for(int i = 0; i < *pCantidad; i++){
		if(*(pNombre+i) == 'a' || *(pNombre+i) == 'e' || *(pNombre+i)== 'i' || *(pNombre+i) == 'o' || *(pNombre+i) == 'u' || *(pNombre+i) == 'A' || *(pNombre+i) == 'E' || *(pNombre+i) == 'I' || *(pNombre+i) == 'O' || *(pNombre+i) == 'U'){
			(*pVocales)++;
		}
	}
	
	return *pVocales;
}

//Obtiene la cantidad por cada vocal de un string
void array_vocales(char *pCadena, short *pVocales)
{
	short cantidad=0,*pCantidad = &cantidad;
	*pCantidad = strlen(pCadena);
	
	for(int i = 0; i < *pCantidad; i++){
		if(*(pCadena+i) == 'a' || *(pCadena+i) == 'A'){
			(*pVocales)++;
			continue;
		}
		if(*(pCadena+i) == 'e' || *(pCadena+i) == 'E'){
			(*(pVocales+1))++;
			continue;
		}
		if(*(pCadena+i) == 'i' || *(pCadena+i) == 'I'){
			(*(pVocales+2))++;
			continue;
		}
		if(*(pCadena+i) == 'o' || *(pCadena+i) == 'O'){
			(*(pVocales+3))++;
			continue;
		}
		if(*(pCadena+i) == 'u' || *(pCadena+i) == 'U'){
			(*(pVocales+4))++;
			continue;
		}
	}
}

//Muestra cantidad por cada vocal de un string
void mostrar_vocales(short *pVocales)
 {
	 gotoxy(18,8);printf("Cantidad por vocal a en la cadena: %d \n", *(pVocales));
	 gotoxy(18,9);printf("Cantidad por vocal e en la cadena: %d \n", *(pVocales+1));
	 gotoxy(18,10);printf("Cantidad por vocal i en la cadena: %d \n", *(pVocales+2));
	 gotoxy(18,11);printf("Cantidad por vocal o en la cadena: %d \n", *(pVocales+3));
	 gotoxy(18,12);printf("Cantidad por vocal u en la cadena: %d \n", *(pVocales+4));
 }
 
 
//Ingresa los datos para un arreglo entero
void ingresar_arreglo(int* pNumeros, int* pFilas, int* pColumnas)
{
	int z = 0, k = 0;
	for(int i = 0; i < *pFilas; i++){
		gotoxy(19,4+k);printf("Ingrese los %d numeros para la fila #%d \n", *pColumnas, i+1);
		for(int j = 0; j < *pColumnas; j++){
			gotoxy(30,6+k+j);printf("Numero %d: ", j+1);
			scanf("%d", (pNumeros+z));
			z++;
		}
		k = k + (*pColumnas + 3);
	}

}

//Suma dos matrices en otra
void sumar_matriz(int* pMatrizA, int* pMatrizB, int* pMatrizSuma, int* pFilas, int* pColumnas)
{
	int z = 0;
	for(int i = 0; i < *pFilas; i++){
		for(int j = 0; j < *pColumnas; j++){
			*(pMatrizSuma+z) = *(pMatrizA+z) + *(pMatrizB+z);
			z++;
		}
	}
}

//Muestra los datos de un arreglo entero
void mostrar_arreglo(int* pMatrizSuma, int* pFilas, int* pColumnas)
{
	int z = 0, k = 0;
	for(int i = 0; i < *pFilas; i++){
		for(int j = 0; j < *pColumnas; j++){
			gotoxy(20+k,6+i);printf("%d \t", *(pMatrizSuma+z));
			z++;
			k+=5;
		}
		k=0;
	}

}

//Obtiene la matriz traspuesta de una matriz
void matriz_traspuesta(int* pMatrizA, int* pMatrizB, int* pFilas, int* pColumnas)
{
	int z = 0;
	for(int i = 0; i < *pColumnas; i++){
		for(int j = 0; j < *pFilas; j++){
			*(pMatrizB+z) = *(pMatrizA+z);
			z++;
		}
	}
}

//Ingresa los datos para 3 alumnos
void ingresar_alumno()
{
	for(int i = 0; i < 3; i++){
		fflush(stdin);
		gotoxy(19,4);printf("Estudiante #%d \n \n", i+1);
		gotoxy(19,6);printf("Nombre: ");
		fgets((student+i)->nombre, 30, stdin);
		gotoxy(19,7);printf("Edad: ");
		scanf("%d", &(student+i)->edad);
		gotoxy(19,8);printf("Promedio: ");
		scanf("%f", &(student+i)->promedio);
		system("cls");
		dibujaRectangulo(1,1,78,24);
	}
}

//Obtiene el indice del estudiante con mayor promedio
short mayor_promedio()
{
	short indice = 0, *pIndice;
	float mayor = 0, *pMayor;
	pMayor = &mayor;
	pIndice = &indice;
	
	for(int i = 0; i < 3; i++){
		if((student+i)->promedio > *pMayor){
			*pMayor = (student+i)->promedio;
			*pIndice = i;
		}
	}	
	return *pIndice;
}

//Muestra el alumno con mejor promedio
void mejor_promedio(Alumno *pAlumno, short *pIndice)
{
	gotoxy(19,4);printf("El Alumno con mejor Promedio es \n \n");
	gotoxy(19,6);printf("Nombre: %s", (pAlumno+*pIndice)->nombre);
	gotoxy(19,7);printf("Edad: %d \n", (pAlumno+*pIndice)->edad);
	gotoxy(19,8);printf("Promedio: %.2f \n", (pAlumno+*pIndice)->promedio);
}

//ingresa los datos del tiempo de cada etapa de un ciclista
int ingresar_etapas()
{
	for(int i = 0; i < 3; i++){
		fflush(stdin);
		gotoxy(30,4);printf("Etapa #%d \n \n", i+1);
		gotoxy(30,6);printf("Horas: ");
		scanf("%d", &(etapas+i)->horas);
		gotoxy(30,7);printf("Minutos: ");
		scanf("%d", &(etapas+i)->minutos);
		gotoxy(30,8);printf("Segundos: ");
		scanf("%d", &(etapas+i)->segundos);
		system("cls");
		dibujaRectangulo(1,1,78,24);
	}
	
	return 0;
}

//Calcula el tiempo en segundos de las etapas del ciclista
long calcular_tiempo()
{
	long tiempo = 0, *pTiempo = &tiempo;
	for(int i = 0; i < 3; i++){
		*pTiempo = *pTiempo + (((etapas+i)->horas * 3600) + ((etapas+i)->minutos * 60) + ((etapas+i)->segundos));
	}
	
	return *pTiempo;
}

//Muestra el tiempo total por las etapas del ciclista
void muestra_tiempo(long *pTiempo)
{
	short horas, minutos, segundos;
	short* pHoras, *pMinutos, *pSegundos;
	
	pHoras = &horas; pMinutos = &minutos, pSegundos = &segundos;
	
	*pHoras = (*pTiempo/3600);
	*pMinutos = ((*pTiempo - (*pHoras * 3600)) / 60);
	*pSegundos = *pTiempo - (*pHoras * 3600 + *pMinutos * 60);
	
	
	gotoxy(30,4);printf("Tiempo total: \n \n");
	gotoxy(30,6);printf("Horas: %d \n", *pHoras);
	gotoxy(30,7);printf("Minutos: %d \n", *pMinutos);
	gotoxy(30,8);printf("Segundos: %d \n", *pSegundos);
}


