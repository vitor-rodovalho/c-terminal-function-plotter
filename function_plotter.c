#include <stdio.h>
#include <math.h>

/*
Nota sobre o programa:
Gráficos que são muito verticais ou horizontais encontram problemas de representação, devido a impossibilidade
de fazer a mudança de linhas ou colunas de maneira suave no terminal.
*/

// Precisão/densidade da curva (int)
#define D 100

/*
Dimensões da tela (int) 
Alterar tais valores afeta a proporção e visualização do gráfico
*/
#define M 50
#define N 50

/*
Posiciona o gráfico na tela (double)
Quando xi tende a 0, o eixo y tende à esquerda da tela das dimensões utilizadas do terminal
Quando xi tende a -L, o eixo y tende à direita da tela das dimensões utilizadas do terminal
Quando yi tende a 0, o eixo x tende à primeira linha da tela das dimensões utilizadas do terminal
Quando yi tende a A, o eixo x tende à última linha da tela das dimensões utilizadas do terminal
O meio, nas dimensões utilizadas, se localiza em xi = -5.0 e yi = 5.0
*/
#define xi -15.0
#define yi 15.0

/*
Dimensões do plano(double)
Funciona como um zoom in, ao diminuir ambos os valores, e zoom out, ao aumentar ambos os valores
O padrão é A = 10.0 e L = 10.0, a mudança das dimensões também muda a localização da origem do gráfico
Para movimentar a origem novamente para o centro da proporção, altere os valores de xi e yi para a metade dos valores de A e L
*/
#define A 30.0
#define L 30.0

/*
Criação da matriz que vai representar o plano cartesiano 
As linhas e as colunas são as dimensões da tela definidas anteriormente
*/
char mat[M][N];

// Vetor global que possibilita a escolha de coeficientes em funções polinomiais
double coeficientes[3];

// Variável global que é a escolha de qual função o usuário quer utilizar
int escolha;

// Protótipos das funções cridas
double f(double x);
void clean(void);
void mark(double x, double y, char c);
void axis(void);
void graph(void);
void print(void);
void red(void);
void yellow(void);
void green(void);
void blue(void);
void purple(void);
void cyan(void);
void reset(void);

/*
Função principal que roda o menu de seleção de funções do programa e também chama as funções criadas
Primeiro a função clean() é chamada, para limpar a matriz de qualquer resquício de memória
Depois é chamada a função axis(), que vai salvar os eixos dentro da matriz
Em terceiro vem a função graph(), que vai efetivamente salvar o esboço do gráfico escolhido
E, por fim, é chamada a função print(), que vai apenas exibir a matriz, ou no caso, o gráfico 
*/  
int main() {

    // Menu de escolhas das funções, caso for 0, o programa para de rodar
    do {

        // Opções de funções abrangidas pelo programa devem ser escritas aqui
        printf("Digite 1 para funcao afim, expressao \"f(x) = ax + b\";\n");
        purple();
        printf("Digite 2 para funcao modular, expressao \"f(x) = |ax + b|\";\n");
        blue();
        printf("Digite 3 para funcao de segundo grau, expressao \"f(x) = ax^2 + bx + c\";\n");
        cyan();
        printf("Digite 4 para funcao de terceiro grau, expressao \"f(x) = ax^3 + bx^2 + cx\";\n");
        green();
        printf("Digite 5 para funcao seno, expressao \"f(x) = a * sen(x)\";\n");
        yellow();
        printf("Digite 6 para funcao cosseno, expressao \"f(x) = a * cos(x)\";\n");
        red();
        printf("Digite 7 para funcao tangente, expressao \"f(x) = a * tan(x)\";\n");
        purple();
        printf("Digite 8 para funcao exponencial, expressao \"f(x) = a * e^x\";\n");
        blue();
        printf("Digite 9 para funcao logaritmica na base 10, expressao \"f(x) = a * log(x)\";\n");
        red();
        printf("Ou digite 0 para finalizar o programa.\n");
        reset();

        scanf("%d", &escolha);

        switch (escolha)
        {

        case 0:
        // A opção 0 finaliza o programa

            red();
            printf("Voce digitou 0, entao o programa sera finalizado.\n");
            reset();
            break;

        
        case 1:
        // Função Afim

            printf("Voce digitou 1 e escolheu a opcao de Funcao Afim.\n");
            printf("Digite os valores de \"a\" e de \"b\", separados por espaco:\n");
            green();
            scanf("%lf %lf", &coeficientes[0], &coeficientes[1]);
            reset();
            break;


        case 2:
        // Função Modular

            printf("Voce digitou 2 e escolheu a opcao de Funcao Modular.\n");
            printf("Digite os valores de \"a\" e de \"b\", separados por espaco:\n");
            green();
            scanf("%lf %lf", &coeficientes[0], &coeficientes[1]);
            reset();
            break;


        case 3:
        // Função de Segundo Grau

            printf("Voce digitou 3 e escolheu a opcao de Funcao de Segundo Grau.\n");
            printf("Digite os valores de \"a\", \"b\" e \"c\", separados por espaco:\n");
            green();
            scanf("%lf %lf %lf", &coeficientes[0], &coeficientes[1], &coeficientes[2]);
            reset();
            break;


        case 4:
        // Função de Terceiro Grau

            printf("Voce digitou 4 e escolheu a opcao de Funcao de Terceiro Grau.\n");
            printf("Digite os valores de \"a\", \"b\" e \"c\", separados por espaco:\n");
            green();
            scanf("%lf %lf %lf", &coeficientes[0], &coeficientes[1], &coeficientes[2]);
            reset();
            break;


        case 5:
        // Função Seno

            printf("Voce digitou 5 e escolheu a opcao de Funcao Seno.\n");
            printf("Digite o valor de \"a\":\n");
            green();
            scanf("%lf", &coeficientes[0]);
            reset();
            break;


        case 6:
        // Função Cosseno

            printf("Voce digitou 6 e escolheu a opcao de Funcao Cosseno.\n");
            printf("Digite o valor de \"a\":\n");
            green();
            scanf("%lf", &coeficientes[0]);
            reset();
            break;


        case 7:
        // Função Tangente

            printf("Voce digitou 7 e escolheu a opcao de Funcao Tangente.\n");
            printf("Digite o valor de \"a\":\n");
            green();
            scanf("%lf", &coeficientes[0]);
            reset();
            break;


        case 8:
        // Função Exponencial

            printf("Voce digitou 8 e escolheu a opcao de Funcao Exponencial.\n");
            printf("Digite o valor de \"a\":\n");
            green();
            scanf("%lf", &coeficientes[0]);
            reset();
            break;


        case 9:
        // Função Logarítimica

            printf("Voce digitou 9 e escolheu a opcao de Funcao Logaritmica.\n");
            printf("Digite o valor de \"a\":\n");
            green();
            scanf("%lf", &coeficientes[0]);
            reset();
            break;

        }


        // Impossibilita o programa de rodar o gráfico ao escolher finalizar (opção 0)
        if (escolha == 0) break;

        else{
            clean();
            axis();
            graph();
            print();
            printf("\n\n");
        }

    } while (escolha != 0);

}



// Função de cálculo das funções matemáticas abrangidas pelo programa
// OBS.: cada função criada deve ser armazenada aqui
double f(double x) {

    switch (escolha){

        case 0: 
        // Finaliza a função

            return 0;
            break;


        case 1:
        // Retorna o resultado de ax + b

            return (coeficientes[0] * x) + coeficientes[1];
            break;


        case 2:
        // Retorna o resultado de |ax + b|

            return fabs((coeficientes[0] * x) + coeficientes[1]);
            break;


        case 3:
        // Retorna o resultado de ax² + bx + c

            return (coeficientes[0] * pow(x, 2)) + (coeficientes[1] * x) + coeficientes[2];
            break;


        case 4:
        // Retorna o resultado de ax³ + bx² + cx

            return (coeficientes[0] * pow(x, 3)) + (coeficientes[1] * pow(x, 2)) + (coeficientes[2] * x);
            break;


        case 5:
        // Retorna o resultado de a * sen(x)

            return coeficientes[0] * sin(x);
            break;


        case 6:
        // Retorna o resultado de a * cos(x)

            return coeficientes[0] * cos(x);
            break;


        case 7:
        // Retorna o resultado de a * tan(x)

            return coeficientes[0] * tan(x);
            break;


        case 8:
        // Retorna o resultado de a * e^x

            return coeficientes[0] * exp(x);
            break;


        case 9: 
        // Retora o resultado de a * log(x)

            // Validação de segurança para Logaritmo
            if (x <= 0) {
                // Retorna um valor que ficará fora da tela e será ignorado pelo mark()
                return -99999.0; 
            }

            return coeficientes[0] * log10(x);
            break;


        default:

            return 0;
            break;
    }

}



/*
Função que limpa a matriz, atribuindo um espaço em todos os seus itens, antes de utilizá-la
Esta função é do tipo "void" pois não retorna nenhum valor
*/
void clean(void) {
    
    // Essa dupla de for, tendo i e j percorrendo todos os valores até M - 1 e N - 1, vai acessar todos os itens da matriz
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = ' ';
        }
    }

}



// Função que calcula a correspondência dos pontos x e y do plano cartesiano em colunas e linhas, respectivamente
void mark(double x, double y, char c) {

    // Manipualações algébricas para encontrar funções lineares que abranjam todo o intervalo da matriz
    int i = (M - 1)  * ((yi - y) / A);
    int j = (N - 1)  * ((x - xi) / L);

    // Quando os valores calculados são positivos e estão dentro dos limites definidos nas dimensões da tela, o caractere é registrado na matriz
    if ((0 <= i) && (i < M) && (0 <= j) && (j < N)) {
        mat[i][j] = c;
    }

}



// Função que salva os eixos x e y nos devidos índices na matriz
void axis(void) {

    /* Em um determinado pedaço do gráfico, temos na teoria infinitos pontos
    Embora neste caso o terminal não tenha infinitos pontos, precisamos dividir esse intervalo em pontos que utilizaremos
    O intervalo do eixo x é definido [xi, xi + L], e o do eixo y é [yi, yi - A]
    De certa forma, então os intervalos têm tamanhos L e A, que são as dimensões do plano
    Então se dividirmos cada ponto desse intervalo L por K, cada ponto tem um tamanho L/K
    A questão é que se o K escolhido for pequeno, o gráfico se torna mais impreciso
    Então por isso o divisor escolhido é (D * N (ou M)), para o D servir como um multiplicador, aumentando o número de pontos calculados
    Mesmo que o terminal tenha um limite de 1 caractere por espaço vazio
    */
    double dx = L / (D * N);
    double dy = A / (D * M);

    // Mesmo com o limitador de pontos do terminal, i vai até (D * N) para garantir a precisão desejada
    for (int i = 0; i <= D * N; i++) {

        // O valor inicial xi é acrescido do iésimo ponto dentro do intervalo L, como explicado anteriormente
        double x = xi + (i * dx);

        // Aqui o eixo X é finalmente desenhado na memória da matriz
        mark(x, 0.0, '-');

    }


    // Mesmo com o limitador de pontos do terminal, i vai até (D * M) para garantir a precisão desejada
    for (int i = 0; i <= D * M; i++) {

        // O valor yi é decrescido do iésimo ponto, já que o eixo y vai de cima para baixo
        double y = yi - (i * dy);

        // Aqui o eixo Y é finalmente desenhado na memória da matriz
        mark(0.0, y, '|');

    }

    // Aqui a origem é sobrescrita, após o eixo x e y terem sido salvos, na origem [0, 0]
    mark(0.0, 0.0, '+');

}



// Função que vai de fato esboçar o gráfico
void graph(void) {

    // Da mesma forma definida anteriormente, pega o valor de cada 
    double dx = L / (D * N);

    /*
    Com este for, todos os pontos da matriz, com a precisão desejada, vão ser percorridos
    E todos os itens da matriz que tiverem correspondência gráfica serão salvos como "o", caractere que desenhará o esboço
    */
    for (int i = 0; i < D * N; i++) {
        double x = xi + (i * dx);
        mark(x, f(x), 'o');
    }
}



// Função que vai printar cada item da matriz, após ela ter sido processada pelas outras funções
void print(void) {

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }

}



// Funções para a alteraçõo das cores dos printf
void red () {
  printf("\033[1;31m");
}

void yellow (){
  printf("\033[1;33m");
}

void green (){
  printf("\033[0;32m");
}

void blue (){
  printf("\033[0;34m");
}

void purple (){
  printf("\033[0;35m");
}

void cyan (){
  printf("\033[0;36m");
}

void reset () {
  printf("\033[0m");
}