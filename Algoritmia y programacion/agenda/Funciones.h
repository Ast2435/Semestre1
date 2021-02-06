void menu ();
int op();

void menu (void){

 // Menú del Programa Principal
	   
      fflush(stdin);
      system("cls");
      printf("\t\tMen\243 Principal\n");
      printf("1.- Agregar Alumno\n"); 
      printf("2.- Mostrar alumnos\n"); 
      printf("3.- Borrar un alumno\n"); 
      printf("4.- Guardar\n");
      printf("5.- Salir\n");
      printf("Selecciona una opci\242n: "); 
       
  }
  
  int op(){
  	int d;
  	fflush(stdin); 
      scanf("%d",&d);
      return(d);
}
