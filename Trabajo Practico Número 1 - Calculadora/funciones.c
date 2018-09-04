#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
*\brief Se pasa por parametro un numero y se verifica si valido.
*\param numeroIngresado: Es el valor a verificar si es el correcto.
*\param min: Es el numero minimo que se acepta como parametro.
*\param max: Es el numero maximo que se acepta como parametro.
*\return Retorna 0 si todo es correcto o -1 si hubo error.
*/

int validarOperadoresIngresados (int numeroIngresado,int min, int max)
{

    if (numeroIngresado <= min || numeroIngresado >= max)
        {
            return-1;
        }
    return 0;
}

/**
*\brief Se solicita una numero el cual, se verifica si es un valor valido. Se contemplan 3 intentos y sale de la funcion.
*\param numeroIngresado: Es el valor a verificar si es el correcto.
*\param pOperadorVerificado: Variable que almacena el valor verificado.
*\param min: Es el numero minimo que se acepta como parametro.
*\param max: Es el numero maximo que se acepta como parametro.
*\param intentos: Numero de posibilidades que va a tener  el usuario para equivocarse.
*\return Retorna 0 si todo es correcto o -1 si hubo error.
*/

int pedirOperadorParaRealizarLasOperaciones (int* pOperadorVerificado, int min, int max)
{
    int numeroIngresado;
    int intentos = 3;
    do
    {
        printf("\n\n  INGRESAR EL PRIMER VALOR CON EL CUAL REALIZAR OPERACIONES: ");
        fflush(stdin);//__fpurge//
        if(scanf("%d",&numeroIngresado) !=1 || validarOperadoresIngresados (numeroIngresado, min, max) != 0)
        {
            system("cls");
            printf("\n\nUSTED INGRESO UN VALOR EQUIVOCO. INTENTE NUEVAMENTE... \n\n\n");
            intentos--;
        }
        else
        {
            *pOperadorVerificado = numeroIngresado;
            system("cls");
            break;
        }
        if (intentos == 0)
        {
            system("cls");
            printf("\n\nUSTED SOBREPASO LA CANTIDAD DE INTENTOS DISPONIBLES!!!\n\n\n");
            break;
        }
    }while (intentos > 0);
    return 0;
}

/**
*\brief Se toma por parametro 2 operadores que ya fueron verficados con anterioridad, y se realiza una suma de estos.
*\param pPrimerOperado: Primer numero verificado que se ultilizara para la suma.
*\param pSegundoOperador: Segundo numero verificado que se ultilizara para la suma.
*\param pResultadoSumaDeLosOperadores: Variable en el cual se almacena el valor de la suma.
*\return Retorna 0 si todo es correcto o -1 si hubo error.
*/

int sumaDeLosOperadores (int* pPrimerOperador, int* pSegundoOperador, int* pResultadoSumaDeLosOperadores)
{
    *pResultadoSumaDeLosOperadores = *pPrimerOperador + *pSegundoOperador;
    return 0;
}

/**
*\brief Se toma por parametro 2 operadores que ya fueron verficados con anterioridad, y se realiza una resta de estos.
*\param pPrimerOperado: Primer numero verificado que se ultilizara para la resta.
*\param pSegundoOperador: Segundo numero verificado que se ultilizara para la resta.
*\param pResultadoRestaDeLosOperadores: Variable en el cual se almacena el valor de la resta.
*\return Retorna 0 si todo es correcto o -1 si hubo error.
*/

int restaDeLosOperadores (int* pPrimerOperador, int* pSegundoOperador, int* pResultadoRestaDeLosOperadores)
{
    *pResultadoRestaDeLosOperadores = *pPrimerOperador - *pSegundoOperador;
    return 0;
}

/**
*\brief Se toma por parametro 2 operadores que ya fueron verficados con anterioridad, y se realiza una multiplicacion de estos.
*\param pPrimerOperado: Primer numero verificado que se ultilizara para la multiplicacion.
*\param pSegundoOperador: Segundo numero verificado que se ultilizara para la multiplicacion.
*\param pResultadoMultiplicacionDeLosOperadores: Variable en el cual se almacena el valor de la multiplicacion.
*\return Retorna 0 si todo es correcto o -1 si hubo error.
*/

int multiplicacionDeLosOperadores (int* pPrimerOperador, int* pSegundoOperador, int* pResultadomultiplicacionDeLosOperadores)
{
    *pResultadomultiplicacionDeLosOperadores = *pPrimerOperador * *pSegundoOperador;
    return 0;
}

/**
*\brief Se toma por parametro 2 operadores que ya fueron verficados con anterioridad, y se realiza una division de estos, en el caso que sea posible.
*\param pPrimerOperado: Primer numero verificado que se ultilizara para la division.
*\param pSegundoOperador: Segundo numero verificado que se ultilizara para la division.
*\param pResultadoDivisionDeLosOperadores: Variable en el cual se almacena el valor de la division.
*\return Retorna 0 si todo es correcto o -1 si se ingresa un 0 como divisor.
*/

int divisionDeLosOperadores (int* pPrimerOperador, int* pSegundoOperador, float* pResultadoDivisionDeLosOperadores)
{
    if (*pSegundoOperador !=0)
    {
		*pResultadoDivisionDeLosOperadores = (float)*pPrimerOperador / *pSegundoOperador;
		return 0;
    }
    return -1;
}

/**
*\brief Se toma por parametro un operador que ya fue verificado con anterioridad se y realiza el factorial del mismo, en el caso que sea posible.
*\param pPrimerOperador: Primer numero verificado que se ultilizara para obtener el factorial.
*\param pResultadoFactorialDelPrimerOperador: Variable en el cual se almacena el valor del resultado del factorial del primer operador ingresado.
*\return Retorna 0 si todo es correcto o retorna -1  si no se pudo realizar el factorial del valor ingresado.
*/

int factorialDelPrimerOperador(int* pPrimerOperador, long* pResultadoFactorialDelPrimerOperador)
{
    int primerNumeroIngresado;
    long valorParcialDelResultadoFactorial = 1;
    int i;
    primerNumeroIngresado = *pPrimerOperador;
    if(primerNumeroIngresado > 0)
    {
        for(i = primerNumeroIngresado; i >= 1; i--)
        {
            valorParcialDelResultadoFactorial = valorParcialDelResultadoFactorial*i;
            if(i==1)
            {
                *pResultadoFactorialDelPrimerOperador = valorParcialDelResultadoFactorial;
                valorParcialDelResultadoFactorial = 1;
            }
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

/**
*\brief Se toma por parametro un operador que ya fue verificado con anterioridad se y realiza el factorial del mismo, en el caso que sea posible.
*\param pSegundoOperador: Segundo numero verificado que se ultilizara para obtener el factorial.
*\param pResultadoFactorialDelSegundoOperador: Variable en el cual se almacena el valor del resultado del factorial del segundo operador ingresado.
*\return Retorna 0 si todo es correcto o retorna -1  si no se pudo realizar el factorial del valor ingresado.
*/

int factorialDelSegundoOperador(int* pSegundoOperador, long* pResultadoFactorialDelSegundoOperador)
{
    int segundoNumeroIngresado;
    long valorParcialDelResultadoFactorial = 1;
    int i;
    segundoNumeroIngresado = *pSegundoOperador;
    if(segundoNumeroIngresado > 0)
    {
        for(i = segundoNumeroIngresado; i >= 1; i--)
        {
            valorParcialDelResultadoFactorial = valorParcialDelResultadoFactorial*i;
            if(i==1)
            {
                *pResultadoFactorialDelSegundoOperador = valorParcialDelResultadoFactorial;
                valorParcialDelResultadoFactorial = 1;
            }
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

/**
*\brief Se toma por parametro 2 numeros, y el resultado de las diferentes operaciones que se ralizaron con ellas (Suma, Resta, Multiplicacion, Division y Factorial.
*\param pPrimerOperador: Primer numero con el cual vamos a operar.
*\param pSegundoOperador: Segundo numero con el cual vamos a operar.
*\param pResultadoSumaDeLosOperadores: Resultado de la Suma de los operadores ingresados.
*\param pResultadoRestaDeLosOperadores: Resultado de la Resta de los operadores ingresados.
*\param pResultadomultiplicacionDeLosOperadores: Resultado de la multiplicacion de los operadores ingresados.
*\param pResultadoDivisionDeLosOperadores: Resultado de la division (en el caso de que sea posible) de los operadores ingresados.
*\param pResultadoFactorialDelPrimerOperador: Variable en el cual se almacena el valor del resultado del factorial del primer operador ingresado.
*\param pResultadoFactorialDelSegundoOperador: Variable en el cual se almacena el valor del resultado del factorial del segundo operador ingresado.
*\return retorna 0 si todo es correcto.
*/

int mostrarResultadoDeTodasLasOperaciones (int* pPrimerOperador, int* pSegundoOperador, int* pResultadoSumaDeLosOperadores, int* pResultadoRestaDeLosOperadores, int* pResultadomultiplicacionDeLosOperadores, float* pResultadoDivisionDeLosOperadores, long* pResultadoFactorialDelPrimerOperador, long* pResultadoFactorialDelSegundoOperador)
{
    printf("\n\n\tRESULTADOS:\n\n\n");
    printf("\nLa suma realizada entre %d y %d, da un restulado total de %d.\n", *pPrimerOperador, *pSegundoOperador, *pResultadoSumaDeLosOperadores);
    printf("\nLa resta realida entre %d y %d, da un resultado total de %d.\n", *pPrimerOperador, *pSegundoOperador, *pResultadoRestaDeLosOperadores);
    printf("\nLa multiplicacion realizada entre %d y %d, da un resultado total de %d.\n", *pPrimerOperador, *pSegundoOperador, *pResultadomultiplicacionDeLosOperadores);
    if (*pSegundoOperador != 0)
    {
        printf("\nLa division realizada entre %d y %d, da un resultado total de %.2f.\n", *pPrimerOperador, *pSegundoOperador, *pResultadoDivisionDeLosOperadores);
    }
    else
    {
        printf("\nLa division solicitada no puede realizarce, debido a que el divisor ingresado es 0.\n");
    }
    if (*pPrimerOperador > 0)
    {
        printf("\nEl resultado factorial de %d es %ld.\n", *pPrimerOperador, *pResultadoFactorialDelPrimerOperador);
    }
    else
    {
        printf("\nEl primer valor el cual ingreso, no se le puede realizar el factorial.\n");
    }
    if (*pSegundoOperador > 0)
    {
        printf("\nEl resultado factorial de %d es %ld.\n\n", *pSegundoOperador, *pResultadoFactorialDelSegundoOperador);
    }
    else
    {
       printf("\nEl segundo valor el cual ingreso, no se le puede realizar el factorial.\n\n");
    }
    return 0;
}

/**
*\brief Se muestra el menu de las diferentes operaciones que se pueden realizar. Los 2 operadores se inicializan en 0 por defecto.
*\return retorna 0 si todo es correcto.
*/

void menuDeCalculadora ()
{
    int opcionIngresada = 0;
    int primerOperador = 0;
    int segundoOperador = 0;
    int resultadoSumaDeLosOperadores;
    int resultadoRestaDeLosOperadores;
    int resultadoMultiplicacionDeLosOperadores;
    float resultadoDivisionDeLosOperadores;
    long resultadoFactorialDelPrimerOperador;
    long resultadoFactorialDelSegundoOperador;
    int seguir = 1;
    while (seguir ==1)
    {
        printf("\n         #############################################################");
        printf("\n         *                                                           *");
        printf("\n         *                >> C A L C U L A D O R A <<                *");
        printf("\n         *                                                           *");
         printf("\n         #############################################################\n");
        printf("\n\t\t\t INGRESE LA OPCION QUE NECESITE:\n\n\n\n\n");
        printf("\n  1- INGRESE EL PRIMER VALOR CON EL CUAL NECESITE OPERAR: \n");
        printf("\n  2- INGRESE EL SEGUNDO VALOR CON EL CUAL NECESITE OPERAR: \n");
        printf("\n  3- CALCULAR OPERACIONES ARITMETICAS CON LOS OPERADORES INGRESADOS. \n");
        printf("\n  4- MOSTRAR TODOS LOS RESULTADOS DE LAS OPERACIONES ARITMETICAS REALIZADAS. \n");
        printf("\n  5- SALIR DEL PROGRAMA. \n\n\n");
        printf("\n  LA OPCION INGRESADA ES: ");
        scanf("%d",&opcionIngresada);
        system("cls");
        switch (opcionIngresada)
        {
            case 1:
                system("cls");
                pedirOperadorParaRealizarLasOperaciones(&primerOperador, -99999999, 99999999);
                printf("\n\n\tUSTED INGRESO EL VALOR: %d.\n\n", primerOperador);
                fflush(stdin);
                system("Pause");
                break;

            case 2:
                system("cls");
                pedirOperadorParaRealizarLasOperaciones(&segundoOperador, -99999999, 99999999);
                printf("\n\n\tUSTED INGRESO EL VALOR: %d.\n\n", segundoOperador);
                fflush(stdin);
                system("Pause");
                break;

            case 3:
                system("cls");
                sumaDeLosOperadores (&primerOperador, &segundoOperador, &resultadoSumaDeLosOperadores);
                restaDeLosOperadores (&primerOperador, &segundoOperador, &resultadoRestaDeLosOperadores);
                multiplicacionDeLosOperadores (&primerOperador, &segundoOperador, &resultadoMultiplicacionDeLosOperadores);
                divisionDeLosOperadores (&primerOperador, &segundoOperador, &resultadoDivisionDeLosOperadores);
                factorialDelPrimerOperador(&primerOperador, &resultadoFactorialDelPrimerOperador);
                factorialDelSegundoOperador(&segundoOperador, &resultadoFactorialDelSegundoOperador);
                printf("\n\n\n\n\t\tREALIZANDO LOS CALCULOS SOLICITADOS...\n\n\n");
                system("Pause");
                break;

            case 4:
                system("cls");
                mostrarResultadoDeTodasLasOperaciones(&primerOperador, &segundoOperador, &resultadoSumaDeLosOperadores, &resultadoRestaDeLosOperadores, &resultadoMultiplicacionDeLosOperadores, &resultadoDivisionDeLosOperadores, &resultadoFactorialDelPrimerOperador, &resultadoFactorialDelSegundoOperador);
                system("Pause");
                break;

            case 5:
                seguir=0;
                printf("\n         #############################################################");
                printf("\n         *                                                           *");
                printf("\n\t\t\t      Cerrando programa...\n\n\n\t\t\t\tHASTA LUEGO!!!\n");
                printf("\n         *                                                           *");
                printf("\n         #############################################################\n\n");
                break;

            default:
                printf("\n\n\nEL VALOR QUE INGRESO NO PERTENECE A UNA OPCION DISPONIBLE\n\n\n");
                system("Pause");
        }
    }
    system("Pause");
}
