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
 * \param factorial int* lugar en el que se guarda el resultado del factorial
 * \return void
 *
 */
void funcionFactorial (float* num, unsigned long long int* factorial);

/** \brief muestra el factorial de un numero
 *
 * \param num float numero que se va a factoriar pasado por valor
 * \param factorial int resultado del factoreo
 * \return void
 *
 */
void funcionMostrarFactorial(float num,unsigned long long int factorial);

#endif // FUNCIONES_H_INCLUDED
