#ifndef ROLDAN_H_INCLUDED
#define ROLDAN_H_INCLUDED



#endif // ROLDAN_H_INCLUDED

//String
/** \brief                      Toma una cadena de caracteres, al analizarlo y éste cumplir las condiciones
 *                              necesarias lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minimo int            Mínima cantidad de caracteres aceptado.
 * \param maximo int            Máxima cantidad de caracteres aceptado.
 * \param reintentos int*       Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param resultado char*       Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int getString(char* mensaje, char* mensajeError, int minimo, int maximo, int* reintentos, char* resultado);

/** \brief                      Toma una cadena de caracteres ingresado por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minimo int            Mínima cantidad de caracteres aceptado.
 * \param maximo int            Máxima cantidad de caracteres aceptado.
 * \param reintentos int*       Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param resultado char*       Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getString (char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* resultado);

//Char
/** \brief                      Toma un caracter ingresado por el usuario, al analizarlo y éste cumplir las condiciones
 *                              necesarias de un caracter lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minimo int            Mínima cantidad de caracteres aceptado.
 * \param maximo int            Máxima cantidad de caracteres aceptado.
 * \param reintentos int*       Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param resultado char*       Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getChar(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* resultado);

/** \brief                      Valida si el dato ingresado cumple con las condiciones de un caracter.
 *
 * \param charRecibido char     Caracter recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidChar(char charRecibido);

//Nombre
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de un nombre lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minimo int            Mínima cantidad de caracteres aceptado.
 * \param maximo int            Máxima cantidad de caracteres aceptado.
 * \param reintentos int*       Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param resultado char*       Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getName(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* resultado);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un nombre.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidName(char* stringRecibido);

//Float
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de un float lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param minimo int            Número mínimo aceptado.
 * \param maximo int            Número máximo aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input float*          Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getFloat(char* mensaje, char* mensajeError, int minSize, int maxSize, int minimo, int maximo, int reintentos, float* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un float.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidFloatNumber(char* stringRecibido);

//Telefono
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de un teléfono lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input char*           Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getTelefono(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un teléfono.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidTelephone(char* stringRecibido);

//DNI
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de un DNI lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input char*           Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getDNI(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un DNI.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidDNI(char* stringRecibido);

//CUIT
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de un CUIT lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input char*           Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getCUIT(char* mensaje, char* mensajeError, int reintentos, char* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un CUIT.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidCUIT(char* stringRecibido);

//Email
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de un Email lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input char*           Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getEmail(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un Email.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidEmail(char* stringRecibido);

//Texto
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de un texto lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input char*           Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getTexto(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un texto.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidTexto(char* stringRecibido);

//Alfanumerico
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de letras y números lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input char*           Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getAlfanumerico(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de letras y números.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidAlphanumeric(char* stringRecibido);

//unSignedInt
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de número sin signo lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param minimo int            Número mínimo aceptado.
 * \param maximo int            Número máximo aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input int*            Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getUnsignedInt(char* mensaje,char* mensajeError,int minSize,int maxSize,int minimo,int maximo,int reintentos,int* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un número sin signo.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidNumber(char* stringRecibido);

//SignedInt
/** \brief                      Toma una cadena de caracteres ingresada por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de número con signo lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param minSize int           Mínima cantidad de caracteres aceptado.
 * \param maxSize int           Máxima cantidad de caracteres aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \param input int*            Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int utn_getSignedInt(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, int* input);

/** \brief                      Valida si la cadena de caracteres cumple con las condiciones de un número con signo.
 *
 * \param stringRecibido char*  Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int isValidSignedNumber(char* stringRecibido);

//Sexo
/** \brief                      Valida si el char cumple con las condiciones de sexo femenino o masculino.
 *
 * \param sexo char             Cadena de caracteres recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int validacionSexo(char sexo);

/** \brief                      Toma un caracter ingresado por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de sexo femenino o masculino lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param pSexo char*           Puntero al espacio memoria donde se dejará el resultado de la función.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int getSexo(char* mensaje,char* mensajeError,char* pSexo,int reintentos);

//Fecha
/** \brief                      Valida si el entero cumple con las condiciones de año.
 *
 * \param anio int              Entero recibido a analizar.
 * \param minimo int            Año mínimo aceptado.
 * \param maximo int            Año máximo aceptado.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int anioActivo(int anio, int minimo, int maximo);

/** \brief                      Valida si el entero cumple con las condiciones de mes de 30 días.
 *
 * \param mes int               Entero recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int mesActivo_30(int mes);

/** \brief                      Valida si el entero cumple con las condiciones de mes de 31 días.
 *
 * \param mes int               Entero recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int mesActivo_31(int mes);

/** \brief                      Valida si el entero cumple con las condiciones de día hast 30.
 *
 * \param dia int               Entero recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int diaActivo_30(int dia);

/** \brief                      Valida si el entero cumple con las condiciones de día hast 31.
 *
 * \param dia int               Entero recibido a analizar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int diaActivo_31(int dia);

/** \brief                      Valida si la fecha ingresada cumple con las condiciones necesarias de día, mes y año.
 *
 * \param dia int               Entero recibido a analizar.
 * \param mes int               Entero recibido a analizar.
 * \param anio int              Entero recibido a analizar.
 * \param minimo int            Año mínimo aceptado.
 * \param maximo int            Año máximo aceptado.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int validacionFecha(int dia, int mes, int anio, int minimo, int maximo);

/** \brief                      Toma tres enteros ingresados por el usuario, al analizarlos y estos
 *                              cumplir las condiciones necesarias de día, mes y año lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param pDia int*             Puntero al espacio memoria donde se dejará el resultado de la función.
 * \param pMes int*             Puntero al espacio memoria donde se dejará el resultado de la función.
 * \param pAnio int*            Puntero al espacio memoria donde se dejará el resultado de la función.
 * \param minimoAnio int        Número mínimo aceptado.
 * \param maximoAnio int        Número máximo aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int getFecha(char* mensaje,char* mensajeError,int* pDia, int* pMes, int* pAnio,int minimoAnio,int maximoAnio,int reintentos);

//Edad
/** \brief                      Valida si el entero cumple con las condiciones de edad.
 *
 * \param edad int              Entero recibido a analizar.
 * \param maximo int            Número máximo aceptado.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int validacionEdad(int edad,int maximo);

/** \brief                      Toma un entero ingresado por el usuario, al analizarlo y éste
 *                              cumplir las condiciones necesarias de edad lo retorna al espacio de memoria del puntero.
 *
 * \param mensaje char*         Muestra mensaje ingresado.
 * \param mensajeError char*    Muestra mensaje de error ingresado.
 * \param pEdad int*            Puntero al espacio memoria donde se dejará el resultado de la función.
 * \param maximo int            Número máximo aceptado.
 * \param reintentos int        Cantidad de reintentos al ingresar erroneamente el dato solicitado.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int getEdad(char* mensaje,char* mensajeError,int* pEdad,int maximo,int reintentos);
