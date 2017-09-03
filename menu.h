/* Menu de opciones del contenido
*  Fecha 03/09/2017
*  Elaborado por: John Sebastian Nieto gil 
*  Elaborado por: Ricardo Andres Villalobos
*/

//Muestra un menu con opciones en pantalla 
void menu(){
	
	short opcion, subOpcion, vocales[5] = {0,0,0,0,0}, indice;
	short *pVocales = vocales, *pIndice = &indice;
	int cantidad = 0, matrizA[50][50], matrizB[50][50], matrizC[50][50], filas = 0, columnas = 0, numero, numeros[100], buscar, mayor = 0, menor = 0, discapacitado = 0, noDiscapacitado = 0;
	int *pCantidad = &cantidad, *pMatrizA = &matrizA[0][0], *pMatrizB = &matrizB[0][0], *pMatrizC = &matrizC[0][0], *pFilas = &filas, *pColumnas = &columnas, *pNumero = &numero, *pNumeros = numeros, *pBuscar = &buscar, *pMayor = &mayor, *pMenor = &menor, *pDiscapacitado = &discapacitado, *pNoDiscapacitado = &noDiscapacitado;
	long tiempo =  0;
	long *pTiempo = &tiempo;
	char nombre[50], cadena[50];
	char *pNombre = nombre, *pCadena = cadena;
	
	system("color A");
	do
	{
		system("cls");
		dibujaRectangulo(2,2,78,23);
		gotoxy(36,4);printf("MENU \n");
		gotoxy(24,6);printf("1. Arreglos con punteros \n");
		gotoxy(24,7);printf("2. Matrices con punteros \n");
		gotoxy(24,8);printf("3. Ejercicios de punteros \n");
		gotoxy(24,9);printf("4. Estructuras con punteros \n");
		gotoxy(24,10);printf("0. Salir \n");
		gotoxy(24,12);printf("Ingrese la opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				do
				{
					system("cls");
					dibujaRectangulo(2,2,78,23);
					gotoxy(35,4);printf("Array \n");
					gotoxy(21,6);printf("1. Mostrar array numeros decimales \n");
					gotoxy(21,7);printf("2. Mostrar array de 0 y 1 \n");
					gotoxy(21,8);printf("3. array 4X4 (cuadrado, cubo, cuarta) \n");
					gotoxy(21,9);printf("0. Salir \n");
					gotoxy(21,11);printf("Ingrese la opcion : ");
					scanf("%d", &subOpcion);
					
					switch(subOpcion)
					{
						case 0:
						{
							opcion = 1;
							break;
						}
						case 1:
						{
							arreglo_decimales();
							getch();
							break;
						}
						case 2:
						{
							system("cls");
							dibujaRectangulo(1,1,78,24);
							gotoxy(18,4);printf("Ingrese los dos valores para el arreglo \n");
							gotoxy(18,6);scanf("%d", pFilas);
							gotoxy(18,7);scanf("%d", pColumnas);
							gotoxy(18,9);printf("Resultado \n \n");
							arreglo_ceros_unos(pFilas, pColumnas, pMatrizA);
							mostrar_array(pFilas, pColumnas, pMatrizA);
							getch();
							break;
						}
						case 3:
						{
							system("cls");
							dibujaRectangulo(1,1,78,24);
							arreglo(pMatrizA);
							arreglo_potencia(pMatrizA);
							*pFilas = 4;
							*pColumnas = 4;
							system("cls");
							gotoxy(18,9);printf("Resultado");
							mostrar_array(pFilas, pColumnas, pMatrizA);
							getch();
							break;
						}
						default:
						{
							gotoxy(30,13);printf("Numero no valido");
							getch();
							break;
						}
					}
				}while(subOpcion != 0);
				break;
			}
			case 2:
			{
				do
				{
					system("cls");
					dibujaRectangulo(1,1,78,24);
					gotoxy(34,4);printf("Matrices \n");
					gotoxy(9,6);printf("1. Matriz 3X3 (usuario completa valores)\n");
					gotoxy(9,7);printf("2. Matriz 3X3 automatica por el sistema \n");
					gotoxy(9,8);printf("3. Matriz 3X3 automatica con numeros primos por el sistema \n");
					gotoxy(9,9);printf("0. Salir \n");
					gotoxy(9,11);printf("Ingrese la opcion : ");
					scanf("%d", &subOpcion);
					
					switch(subOpcion)
					{
						case 0:
						{
							opcion = 1;
							break;
						}
						case 1:
						{
							system("cls");
							dibujaRectangulo(1,1,78,24);
							obtener_datos_matriz(pMatrizA);
							gotoxy(23,4);printf("Resultado: ");
							matriz_valores(pMatrizA);
							getch();
							break;
						}
						case 2:
						{
							system("cls");
							dibujaRectangulo(1,1,78,24);
							completar_matriz_automatica(pMatrizA);
							gotoxy(23,4);printf("Resultado: ");
							matriz(pMatrizA);
							getch();
							break;
						}
						case 3:
						{
							system("cls");
							dibujaRectangulo(1,1,78,24);
							obtener_primos(pMatrizA);
							gotoxy(23,4);printf("Resultado: ");
							matriz(pMatrizA);
							getch();
							break;
						}
						default:
						{
							gotoxy(30,13);printf("Numero no valido");
							getch();
							break;
						}
					}
				}while(subOpcion != 0);
				break;
			}
			case 3:
			{
				do
				{
					system("cls");
					dibujaRectangulo(1,1,78,24);
					gotoxy(26,4);printf("Ejercicios con punteros \n");
					gotoxy(15,6);printf("1. Comprobar par - impar (Direccion de memoria) \n");
					gotoxy(15,7);printf("2. Determinar primo (Direccion de memoria) \n");
					gotoxy(15,8);printf("3. Determinar pares (Direccion de memoria) \n");
					gotoxy(15,9);printf("4. Menor elemento del vector \n");
					gotoxy(15,10);printf("5. Orden ascendente arreglo \n");
					gotoxy(15,11);printf("6. Buscar numero) \n");
					gotoxy(15,12);printf("7. Nombre y sus numero de vocales \n");
					gotoxy(15,13);printf("8. Cadena cantidad vocales(a,e,i,o,u) \n");
					gotoxy(15,14);printf("9. Suma de matrices \n");
					gotoxy(15,15);printf("10. Matriz traspuesta \n");
					gotoxy(15,16);printf("11. Alumno mejor promedio \n");
					gotoxy(15,17);printf("12. Tiempo por etapas ciclista \n");
					gotoxy(15,18);printf("0. Salir \n");
					gotoxy(15,19);printf("Ingrese la opcion : ");
					scanf("%d", &subOpcion);
					
					switch(subOpcion)
					{
						case 0:
						{
							opcion = 1;
							break;
						}
						case 1:
						{
							int numero, *pNumero = &numero;
							gotoxy(15,21);printf("Ingrese un numero: ");
							scanf("%d", pNumero);
							gotoxy(15,22);par_impar(pNumero);
							getch();
							break;
						}
						case 2:
						{
							gotoxy(15,21);printf("Ingrese un numero: ");
							scanf("%d", pNumero);
							
							if(es_primo(pNumero)){
								gotoxy(15,22);printf("El número es primo su posion en memoria es: %p", pNumero);
							}
							else{
								gotoxy(15,22);printf("El número no es primo su posion en memoria es: %p", pNumero);
							}
							getch();
							break;
						}
						case 3:
						{
							*pCantidad = 10;
							system("cls");
							dibujaRectangulo(1,1,78,24);
							ingresar_vector(pNumeros, pCantidad);
							system("cls");
							muestra_pares(pNumeros);
							getch();
							break;
						}
						case 4:
						{
							*pCantidad = 10;
							gotoxy(15,21);printf("Ingrese la cantidad de numeros: ");
							scanf("%d", pCantidad);
							system("cls");
							ingresar_vector(pNumeros, pCantidad);
							system("cls");
							gotoxy(28,12);printf("El numero menor es: %d", muestra_menor(pNumeros, pCantidad));
							getch();
							break;
						}
						case 5:
						{
							gotoxy(15,21);printf("Ingrese la cantidad de numeros: ");
							scanf("%d", pCantidad);
							system("cls");
							ingresar_vector(pNumeros, pCantidad);
							ordenar_arreglo(pNumeros, pCantidad);
							system("cls");
							mostrar_arreglo_ordenado(pNumeros, pCantidad);
							getch();
							break;
							
						}
						case 6:
						{
							gotoxy(15,21);printf("Ingrese la cantidad de numeros: ");
							scanf("%d", pCantidad);
							system("cls");
							ingresar_vector(pNumeros, pCantidad);
							system("cls");
							dibujaRectangulo(1,1,78,24);
							gotoxy(15,4);printf("Ingrese el numero a buscar: ");
							scanf("%d", pBuscar);
							if(in_array(pNumeros, pCantidad, pBuscar)){
								gotoxy(15,6);printf("Numero encontrado");
							}
							else{
									gotoxy(15,6);printf("Numero no encontrado");
							}
							getch();
							break;
							
						}
						case 7:
						{
							gotoxy(15,21);printf("Ingrese su nombre: ");
							fflush(stdin);
							fgets(pNombre, 50, stdin);
							*pCantidad = contar_vocales(pNombre);
							gotoxy(15,22);printf("Su nombre tiene %d vocales", *pCantidad);
							getch();
							break;
						}
						case 8:
						{
							system("cls");
							dibujaRectangulo(2,2,78,23);
							gotoxy(18,4);printf("Ingrese una cadena de maximo 50 caracteres: \n");
							fflush(stdin);
							gotoxy(18,6);fgets(pCadena, 50, stdin);
							array_vocales(pCadena, pVocales);
							mostrar_vocales(pVocales);
							getch();
							break;
							
						}
						case 9:
						{
							gotoxy(15,21);printf("Ingrese la cantidad de Filas para las matrices: ");
							scanf("%d", pFilas);
							gotoxy(15,22);printf("Ingrese la cantidad de Columnas para las matrices: ");
							scanf("%d", pColumnas);
							system("cls");
							ingresar_arreglo(pMatrizA, pFilas, pColumnas);
							system("cls");
							gotoxy(33,2);printf("Matriz #2");
							ingresar_arreglo(pMatrizB, pFilas, pColumnas);
							sumar_matriz(pMatrizA, pMatrizB, pMatrizC, pFilas, pColumnas);
							system("cls");
							gotoxy(20,4);printf("La suma de las matrices es: ");
							mostrar_arreglo(pMatrizC, pFilas, pColumnas);
							getch();
							break;
						}
						case 10:
						{
							gotoxy(15,21);printf("Ingrese la cantidad de Filas para las matrices: ");
							scanf("%d", pFilas);
							gotoxy(15,22);printf("Ingrese la cantidad de Columnas para las matrices: ");
							scanf("%d", pColumnas);
							system("cls");
							ingresar_arreglo(pMatrizA, pFilas, pColumnas);
							matriz_traspuesta(pMatrizA, pMatrizB, pFilas, pColumnas);
							system("cls");
							gotoxy(20,4);printf("La Matriz traspuesta es: ");
							mostrar_arreglo(pMatrizB, pFilas, pColumnas);
							getch();
							break;
						}
						case 11:
						{
							system("cls");
							dibujaRectangulo(1,1,78,24);
							ingresar_alumno();
							*pIndice = mayor_promedio();
							mejor_promedio(pStudent, pIndice);
							getch();
							break;
							
						}
						case 12:
						{
							system("cls");
							dibujaRectangulo(2,2,78,23);
							ingresar_etapas();
							*pTiempo = calcular_tiempo();
							muestra_tiempo(pTiempo);
							getch();
							break;
						}
						default:
						{
							gotoxy(15,21);printf("Numero no valido");
							getch();
							break;
						}
					}
				}while(subOpcion != 0);
				break;
			}
			case 4:
			{
				do
				{
					system("cls");
					dibujaRectangulo(2,2,78,23);
					gotoxy(26,4);printf("Estructuras con punteros \n");
					gotoxy(18,6);printf("1. Competidor y categoria \n");
					gotoxy(18,7);printf("2. Estudiante, mejor promedio \n");
					gotoxy(18,8);printf("3. Trabajador, salario mayor y menor \n");
					gotoxy(18,9);printf("4. Alumno promedio anidadados");
					gotoxy(18,10);printf("5. Alumno promedio anidadados (N Alumnos)");
					gotoxy(18,11);printf("6. Personas (discapacidad)");
					gotoxy(18,12);printf("0. Salir");
					gotoxy(18,13);printf("Ingrese la opcion : ");
					scanf("%d", &subOpcion);
					
					switch(subOpcion)
					{
						case 0:
						{
							opcion = 1;
							break;
						}
						case 1:
						{
							system("cls");
							dibujaRectangulo(2,2,78,23);
							datos_competidor();
							categoria_competidor();
							muestra_competidor(pCompetidor);
							getch();
							break;
						}
						case 2:
						{
							system("cls");
							dibujaRectangulo(2,2,78,23);
							datos_estudiante();
							indice = mejor_promedio_estudiante();
							mostrar_estudiante(pEstudiante, indice);
							getch();
							break;
						}
						case 3:
						{
							gotoxy(18,16);printf("Ingrese la cantidad de Trabajadores: ");
							scanf("%d", pCantidad);
							system("cls");
							dibujaRectangulo(2,2,78,23);
							ingresar_trabajador(pCantidad);
							*pMayor = salario_mayor(pTrabajador, pCantidad);
							*pMenor = salario_menor(pTrabajador, pCantidad);
							muestra_trabajador(pTrabajador, pMayor, pMenor);
							getch();
							break;
						}
						
						case 4:
						{
							system("cls");
							dibujaRectangulo(2,2,78,23);
							*pCantidad = 1;
							datos_alumno(pCantidad);
							muestra_alumno();
							getch();
							break;
						}
						
						case 5:
						{
							gotoxy(18,16);printf("Ingrese la cantidad de estudiantes: ");
							scanf("%d", pCantidad);
							system("cls");
							dibujaRectangulo(2,2,78,23);
							datos_alumno(pCantidad);
							*pMayor = mayor_promedio(pAlumno, pCantidad);
							*pMenor = menor_promedio(pAlumno, pCantidad);
							muestra_promedios(pAlumno, pMayor, pMenor);
							getch();
							break;
						}
						
						case 6:
						{
							gotoxy(18,16);printf("Ingrese la cantidad de personas: ");
							scanf("%d", pCantidad);
							system("cls");
							system("cls");
							dibujaRectangulo(2,2,78,23);
							datos_persona(pCantidad);
							contar_personas(pCantidad, pDiscapacitado, pNoDiscapacitado);
							vector_personas(pCantidad);
							system("cls");
							mostrar_personas_discapacitadas(perDiscapacitado, pDiscapacitado);
							mostrar_personas_SinDiscapacidad(perNoDiscapacitado, pNoDiscapacitado);
							getch();
							break;
						}
						default:
						{
							gotoxy(30,13);printf("Numero no valido");
							getch();
							break;
						}
					}
				}while(subOpcion != 0);
				break;
			}
			default:
			{
				gotoxy(30,13);printf("Numero no valido");
				getch();
				break;
			}
		}
	}while(opcion != 0);
}
