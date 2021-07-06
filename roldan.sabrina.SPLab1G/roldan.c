#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "roldan.h"


//String
int getString(char* mensaje, char* mensajeError, int minimo, int maximo, int* reintentos, char* resultado)
{
    int retorno=0;
    char bufferStr[maximo+10];

    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=minimo && strlen(bufferStr)<maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno=1;
                break;
            }
            printf("%s 1",mensajeError);
            (*reintentos)--;
        }while((*reintentos)>=0);
    }
    return retorno;
}

int utn_getString(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno=0;
    char bufferStr[maximo+10];

    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=minimo && strlen(bufferStr)<maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno=1;
                break;
            }
            printf("%sReintentos: %d\n",mensajeError,reintentos);
            reintentos--;
        }while(reintentos>=0);
    }
    return retorno;
}

//char
int utn_getChar(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno=0;
    char bufferChar[256];

    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,1,3,&reintentos,bufferChar)&&isValidChar(bufferChar[0])) //==0
            {
                *resultado=bufferChar[0];
                retorno=1;
                break;
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char charRecibido)
{
    int retorno=1;
    if(charRecibido<'A' || (charRecibido>'Z' && charRecibido<'a') || charRecibido>'z')
    {
        retorno=0;
    }

    return retorno;
}

//Nombre
int utn_getName(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno=0;
    char bufferStr[maximo];

    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minimo,maximo,&reintentos,bufferStr)) //==0
            {
                if(isValidName(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,maximo);
                    retorno=1;
                    break;
                }
                else
                {
                    printf("%sReintentos: %d\n",mensajeError,reintentos);
                    reintentos--;
                }
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidName(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'A' && stringRecibido[i]!=' ' && stringRecibido[i]!='-') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]<'a') ||
           stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//Float
int utn_getFloat(char* mensaje, char* mensajeError, int minSize, int maxSize, int minimo, int maximo, int reintentos, float* input)
{
    int retorno=0;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && minimo<maximo && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr)&&isValidFloatNumber(bufferStr)==1)
            {
                *input=atof(bufferStr);
                retorno=1;
                break;
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidFloatNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//Telefono
int utn_getTelefono(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=0;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && (input!=NULL))
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr)&&isValidTelephone(bufferStr)==1)
            {
                strncpy(input,bufferStr,maxSize);
                retorno=1;
                break;
            }
            else
            {
                printf("%sMaximo de 21 caracteres. Reintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidTelephone(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='-' || stringRecibido[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//DNI
int utn_getDNI(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input)
{
    maxSize=11; //con puntos
    minSize=8;  // sin puntos
    int retorno=0;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr)&&isValidDNI(bufferStr)==1)
            {
                strncpy(input,bufferStr,maxSize);
                retorno=1;
                break;
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidDNI(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//CUIT
int utn_getCUIT(char* mensaje, char* mensajeError, int reintentos, char* input)
{
    int maxSize=14;     //con guiones 13 elementos
    int minSize=11;     // sin puntos
    int retorno=0;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr)&&isValidCUIT(bufferStr)==1)
            {
                strncpy(input,bufferStr,maxSize);
                retorno=1;
                break;
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidCUIT(char* stringRecibido)
{
    int retorno=1;
    int i;
    int j;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-')) // chequeo que solo sean numeros o -
        {
            retorno=0;
            break;
        }

        if(buffer[i]=='-')  //eliminimoo los -
        {
            for(j=i;buffer[j]!='\0';j++)
            {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    int digitos[10]={2,3,4,5,6,7,2,3,4,5};
    int acumulado = 0;
    int verificador;

    for(i=0;i < strlen(buffer-1); i++)
    {
        acumulado+=buffer[i]*digitos[i];
    }

    verificador=11-(acumulado%11);
	if(verificador == 11)
	{
		verificador = 0;
	}

	if(buffer[11]!=verificador)
    {
        retorno=0;
    }

    return retorno;
}

//Email
int utn_getEmail(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=0;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr)&&isValidEmail(bufferStr)==1)
            {
                strncpy(input,bufferStr,maxSize);
                retorno=1;
                break;
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidEmail(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//Texto
int utn_getTexto(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=0;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr)&&isValidTexto(bufferStr)==1)
            {
                strncpy(input,bufferStr,maxSize);
                retorno=1;
                break;
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidTexto(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//Alfanumerico
int utn_getAlfanumerico(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=0;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr)&&isValidAlphanumeric(bufferStr)==1)
            {
                strncpy(input,bufferStr,maxSize);
                retorno=1;
                break;
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidAlphanumeric(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//unSignedInt
int utn_getUnsignedInt(char* mensaje,char* mensajeError,int minSize,int maxSize,int minimo,int maximo,int reintentos,int* input)
{
    int retorno=0;
    int aux;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && maximo>=minimo && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr) && isValidNumber(bufferStr)==1)
            {
                aux=atoi(bufferStr);
                if (aux>=minimo && aux<=maximo)
                {
                    *input=aux;
                    retorno=1;
                    break;
                }
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//SignedInt
int utn_getSignedInt(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, int* input)
{
    int retorno=0;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr) && isValidSignedNumber(bufferStr)==1)
            {
                *input=atoi(bufferStr);
                retorno=1;
                break;
            }
            else
            {
                printf("%sReintentos: %d\n",mensajeError,reintentos);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidSignedNumber(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[0]!='+' && stringRecibido[0]!='-'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int validacionSexo(char sexo)
{
    if((tolower(sexo)=='f' || tolower(sexo)=='m'))
    {
        return 1;
    }

    return 0;
}

int getSexo(char* mensaje,char* mensajeError,char* pSexo,int reintentos)
{
    char sexo;

    printf(mensaje);
    fflush(stdin);
    scanf("%c",&sexo);

    while(!validacionSexo(sexo))
    {
        printf("%sReintentos: %d\n",mensajeError,reintentos);
        printf(mensaje);
        fflush(stdin);
        scanf("%c",&sexo);

        reintentos--;
        if(reintentos==0)
        {
            printf("Maximo de reintentos alcanzado.\n");
            return 0;
        }

    }

    *pSexo=sexo;

    return 1;
}

//Fecha
int anioActivo(int anio, int minimo, int maximo)
{
    int retorno=0;

    if(anio>minimo && anio<maximo)
    {
        retorno=1;
    }

    return retorno;
}

int mesActivo_30(int mes)
{
    int retorno=0;

    if(mes==4 || mes==6 || mes==9 || mes==11)
    {
        retorno=1;
    }

    return retorno;
}

int mesActivo_31(int mes)
{
    int retorno=0;

    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
    {
        retorno=1;
    }

    return retorno;
}

int diaActivo_30(int dia)
{
    int retorno=0;

    if(dia>0 && dia<=30)
    {
        retorno=1;
    }

    return retorno;
}

int diaActivo_31(int dia)
{
    int retorno=0;

    if(dia>0 && dia<=31)
    {
        retorno=1;
    }

    return retorno;
}

int validacionFecha(int dia, int mes, int anio, int minimo, int maximo)
{
    int retorno=0;

    if(anioActivo(anio, minimo, maximo))
    {
        if(mesActivo_30(mes) && diaActivo_30(dia))
        {
            retorno=1;
        }
        else if((mesActivo_31(mes)) && (diaActivo_31(dia)))
        {
            retorno=1;
        }
        else if(mes==2 && dia>0 && dia<=29)
        {
            retorno=1;
        }
    }

    return retorno;

}

int getFecha(char* mensaje,char* mensajeError,int* pDia, int* pMes, int* pAnio,int minimoAnio,int maximoAnio,int reintentos)
{
    int dia;
    int mes;
    int anio;

    printf(mensaje);
    fflush(stdin);//En caso de ingresar un caracter
    scanf("%d/%d/%d",&dia,&mes,&anio);
    while(!validacionFecha(dia,mes,anio,minimoAnio,maximoAnio))
    {
        printf("%s Formato (dd/mm/aaaa). Reintentos: %d\n",mensajeError,reintentos);
        printf(mensaje);
        fflush(stdin);//En caso de ingresar un caracter
        scanf("%d/%d/%d",&dia,&mes,&anio);

        reintentos--;
        if(reintentos==0)
        {
            printf("Maximo de reintentos alcanzado.\n");
            return 0;
        }
    }

    *pDia=dia;
    *pMes=mes;
    *pAnio=anio;

    return 1;
}

//Edad
int validacionEdad(int edad,int maximo)
{
    if(edad>0 && edad<maximo)
    {
        return 1;
    }

    return 0;
}

int getEdad(char* mensaje,char* mensajeError,int* pEdad,int maximo,int reintentos)
{
    int edad;

    printf(mensaje);
    fflush(stdin); // En caso de que se ingrese un caracter.
    scanf("%d",&edad);

    while(!validacionEdad(edad,maximo))
        {
            printf("%sReintentos: %d\n",mensajeError,reintentos);
            printf(mensaje);
            fflush(stdin); // En caso de que se ingrese un caracter.
            scanf("%d",&edad);

            reintentos--;
            if(reintentos==0)
            {
                printf("Maximo de reintentos alcanzado.\n");
                return 0;
            }
        }

    *pEdad=edad;

    return 1;
}
