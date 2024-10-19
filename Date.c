/*******************************************************************************
Programa para cambiar formato de fecha

By
Angel Antonio Mendez Hernandez
********************************************************************************/
#include <stdio.h>

/*Esta funcion determina el rango en el que esta
el valor que se le de, 0 si son unidades, 1 si está
en rango de decenas, 2 en el orden de centenas, etc*/
int rango(int a){
    int i=-1;
    while(a>0){
        i++;
        a/=10;
    }
    return i;
}

//Esta funcion calcula 10^p
int pot10(int p){
    int n=1;
    for(;p>0;p--)
        n*=10;
    return n;
}

/*Esta es la más interesante... Recibe un valor y su rango en el valor original
entonces trata de ubicarlo para poder imprimirlo en letra*/
void digitos(int a, int b){
    switch(a){
        case 0:
            printf("");
            break;
        case 1:
            if(b<3)
                ((b==2)?(printf("cien ")):((b==1)?(printf("dieci")):(printf("uno"))));
            else
                printf("mil ");
            break;
        case 2:
            if(b<3)
                ((b==2)?(printf("doscientos ")):((b==1)?(printf("veinti")):(printf("dos"))));
            else
                printf("dos mil ");
            break;
        case 3:
            if(b<3)
                ((b==2)?(printf("trescientos ")):((b==1)?(printf("treinta y ")):(printf("tres"))));
            else
                printf("tres mil ");
            break;
        case 4:
            if(b<3)
                ((b==2)?(printf("cuatrocientos ")):((b==1)?(printf("cuarenta y ")):(printf("cuatro"))));
            else
                printf("cuatro mil ");
            break;
        case 5:
            if(b<3)
                ((b==2)?(printf("quinientos ")):((b==1)?(printf("cincuenta y ")):(printf("cinco"))));
            else
                printf("cinco mil ");
            break;
        case 6:
            if(b<3)
                ((b==2)?(printf("seiscientos ")):((b==1)?(printf("sesenta y ")):(printf("seis"))));
            else
                printf("seis mil ");
            break;
        case 7:
            if(b<3)
                ((b==2)?(printf("setecientos ")):((b==1)?(printf("setenta y ")):(printf("siete"))));
            else
                printf("siete mil ");
            break;
        case 8:
            if(b<3)
                ((b==2)?(printf("ochocientos ")):((b==1)?(printf("ochenta y ")):(printf("ocho"))));
            else
                printf("ocho mil ");
            break;
        case 9:
            if(b<3)
                ((b==2)?(printf("novecientos ")):((b==1)?(printf("noventa y ")):(printf("nueve"))));
            else
                printf("nueve mil ");
            break;
    }
}

//numero a mes
void meses(int a){
    switch(a){
        case 1: printf("enero "); break;
        case 2: printf("febrero "); break;
        case 3: printf("marzo "); break;
        case 4: printf("abril "); break;
        case 5: printf("mayo "); break;
        case 6: printf("junio "); break;
        case 7: printf("julio "); break;
        case 8: printf("agosto "); break;
        case 9: printf("septiembre "); break;
        case 10: printf("octubre "); break;
        case 11: printf("noviembre "); break;
        case 12: printf("diciembre "); break;
    }
}

//casos especiales
void dive(int a){
    switch(a){
        case 11: printf("once"); break;
        case 12: printf("doce"); break;
        case 13: printf("trece"); break;
        case 14: printf("catorce"); break;
        case 15: printf("quince"); break;
    }
}
void decenas(int a){
    switch(a){
        case 10: printf("diez"); break;
        case 20: printf("veinte"); break;
        case 30: printf("treinta"); break;
        case 40: printf("cuarenta"); break;
        case 50: printf("cincuenta"); break;
        case 60: printf("sesenta"); break;
        case 70: printf("setenta"); break;
        case 80: printf("ochenta"); break;
        case 90: printf("noventa"); break;
    }
}

int main()
{
    int dia=0, mes=0, anio=0, rd, ra, div;
    while((dia<1 || dia>31) || (mes<1 || mes>12) || (anio<1 || anio >9999)){
        printf("Ingrese la fecha dd/mm/aaaa: ");
        scanf("%d/%d/%d",&dia,&mes,&anio);
    }
    printf("La fecha es ");

    //Para el dia
    for(rd=rango(dia);rd>=0;rd--){
        if(dia%10==0 && rd==1){
            decenas(dia);
            break;
        }
        if(dia>10 && dia<16){
            dive(dia);
            rd--;
        }
        else{
            div=dia/pot10(rd);
            digitos(div%10,rd);
        }
    }
    //Para el mes
    printf(" de ");
    meses(mes);
    printf("del ");

    //Para el anio
    int dif;
    for(ra=rango(anio);ra>=0;ra--){
        if(ra==1){
            if(anio%10==0){
                dif=anio%100;
                decenas(dif);
                break;
            }
            div=anio%100;
            if(div>10 && div<16){
                dive(div);
                break;
            }
            else{
                div = anio / pot10(ra);
                digitos(div % 10, ra);
            }
        }
        else{
            div = anio / pot10(ra);
            digitos(div % 10, ra);
        }
    }
    printf("\n");
    return 0;
}
