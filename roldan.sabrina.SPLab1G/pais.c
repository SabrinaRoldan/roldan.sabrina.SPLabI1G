#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pais.h"

int menu(int* opcion)
{
    system("cls");
    printf("        ***  Menu de opciones  ***\n\n");
    printf("  1- Cargar los datos de un archivo de texto\n");
    printf("  2- Imprimir lista\n");
    printf("  3- Asignar estadisticas\n");
    printf("  4- Paises exitosos\n");
    printf("  5- Paises no exitosos\n");
    printf("  6- Orden por nivel de infeccion\n");
    printf("  7- Paises mas castigados\n");
    printf("  8- Guardar los datos en un archivo de texto\n");
    printf("  9- Guardar los datos en un archivo binario\n");
    printf(" 10- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",opcion);

    return *opcion;

}

Pais* pais_new()
{
    Pais* nuevoPais=(Pais*) malloc(sizeof(Pais));

    if(nuevoPais!=NULL)
    {
        nuevoPais->id=0;
        strcpy(nuevoPais->nombre,"");
        nuevoPais->vac1dosis=0;
        nuevoPais->vac2dosis=0;
        nuevoPais->sinVacunar=0;
    }

    return nuevoPais;

}

Pais* pais_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr,char* vac2dosisStr,char* sinVacunarStr)
{
    Pais* nuevoPais=pais_new();

    if(nuevoPais!=NULL)
    {
        if(!(pais_setId(nuevoPais,atoi(idStr)) &&
           pais_setNombre(nuevoPais,nombreStr) &&
           pais_setVac1dosis(nuevoPais,atoi(vac1dosisStr)) &&
           pais_setVac2dosis(nuevoPais,atoi(vac2dosisStr)) &&
           pais_setSinVacunar(nuevoPais,atoi(sinVacunarStr))
           ))
        {
            free(nuevoPais);
            nuevoPais=NULL;
        }
    }

    return nuevoPais;
}

void pais_delete(Pais* pais)
{
    if(pais!=NULL)
    {
        free(pais);
    }
}

int pais_setId(Pais* this,int id)
{
    int retorno=0;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }

    return retorno;
}

int pais_getId(Pais* this,int* id)
{
    int retorno=0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }

    return retorno;
}

int pais_setNombre(Pais* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL && strlen(nombre)>=2 && strlen(nombre)<=128)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }

    return retorno;
}

int pais_getNombre(Pais* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }

    return retorno;
}

int pais_setVac1dosis(Pais* this,int vac1dosis)
{
    int retorno=0;

    if(this!=NULL && vac1dosis>=0)
    {
        this->vac1dosis=vac1dosis;
        retorno=1;
    }

    return retorno;
}

int pais_getVac1dosis(Pais* this,int* vac1dosis)
{
    int retorno=0;

    if(this!=NULL && vac1dosis!=NULL)
    {
        *vac1dosis=this->vac1dosis;
        retorno=1;
    }

    return retorno;
}

int pais_setVac2dosis(Pais* this,int vac2dosis)
{
    int retorno=0;

    if(this!=NULL && vac2dosis>=0)
    {
        this->vac2dosis=vac2dosis;
        retorno=1;
    }

    return retorno;
}

int pais_getVac2dosis(Pais* this,int* vac2dosis)
{
    int retorno=0;

    if(this!=NULL && vac2dosis!=NULL)
    {
        *vac2dosis=this->vac2dosis;
        retorno=1;
    }

    return retorno;
}

int pais_setSinVacunar(Pais* this,int sinVacunar)
{
    int retorno=0;

    if(this!=NULL && sinVacunar>=0)
    {
        this->sinVacunar=sinVacunar;
        retorno=1;
    }

    return retorno;
}

int pais_getSinVacunar(Pais* this,int* sinVacunar)
{
    int retorno=0;

    if(this!=NULL && sinVacunar!=NULL)
    {
        *sinVacunar=this->sinVacunar;
        retorno=1;
    }

    return retorno;
}

int mostrarPais(Pais* this)
{
    int retorno=0;

    if(this!=NULL)
    {
      printf("%4d  %20s             %4d      %6d    %6d\n"
           ,this->id
           ,this->nombre
           ,this->vac1dosis
           ,this->vac2dosis
           ,this->sinVacunar);
        retorno=1;
    }

    return retorno;
}

int pais_compareId(void* pais1, void* pais2)
{
    int retorno=0;

    Pais* p1=NULL;
    Pais* p2=NULL;

    if(pais1!=NULL && pais2!=NULL)
    {
        p1=(Pais*) pais1;
        p2=(Pais*) pais2;

        if((p1->id)>(p2->id))
        {
            retorno=-1;
        }
        else if((p1->id)<(p2->id))
        {
            retorno=1;
        }
    }
    return retorno;
}

int pais_compareNombre(void* pais1, void* pais2)
{
    int retorno=0;

    Pais* p1=NULL;
    Pais* p2=NULL;

    if(pais1!=NULL && pais2!=NULL)
    {
        p1=(Pais*) pais1;
        p2=(Pais*) pais2;

        if(strcmp(p1->nombre,p2->nombre)>0)
        {
            retorno=-1;
        }
        else if(strcmp(p1->nombre,p2->nombre)<0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int pais_compareVac1dosis(void* pais1, void* pais2)
{
    int retorno=0;

    Pais* p1=NULL;
    Pais* p2=NULL;

    if(pais1!=NULL && pais2!=NULL)
    {
        p1=(Pais*) pais1;
        p2=(Pais*) pais2;

        if((p1->vac1dosis)>(p2->vac1dosis))
        {
            retorno=-1;
        }
        else if((p1->vac1dosis)<(p2->vac1dosis))
        {
            retorno=1;
        }
    }
    return retorno;
}

int pais_compareVac2dosis(void* pais1, void* pais2)
{
    int retorno=0;

    Pais* p1=NULL;
    Pais* p2=NULL;

    if(pais1!=NULL && pais2!=NULL)
    {
        p1=(Pais*) pais1;
        p2=(Pais*) pais2;

        if((p1->vac2dosis)>(p2->vac2dosis))
        {
            retorno=-1;
        }
        else if((p1->vac2dosis)<(p2->vac2dosis))
        {
            retorno=1;
        }
    }
    return retorno;
}

int pais_compareSinVacunar(void* pais1, void* pais2)
{
    int retorno=0;

    Pais* p1=NULL;
    Pais* p2=NULL;

    if(pais1!=NULL && pais2!=NULL)
    {
        p1=(Pais*) pais1;
        p2=(Pais*) pais2;

        if((p1->sinVacunar)>(p2->sinVacunar))
        {
            retorno=-1;
        }
        else if((p1->sinVacunar)<(p2->sinVacunar))
        {
            retorno=1;
        }
    }
    return retorno;
}

int pais_filterExitosos(void* pais1)
{
    int retorno=0;
    Pais* pais=NULL;
    if(pais1!=NULL)
    {
        pais=(Pais*) pais1;
        if(pais->vac2dosis>30)
        retorno=1;
    }
    return retorno;
}

int pais_filterAlHorno(void* pais1)
{
    int retorno=0;
    Pais* pais=NULL;
    if(pais1!=NULL)
    {
        pais=(Pais*) pais1;
        if((pais->sinVacunar)>(pais->vac1dosis))
        retorno=1;
    }
    return retorno;
}
