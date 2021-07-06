#include "LinkedList.h"

#ifndef pais_H_INCLUDED
#define pais_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}Pais;

int menu(int* opcion);

/** \brief                          Crea un nuevo pais.
 *
 * \return Pais*                Retorna un pais.
 *
 */
Pais* pais_new();

/** \brief                          Crea nuevos parametros para el pais casteados a string.
 *
 * \param idStr char*               Id de pais.
 * \param nombreStr char*           Nombre del pais.
 * \param horasTrabajadasStr char*  vac1dosis del pais.
 * \param vac1dosisStr char*           Vac1dosis del pais.
 * \return Pais*                Retorna un pais.
 *
 */
Pais* pais_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr,char* vac2dosisStr,char* sinVacunarStr);

/** \brief                          Elimina un pais.
 *
 * \param pais Pais*        Estructura Empleado.
 * \return void                     No retorna valores.
 *
 */
void pais_delete(Pais* pais);

/** \brief                          Setter de Id de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param id int                    Id de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int pais_setId(Pais* this,int id);

/** \brief                          Getter de Id de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param id int                    Id de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int pais_getId(Pais* this,int* id);

/** \brief                          Setter de nombre de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param nombre char*              Nombre de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int pais_setNombre(Pais* this,char* nombre);

/** \brief                          Getter de nombre de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param nombre char*              Nombre de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int pais_getNombre(Pais* this,char* nombre);

/** \brief                          Setter de las horas trabajadas de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param horasTrabajadas int       vac1dosis de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int pais_setVac1dosis(Pais* this,int vac1dosis);

/** \brief                          Getter de las horas trabajadas de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param horasTrabajadas int       vac1dosis de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 */
int pais_getVac1dosis(Pais* this,int* vac1dosis);

/** \brief                          Setter de vac1dosis de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param vac1dosis int                Vac1dosis de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int pais_setVac2dosis(Pais* this,int vac2dosis);

/** \brief                          Getter de vac1dosis de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param vac1dosis int                Vac1dosis de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int pais_getVac2dosis(Pais* this,int* vac2dosis);

/** \brief                          Setter de vac1dosis de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param vac1dosis int                Vac1dosis de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int pais_setSinVacunar(Pais* this,int sinVacunar);

/** \brief                          Getter de vac1dosis de pais.
 *
 * \param this Pais*            Estructura pais.
 * \param vac1dosis int                Vac1dosis de pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int pais_getSinVacunar(Pais* this,int* sinVacunar);

/** \brief                          Muestra el pais con sus valores.
 *
 * \param this Pais*            Estructura pais.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int mostrarPais(Pais* this);

/** \brief                          Compara Ids de paiss.
 *
 * \param pais1 void*           Primer pais a comparar.
 * \param pais2 void*           Segundo pais a comparar.
 * \return int                      Retorna -1 si el 1er pais es mayor al segundo.
 *
 */
int pais_compareId(void* pais1, void* pais2);

/** \brief                          Compara Nombres de paiss.
 *
 * \param pais1 void*           Primer pais a comparar.
 * \param pais2 void*           Segundo pais a comparar.
 * \return int                      Retorna -1 si el 1er pais es mayor al segundo.
 *
 */
int pais_compareNombre(void* pais1, void* pais2);

/** \brief                          Compara Horas Trabajadas de paiss.
 *
 * \param pais1 void*           Primer pais a comparar.
 * \param pais2 void*           Segundo pais a comparar.
 * \return int                      Retorna -1 si el 1er pais es mayor al segundo.
 *
 */
int pais_compareVac1dosis(void* pais1, void* pais2);

/** \brief                          Compara Vac1dosiss de paiss.
 *
 * \param pais1 void*           Primer pais a comparar.
 * \param pais2 void*           Segundo pais a comparar.
 * \return int                      Retorna -1 si el 1er pais es mayor al segundo.
 *
 */
int pais_compareVac2dosis(void* pais1, void* pais2);

/** \brief                          Compara Vac1dosiss de paiss.
 *
 * \param pais1 void*           Primer pais a comparar.
 * \param pais2 void*           Segundo pais a comparar.
 * \return int                      Retorna -1 si el 1er pais es mayor al segundo.
 *
 */
int pais_compareSinVacunar(void* pais1, void* pais2);

int pais_filterExitosos(void* pais1);

int pais_filterAlHorno(void* pais1);


#endif // employee_H_INCLUDED
