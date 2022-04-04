#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct conj{
    char par[11];
    struct conj *luva;
}conj;

conj *estalo = NULL; 
int impar = 0;

void cpf(char *par){ //adicionar sempre no fim da lista, logo após adicionar, recebe null
    int pessoa = impar;
    conj *joia = malloc(sizeof(conj));
    strcpy (joia->par, par);
    joia->luva = NULL;

    
    if(pessoa == 0){ // estalo: vazia ou ter elementos

        joia->luva = estalo;
        estalo = joia;

    }else{

        conj *thanos = estalo;
        for(int i=0; i<pessoa -1; i++){
            thanos = thanos->luva;
        }
        joia->luva = thanos->luva;
        thanos->luva = joia;
    }
        impar++;
}

void deixar_vivo_e_mostrar_o_felizardo_ou_a_felizarda(){

    conj *thanos = estalo;
    for(int i = 0; i< impar; i++){
        printf("%s ", thanos->par);
        thanos = thanos->luva;
    }printf("\n");
}

void po(int pessoa){

    if(pessoa >= 0 && pessoa < impar){

        if(pessoa == 0){ // remove no estalo
                conj *lixo = estalo;
                estalo = estalo->luva;
                free(lixo);
        }else{ // remove no fim e no meio
            conj *thanos = estalo;
            for(int i=0; i<pessoa -1; i++){
                thanos = thanos->luva;
            }
            conj *lixo = thanos->luva;
            thanos->luva = thanos->luva->luva;
            free(lixo);
        }
        impar--;
        }else{
            printf("\n ESTALO \n");
        }
}
//escolhe a metade das pessoas aleatoriamente e remove
void randEstalo(){
    int estalo1 = 0;
    int qtdpessoa = impar/2;

    for (int i = 0; i < qtdpessoa; i++)
    {
        estalo1 = rand() % impar;
        printf("%d  ",impar);
        printf("%d\n", estalo1);
        po(estalo1);
    }
}

int main(){
    cpf("47734581005");
    cpf("69536917009");
    cpf("63323513061");
    cpf("32739560036");
    cpf("27567694018");
    cpf("28159894090");
    cpf("16116555012");
    cpf("45015988087");
    cpf("28622802086");
    cpf("19351782026");
    deixar_vivo_e_mostrar_o_felizardo_ou_a_felizarda();
    randEstalo();
    deixar_vivo_e_mostrar_o_felizardo_ou_a_felizarda();

    return 0;
}