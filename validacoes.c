#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"


int validarCPF(const char *cpf){
    char numeros[12];
    int j=0;

    for(int i=0; cpf[i] != '\0'; i++){
        if(isdigit(cpf[i])){
            numeros[j++]=cpf[i];
        }
    }
    numeros[j]= '\0';

    if(strlen(numeros) != 11)
    return 0;

    int iguais=1;
    for(int i=1; i<11; i++){
        if(numeros[i] != numeros[0]){
            iguais = 0;
            break;
        }
    }
    if(iguais)
    return 0;

    int soma=0;
    for(int i=0; i<9;i++){
        soma+=(numeros[i]-'0')*(10-i);
    }
    int dig1=(soma*10)%11;
    if(dig1==10)dig1=0;

    if(dig1 != (numeros[9]-'0'))
    return 0;

    soma=0;
    for(int i=0; i<10; i++){
        soma+=(numeros[i]-'0')*(11-i);
    }
    int dig2=(soma*10)%11;
    if(dig2==10) dig2=0;
    if(dig2 != (numeros[10]-'0'))
    return 0;

    return 1;
}

int validarCNPJ(const char *cnpj){
    char numeros[20];
    int j=0;

    for(int i=0; cnpj[i] != '\0'; i++){
        if(isdigit(cnpj[i])){
            numeros[j++]=cnpj[i];
        }
    }
    numeros[j]='\0';

    if(strlen(numeros)!=14)
    return 0;

    int iguais=1;
    for(int i=1; i<14; i++){
        if(numeros[i]!=numeros[0]){
            iguais=0;
            break;
        }
    }
    if(iguais)
    return 0;

    int pesos1[12]={5,4,3,2,9,8,7,6,5,4,3,2};
    int pesos2[13]={6,5,4,3,2,9,8,7,6,5,4,3,2};
    
    int soma=0;
    for(int i=0; i<12; i++){
        soma+=(numeros[i]-'0')*pesos1[i];
    }
    int dig1=soma%11;
    dig1=(dig1<2)?0:(11-dig1);

    if(dig1!=(numeros[12]-'0'))
    return 0;

    soma=0;     //numero 2
    for(int i=0;i<13;i++){
        soma+=(numeros[i]-'0')*pesos2[i];
    }
    int dig2=soma%11;
    dig2=(dig2<2)?0:(11-dig2);

    if(dig2!=(numeros[13]-'0'))
    return 0;

    return 1;
}

int validarTelefone(const char *tel) {
    int len = strlen(tel);
    if (len < 8 || len > 15) return 0;

    for (int i = 0; i < len; i++) {
        if (!isdigit(tel[i])) return 0;
    }
    return 1;
}

int validarEmail(const char *email) {
    int len = strlen(email);
    if (len < 5) return 0;

    int achouArroba = 0, achouPonto = 0;

    for (int i = 0; i < len; i++) {
        if (email[i] == '@') achouArroba = 1;
        if (email[i] == '.' && achouArroba) achouPonto = 1;
    }

    return achouArroba && achouPonto;
}

int validarTexto(const char *s) {
    if (strlen(s) < 2) return 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!isalpha(s[i]) && s[i] != ' ')
            return 0;
    }
    return 1;
}

//Aqui ele valida todos os processos de cadastro do cliente, verifica se o cpf ou o cnpj é valido, verifica se o numero de telefone é valido, e se o gmail do cliente é valido