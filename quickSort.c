#include <stdio.h>
#include <stdlib.h>

void trocaDeLugar(double vetor[], int v, int t)
{

    double auxiliar = vetor[v];
    vetor[v] = vetor[t];
    vetor[t] = auxiliar;

}

int particiona(double vetor[], int comeco, int final)
{

    int pivoDoIndice;
    double pivo;

    pivo = vetor[final]; 
    pivoDoIndice = comeco;

    for (int i = comeco; i < final; i++)
    {
        
        if (vetor[i] <= pivo)
        {
            
            trocaDeLugar(vetor, i, pivoDoIndice);
            
            pivoDoIndice++;
        }
    }

    
    trocaDeLugar(vetor, pivoDoIndice, final);

    
    return pivoDoIndice;

}

void quickSort(double vetor[], int comeco, int final)
{

    if (comeco < final)
    {
        
        int pivoDoIndice = particiona(vetor, comeco, final);

        
        quickSort(vetor, comeco, pivoDoIndice - 1);
        quickSort(vetor, pivoDoIndice + 1, final);
    }

}

int main(int argc, char* argv[])
{

    int i, j, n, k, c;
    double r;
    double* notas;

    // lendo o número de vagas oferecidas
    scanf("%d", &n);

    i = 0;
    while (i != n) {

        // lendo a quantidade de pessoas que, potencialmente, serão chamadas para a segunda fase
        scanf("%d", &k);

        // lendo o número de candidatos que concorreram à vaga
        scanf("%d", &c); 

        notas = malloc(c * sizeof(double));

        for (j = 0; j < c; j++) {

            // lendo a nota de cada candidato
            scanf("%lf", &r);

            notas[j] = r;

        }

        // ordenando o vetor
        quickSort(notas, 0, c - 1);
        
        // pegando a k_ésima maior nota
        printf("%.2lf\n", notas[c - k]);

        i++;
    }

    return 0;

}