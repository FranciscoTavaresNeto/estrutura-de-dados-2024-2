#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int dia,mes,ano;
}Data;

const Data Hoje = {04,10,2024};

typedef struct endereco{
    char nomeRua [20];
    int numero;
    int cep;
}Endereco;


typedef struct pessoa{
    int cod;
    char nome [10];
    char sobrenome [20];
    int idade;
    char telefone [15];
    Data nascimento;
    Endereco *endereco;  //ponteiro de Endereço
}Pessoa;


void imprimeEndereco(Endereco end){
    printf(" Endereco: %s %d ",end.nomeRua,end.numero);
    printf("\n CEP: %d \n",end.cep);
}

void imprimePessoa(Pessoa novaPessoa){
    printf("\n Código %d ",novaPessoa.cod);
    printf("\n Nome: %s %s",novaPessoa.nome,novaPessoa.sobrenome);
    printf("\n Idade: %d e Telefone: %s ",novaPessoa.idade,novaPessoa.telefone);
    printf("\n Data de Nascimento: %d/%d/%d \n",
         novaPessoa.nascimento.dia,novaPessoa.nascimento.mes,novaPessoa.nascimento.ano);
    imprimeEndereco(*novaPessoa.endereco);
};





int calcularIdade(Pessoa pessoa){
    int idade = Hoje.ano - pessoa.nascimento.ano;
    if(Hoje.mes < pessoa.nascimento.mes)
        idade--;
    else{
        if(Hoje.mes == pessoa.nascimento.mes)
            if(Hoje.dia < pessoa.nascimento.dia)
                idade--;
    }
    //printf("\n Idade= %d",idade);
    
    return idade;
}

void atualizaIdade(Pessoa *pessoa){
    //ponteiro pessoa, referencia idade ->
    pessoa->idade = calcularIdade(*pessoa);
}

void atualizaTelefone(Pessoa *pessoa){
    printf("\n Informe o novo Telefone: ");
    scanf("%s",pessoa->telefone);
}

void preencheDadosPessoa(Pessoa *pessoa, int cod){
    Data dNascimento;
    pessoa->cod = cod;
    printf("\n Informe seu nome:");
    scanf("%s",pessoa->nome);
    printf("\n Informe seu sobrenome:");
    scanf("%s",pessoa->sobrenome);
    printf("\n Informe seu telefone:");
    scanf("%s",pessoa->telefone);
    printf("\n Informe seu dada nascimento:");
    scanf("%d %d %d",&dNascimento.dia,&dNascimento.mes,&dNascimento.ano);
    pessoa->nascimento = dNascimento;
    pessoa->idade = calcularIdade(*pessoa);
}

int main(){

    Data natal = {25,10,2000};
    Pessoa joao;
    joao.cod = 1;
    joao.idade = 50;
    strcpy(joao.nome,"Joao");
    strcpy(joao.sobrenome,"Farias de Souza");
    strcpy(joao.telefone,"5332324567");
    joao.nascimento = natal;

    //Declaração e atribuição de valores a uma Pessoa
    Pessoa maria = {2,"Maria","Aparecida",0,"53323244411",Hoje};
    
    Endereco *portugal265 = (Endereco *) malloc(sizeof(Endereco));

    strcpy(portugal265->nomeRua,"Avenida Portugual");
    portugal265->numero = 265;
    portugal265->cep = 95200130;

    joao.endereco = portugal265;
    maria.endereco = portugal265;

    imprimePessoa(joao); 
    imprimePessoa(maria); 

    joao.endereco->numero = 500;

    imprimePessoa(joao); 
    imprimePessoa(maria); 

    portugal265->numero = 265;

    imprimePessoa(joao); 
    imprimePessoa(maria); 

    /*    
    //imprimePessoa(joao);    
    
    //atualizaIdade(&joao);
    //atualizaTelefone(&joao);

    imprimePessoa(joao);

    atualizaIdade(&maria);
    imprimePessoa(maria);

    Pessoa nova;
    preencheDadosPessoa(&nova,3);
    imprimePessoa(nova);

    //Qualquer é Ponteiro
    Pessoa *qualquer;
    
    qualquer = &maria;

    imprimePessoa(*qualquer);

    qualquer = &joao;

    imprimePessoa(*qualquer);
    atualizaTelefone(qualquer);
    imprimePessoa(*qualquer);

    //Atribuir Null ao Ponteiro
    qualquer = NULL;

    //Alocação dinâmica
    qualquer = (Pessoa *)malloc (sizeof(Pessoa));
    
    preencheDadosPessoa(qualquer,4);

    imprimePessoa(*qualquer);

    //Liberar a memoria FREE
    free(qualquer);

    imprimePessoa(*qualquer);
*/

















}


