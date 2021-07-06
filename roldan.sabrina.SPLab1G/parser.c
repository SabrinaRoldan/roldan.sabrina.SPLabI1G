#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Pais.h"

/** \brief Parsea los datos los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int parser_PaisFromText(FILE* pFile, LinkedList* pArrayListPais,int* proximoId)
{
    int retorno=0;
    int cant;
    int nuevoId;
    char buffer[4][128];

    Pais* pais=pais_new();
    if(pFile==NULL)
        {
            printf("No se pudo cargar el archivo\n");
        }

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

        do
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            if(cant<5)
            {
                printf("Error al cargar el archivo.\n");
                break;
            }

            pais=pais_newParametros((itoa((atoi(buffer[0])+(*proximoId)),buffer[0],10)),buffer[1],buffer[2],buffer[3],buffer[4]);

            if(pais==NULL)
            {
                printf("Error al cargar el pais.\n");
            }
            else
            {
                ll_add(pArrayListPais,pais);
                retorno=1;
            }


        }while(!feof(pFile));

        nuevoId=atoi(buffer[0])+(*proximoId);
        *proximoId=nuevoId;
        (*proximoId)++;
        return retorno;
}

/** \brief Parsea los datos los datos de los paises desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int parser_PaisFromBinary(FILE* pFile , LinkedList* pArrayListPais,int* proximoId)
{
    int cant;
    int retorno=0;
    int nuevoId;

    if(pFile==NULL)
    {
        printf("No se pudo abrir  el archivo\n");
    }

    while(!feof(pFile))
    {
        Pais* pais=pais_new();
        if(pais!=NULL)
        {
            //pais->id=pais->id+(*proximoId);
            cant=fread(pais,sizeof(Pais),1,pFile);

            if(cant<1)
            {
                break;
            }
            ll_add(pArrayListPais,pais);
            pais->id=pais->id+(*proximoId);
            nuevoId=pais->id;
            pais=NULL;
            retorno=1;
        }
    }

    *proximoId=nuevoId;
    (*proximoId)++;


    return retorno;
}
