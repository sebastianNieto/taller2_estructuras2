/* Ejercicios que implementan punteros a estructuras
*  Fecha 03/09/2017
*  Elaborado por: John Sebastian Nieto gil 
*  Elaborado por: Ricardo Andres Villalobos
*/


struct Competidores
{
	char nombre[30];
	unsigned short int edad;
	char sexo;
	char club[10], categoria[8];
}competidor, *pCompetidor = &competidor;

struct Estudiante
{
	char nombre[30];
	unsigned short edad;
	unsigned short grado;
	float promedio;
}estudiante[3], *pEstudiante = estudiante;

struct Trabajador
{
	char nombre[30];
	unsigned short edad;
	char sexo;
	char cargo[20];
	float salario;
} trabajador[100], *pTrabajador = trabajador;

struct Promedio
{
	float nota1,nota2,nota3;
};

struct AlumnoPromedio
{
	char nombre[30];
	unsigned short  edad;
	char sexo;
	struct Promedio promedio;
} alumno[100], *pAlumno = alumno;

struct Persona
{
	char nombre[30];
	bool discapacitado;
} persona[100], perDiscapacitado[100], perNoDiscapacitado[100], *pPersona = persona,
*pPerDiscapacitado = perDiscapacitado, *pPerNoDiscapacitado = perNoDiscapacitado;

void datos_competidor();
void categoria_competidor();
void muestra_competidor(Competidores *);
void datos_estudiante();
int mejor_promedio_estudiante();
void mostrar_estudiante(Estudiante *, short);
void ingresar_trabajador(int *cantidad);
int salario_mayor(Trabajador *, int* );
int salario_menor(Trabajador *, int* );
void muestra_trabajador(Trabajador *, int *, int *);
void datos_alumno(int*);
void muestra_alumno();
int mayor_promedio(AlumnoPromedio *, int* );
int menor_promedio(AlumnoPromedio *, int* );
void muestra_promedios(AlumnoPromedio *, int *, int *);
void datos_persona(int*);
void contar_personas(int *, int *, int *);
void vector_personas(int *);
void mostrar_personas_discapacitadas(Persona *, int *);
void mostrar_personas_SinDiscapacidad(Persona *, int *);



//Obtiene los datos para el competidor
void datos_competidor()
{
	
	gotoxy(15,4);printf("ingrese el nombre del competidor: ");
	fflush(stdin);
	fgets(pCompetidor->nombre, 30, stdin);
	gotoxy(15,5);printf("ingrese la edad del competidor: ");
	scanf("%d", &pCompetidor->edad);
	gotoxy(15,6);printf("ingrese el sexo del competidor: F-M: ");
	scanf("%*c %c", &pCompetidor->sexo);
	gotoxy(15,7);printf("ingrese el club del competidor: ");
	fflush(stdin);
	fgets(pCompetidor->club, 30, stdin);
	
}

//obtiene la categoria del competidor segun la edad
void categoria_competidor()
{	
	if(pCompetidor->edad <= 30){
		if(pCompetidor->edad <=15){
			strcpy(pCompetidor->categoria, "Infantil");
		}
		else{
			strcpy(pCompetidor->categoria, "joven");
		}
	}
	else{
		strcpy(pCompetidor->categoria, "Mayor");
	}
}

//Muestra los datos del competidor
void muestra_competidor(Competidores *competidor)
{	
	gotoxy(15,9);printf("Los datos del competidor son:");
	gotoxy(15,11);printf("Nombre: %s \n", competidor->nombre);
	gotoxy(15,12);printf("Edad: %d \n", competidor->edad);
	gotoxy(15,13);printf("Sexo: %c \n", competidor->sexo);
	gotoxy(15,14);printf("Club: %s \n", competidor->club);
	gotoxy(15,15);printf("Categoria: %s \n", competidor->categoria);
}

//Ingresa los datos para 3 estudiantes
void datos_estudiante()
{
	for(short i = 0; i < 3; i++){
		fflush(stdin);
		gotoxy(15,4);printf("Estudiante %d: ", i+1);
		gotoxy(15,6);printf("ingrese el nombre del estudiante: ");
		fgets((pEstudiante+i)->nombre, 30, stdin);
		gotoxy(15,7);printf("ingrese la edad del estudiante: ");
		scanf("%d", &(pEstudiante+i)->edad);
		gotoxy(15,8);printf("ingrese el grado del estudiante: ");
		scanf("%d", &(pEstudiante+i)->grado);;
		gotoxy(15,9);printf("ingrese el promedio del estudiante: ");
		scanf("%f", &(pEstudiante+i)->promedio);
		system("cls");
		dibujaRectangulo(2,2,78,23);
		
	}
	
}

//Retorna el indice del estudiante con mejor promedio
int mejor_promedio_estudiante()
{
	float mayor = 0;
	short indice;
	for(short i = 0; i < 3; i++){
		if((pEstudiante+i)->promedio > mayor){
			mayor = (pEstudiante+i)->promedio;
			indice = i;
		}
	}
	
	return indice;
}

// Muestra el estudiante con mejor promedio
void mostrar_estudiante(Estudiante *estudiante, short indice)
{
	gotoxy(15,4);printf("El estudiante con mejor proemdio es: \n");
	gotoxy(15,6);printf("Nombre: %s \n", (estudiante+indice)->nombre);
	gotoxy(15,7);printf("Edad: %d \n", (estudiante+indice)->edad);
	gotoxy(15,8);printf("Grado: %d \n", (estudiante+indice)->grado);
	gotoxy(15,9);printf("Promedio: %.2f \n", (estudiante+indice)->promedio);
}

//Ingresa los datos de uno o varios trabajadores
void ingresar_trabajador(int *cantidad)
{	
	
	for(int i = 0; i < *cantidad; i++){
		fflush(stdin);
		gotoxy(15,4);printf("Trabajador %d: ", i+1);
		gotoxy(15,6);printf("Ingrese el nombre del trabajador: ");
		fgets((pTrabajador+i)->nombre, 30, stdin);
		gotoxy(15,7);printf("Ingrese la edad del trabajador: ");
		scanf("%d", &(pTrabajador+i)->edad);
		fflush(stdin);
		gotoxy(15,8);printf("Ingrese el sexo del trabajador: ");
		scanf("%c", &(pTrabajador+i)->sexo);
		fflush(stdin);
		gotoxy(15,9);printf("Ingrese el cargo del trabajador: ");
		fgets((pTrabajador+i)->cargo, 20, stdin);
		gotoxy(15,10);printf("Ingrese el salario del trabajador: ");
		scanf("%f", &(pTrabajador+i)->salario);
		system("cls");
		dibujaRectangulo(2,2,78,23);
	}
}

//retorna el indice del trabajador con Mayor salario
int salario_mayor(Trabajador *trabajador, int* cantidad)
{	
	int indice = 0, *pIndice;
	float mayor = 0, *pMayor;
	pMayor = &mayor;
	pIndice = &indice;
	for(int i = 0; i < *cantidad; i++){
		if((trabajador+i)->salario > *pMayor){
			*pMayor = (trabajador+i)->salario;
			*pIndice = i;
		}
	}	
	return *pIndice;
}

//retorna el indice del trabajador con Menor salario
int salario_menor(Trabajador *trabajador, int* cantidad)
{
	float menor = 0, *pMenor; 
	int indice = 0, *pIndice;
	pMenor = &menor;
	pIndice = &indice;
	for(int i = 0; i < *cantidad; i++){
		if((trabajador+i)->salario < *pMenor || *pMenor == 0){
			*pMenor = (trabajador+i)->salario;
			*pIndice = i;
		}
	}	
	
	return *pIndice;
}

//Muestra el trabajador con mayor salario y menor salario segun los indices
void muestra_trabajador(Trabajador *trabajador, int *indiceMayor, int *indiceMenor)
{
	gotoxy(15,4);printf("El Trabajador con mayor salario es \n");
	gotoxy(15,6);printf("Nombre: %s \n", (trabajador+*indiceMayor)->nombre);
	gotoxy(15,7);printf("Edad: %d \n", (trabajador+*indiceMayor)->edad);
	gotoxy(15,8);printf("Sexo: %c \n", (trabajador+*indiceMayor)->sexo);
	gotoxy(15,9);printf("Cargo: %s \n", (trabajador+*indiceMayor)->cargo);
	gotoxy(15,10);printf("Salario: %.2f \n \n", (trabajador+*indiceMayor)->salario);
	gotoxy(15,12);printf("El Trabajador con menor salario es ");
	gotoxy(15,14);printf("Nombre: %s \n", (trabajador+*indiceMenor)->nombre);
	gotoxy(15,15);printf("Edad: %d \n", (trabajador+*indiceMenor)->edad);
	gotoxy(15,16);printf("Sexo: %c \n", (trabajador+*indiceMenor)->sexo);
	gotoxy(15,17);printf("Cargo: %s \n", (trabajador+*indiceMenor)->cargo);
	gotoxy(15,18);printf("Salario: %.2f \n \n", (trabajador+*indiceMenor)->salario);
}

//Ingresa los datos de un alumno
void datos_alumno(int* cantidad)
{
	
	for(int i = 0; i < *cantidad; i++){
		gotoxy(18,4);printf("Nombre del estudiante: ");
		fflush(stdin);
		fgets((pAlumno+i)->nombre, 30, stdin);
		gotoxy(18,5);printf("Edad del estudiante: ");
		scanf("%d", &(pAlumno+i)->edad);
		gotoxy(18,6);printf("Sexo del estudiante: ");
		scanf("%*c %c", &(pAlumno+i)->sexo);
		gotoxy(18,7);printf("Nota1 del estudiante: ");
		scanf("%f", &(pAlumno+i)->promedio.nota1);
		gotoxy(18,8);printf("Nota2 del estudiante: ");
		scanf("%f", &(pAlumno+i)->promedio.nota2);
		gotoxy(18,9);printf("Nota3 del estudiante: ");
		scanf("%f", &(pAlumno+i)->promedio.nota3);
		system("cls");
		dibujaRectangulo(2,2,78,23);
	}
}

//Muestra los datos del alumno
void muestra_alumno()
{
	float promedio, *pPromedio;
	pPromedio = &promedio;
	
	gotoxy(18,4);printf("Datos del alumno");
	gotoxy(18,6);printf("Nombre del estudiante: %s \n", (pAlumno)->nombre);
	gotoxy(18,7);printf("Sexo del estudiante: %c \n", (pAlumno)->sexo);
	gotoxy(18,8);printf("Edad del estudiante: %d \n", (pAlumno)->edad);
	gotoxy(18,9);printf("Nota1 del estudiante: %.2f \n", (pAlumno)->promedio.nota1);
	gotoxy(18,10);printf("Nota2 del estudiante: %.2f \n", (pAlumno)->promedio.nota2);
	gotoxy(18,11);printf("Nota3 del estudiante: %.2f \n", (pAlumno)->promedio.nota3);
	*pPromedio = ((pAlumno)->promedio.nota1 + (pAlumno)->promedio.nota2 + (pAlumno)->promedio.nota3)/3;
	gotoxy(18,12);printf("Promedio del estudiante: %.2f \n", *pPromedio);
}

//retorna el indice del Alumno con Mayor promedio
int mayor_promedio(AlumnoPromedio *pAlumno, int* cantidad)
{
	int indice = 0, *pIndice;
	float mayor = 0, *pMayor, promedio, *pPromedio = &promedio;
	pMayor = &mayor;
	pIndice = &indice;
	
	for(int i = 0; i < *cantidad; i++){
		*pPromedio = ((pAlumno+i)->promedio.nota1 + (pAlumno+i)->promedio.nota2 + (pAlumno+i)->promedio.nota3)/3;
		if(*pPromedio > *pMayor){
			*pMayor = *pPromedio;
			*pIndice = i;
		}
	}	
	return *pIndice;
}

//retorna el indice del alumno con Menor promedio
int menor_promedio(AlumnoPromedio *pAlumno, int* cantidad)
{
	int indice = 0, *pIndice;
	float menor = 0, *pMenor, promedio, *pPromedio = &promedio;
	pMenor = &menor;
	pIndice = &indice;
	
	for(int i = 0; i < *cantidad; i++){
		*pPromedio = ((pAlumno+i)->promedio.nota1 + (pAlumno+i)->promedio.nota2 + (pAlumno+i)->promedio.nota3)/3;
		if(*pPromedio < *pMenor || *pMenor == 0){
			*pMenor = *pPromedio;
			*pIndice = i;
		}
	}	
	return *pIndice;
}

//Muestra el alumno con mayor promedio y menor proemdio segun los indices
void muestra_promedios(AlumnoPromedio *pAlumno, int *indiceMayor, int *indiceMenor)
{
	float promedio, *pPromedio = &promedio;
	gotoxy(18,4);printf("El Alumno con mayor Promedio es \n");
	gotoxy(18,6);printf("Nombre: %s \n", (pAlumno+*indiceMayor)->nombre);
	gotoxy(18,7);printf("Edad: %d \n", (pAlumno+*indiceMayor)->edad);
	gotoxy(18,8);printf("Sexo: %c \n", (pAlumno+*indiceMayor)->sexo);
	*pPromedio = ((pAlumno+*indiceMayor)->promedio.nota1 + (pAlumno+*indiceMayor)->promedio.nota2 + (pAlumno+*indiceMayor)->promedio.nota3)/3;
	gotoxy(18,9);printf("Promedio: %.2f \n \n", *pPromedio);
	gotoxy(18,11);printf("El Alumno con menor promedio es ");
	gotoxy(18,13);printf("Nombre: %s \n", (pAlumno+*indiceMenor)->nombre);
	gotoxy(18,14);printf("Edad: %d \n", (pAlumno+*indiceMenor)->edad);
	gotoxy(18,15);printf("Sexo: %c \n", (pAlumno+*indiceMenor)->sexo);
	*pPromedio = ((pAlumno+*indiceMenor)->promedio.nota1 + (pAlumno+*indiceMenor)->promedio.nota2 + (pAlumno+*indiceMenor)->promedio.nota3)/3;
	gotoxy(18,16);printf("Promedio: %.2f \n \n", *pPromedio);
}

//Ingresa los datos de las personas y si son discapacitadas o no
void datos_persona(int* pCantidad)
{
	char opcion;
	char* pOpcion;
	pOpcion = &opcion;
	
	for(int i = 0; i < *pCantidad; i++){
		fflush(stdin);
		gotoxy(18,4);printf("Persona #%d: ", i+1);
		gotoxy(18,6);printf("Ingrese el nombre de la persona: ");
		fgets((pPersona+i)->nombre, 30, stdin);
		gotoxy(18,7);printf("Es discapacitado ? S - N: ");
		scanf("%c", pOpcion);
		system("cls");
		dibujaRectangulo(2,2,78,23);
		if(*pOpcion == 's' || *pOpcion == 'S'){
			(pPersona+i)->discapacitado = true;
		}
		else{
			(pPersona+i)->discapacitado = false;
		}
	}
}

//Cuenta cuantas personas son discapacitadas y cuantas no
void contar_personas(int *pCantidad, int *discapacitado, int *noDiscapacitado)
{
	for(int i = 0; i < *pCantidad; i++){
		((pPersona+i)->discapacitado)? (*discapacitado)++ : (*noDiscapacitado)++;
	}
}

//Copia un vector con las personas discapacitadas y otro con las que no
void vector_personas(int *pCantidad)
{
	int con = 0, sin = 0;
	int* pCon, *pSin;
	
	pCon = &con;
	pSin = &sin;
	
	for(int i = 0; i < *pCantidad; i++){
		if((pPersona+i)->discapacitado){
			strcpy((pPerDiscapacitado+*pSin)->nombre,(pPersona+i)->nombre);
			(*pSin)++;
		}
		else{
			strcpy((pPerNoDiscapacitado+*pCon)->nombre, (pPersona+i)->nombre);
			(*pCon)++;
		}
	}
}

//Muestra las personas con alguna discapacidad
void mostrar_personas_discapacitadas(Persona *pDiscapacitado, int *discapacitado)
{
	printf("Listado Personas Discapacitadas \n \n");
	for(int i = 0; i < *discapacitado; i++){
		printf("-%s", (pDiscapacitado+i)->nombre);
	}
}

//Muestra las peronas que no son discapacitadas
void mostrar_personas_SinDiscapacidad(Persona *pNoDiscapacitado, int *noDiscapacitado)
{
	printf("\nListado Personas Sin Discapacidad \n \n");
	for(int i = 0; i < *noDiscapacitado; i++){
		printf("- %s", (pNoDiscapacitado+i)->nombre);
	}
}
