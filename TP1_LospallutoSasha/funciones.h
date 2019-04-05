#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Realiza la suma de dos numeros
 *
 * \param num1 float numero pasado por valor
 * \param num2 float numero pasado por valor
  * \param suma float* lugar de memoria donde se va a guardar el resultado de la suma
 * \return void
 *
 */
void funcionSuma (float num1, float num2, float* suma);

/** \brief Realiza la resta de dos numeros
 *
 * \param num1 float numero pasado por valor
 * \param num2 float numero pasado por valor
  * \param resta float* lugar de memoria donde se va a guardar el resultado de la resta
 * \return void
 *
 */
void funcionResta (float num1,float num2,float * resta);

/** \brief Realiza la multiplicacion de dos numeros
 *
 * \param num1 float numero pasado por valor
 * \param num2 float numero pasado por valor
  * \param multiplicar float* lugar de memoria donde se va a guardar el resultado de la multiplicacion
 * \return void
 *
 */
void funcionMultiplicar (float num1,float num2, float* multiplicar);

/** \brief Realiza la division de dos numeros
 *
 * \param num1 float numero pasado por valor
 * \param num2 float numero pasado por valor
  * \param dividir float* lugar de memoria donde se va a guardar el resultado de la division
 * \return int -1 si se ingreso un divisor cero, 0 si se pudo realizar la division
 *
 */
int funcionDividir (float num1, float num2, float* dividir);

/** \brief realiza el factorial de un numero y se devuelve el resultado o el error
 *
 * \param num float* numero pasado por referencia
 * \param factorial unsigned long int* lugar en el que se guarda el resultado del factorial
 * \return void
 *
 */
void funcionFactorial (float* num, unsigned long int* factorial);

/** \brief muestra el factorial de un numero
 *
 * \param num float numero que se va a factoriar pasado por valor
 * \param factorial unsigned long int resultado del factoreo
 * \return void
 *
 */
void funcionMostrarFactorial(float num,unsigned long int factorial);


/** \brief valida si el numero ingresado tiene alguna letra
 *
 * \param numero char* caracteres ingresado, pasado por parametro
 * \return devuelve cero si el numero ingresado es un float, de lo contrario retorna -1
 *
 */
int validarNumero (char* numero);

int utn_getNumero(float* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos);
/*Recibe la variable de tipo float *pResultado donde se guardara el numero.un const char* para el mensaje otro para el mensaje de error,
  tambien recibe int minimo y maximo para los limites de los valores aceptados. recibe la cantidad de reintentos de error, y devuelve
  0 si funciono -1 si no. */

int utn_getFloat(float *pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos);
/*Recibe la variable de tipo float *pResultado donde se guardara el numero.un const char* para el mensaje otro para el mensaje de error,
  tambien recibe int minimo y maximo para los limites de los valores aceptados. recibe la cantidad de reintentos de error, y devuelve
  0 si funciono -1 si no. */

int getFloat(float *pResultado);
/*toma el ingreso por consola de un char* y lo transforma en float , lo guarda en la varible pRersultado. devuelve 0 si funciono y -1
  si no funciono*/

#endif // FUNCIONES_H_INCLUDED
