typedef struct {
    char nombre[20];
    char carrera[20];
    int numeroMaterias;
    Materia *materias;
} Profesor;

typedef struct {
    char nombre[20];
    int nivel;
    char carrera[20];
    int numeroMaterias;
    Materia *materias;
} Estudiante;

typedef struct {
    char nombre[20];
    int paralelo;
    int creditos;
} Materia;
