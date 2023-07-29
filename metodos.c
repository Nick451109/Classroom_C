#include "estructuras.c"

/*
crear profesor, crear estudiante, mostrar datos, eliminar materia, cambiar nivel y agréguelos en un archivo metodos.c


*/

void crearProfesor(Profesor *profesor)
{

    int numMaterias;

    printf("Ingrese nombre del profesor: \n");
    scanf("%s", profesor->nombre);

    printf("Ingrese carrera del profesor: \n");
    scanf("%s", profesor->carrera);

    printf("Ingrese cantidad de materias dictando: \n");
    scanf("%i", &numMaterias);

    while (numMaterias < 2 || numMaterias > 3)
    {
        printf("Un profesor solo puede dictar de 2 a 3 materias, ingrese un numero valido");

        scanf("%i", &numMaterias);
    };

    profesor->materias = numMaterias;
    profesor->materias = (Materia *)malloc(numMaterias * sizeof(Materia));

    for (int i = 0; i < numMaterias; i++)
    {
        Materia *materia = &profesor->materias[i];
        printf("Nombre de la materia %i: \n", i + 1);
        scanf("%s", materia->nombre);
        printf("Paralelo de la materia %i: \n", i + 1);
        scanf(" %d", &(materia->paralelo));
        scanf("%*[^\n]");
        getchar();
    }
}

void crearEstudiante(Estudiante *estudiante)
{

    int numMaterias;

    printf("Ingrese nombre del estudiante: \n");
    scanf("%s", estudiante->nombre);

    printf("Ingrese nivel del estudiante: \n");
    scanf("%i", estudiante->nivel);
    // scanf("%*[^\n]");
    // getchar();

    printf("Ingrese carrera del estudiante: \n");
    scanf("%s", estudiante->carrera);

    printf("Ingrese cantidad de materias tomando: \n");
    scanf("%i", &numMaterias);

    while (numMaterias < 3 || numMaterias > 7)
    {
        printf("Un estudiante solo puede ver de 3 a 7 materias, ingrese un numero valido");

        scanf("%i", &numMaterias);
    };

    estudiante->numeroMaterias = numMaterias;
    estudiante->materias = (Materia *)malloc(numMaterias * sizeof(Materia));

    for (int i = 0; i < numMaterias; i++)
    {
        Materia *materia = &estudiante->materias[i];
        printf("Nombre de la materia %i: \n", i + 1);
        scanf("%s", materia->nombre);
        printf("Creditos de la materia %i: \n", i + 1);
        scanf(" %d", &(materia->creditos));
        scanf("%*[^\n]");
        getchar();
    }
}

void mostrarDatosProfesor(Profesor *profesores, int cantidadPersonas)
{
    printf("\n--Profesores--\n");
    for (int i = 0; i < cantidadPersonas; i++)
    {
        printf("Nombre: %s, Carrera: %s\n", profesores[i].nombre,
               profesores[i].carrera);
        for (int j = 0; j < profesores[i].numeroMaterias; j++)
        {
            printf("Materia %i\n", j + 1);
            printf("\tNombre:%s\n", profesores[i].materias[j].nombre);
            printf("\tCreditos:%i\n", profesores[i].materias[j].paralelo);
        }
    }
}

void mostrarDatosEstudiante(Estudiante *estudiantes, int cantPersonas)
{
    printf("\n---Estudiantes---\n");
    for (int i = 0; i < cantPersonas; i++)
    {
        printf("Nombre: %s, Nivel: %i, Carrera: %s\n", estudiantes[i].nombre,
               estudiantes[i].nivel, estudiantes[i].carrera);

        for (int j = 0; j < estudiantes[i].numeroMaterias; j++)
        {
            printf("Materia %i\n", j + 1);
            printf("\tNombre:%s\n", estudiantes[i].materias[j].nombre);
            printf("\tCreditos:%i\n", estudiantes[i].materias[j].creditos);
        }
    }
}

void eliminarMateriaEstudiante(Estudiante *estudiantes, int cantidadEstudiantes)
{
    int opcion;
    char nombreEstudiante[20];
    int materia;

    printf("Desea eliminar una materia de un estudiante? [Si=1/No=0]:\n");
    scanf("%i", &opcion);

    if (opcion == 0)
    {
        return;
    }

    printf("Ingrese el nombre del estudiante:\n");
    scanf("%s", nombreEstudiante);

    printf("Ingrese el numero de la materia que quiere eliminar:\n");
    scanf("%i", &materia);

    Estudiante *estudianteModificar;
    for (int i = 0; i < cantidadEstudiantes; i++)
    {
        if (strcmp(estudiantes[i].nombre, nombreEstudiante) == 0)
        {
            estudianteModificar = &estudiantes[i];
            break;
        }
    }
    Materia materiaEliminada = estudianteModificar->materias[materia - 1];

    for (int j = (materia - 1); j < (*estudianteModificar).numeroMaterias - 1; j++)
    {
        estudianteModificar->materias[j] = estudianteModificar->materias[j + 1];
    }

    estudianteModificar->numeroMaterias--;
    printf("La materia %s del estudiante %S ha sido eliminada con éxito", materiaEliminada, nombreEstudiante);
    mostrarEstudiantes(estudiantes, cantidadEstudiantes);
}

void eliminarMateriaProfesores(Profesor *profesores, int cantidadProfesores){
    int opcion;
    char nombreProfesor[20];
    int materia;

    printf("Desea eliminar una materia de un profesor? [Si=1/No=0]:\n");
    scanf("%i", &opcion);

    if(opcion == 0){ 
        return ;
        }

    printf("Ingrese el nombre del profesor:\n");
    scanf("%s", nombreProfesor);

    printf("Ingrese el numero de la materia que quiere eliminar:\n");
    scanf("%i", &materia);
    
    Profesor *profesorModificar;
    for(int i=0; i<cantidadProfesores; i++){
        if(strcmp(profesores[i].nombre, nombreProfesor) == 0){
            profesorModificar = &profesores[i];
            break;
        }
    }
    Materia materiaEliminada = profesorModificar->materias[materia-1];
    for(int j = (materia-1); j < (*profesorModificar).numeroMaterias - 1; j++){
       profesorModificar->materias[j] = profesorModificar->materias[j+1];
    }
    profesorModificar->numeroMaterias--;
    printf("La materia %s del profesor %S ha sido eliminada con exito\n", materiaEliminada.nombre,nombreProfesor );
    mostrarProfesores(profesores,cantidadProfesores);
}

void cambiarNivel(Estudiante *estudiantes, int cantidadEstudiantes)
{
    int nuevoNivel;
    int opcion;
    Estudiante *estudianteModificar;

    printf("Desea cambiar el nivel de un estudiante? [Si=1/No=0]:\n");
    scanf("%i", &opcion);
    if (opcion == 0)
    {
        return;
    }
    printf("Ingrese el nombre del estudiante:\n ");
    char nombreEstudiante[20];
    scanf("%s", nombreEstudiante);

    printf("Ingrese el nuevo nivel del estudiante:\n");
    scanf("%i", &nuevoNivel);

    for (int i = 0; i < cantidadEstudiantes; i++)
    {
        if (strcmp(estudiantes[i].nombre, nombreEstudiante) == 0)
        {
            estudianteModificar = &estudiantes[i];
            break;
        }
    }
    estudianteModificar->nivel = nuevoNivel;
    mostrarEstudiantes(estudiantes, cantidadEstudiantes);
}
