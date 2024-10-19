/*******************************************************************************
Programa para cambiar la base de números enteros

By
Angel Antonio Mendez Hernandez
********************************************************************************/
#include <stdio.h>

/*Funcion para ubicar residuos mayores o iguales que
10 con su respectiva letra en su base*/
void letras(int a){
    switch(a){
        case 10: printf("A"); break;
        case 11: printf("B"); break;
        case 12: printf("C"); break;
        case 13: printf("D"); break;
        case 14: printf("E"); break;
        case 15: printf("F"); break;
    }
}

int main()
{
    unsigned long decimal=0, dcopia, base=0, i=1;
    while(decimal<=0){
    	printf("Ingrese el valor que desea convertir: ");
    	scanf("%lu",&decimal);
    }
    /*dcopia=decimal;
    La idea es simple, guardar los residuos al dividir por la base deseada
    y poner esos residuos en la misma variable en la posicion
    correspondiente (por eso la i y sus multiplicaciones por 10)*/
    int nbase;
    for(nbase=2;nbase<10;nbase++){
        dcopia=decimal;
        base=0;
        i=1;
        while(dcopia!=0){
            base+=i*(dcopia%nbase);
            dcopia/=nbase;
            i*=10;
        }
    printf("El valor en base %d es: %lu_%d\n",nbase, base, nbase);
    }
    printf("El valor en base 10 es: %lu_10\n", decimal);

    nbase=11;
    for(;nbase<17;nbase++){
        printf("El valor en base %d es: ",nbase);
        dcopia=decimal;
        base=decimal;
        while(base>=nbase){
            base=dcopia/nbase;
            dcopia=base;
        }
        if(dcopia>=10 && dcopia<=16)
            letras(dcopia);
        else
            printf("%lu", dcopia);
        for(dcopia=decimal, base=0;dcopia>=nbase;dcopia/=nbase){
            i=dcopia%nbase;
            base++;
        }
        if(i>=10 && i<=16)
            letras(i);
        else
            printf("%lu", i);
        int d=0;
        for(dcopia=decimal,base--;base>0;base--){
            while(d<base){
                i=dcopia%nbase;
                dcopia/=nbase;
                d++;
            }
            if(i>=10 && i<=16)
                letras(i);
            else
                printf("%lu", i);
            dcopia=decimal;
            d=0;
        }
        printf("_%d\n",nbase);
    }
    return 0;
}
