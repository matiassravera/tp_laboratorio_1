
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int validarOperadoresIngresados (int numeroIngresado,int min, int max);
int pedirOperadorParaRealizarLasOperaciones (int* pOperadorVerificado, int min, int max);
int sumaDeLosOperadores (int* pPrimerOperador, int* pSegundoOperador, int* pResultadoSumaDeLosOperadores);
int restaDeLosOperadores (int* pPrimerOperador, int* pSegundoOperador, int* pResultadoRestaDeLosOperadores);
int multiplicacionDeLosOperadores (int* pPrimerOperador, int* pSegundoOperador, int* pResultadomultiplicacionDeLosOperadores);
int divisionDeLosOperadores (int* pPrimerOperador, int* pSegundoOperador, float* pResultadoDivisionDeLosOperadores);
int factorialDelPrimerOperador(int* pPrimerOperador, long* pResultadoFactorialDelPrimerOperador);
int factorialDelSegundoOperador(int* pSegundoOperador, long* pResultadoFactorialDelSegundoOperador);
int mostrarResultadoDeTodasLasOperaciones (int* pPrimerOperador, int* pSegundoOperador, int* pResultadoSumaDeLosOperadores, int* pResultadoRestaDeLosOperadores, int* pResultadomultiplicacionDeLosOperadores, float* pResultadoDivisionDeLosOperadores, long* pResultadoFactorialDelPrimerOperador, long* pResultadoFactorialDelSegundoOperador);
void menuDeCalculadora ();

#endif // FUNCIONES_H_INCLUDED

