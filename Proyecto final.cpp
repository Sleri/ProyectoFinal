#include <cstdlib> //libreria para el uso del atoi
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h> //libreria para el get y fflush
#include <stdlib.h> //libreria para cambiar la interfaz
#include <conio.h>

/*
integrantes:
natalia agudelo valdes
juan sebastian bayer
juan david hoyos ramirez
sebastian ariza rodriguez
*/

using namespace std;
//declaracion de variables
bool encontrado = false; 

char respuesta;
string usuario,contrasena;
int opcion; 

//estructura de la informacion de las peliculas
struct peliculas{
	int codigo;
	int codigoAux;
	string nombreAux;
	string nombrePelicula;
	string nombreAutor;
	string autorAux;
	string genero;
	string generoAux;
	char cantidad[10];
	int anio;
	int anioAux;
	
}pelis[10];

//estructura del alquiler de la pelicula
struct Alquiler
{
	char fecha[15];
    char documento[30];
	char nombre[30];
	char telefono[15];
	int cantidadAlquilar;
}alqui[5];


//funcion donde se observa el inventario de las peliculas en la base de datis
void consultas()
{
	int contador = 0; //declaracion variable
    ifstream lectura; //se crea la variable que leera el documento
    lectura.open("peliculas.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if(lectura.is_open())
	{
    	//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
    	lectura>>pelis[contador].codigo;
    	while(!lectura.eof()) //mientras se pueda leer
		{
			//muestra la informacion de todas las peliculas guardades - inventario
			//lee e imprime las peliculas almacenadas
        	lectura>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
	        cout<<"\n";
    	    cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
	        cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    	    cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
	        cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
	        cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
			lectura>>pelis[contador].codigo;
    	}
    }else
	{
		//decision por si no se puede abrir el documento de almacenaje de la peliculas
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close(); //se cierra la lectura del documento peliculicas txt
	
	cout <<"\nPresione enter para volver al menu principal. . .\n"; //mensaje de salida para volver al menu principal
	getch();
}

//funcion del administrador para agregar peliculas nuevas al inventario
void insertarpeliculas(){
    //Variables de la biblioteca fstream para el manejo de archivos
    ofstream escritura; //creacion del archivo 1
    ifstream consulta; //variable para la lectura del documento establecido
    //ofstream escritura2; //creacion del archivo 2
    int contador = 0; //declaracion de la variable
    //mensaje de bienvenida para el administrador
	cout<<"BIENVENIDO AL SISTEMA DE ADMINISTRADOR";
	cout<<"\n\n";
	fflush(stdin);
	cout<<"Usuario (root): "; //ingreso del nombre de usuario del administrador
	cin>>usuario; //lectura del nombre de ususario del administrador
	fflush(stdin);
	cout<<"Contrasena (root123): "; //ingreso de la contraseña del administrador
	cin>>contrasena; //lectura de la contrasela del administrador
	
    //decision para verificar que el usuario y la contraseña sean correctas
	if(usuario == "root" && contrasena == "root123")
	{
		cout<<"\nAcceso Permitido\n";
		cout<<"Oprima enter para continuar\n\n"; //mensaje de ingreso al siguiente paso
		getch();
		do
		{	
			system("cls"); 
			cout<<"1. Ingresar Peliculas\n2. Consultas peliculas prestadas\n3. Eliminar cantidad de pelicula\n4. Multas\n5. Salir"; //menu del administrador
			cout<<"\nElige una opcion: "; 
			fflush(stdin);
			cin>>opcion; //lectura de la opcion selesccionada por el administrador
		
			switch(opcion)
			{
				case 1: //caso 1 ingresar peliculas
				system("cls");
				contador = 0;
				do
				{
					system("cls");
					//escritura2.open("peliculas2.txt", ios::out | ios::app); //crea y escribe, si ya tiene texto une al final del archivo
					escritura.open("peliculas.txt", ios::out | ios::app); //crea y escribe, si ya tiene texto une al final del archivo
    				consulta.open("peliculas.txt", ios::in); //solamente consulta o lee usando la variable sobre el archivo físico peliculas.txt
					
					if(escritura.is_open() && consulta.is_open() /*&& escritura2.is_open()*/) //decicion para saber si el codigo ingresado ya existe 
					{
						bool repetido = false; //declaracion de variable
        				cout<<"Ingresa el codigo de la pelicula: ";
        				fflush(stdin);
        				cin>>pelis[contador].codigoAux; //lectura del codigo auxiliar que ira almacenado en el documento temporal creado
        				
						
						//A continuación se aplica el tipo de lectura de archivos secuencial
						consulta>>pelis[contador].codigo;
						while(!consulta.eof()) //recorre todo el archivo para saber si el codigo ingresado ya existe
						{
						consulta>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
							if(pelis[contador].codigoAux == pelis[contador].codigo)
							{
								cout<<"\nYa hay una pelicula con este codigo\n";
								repetido = true;
								
							}
							consulta>>pelis[contador].codigo; //llamado de la variable
						}
						
						if(repetido == false) //decision que se ejecuta al no haber un codigo igual al ingresado por el administrador
						{
							cout<<"Ingrese el nombre de la pelicula (En caso de que haya espaciado usar _): ";
							fflush(stdin);
							getline(cin,pelis[contador].nombrePelicula); //lectura del nombre de la pelicula
							
							cout<<"Ingrese la cantidad de la pelicula: ";
							fflush(stdin);
							gets(pelis[contador].cantidad); //lectura de la cantidad de la pelicula
							
							cout<<"Ingresa el anio de la pelicula: ";
							fflush(stdin);
							cin>>pelis[contador].anio; //lectura del año de la pelicula
							
							
							cout<<"Ingresa el nombre del Autor de la pelicula (En caso de que haya espaciado usar _): ";
							fflush(stdin);
							getline(cin,pelis[contador].nombreAutor); //lectura del nombre de autor
							
							cout<<"Ingrese el genero de la pelicula: ";
							fflush(stdin);
							getline(cin,pelis[contador].genero); //lectura del genero de la pelicula
							
							//ESCRIBIENDO LOS DATOS CAPTURADOS POR EL USUARIO EN EL ARCHIVO
							escritura<<pelis[contador].codigoAux<<" "<<pelis[contador].nombrePelicula<<" "<<pelis[contador].cantidad<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreAutor<<" "<<pelis[contador].genero<<endl;
							//escritura<<pelis[contador].codigoAux<<" "<<pelis[contador].nombrePelicula<<" "<<pelis[contador].cantidad<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreAutor<<" "<<pelis[contador].genero<<endl;
							
							cout<<"\nPelicula agregada\n"; //mensaje de salida
						}
						//mensaje para volver a ejecutar el ciclo o salir de el
						cout<<"Desea ingresar otra pelicula (s/n)?: ";
						fflush(stdin);
            			cin>>respuesta; //lee la respuesta seleccionada
					
					}else //decision si no se puede abrir el archivo
					{
						cout<<"El archivo no se pudo abrir \n"; //mensaje de salida al no poder abrir el archivo
					}
				contador++;
			
				escritura.close();  //se cierra el archivo 1
				consulta.close();  //se cierra el archivo que lee el documento peliculas.txt
				
				}while(respuesta =='S' or respuesta =='s');
				break; 
				
				case 2: //funcion para consultar las peliculas prestadas o alquiladas
				{
					contador = 0;
   					ifstream lectura; //declaracion de la variable que leera el documento
    				lectura.open("DatosAlquiler.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    				if(lectura.is_open()){
    					//LEYENDO Y MOSTRANDO CADA CAM,PO DEL ARCHIVO DE FORMA SECUENCIAL
    					lectura>>alqui[contador].fecha;
    					cout<<"\nLista de peliculas alquiladas:\n";
    					while(!lectura.eof()){ //hace el recorrido del documento DatosAlquiler.txt y muestra la informacion que este dentro de esta
							lectura>>alqui[contador].documento>>alqui[contador].nombre>>alqui[contador].telefono>>pelis[contador].nombrePelicula>>alqui[contador].cantidadAlquilar;
        					cout<<"\n";
        					cout<<"Nombre: "<<pelis[contador].nombrePelicula<<endl;
        					cout<<"Cantidad: "<<alqui[contador].cantidadAlquilar<<endl;
        					cout<<"Alquilada por: "<<alqui[contador].nombre<<endl;
        					cout<<"Fecha: "<<alqui[contador].fecha<<endl;
        					cout<<"Cedula: "<<alqui[contador].documento<<endl;
        					cout<<"Telefono: "<<alqui[contador].telefono<<endl;
        					lectura>>alqui[contador].fecha; //llamada de la variable para seguir acumulando
    					}
    				}else{
        				cout<<"El archivo no se pudo abrir \n"; //decision por si el documeno no se puede abrir
    				}
    				lectura.close(); //se cierra la variable que hace la lectura del documento DatosAlquiler.txt
					contador++;
					cout<<"\nPresione enter para continuar\n"; //mensaje de salida al menu del administrador
					getch();
				break;
				}
		
				case 3:	//caso 3 eliminacion de las peliculas
				{	
				
					//declaracion de variables
					ofstream fechaDatos, aux;
					ifstream Imprimir, archivo1, lectura;
					int contador = 0, x, resta;
	
					do
   	 				{
    					system("cls");
    					cout<<"\nLista de peliculas para alquilar:\n";
    					Imprimir.open("peliculas.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE apertura del documento
    					if(Imprimir.is_open())
						{
	    					//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
    						Imprimir>>pelis[contador].codigo;
	    					while(!Imprimir.eof())
							{
			        			Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
    			    			cout<<"\n";
			        			cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    			    			cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        						cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
		        				Imprimir>>pelis[contador].codigo; //llamado de la variable para seguir acumulando
    						}
    					}else
						{	
	        				cout<<"El archivo no se pudo abrir \n"; //mensaje de salida al no poder abrir el documento
	    				}
    					Imprimir.close(); //cierre del documento
    					
    					
    					
						archivo1.open("peliculas.txt", ios::out | ios::in);//apertura del documento
    					cout<<"\nIngrese el codigo de la pelicula a la cual eliminara x cantidad: ";
    					
						encontrado = false; //variable logica
						
    					if(archivo1.is_open())
						{
	    					fflush(stdin);
    	    				cin>>pelis[contador].codigoAux; //lectura del codigo auxiliar
        					
	        				archivo1>>pelis[contador].codigo; //llamada de la variable
    	    				while(!archivo1.eof()) //mientras se pueda abrir el documento
							{
        	    				archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero; //recorrido
	        					
								
    	    					if(pelis[contador].codigoAux == pelis[contador].codigo){//comparar cada registro para ver si es encontrado
		        	    			cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    		    					cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
	    		    				x = atoi(pelis[contador].cantidad); //conversion de char a entero
		    		    			
	        		    			encontrado = true; //variable logica
    	        					cout<<"\nCuantas desea eliminar?: ";
        	    					fflush(stdin);
	    							cin>>alqui[contador].cantidadAlquilar;//lectura de la cantidad de peliculas a alquilar 
    								if(alqui[contador].cantidadAlquilar < x) //cantidad de peliculas a alquilar menor a la resta ejecutada
    								{
	    								//El proceso no se puso aqui porque se cree que hay una interferencia
									}else
									{
										//mensaje de salida con interaccion del usuario 
										cout<<"\nNo hay suficientes peliculas disponibles";
										cout<<"\nPresione enter para continuar\n";
										getch();
									}
    	    					}
								
	        					//lectura adelantada
    	    					archivo1>>pelis[contador].codigo; //llamado de la variable
        					}
	        				
							if (encontrado == false)
							{
    	        				cout<<"\nNo hay registros con el codigo: "<<pelis[contador].codigoAux<<"\n"; //mensaje de salida
	        				}
	    				
						}else
						{
	        				cout<<"\nAun no se pudo abrir el archivo..."; //mensaje de salida
	    				}
						archivo1.close(); //cierre del documento
						
						
    					encontrado = false; //variable logica
    					if(alqui[contador].cantidadAlquilar < x) //pelicula alquida menor a la de la resta
    					{
    						aux.open("auxiliar.txt", ios::out); //creacion del documento
    						lectura.open("peliculas.txt", ios::in); //lectura del documento peliculas.txt
							
    						if (aux.is_open() && lectura.is_open()) //apertura de los dos documentos
							{
    		    				lectura>>pelis[contador].codigo; //llamado de la variable
        						while (!lectura.eof())//mientras se pueda leer el documento
								{
    	            				lectura>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero; //recorrido
        	        				if (pelis[contador].codigoAux == pelis[contador].codigo) //comparacion del codigo a buscar con los registros del documento
									{
	                    				encontrado = true; //variable logica
										resta = x - alqui[contador].cantidadAlquilar; //operacion 
										
            	        				aux<<pelis[contador].codigo<<" "<<pelis[contador].nombrePelicula<<" "<<resta<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreAutor<<" "<<pelis[contador].genero<<endl; //guardado en el aux
            	        				//mensaje de salida con interaccion del usuario
										cout<<"\nFinalizando pedido. . .\n";
										cout<<"\nPresione enter para continuar\n";
	               					}else
									{
        	            				aux<<pelis[contador].codigo<<" "<<pelis[contador].nombrePelicula<<" "<<pelis[contador].cantidad<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreAutor<<" "<<pelis[contador].genero<<endl;
            	    				}
	                				lectura>>pelis[contador].codigo; //llamado de la variable
    	        				}
	    					}else
							{
		        			cout<<"\nEl archivo no se pudo abrir\n"; //mensaje de salida
		    				}
						
    						if (encontrado == false)
							{
	    	    				cout<<"\nNo hay ninguna pelicula con el codigo: "<<pelis[contador].codigoAux<<"\n"; //mensaje de salida
		    				}
							
    						aux.close(); //cierre del documento
    						lectura.close(); //cierre del documento
	    					remove ("peliculas.txt"); //eliminacion del documento
    						rename("auxiliar.txt", "peliculas.txt"); //el auxiliar reemplaza al original
						}
	    				
						contador++;
    					cout<<"\nDesea alquilar otra pelicula (s/n)?: ";
						fflush(stdin);
        				cin>>respuesta; //lectura de la opcion seleccionada por el usuario 
        				
					}while(respuesta =='S' or respuesta =='s');	
				break;
				}
				
				case 4:
				{
					//declaracion de variables
					ifstream archivo1, lectura;
					int dias,Vmulta;
					contador = 0;
					
					do
    				{
    					system("cls");
						lectura.open("DatosAlquiler.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE apertura del documento
    					if(lectura.is_open()){
	    					//LEYENDO Y MOSTRANDO CADA CAM,PO DEL ARCHIVO DE FORMA SECUENCIAL
    						lectura>>alqui[contador].fecha;
    						cout<<"\nLista de peliculas alquiladas:\n";
    						while(!lectura.eof()){ //hace el recorrido del documento DatosAlquiler.txt y muestra la informacion que este dentro de esta
								lectura>>alqui[contador].documento>>alqui[contador].nombre>>alqui[contador].telefono>>pelis[contador].nombrePelicula>>alqui[contador].cantidadAlquilar;
        						cout<<"\n";
	        					cout<<"Nombre: "<<pelis[contador].nombrePelicula<<endl;
    	    					cout<<"Cantidad: "<<alqui[contador].cantidadAlquilar<<endl;
        						cout<<"Alquilada por: "<<alqui[contador].nombre<<endl;
        						cout<<"Fecha: "<<alqui[contador].fecha<<endl;
        						cout<<"Cedula: "<<alqui[contador].documento<<endl;
        						cout<<"Telefono: "<<alqui[contador].telefono<<endl;
	        					lectura>>alqui[contador].fecha;
    						}
    					}else{
        					cout<<"El archivo no se pudo abrir \n"; //decision por si el documeno no se puede abrir
    					}
    					lectura.close(); //se cierra la variable que hace la lectura del documento DatosAlquiler.txt
    					
    					
						archivo1.open("DatosAlquiler.txt", ios::out | ios::in);//apertura del documento
						encontrado=false; //variable logica
						if(archivo1.is_open()) //si se abre el documento
						{
							cout<<"\nIngrese el nombre de la pelicula que desea hacer la multa: ";
							fflush(stdin);
							cin>>pelis[contador].nombreAux; //lectura del nombre a buscar
							
							archivo1>>pelis[contador].nombrePelicula; //llamado de la variable
							
							while(!archivo1.eof()){ //mientras se pueda leer el documento
								archivo1>>alqui[contador].documento>>alqui[contador].nombre>>alqui[contador].telefono>>pelis[contador].nombrePelicula>>alqui[contador].cantidadAlquilar; //recorrido				
								
								if(pelis[contador].nombreAux == pelis[contador].nombrePelicula) //comparacion 
								{
									cout<<"\nCuantos dias han pasado desde el alquiler?: ";
									fflush(stdin);
									cin>>dias; //lectura de los dias ingresados
									if(dias > 20) //condicion
									{
										Vmulta=dias*1000; //operacion
										cout<<"\nSe debe aplicar una multa de: "<<Vmulta<<" pesos"; //mensaje de salida
									}else
									{
										cout<<"\nAun esta a tiempo de entrega"; //mensaje de salida
									}
									encontrado=true; //variable logica
								}
								archivo1>>pelis[contador].nombrePelicula; //llamado de la varible y acumulacion de esta
							}
							
							if(encontrado==false)
							{
								cout<<"\nNo hay peliculas con ese nombre\n"; //mensaje de salida
							}
		
						}else
						{
							cout<<"\nAun no se pudo abrir el archivo"; //mensaje de salida
						}
						
						archivo1.close(); //cierre del documento
						cout<<"\nDesea agregar otra multa s/n?: ";
						fflush(stdin);
						cin>>respuesta; //lectura de la respuesta del usuario
						contador++;
					}while(respuesta=='S' or respuesta=='s');
					break;
				}
					
				
			}//esta cierra el switch
		}while(opcion != 5);//esta cierra el do principal 
  	}else
	{
		//mensaje de salida con interaccion del usuario
  		cout<<"\nAcceso denegado\n";
		cout<<"Oprima enter para continuar\n\n"; 
		getch();
	}
}// cierra el void

//funcion de busqueda por las caracteristicas de las peliculas
void buscar()
{
	//declaracion de variables
	int n;
	int contador;
    ifstream lectura, archivo1, archivo2;

	do{
		system("cls");
		cout<<"Ingrese segun el numero, lo que desea hacer:\n1. Consultar por codigo\n2. Consultar por nombre\n3. Consultar por anio\n4. Consultar por autor\n5. Consultar por genero\n6. Salir\n";
		cout<<"\nElige una opcion: "; 
		fflush(stdin);
		cin>>n; //lectura de la opcion seleccionada por el usuario
		
		switch(n)
		{
		case 1:
		{
			ifstream Imprimir; //lectura
			do{
			
			system("cls");
			contador = 0;
			archivo1.open("peliculas.txt", ios::out | ios::in); //apertura del documento
			encontrado = false; //variable logica
			
			cout<<"\nLista de peliculas:\n";
    		Imprimir.open("peliculas.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE apertura del documento
    		if(Imprimir.is_open()) //si se abre
			{
	    		//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
    			Imprimir>>pelis[contador].codigo;
	    		while(!Imprimir.eof()) //recorrido del documento
				{
		        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
    		    	cout<<"\n";
		        	cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    	cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        			cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        			cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    		cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
	        		cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        	Imprimir>>pelis[contador].codigo; //llamado de la variable para acumular en este
		        	
    			}
    		}else
			{	
		        cout<<"El archivo no se pudo abrir \n"; //mensaje de salida
		    }
    		Imprimir.close(); //cierre del documento
			
			
    		if(archivo1.is_open()) //si hay apertura del documento
			{
				cout<<"\nIngrese el codigo de la pelicula que desea buscar: ";
				fflush(stdin);
        		cin>>pelis[contador].codigoAux; //lectura del codigo a buscar
        		
							        
        		archivo1>>pelis[contador].codigo; //llamado de la variable
        		
        		while(!archivo1.eof()) //recorrido del documento
				{
	            	archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
        			//comparar cada registro para ver si es encontrado				
        			if(pelis[contador].codigoAux == pelis[contador].codigo)
					{
            			cout<<"\nCodigo de la pelicula: "<<pelis[contador].codigo<<endl;
        				cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        				cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        				cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
        				cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
        				cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
        				
            			encontrado = true;//variable logica
        			}
        			//lectura adelantada
        			archivo1>>pelis[contador].codigo; //llamado de la variable y su acumulacion 
        		}
        		if (encontrado == false)
				{
            		cout<<"\nNo hay registros con el codigo: "<<pelis[contador].codigoAux<<"\n"; //mensaje de salida
        		}
    		}else
			{
        		cout<<"\nAun no se pudo abrir el archivo..."; //mensaje de salida
    		}
			
			archivo1.close();
			cout<<"\nDesea buscar otra pelicula (s/n)?: ";
			fflush(stdin);
            cin>>respuesta; //lectura de la respuesta del usuario
			
			contador++;	
			}while(respuesta =='S' or respuesta =='s');
			
		break;
		}
		case 2:
		{
			ifstream Imprimir; //variable de lectura
			do
			{
				system("cls");
				contador = 0;
				archivo1.open("peliculas.txt", ios::out | ios::in); //aperturas del documento peliculas.txt
				encontrado = false; //variable logica
				
				
				cout<<"\nLista de peliculas:\n";
    			Imprimir.open("peliculas.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE apertura del documento 
	    		if(Imprimir.is_open()) //si el documento se abre
				{
	    			//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
    				Imprimir>>pelis[contador].codigo;
		    		while(!Imprimir.eof()) //recorrido del documento
					{
			        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
    			    	cout<<"\n";
		        		cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    		cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        				cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        				cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    			cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
	        			cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        		Imprimir>>pelis[contador].codigo; //llamado de la variable para su acumulacion
	    			}
	    		}else
				{	
			        cout<<"El archivo no se pudo abrir \n"; //mensaje de salida
		    	}
	    		Imprimir.close(); //cierre del documento
				
				
    			if(archivo1.is_open()) //si el documento se abre
				{
					cout<<"\nIngrese el nombre de la pelicula que desea buscar: ";
					fflush(stdin);
        			getline(cin,pelis[contador].nombreAux); //lectura de la pelicula a buscar
        			
        			archivo1>>pelis[contador].nombrePelicula;//llamado de la variable
        			while(!archivo1.eof())//recorrido de la variable
					{
	            		archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero; //aqui quite el pelis[contador].codigo porque dejaba el programa buggueado
        				//comparar cada registro para ver si es encontrado
						
        				if(pelis[contador].nombreAux == pelis[contador].nombrePelicula) //comparacion y busqueda en el registro 
						{
	                        cout<<"\n"<<endl;  
	        				cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    	    				cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        					cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
        					cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
        					cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
        					
            				encontrado = true; //variable logica
        				}
						
        				//lectura adelantada
        				archivo1>>pelis[contador].nombrePelicula;
        				
        			}
        			if (encontrado == false)
					{
	            		cout<<"\nNo hay registros con el nombre: "<<pelis[contador].nombreAux<<"\n"; //mensaje de salida
    	    		}
    			
				}else
				{
	        		cout<<"\nAun no se pudo abrir el archivo..."; //mensaje de salida
    			}
			
				archivo1.close(); //cierre del documento
				cout<<"\nDesea buscar otra pelicula (s/n)?: ";
				fflush(stdin);
            	cin>>respuesta; //lectura de la respuesta seleccionada por el usuario
				contador++;	
			}while(respuesta =='S' or respuesta =='s');	
		break;
		}
		case 3:
		{
			
			ifstream Imprimir; //variable de lectura declaracion
			do{
			
			system("cls");
			contador = 0;
			archivo1.open("peliculas.txt", ios::out | ios::in); //apertura del documento
			encontrado = false; //variable logica
			
			cout<<"\nLista de peliculas:\n";
    		Imprimir.open("peliculas.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE apertura
	    	if(Imprimir.is_open()) //si el documento se abre 
			{
	   			//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
   				Imprimir>>pelis[contador].codigo; //llamado de la variable
		    	while(!Imprimir.eof()) //recorrido del documento peliculas.txt
				{
		        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
   			    	cout<<"\n";
		        	cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    	cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        			cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        			cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    		cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
	        		cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        	Imprimir>>pelis[contador].codigo; //llamado de la variable para su acumulacion
    			}
	    	}else
			{	
		        cout<<"El archivo no se pudo abrir \n"; //mensaje de salida
	    	}
    		Imprimir.close(); //cierre del documento
			
			
    		if(archivo1.is_open()) //si el documento se abre
			{
				cout<<"\nIngrese el anio de la pelicula que desea buscar: ";
				fflush(stdin);
        		cin>>pelis[contador].anioAux; //lectura del año a buscar
        		
							        
        		archivo1>>pelis[contador].anio; //llamado de la variable
        		
        		while(!archivo1.eof()) //recorrido del documento peliculas.txt
				{
	            	archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero; //aqui quite el pelis[contador].codigo porque dejaba el programa buggueado
        			//comparar cada registro para ver si es encontrado				
        			if(pelis[contador].anioAux == pelis[contador].anio)
					{
                        cout<<"\n";
        				cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        				cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        				cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
        				cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
        				cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
        				
            			encontrado = true; //variable logica
        			}
					
        			//lectura adelantada
        			archivo1>>pelis[contador].anio; //llamado de la variable
        			
        		}
        		if (encontrado == false)
				{
            		cout<<"\nNo hay registros con el anio: "<<pelis[contador].anioAux<<"\n"; //mensaje de salida
        		}
    		}else
			{
        		cout<<"\nAun no se pudo abrir el archivo..."; //mensaje de salida
    		}
			
			archivo1.close(); //cierre del documento
			cout<<"\nDesea buscar otra pelicula (s/n)?: ";
			fflush(stdin);
            cin>>respuesta; //lectura de la respuesta del usuario
			
			contador++;	
			}while(respuesta =='S' or respuesta =='s');
			break;
			}
			case 4:
			{
				ifstream Imprimir; //declaracion de la variable de lectura
				do
				{
					system("cls");
					contador = 0;
					archivo1.open("peliculas.txt", ios::out | ios::in); //apertura del documento
					encontrado = false; //variable logica
					
					
					cout<<"\nLista de peliculas:\n";
    				Imprimir.open("peliculas.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE apertura del docuemento 
			    	if(Imprimir.is_open()) //si el docuemnto se abre
					{
	   					//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
   						Imprimir>>pelis[contador].codigo;
			    		while(!Imprimir.eof()) //recorrido del documento peliculas.txt
						{
				        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
   					    	cout<<"\n";
							cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    			cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        					cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        					cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    				cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
	        				cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        			Imprimir>>pelis[contador].codigo; //llamado de la variable y su acumulacion
    					}
			    	}else
					{	
			    	    cout<<"El archivo no se pudo abrir \n"; //mensaje de salida
	    			}
		    		Imprimir.close(); //cierre del documento
					
					
    				if(archivo1.is_open()) //si el documento se abre
					{
						cout<<"\nIngrese el autor que desea buscar: ";
						fflush(stdin);
        				cin>>pelis[contador].autorAux; //lectura del autor a buscar
        				
        				archivo1>>pelis[contador].nombreAutor; //llamado de la variable
        				while(!archivo1.eof())//mientras se recorra el documento
						{
	            			archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero; //aqui quite el pelis[contador].codigo porque dejaba el programa buggueado
        					//comparar cada registro para ver si es encontrado
        					if(pelis[contador].autorAux == pelis[contador].nombreAutor)
							{
                        		cout<<"\n";
	        					cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    	    					cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        						cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
        						cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
        						cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
        						
            					encontrado = true; //variable logica 
        					}
							
        					//lectura adelantada
        					archivo1>>pelis[contador].nombreAutor; //llamado de la variable
        					
        				}
        				if (encontrado == false)
						{
            				cout<<"\nNo hay registros con el autor: "<<pelis[contador].autorAux<<"\n"; //mensaje de salida
        				}
    					
					}else
					{
        				cout<<"\nAun no se pudo abrir el archivo..."; //mensaje de salida
    				}
					
					archivo1.close(); //cierre del documento
					cout<<"\nDesea buscar otra pelicula (s/n)?: ";
					fflush(stdin);
           			cin>>respuesta; //lectura de la respuesta del usuario
					contador++;	
				}while(respuesta =='S' or respuesta =='s');
			break;
			}
			case 5:
			{
				ifstream Imprimir; //declaracion de la variable de lectura
				do
				{
					system("cls");
					contador = 0;
					archivo1.open("peliculas.txt", ios::out | ios::in); //apertura del documento
					encontrado = false; //variable logica
					
					
					cout<<"\nLista de peliculas:\n";
    				Imprimir.open("peliculas.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE apertura del documento
			    	if(Imprimir.is_open()) //si el documento se abre
					{
	   					//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
   						Imprimir>>pelis[contador].codigo;
			    		while(!Imprimir.eof()) //mientras se pueda recorrer el documento
						{
				        	Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
   					    	cout<<"\n";
							cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    			cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        					cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
        					cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    				cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
	        				cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        			Imprimir>>pelis[contador].codigo; //llamado de la variable y de su almacenaje
    					}
			    	}else
					{	
			    	    cout<<"El archivo no se pudo abrir \n"; //mensaje de salida
	    			}
		    		Imprimir.close(); //cierre del documento
				
				
    				if(archivo1.is_open()) //si el documento se abre
					{
						cout<<"\nIngrese el genero que desea buscar: ";
						fflush(stdin);
        				cin>>pelis[contador].generoAux; //lectura del genero a buscar
		        		
									        
        				archivo1>>pelis[contador].genero; //llamado de la variable
	        			
    	    			while(!archivo1.eof()) //mientras se pueda leer el documento
						{
			            	archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero; //aqui quite el pelis[contador].codigo porque dejaba el programa buggueado
    		    			//comparar cada registro para ver si es encontrado				
	        				if(pelis[contador].generoAux == pelis[contador].genero)
							{
    		                    cout<<"\n"; 
        						cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        						cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
	        					cout<<"Anio de la pelicula: "<<pelis[contador].anio<<endl;
    	    					cout<<"Autor de la pelicula: "<<pelis[contador].nombreAutor<<endl;
        						cout<<"Genero de la pelicula: "<<pelis[contador].genero<<endl;
		        				
    		        			encontrado = true; //variable logica
	        				}
							
		        			//lectura adelantada
    		    			archivo1>>pelis[contador].genero;
        					
	        			}
    	    			if (encontrado == false)
						{
    	    	    		cout<<"\nNo hay registros con el genero: "<<pelis[contador].generoAux<<"\n"; //mensaje de salida
        				}
	    			}else
					{
    	    			cout<<"\nAun no se pudo abrir el archivo..."; //mensaje de salida
	    			}
					
					archivo1.close();
					cout<<"\nDesea buscar otra pelicula (s/n)?: ";
					fflush(stdin);
    	        	cin>>respuesta; //lectura de la respuesta del usuario
					
					contador++;	
				}while(respuesta =='S' or respuesta =='s');
			break;
			}
		}
	}while(n != 6);	
}


//funcion para el alquiler de las peliculas
void modificar(){
	//declaracion de variables
	ofstream fechaDatos, aux;
	ifstream Imprimir, archivo1, lectura;
	int contador = 0, x, resta;
	
	do
    {
		system("cls");
		fechaDatos.open("DatosAlquiler.txt", ios::out | ios::app); //apertura del documento DatosAlquiler.txt
	
		cout<<"Ingrese la fecha actual dd/mm/aa: ";
		fflush(stdin);
		gets(alqui[contador].fecha); //lectura de la fecha
		
		cout<<"Ingrese su documento: ";
		fflush(stdin);
		gets(alqui[contador].documento); //lectura del documento
		
		cout<<"Ingrese su nombre (En caso de haber espacio entre las palabras usar _): ";
		fflush(stdin);
		gets(alqui[contador].nombre); //lectura del nombre
		
		cout<<"Ingrese su telefono: ";
		fflush(stdin);
		gets(alqui[contador].telefono); //lectura del documento
    	
	    
    	//mensaje de salida con interaccion del usuario
    	cout<<"\nDatos agregados exitosamente\n";
    	cout<<"\nPresione enter para continuar\n";
    	getch();
    
    
		
    	system("cls");
    	cout<<"\nLista de peliculas para alquilar:\n";
    	Imprimir.open("peliculas.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE apertura del documento
    	if(Imprimir.is_open()) //si el documento se abre
		{
	    	//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
    		Imprimir>>pelis[contador].codigo;
	    	while(!Imprimir.eof()) //mientras se pueda leer
			{
		        Imprimir>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
    		    cout<<"\n";
		        cout<<"Codigo de la pelicula: "<<pelis[contador].codigo<<endl;
    		    cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
        		cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
		        Imprimir>>pelis[contador].codigo; //llamado de la variable y se alamacenaje
    		}
    	}else
		{	
	        cout<<"El archivo no se pudo abrir \n"; //mensaje de salida
	    }
    	Imprimir.close(); //cierre del documento
    
    
    
		archivo1.open("peliculas.txt", ios::out | ios::in); //apertura del documento peliculas.txt
    	cout<<"\nIngrese el codigo de la pelicula que desea alquilar: "; 
    	
		encontrado = false; //variable logica
		
    	if(archivo1.is_open()) //si se abre el documento
		{
	    	fflush(stdin);
    	    cin>>pelis[contador].codigoAux; //lectura del codigo a buscar
        	
	        archivo1>>pelis[contador].codigo;//llamado de la variable
    	    while(!archivo1.eof()) //mientras se pueda leer el documento
			{
        	    archivo1>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
	        	//comparar cada registro para ver si es encontrada
    	    	if(pelis[contador].codigoAux == pelis[contador].codigo){
	        	    cout<<"Nombre de la pelicula: "<<pelis[contador].nombrePelicula<<endl;
    	    		cout<<"Cantidad de la pelicula: "<<pelis[contador].cantidad<<endl;
	    	    	x = atoi(pelis[contador].cantidad); //conversion de char a entero
    	    		
	        	    encontrado = true;//variable logica
    	        	cout<<"\nCuantas desea alquilar?: ";
        	    	fflush(stdin);
	    			cin>>alqui[contador].cantidadAlquilar;//lectura de la cantidad de peliculas a alquilar
    				if(alqui[contador].cantidadAlquilar < x) //si la cantidad a alquilar es menor a la de la resta
    				{
    					//guardar datos
	    				fechaDatos<<alqui[contador].fecha<<" "<<alqui[contador].documento<<" "<<alqui[contador].nombre<<" "<<alqui[contador].telefono<<" "<<pelis[contador].nombrePelicula<<" "<<alqui[contador].cantidadAlquilar<<endl;
						fechaDatos.close(); //cierre del documento
					}else
					{
						//mensajes de salida con interaccion del usuario
						cout<<"\nNo hay suficientes peliculas disponibles";
						cout<<"\nPresione enter para continuar\n";
						getch();
					}
    	    	}
			
	        	//lectura adelantada
    	    	archivo1>>pelis[contador].codigo; //llamado de la variable
        	}
	        if (encontrado == false)
			{
    	        cout<<"\nNo hay registros con el codigo: "<<pelis[contador].codigoAux<<"\n"; //mensaje de salida
	        }
	    }else
		{
	        cout<<"\nAun no se pudo abrir el archivo..."; //mensaje de salida
	    }
		archivo1.close(); //cierre del documento
		
		
    	encontrado = false; //variable logica
    	if(alqui[contador].cantidadAlquilar < x) //mientras la cantidad sea menor a la resta
    	{
    		aux.open("auxiliar.txt", ios::out); //apertura del documento
    		lectura.open("peliculas.txt", ios::in); //lectura del documento
			
    		if (aux.is_open() && lectura.is_open()) //apertura de los dos documentos
			{
    		    lectura>>pelis[contador].codigo;//llamado de la variable
        		while (!lectura.eof()) //mientras se pueda hacer el recorrido del documento
				{
    	            lectura>>pelis[contador].nombrePelicula>>pelis[contador].cantidad>>pelis[contador].anio>>pelis[contador].nombreAutor>>pelis[contador].genero;
        	        if (pelis[contador].codigoAux == pelis[contador].codigo) //comparacion en los registros del documento
					{
	                    encontrado = true; //variable logica
						resta = x - alqui[contador].cantidadAlquilar; //operacion
						//guardado en aux
            	        aux<<pelis[contador].codigo<<" "<<pelis[contador].nombrePelicula<<" "<<resta<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreAutor<<" "<<pelis[contador].genero<<endl;
            	        //mensaje de salida y su interaccion del usuario
						cout<<"\nFinalizando pedido. . .\n";
						cout<<"\nTiene 20 dias para entregar la pelicula alquilada\n";
	                }else
					{
        	            aux<<pelis[contador].codigo<<" "<<pelis[contador].nombrePelicula<<" "<<pelis[contador].cantidad<<" "<<pelis[contador].anio<<" "<<pelis[contador].nombreAutor<<" "<<pelis[contador].genero<<endl;
            	    }
	                lectura>>pelis[contador].codigo;//llamado de la vasriable
    	        }
	    	}else
			{
		        cout<<"\nEl archivo no se pudo abrir\n"; //mensaje de salida
		    }
		
    		if (encontrado == false)
			{
    	    	cout<<"\nNo hay ninguna pelicula con el codigo: "<<pelis[contador].codigoAux<<"\n"; //mensaje de salida
	    	}
	
    		aux.close(); //cierre del documento
    		lectura.close(); //cieere del documento
	    	remove ("peliculas.txt"); //eliminacion del documento
    		rename("auxiliar.txt", "peliculas.txt"); //renombracion del docuemento
		}
	    
    	
	    
	    contador++;
    	cout<<"\nDesea alquilar otra pelicula (s/n)?: ";
		fflush(stdin);
        cin>>respuesta; //lectura de la respuesta del documento
			
	}while(respuesta =='S' or respuesta =='s');
}



//funcion principal
int main(){
	
    system ("color B"); //cambio de la interfaz
    int n; //declaracion de la variable
    system("cls"); //limpieza
	cout<<"Bienvenido, antes de comenzar ten encuenta las siguientes indicaciones:\n\n1. Siempre que vayas a llenar un campo ingresa la primera letra en mayuscula.\n\nPresione enter para continuar\n";
	getch();
    do{
    
	system("cls");//limpieza
	    //menu del usuario
  		cout<<"Ingrese el numero segun lo que desea hacer: \n\n";
		cout<<"1. Lista de peliculas\n2. Prestamo/alquiler de peliculas\n3. Buscar\n4. Opciones de administrador\n5. Salir\n\n";
    	
    	cout<<"Elige una opcion: ";
    	fflush(stdin);
    	cin>>n; //lectura de la opcion seleccionada del usuario
    	switch (n){
			case 1:
    			system("cls");
    			consultas(); //funcion de inventario de las peliculas
   			break;
			
			case 2:
    			system("cls");
    			modificar(); //funcion de alquiler de la pelicula
    			
    		break;
			
			case 3:
				system("cls");
    			buscar(); //funcion de la busqueda en diferenteas aspectos
    		break;
			
			case 4:
				system("cls");
    			insertarpeliculas(); //funcion de insertar peliculas
    		break;
			
			case 5:
				cout<<"Saliendo...\n";
			break;
			
			default:
    			cout<<"Opcion equivocada\n";
    		break;
			
    	}//fin switch
	}while (n != 5);

    system("cls"); //limpieza
}
