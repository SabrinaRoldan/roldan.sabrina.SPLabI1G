#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pais.h"
#include "parser.h"
#include "roldan.h"
#include <time.h>


/** \brief Carga los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListPais,int* proximoId)
{
    int retorno=0;
    char path[128];

    if(utn_getEmail("Ingrese el nombre del archivo a cargar: ","Error.\n",3,128,4,path))
    {
        if(path!=NULL && pArrayListPais!=NULL)
        {
            FILE* f=fopen(path,"r");
            if(parser_PaisFromText(f,pArrayListPais,proximoId))
            {
                retorno=1;
                fclose(f);
            }
        }
    }

    return retorno;
}

/** \brief Carga los datos de los paises desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(LinkedList* pArrayListPais,int* proximoId)
{
    int retorno=0;
    char path[128];

    if(utn_getEmail("Ingrese el nombre del archivo a cargar: ","Error.\n",3,128,4,path))
    {
        if(path!=NULL && pArrayListPais!=NULL)
        {
            FILE* f=fopen(path,"rb");
            if(parser_PaisFromBinary(f,pArrayListPais,proximoId))
            {
                retorno=1;
                fclose(f);
            }
        }
    }

    return retorno;
}

/** \brief Alta de paises
 *
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_addPais(LinkedList* pArrayListPais, int* pId)
{
    int retorno=0;
    char nombre[128];
    int vac1dosis;
	int vac2dosis;
    int sinVacunar;
    int id;

    Pais* auxPais=pais_new();

    if(pArrayListPais!=NULL && ll_len(pArrayListPais)>=0)
    {
        system("cls");
        printf("        Alta Pais\n\n");

        if(*pId==0)
        {
            *pId=1;
        }

        id=*pId;
        auxPais->id=id;
        printf("ID: %4d\n\n",auxPais->id);

        if(!utn_getName("Ingrese el nombre del pais: ","Error. ",2,129,4,nombre)&&
           !pais_getNombre(auxPais,nombre))
        {
            printf("Error al cargar el nombre.\n");
            return -1;
        }
        strcpy(auxPais->nombre,nombre);

        if(!utn_getUnsignedInt("Ingrese cantidad de vac1dosis: ","Error.",1,4,0,1000,4,&vac1dosis)&&
           !pais_getVac1dosis(auxPais,&vac1dosis))
        {
            printf("Error al cargar los vac1dosis.\n");
            return -1;
        }
        auxPais->vac1dosis=vac1dosis;

        if(!utn_getUnsignedInt("Ingrese cantidad de vac2dosis: ","Error.",1,7,0,1000000,4,&vac2dosis)&&
           !pais_getVac2dosis(auxPais,&vac2dosis))
        {
            printf("Error al cargar los vac2dosis.\n");
            return -1;
        }
        auxPais->vac2dosis=vac2dosis;

        if(!utn_getUnsignedInt("Ingrese cantidad de sinVacunar: ","Error.",1,7,0,1000000,4,&sinVacunar)&&
           !pais_getSinVacunar(auxPais,&sinVacunar))
        {
            printf("Error al cargar los sinVacunar.\n");
            return -1;
        }
        auxPais->sinVacunar=sinVacunar;

        printf("\n\n");

        (*pId)++;

        retorno=1;

        ll_add(pArrayListPais,auxPais);

    }

    return retorno;
}

/** \brief Modificar datos de pais
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_editPais(LinkedList* pArrayListPais)
{
    int retorno=0;
    //int indice;
    int opcion;
    int id;
    char confirma;
    char nombre[128];
    int vac1dosis;
	int vac2dosis;
    int sinVacunar;

    system("cls");
    printf("        Modificar Pais\n\n");
    printf("Ingrese id: ");
    scanf("%d",&id);

    if(!(ll_get(pArrayListPais,id-1)))
    {
        printf("\nNo existe un pais con el id: %d\n", id);
    }
    else
    {
        id=id-1;
        printf("\n  ID                Nombre   Vac1dosis   Vac2dosis    SinVacunar\n");
        mostrarPais(ll_get(pArrayListPais,id));
        printf("Confirma modificacion?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {

            printf("        Opciones a modificar:\n\n");
            printf("1- Nombre\n");
            printf("2- Vac1dosis\n");
            printf("3- Vac2dosis\n\n");
			printf("4- SinVacunar\n\n");
            printf("Ingrese opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    if(!utn_getName("Ingrese el nombre del pais: ","Error. ",2,129,4,nombre))
                    {
                        printf("Error al cargar el nombre.\n");
                        return -1;
                    }
                    pais_setNombre(ll_get(pArrayListPais,id),nombre);
                    break;

                case 2:
                    if(!utn_getUnsignedInt("Ingrese vac1dosis: ","Error.",1,4,0,1000,4,&vac1dosis))
                    {
                        printf("Error al cargar las horas trabajadas.\n");
                        return -1;
                    }
                    pais_setVac1dosis(ll_get(pArrayListPais,id),vac1dosis);
                    break;

                case 3:
                    if(!utn_getUnsignedInt("Ingrese vac2dosis: ","Error.",1,7,0,1000000,4,&vac2dosis))
                    {
                        printf("Error al cargar la cantidad de vac2dosis.\n");
                        return -1;
                    }
                    pais_setVac2dosis(ll_get(pArrayListPais,id),vac2dosis);
                    break;

                case 4:
                    if(!utn_getUnsignedInt("Ingrese sinVacunar: ","Error.",1,7,0,1000000,4,&sinVacunar))
                    {
                        printf("Error al cargar la cantidad de sinVacunar.\n");
                        return -1;
                    }
                    pais_setSinVacunar(ll_get(pArrayListPais,id),sinVacunar);
                    break;

                default:
                    printf("Opcion no valida\n");
                    break;
            }


            retorno=1;
        }
        else
        {
            printf("Modificacion cancelada por el usuario\n");
        }
    }

    return retorno;
}

/** \brief Baja de pais
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_removePais(LinkedList* pArrayListPais)
{
    int retorno=0;
    int idUsuario;
    char confirma;

    system("cls");
    printf("        Baja Pais\n\n");

    printf("Ingrese id: ");
    scanf("%d",&idUsuario);

    if(!(ll_get(pArrayListPais,idUsuario-1)))
    {
        printf("\nNo existe un pais con el id: %d\n", idUsuario);
    }
    else
    {
        idUsuario=idUsuario-1;

        printf("\n  ID                Nombre   Vac1dosis  Vac2dosis  SinVacunar\n");
        mostrarPais(ll_get(pArrayListPais,idUsuario));
        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            ll_remove(pArrayListPais,idUsuario);
            retorno=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }

    return retorno;
}

/** \brief Listar paises
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_ListPais(LinkedList* pArrayListPais)
{
    char buffer[5][128];
    FILE* f=fopen("vacunas.csv","r");

    if(f==NULL)
    {
        printf("No se pudo cargar el archivo\n");
    }

    //agrega el encabezado de cada columna para leerlo por consola
    fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
    printf("%4s  %20s        %10s %10s %10s\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

    for(int i=0;i<ll_len(pArrayListPais);i++)
    {
        mostrarPais(ll_get(pArrayListPais,i));
    }

    fclose(f);
    return 1;
}

/** \brief Ordenar paises
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_sortPais(LinkedList* pArrayListPais)
{
    int order;

    system("cls");
    if(!utn_getUnsignedInt("\t***   Vac1dosis   ***\n\n***Orden de la lista a mostrar***"
    "\n\n1- Descendente\n2- Ascendente\n\nIngrese la opcion deseada: ","Error. "
    ,1,2,-1,2,4,&order))
    {
        printf("Error al cargar su los datos\n");
    }
    else
    {
        if(order==2)
        {
            order=0;
        }
        printf("\nEsperando status...\n\n");
        ll_sort(pArrayListPais,pais_compareVac1dosis,order);
        printf("Ordenamiento exitoso!\n\n");
    }

    return 0;
}

/** \brief Guarda los datos de los paises en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_saveAsText(LinkedList* pArrayListPais)
{
    int retorno=0;
    int id;
    int cant;
    int vac1dosis;
	int vac2dosis;
    int sinVacunar;
    char nombre[128];
    char path[128];

    if(utn_getEmail("Ingrese el nombre del archivo a guardar: ","Error.\n",3,128,4,path))
    {
        FILE* f=fopen(path,"w");
        if(f==NULL)
        {
            printf("No se pudo guardar el archivo\n");
        }

        fprintf(f,"ID,Nombre,Vac1dosis,Vac2dosis,SinVacunar\n");

        for(int i=0;i<ll_len(pArrayListPais);i++)
        {
            if(pArrayListPais!=NULL)
            {
                pais_getId(ll_get(pArrayListPais,i),&id);
                pais_getNombre(ll_get(pArrayListPais,i),nombre);
                pais_getVac1dosis(ll_get(pArrayListPais,i),&vac1dosis);
                pais_getVac2dosis(ll_get(pArrayListPais,i),&vac2dosis);
                pais_getSinVacunar(ll_get(pArrayListPais,i),&sinVacunar);

                cant=fprintf(f,"%d,%s,%d,%d,%d\n",
                         id
                        ,nombre
                        ,vac1dosis
                        ,vac2dosis
                        ,sinVacunar);
                if(cant<5)
                {
                    break;
                }
                retorno=1;
            }
        }
        fclose(f);
    }

    return retorno;
}

/** \brief Guarda los datos de los paises en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(LinkedList* pArrayListPais)
{
    int cant;
    int retorno=0;
    char path[128];

    if(utn_getEmail("Ingrese el nombre del archivo a cargar: ","Error.\n",3,128,4,path))
    {
        FILE* f=fopen(path,"wb");

        if(f==NULL)
        {
            printf("No se pudo guardar el archivo\n");
            exit(1);
        }

        for(int i=0;i<ll_len(pArrayListPais);i++)
        {
            if(pArrayListPais!=NULL)
            {
                cant=fwrite(ll_get(pArrayListPais,i),sizeof(Pais),1,f);
                if(cant<1)
                {
                    printf("Error\n");
                    break;
                }
                retorno=1;
            }
        }

        fclose(f);
    }

    return retorno;
}

int pais_aleatoryPaises(LinkedList* this)
{
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
    int retorno=0;

    srand(time(NULL));

    vac1dosis=rand() % (60 - 1 +1)+1;
    vac2dosis=rand() % (40 - 1 +1)+1;
    sinVacunar=100-(vac1dosis+vac2dosis);


    if(this!=NULL)
    {
        pais_setVac1dosis(this,vac1dosis);
        pais_setVac2dosis(this,vac2dosis);
        pais_setSinVacunar(this,sinVacunar);
        retorno=1;
    }


    return retorno;
}
