#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pais.h"
#include <time.h>



int main()
{
    int option=0;
    int proximoId=0;
    int flagDatosTexto=0;
    int flagDatosBinario=0;
    int flagIdTexto=0;
    int flagIdBinario=0;

    LinkedList* listaPaises = ll_newLinkedList();

    do{
        switch(menu(&option))
        {
            case 1:
                if(flagIdTexto)
                {
                    proximoId=proximoId-1;
                }

                if(!flagDatosTexto)
                {
                    if(controller_loadFromText(listaPaises,&proximoId))
                    {
                    printf("Se ha cargado el archivo de texto con exito!!\n");
                    flagDatosTexto=1;
                    }
                    else
                    {
                        printf("Error al cargar el archivo de texto\n");
                    }
                }
                else
                {
                    printf("Los datos ya han sido cargados previamente desde este archivo \n");
                }
                break;

            case 2:
                if(ll_len(listaPaises)==0)
                {
                    printf("No hay paises cargados al sistema\n");
                }
                else
                {
                    controller_ListPais(listaPaises);
                }
                break;

            case 3:
                ll_map(listaPaises,pais_aleatoryPaises);
                break;

            case 4:
                if(ll_filter(listaPaises,pais_filterExitosos))
                {
                    if(!controller_saveAsText(listaPaises))
                    {
                        printf("Error al guardar el archivo de texto\n");
                    }
                    else
                    {
                        printf("El archivo de texto se ha guardado con exito!\n\n");
                    }
                }
                else
                {
                    printf("Error al filtrar los campos\n");
                }
                break;

            case 5:
                if(ll_filter(listaPaises,pais_filterAlHorno))
                {
                    if(!controller_saveAsText(listaPaises))
                    {
                        printf("Error al guardar el archivo de texto\n");
                    }
                    else
                    {
                        printf("El archivo de texto se ha guardado con exito!\n\n");
                    }
                }
                else
                {
                    printf("Error al filtrar los campos\n");
                }
                break;

            case 6:
                controller_sortPais(listaPaises);
                break;

            case 7:

                if(!ll_sort(listaPaises,pais_compareSinVacunar,0))
                {
                    system("cls");
                    printf("***Paises más castigados en orden***\n");
                    controller_ListPais(listaPaises);
                }
                else
                {
                    printf("Error al mostrar los paises mas castigados\n");
                }
                break;

            case 8:
                printf("Ha salido del programa.\nHasta la proxima!!!\n\n");
                break;

            default:
                printf("Opcion no valida\n");
                fflush(stdin);
                break;
        }
        system("pause");

    }while(option != 8);

    return 0;
}

