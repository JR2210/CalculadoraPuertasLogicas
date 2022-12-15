#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 4
/*CALCULADORA DE OPERACIONES LOGICAS BASICAS DE 4 BITS CON ACARREO*/
/*OPERACIONES DE TIPO AND EN DIFICULTADES PARA LA IMPLEMENTACION DEBIDO A QUE HAY MULTIPLICACIONES CON
RESULTADOS ENORMES SIENDO OPERADORES DE 4 BITS(SE PUEDE BAJAR A 2 BITS PARA QUE EL MAXIMO SEA 1001)*/

void mostrarNANDyAND(int arrayA[MAX], int arrayB[MAX],int arraySuma[MAX], int tamanio)
{
    printf("\n *** LA MULTIPLICACION DA COMO RESULTADO ***");
    printf("\n  ");
    for(int i = 0 ; i < 2 ; i++)
        printf("%d ",arrayA[i]);
    printf("\nx ");
    for(int i = 0 ; i < 2 ; i++)
        printf("%d ",arrayB[i]);

    printf("\n");
    printf("--------------------");
    printf("\n");
    if(tamanio == 4)
        for(int i = 0 ; i < MAX ; i++)printf("%d ",arraySuma[i]);
    else if(tamanio == 3)
    {
        printf(" ");
        for(int i = 1 ; i < MAX ; i++)printf("%d ",arraySuma[i]);
    }
    else if(tamanio == 2)
        for(int i = 2 ; i < MAX ; i++)printf("%d ",arraySuma[i]);
}

void mostrarSumaNOR(int arrayA[],int arrayB[],int arraySuma[],int mayorCuatro)
{
    printf("\n***LA SUMA NOR DA COMO RESULTADO***\n\n");
    printf("\n  \t");
    for(int i = 0 ; i < MAX ; i++)
        printf("%d ",arrayA[i]);
    printf("\n+ \t");
    for(int i = 0 ; i < MAX ; i++)
        printf("%d ",arrayB[i]);

    printf("\n");
    printf("--------------------\n");
    if(mayorCuatro == 1)
    {
        printf("      ");
        for(int i = 0 ; i <= MAX ; i++)printf("%d ",arraySuma[i]);
    }
    else if(mayorCuatro == 0)
    {
        printf("        ");
        for(int i = 0 ; i < MAX ; i++)printf("%d ",arraySuma[i]);
    }
}

void mostrarSumaOR(int arrayA[MAX], int arrayB[MAX],int arraySuma[MAX],int mayorCuatro)
{
    printf("\n***LA SUMA OR DA COMO RESULTADO***\n\n");
    printf("\n  \t");
    for(int i = 0 ; i < MAX ; i++)
        printf("%d ",arrayA[i]);
    printf("\n+ \t");
    for(int i = 0 ; i < MAX ; i++)
        printf("%d ",arrayB[i]);

    printf("\n");
    printf("--------------------\n");
    if(mayorCuatro == 1)
    {
        printf("      ");
        for(int i = 0 ; i <= MAX ; i++)printf("%d ",arraySuma[i]);
    }
    else if(mayorCuatro == 0)
    {
        printf("        ");
        for(int i = 0 ; i < MAX ; i++)printf("%d ",arraySuma[i]);
    }
}

void mostrarNot(int arrayA[],int arrayNot[])
{
    printf("*** El inverso es ***\n");
    printf("\n    ");
    for(int i = 0 ; i < MAX ; i++)
        printf("%d ",arrayA[i]);
    printf("\nx \t -1");

    printf("\n");
    printf("--------------------\n");
    printf("    ");
    for(int i = 0 ; i < MAX ; i++)printf("%d ",arrayNot[i]);
}

void mostrarSumaXOR(int arrayA[], int arrayB[], int arraySol[])
{
    printf("\n***LA SUMA XOR DA COMO RESULTADO***\n\n");
    printf("\n     ");
    for(int i = 0 ; i < MAX ; i++)
        printf("%d ",arrayA[i]);
    printf("\n+    ");
    for(int i = 0 ; i < MAX ; i++)
        printf("%d ",arrayB[i]);

    printf("\n");
    printf("--------------------\n");
    printf("     ");
    for(int i = 0 ; i < MAX ; i++)printf("%d ",arraySol[i]);
}

void funcionOR()
{
    int arrayA[MAX],arrayB[MAX],arraySuma[10],resto = 0,mayorCuatro = 0;
    printf("Introduzca el primer numero en binario: ");
    for(int i = 0 ; i < MAX ; i++)
    {
        scanf("%d",&arrayA[i]);
        if(arrayA[i] < 0 || arrayA[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro\n",arrayA[i]);
            printf("Vuelva a introducir: ");
            scanf("%d",&arrayA[i]);
        }
    }
    printf("Introduzca el primer numero en binario: ");
    for(int i = 0 ; i < MAX ; i++)
    {
        scanf("%d",&arrayB[i]);
        if(arrayB[i] < 0 || arrayB[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro",arrayB[i]);
            scanf("%d",&arrayB[i]);
        }
    }
    for(int i = MAX-1 ; i >= 0 ; i--)
    {
        arraySuma[i] = arrayA[i] + arrayB[i] + resto;
        if((arraySuma[i] == 2 || arraySuma[i] == 3) && i == 0)
        {
            mayorCuatro = 1;
            arraySuma[i] = 1;
            for(int j = MAX ; j > 0 ; j--)
            {
                arraySuma[j] = arraySuma[j-1];
            }
            arraySuma[0] = 1;
        }else if(arraySuma[i] == 2)
        {
            resto = 1;
            arraySuma[i] = 0;
        }else if(arraySuma[i] == 3)
        {
            resto = 1;
            arraySuma[i] = 1;
        }else if(arraySuma[i] == 1)
        {
            resto = 0;
            arraySuma[i] = 1;
        }else if(arraySuma[i] == 0)
        {
            resto = 0;
            arraySuma[i] = 0;
        }
    }
    mostrarSumaOR(arrayA,arrayB,arraySuma,mayorCuatro);
}

void funcionAND()
{
    int arrayA[2],arrayB[2],arraySol[MAX],sumaPesosA = 0,sumaPesosB = 0,arrayPesos[MAX] = {8,4,2,1}, tamanio = 0;
    printf("Introduzca el primer numero en binario: ");
    for(int i = 0 ; i < 2 ; i++)
    {
        scanf("%d",&arrayA[i]);
        if(arrayA[i] < 0 || arrayA[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro\n",arrayA[i]);
            printf("Vuelva a introducir: ");
            scanf("%d",&arrayA[i]);
        }
    }
    printf("Introduzca el segundo numero en binario: ");
    for(int i = 0 ; i < 2 ; i++)
    {
        scanf("%d",&arrayB[i]);
        if(arrayB[i] < 0 || arrayB[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro",arrayB[i]);
            scanf("%d",&arrayB[i]);
        }
    }
    if(arrayA[0] == 1)
        sumaPesosA += 2;
    if(arrayB[0] == 1)
        sumaPesosB += 2;
    if(arrayA[1] == 1)
        sumaPesosA += 1;
    if(arrayB[1] == 1)
        sumaPesosB += 1;

    int mulTotal = sumaPesosA * sumaPesosB;

    if(mulTotal > 8)
    {
        tamanio = 4;
        for(int i = 0 ; i < MAX ; i++)
        {
            if(mulTotal-arrayPesos[i] >= 0)
            {
                arraySol[i] = 1;
                mulTotal -= arrayPesos[i];
            }else
            {
                arraySol[i] = 0;
            }
        }
    }else if(mulTotal > 3 && mulTotal < 9)
    {
        tamanio = 3;
        for(int i = 1 ; i < MAX ; i++)
        {
            if(mulTotal-arrayPesos[i] >= 0)
            {
                arraySol[i] = 1;
                mulTotal -= arrayPesos[i];
            }else
            {
                arraySol[i] = 0;
            }
        }
    }else if(mulTotal < 4)
    {
        tamanio = 2;
        for(int i = 2 ; i < MAX ; i++)
        {
            if(mulTotal-arrayPesos[i] >= 0)
            {
                arraySol[i] = 1;
                mulTotal -= arrayPesos[i];
            }else
            {
                arraySol[i] = 0;
            }
        }
    }
    mostrarNANDyAND(arrayA,arrayB,arraySol,tamanio);
}

void puertaNot()
{
    int arrayA[MAX],arrayNot[MAX];
    printf("Introduzca el numero a invertir en binario: ");
    for(int i = 0 ; i < MAX ; i++)
    {
        scanf("%d",&arrayA[i]);
        if(arrayA[i] < 0 || arrayA[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro\n",arrayA[i]);
            printf("Vuelva a introducir: ");
            scanf("%d",&arrayA[i]);
        }
    }
    for(int i = 0 ; i < MAX ; i++)
    {
        if(arrayA[i] == 0)
            arrayNot[i] = 1;
        else
            arrayNot[i] = 0;
    }
    mostrarNot(arrayA,arrayNot);
}

void funcionXor()
{
    int arrayA[MAX],arrayB[MAX],arraySol[MAX];
    printf("Introduzca el primer numero en binario: ");
    for(int i = 0 ; i < MAX ; i++)
    {
        scanf("%d",&arrayA[i]);
        if(arrayA[i] < 0 || arrayA[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro\n",arrayA[i]);
            printf("Vuelva a introducir: ");
            scanf("%d",&arrayA[i]);
        }
    }
    printf("Introduzca el primer numero en binario: ");
    for(int i = 0 ; i < MAX ; i++)
    {
        scanf("%d",&arrayB[i]);
        if(arrayB[i] < 0 || arrayB[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro",arrayB[i]);
            scanf("%d",&arrayB[i]);
        }
    }
    for(int i = MAX-1 ; i >= 0 ; i--)
    {
        arraySol[i] = arrayA[i] + arrayB[i];
        if(arraySol[i] == 2)
            arraySol[i] = 0;
        else if(arraySol[i] == 1)
            arraySol[i] = 1;
        else if(arraySol[i] == 0)
            arraySol[i] = 0;
    }
    mostrarSumaXOR(arrayA,arrayB,arraySol);
}

void puertaNOR()
{
    int arrayA[MAX],arrayB[MAX],arraySuma[10],resto = 0,mayorCuatro = 0;
    printf("Introduzca el primer numero en binario: ");
    for(int i = 0 ; i < MAX ; i++)
    {
        scanf("%d",&arrayA[i]);
        if(arrayA[i] < 0 || arrayA[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro\n",arrayA[i]);
            printf("Vuelva a introducir: ");
            scanf("%d",&arrayA[i]);
        }
    }
    printf("Introduzca el primer numero en binario: ");
    for(int i = 0 ; i < MAX ; i++)
    {
        scanf("%d",&arrayB[i]);
        if(arrayB[i] < 0 || arrayB[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro",arrayB[i]);
            scanf("%d",&arrayB[i]);
        }
    }
    for(int i = MAX-1 ; i >= 0 ; i--)
    {
        arraySuma[i] = arrayA[i] + arrayB[i] + resto;
        if((arraySuma[i] == 2 || arraySuma[i] == 3) && i == 0)
        {
            mayorCuatro = 1;
            arraySuma[i] = 1;
            for(int j = MAX ; j > 0 ; j--)
            {
                arraySuma[j] = arraySuma[j-1];
            }
            arraySuma[0] = 1;
        }else if(arraySuma[i] == 2)
        {
            resto = 1;
            arraySuma[i] = 0;
        }else if(arraySuma[i] == 3)
        {
            resto = 1;
            arraySuma[i] = 1;
        }else if(arraySuma[i] == 1)
        {
            resto = 0;
            arraySuma[i] = 1;
        }else if(arraySuma[i] == 0)
        {
            resto = 0;
            arraySuma[i] = 0;
        }
    }
    if(mayorCuatro == 0)
    {
        for(int i = 0; i < MAX ; i++)
        {
            if(arraySuma[i] == 1)
                arraySuma[i] = 0;
            else
                arraySuma[i] = 1;
        }
    }
    else
    {
        for(int i = 0; i <= MAX ; i++)
        {
            if(arraySuma[i] == 1)
                arraySuma[i] = 0;
            else
                arraySuma[i] = 1;
        }
    }
    mostrarSumaNOR(arrayA,arrayB,arraySuma,mayorCuatro);
}

void puertaNAND()
{
    int arrayA[2],arrayB[2],arraySol[MAX],sumaPesosA = 0,sumaPesosB = 0,arrayPesos[MAX] = {8,4,2,1},tamanio = 0;
    printf("Introduzca el primer numero en binario: ");
    for(int i = 0 ; i < 2 ; i++)
    {
        scanf("%d",&arrayA[i]);
        if(arrayA[i] < 0 || arrayA[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro\n",arrayA[i]);
            printf("Vuelva a introducir: ");
            scanf("%d",&arrayA[i]);
        }
    }
    printf("Introduzca el segundo numero en binario: ");
    for(int i = 0 ; i < 2 ; i++)
    {
        scanf("%d",&arrayB[i]);
        if(arrayB[i] < 0 || arrayB[i] > 1)
        {
            printf("%d no es un numero valido, recuerde que estamos en binaro",arrayB[i]);
            scanf("%d",&arrayB[i]);
        }
    }
    if(arrayA[0] == 1)
        sumaPesosA += 2;
    if(arrayB[0] == 1)
        sumaPesosB += 2;
    if(arrayA[1] == 1)
        sumaPesosA += 1;
    if(arrayB[1] == 1)
        sumaPesosB += 1;
        
    int mulTotal = sumaPesosA * sumaPesosB;
    if(mulTotal > 8)
    {
        tamanio = 4;
        for(int i = 0 ; i < MAX ; i++)
        {
            if(mulTotal-arrayPesos[i] >= 0)
            {
                arraySol[i] = 1;
                mulTotal -= arrayPesos[i];
            }else
            {
                arraySol[i] = 0;
            }
        }
        for(int i = 0 ; i < MAX ; i++)
        {
            if(arraySol[i] == 1)
                arraySol[i] = 0;
            else
                arraySol[i] = 1;
        }
    }else if(mulTotal > 3 && mulTotal < 9)
    {
        tamanio = 3;
        for(int i = 1 ; i < MAX ; i++)
        {
            if(mulTotal-arrayPesos[i] >= 0)
            {
                arraySol[i] = 1;
                mulTotal -= arrayPesos[i];
            }else
            {
                arraySol[i] = 0;
            }
        }
        for(int i = 1 ; i < MAX ; i++)
        {
            if(arraySol[i] == 1)
                arraySol[i] = 0;
            else
                arraySol[i] = 1;
        }
    }else if(mulTotal < 4)
    {
        tamanio = 2;
        for(int i = 2 ; i < MAX ; i++)
        {
            if(mulTotal-arrayPesos[i] >= 0)
            {
                arraySol[i] = 1;
                mulTotal -= arrayPesos[i];
            }else
            {
                arraySol[i] = 0;
            }
        }
        for(int i = 2 ; i < MAX ; i++)
        {
            if(arraySol[i] == 1)
                arraySol[i] = 0;
            else
                arraySol[i] = 1;
        }
    }
    mostrarNANDyAND(arrayA,arrayB,arraySol,tamanio);
}

int main()
{
    int seleccion = 0, salida = 1;
    do
    {
        printf("CALCULADORA BOOLEANA DE MAXIMO 4 BITS\n");
        printf("OPCIONES\n");
        printf("1.OR\n");
        printf("2.AND(2BITS)\n");
        printf("3.NOT\n");
        printf("4.XOR\n");
        printf("5.NOR\n");
        printf("6.NAND\n");
        printf("7.SALIR\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seleccion);
        switch(seleccion)
        {
            case 1: funcionOR();break;
            case 2: funcionAND();break;
            case 3: puertaNot();break;
            case 4: funcionXor();break;
            case 5: puertaNOR();break;
            case 6: puertaNAND();break;
            case 7: salida = 0;break;
            default: printf("ESO NO ES UNA OPCION!");break;
        }
        if(salida != 0)
        {
            printf("\nDesea continuar? (0/1): ");
            scanf("%d",&salida);
        }
        system("cls");
    } while(salida != 0);

    return 0;
}