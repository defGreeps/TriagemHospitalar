#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PACIENTES 50

typedef struct
{ // Estrutura de dados do paciente para facilitar os cadastros e atualização de dados
  int id;
  char nome[100];
  int idade;
  float temperatura;
  int nivel_dor;
  int prioridade;
} Paciente;
  
void Cadastro(Paciente lista[], int *total);
void Dados(Paciente lista[], int total);
int Consulta(Paciente lista[], int id, int total);
void Estatisticas(Paciente lista[],int total);

int main()
{ // Menu principal
  // variáveis
  int opcao;
  bool menu = true;
  float temperatura;
  int nivel_dor;

  int total_pacientes = 0; // Variável para controlar o número total de pacientes cadastrados, iniciada em 0

  Paciente lista_pacientes[MAX_PACIENTES]; // Declaração do vetor dos pacientes, que armazenará o tipo Paciente (com limite de 50 pacientes)

  // menu
  do
  {
    printf("1) Cadastro de Pacientes\n");
    printf("2) Dados de Triagem\n");
    printf("3) Estatísticas\n");
    printf("4) Finalizar Programa\n\n");

    printf("Escolha uma opção: \n\n");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1: // Leva para o menu de Cadastro
      Cadastro(lista_pacientes, &total_pacientes);
      break;

    case 2: // Leva para o menu de preenchimento de Dados
      Dados(lista_pacientes, total_pacientes);
      break;

    case 3: // Leva para o menu de estatísticas, onde ficam armazenadas as informações sobre os pacientes
      Estatisticas(lista_pacientes, total_pacientes);
      break;

    case 4: // Encerra o programa
      menu = false;
      break;

    default: // Caso digite um número fora das opções
      if (!(opcao >= 1 && opcao <= 4))
      {
        printf("Número inválido, tente novamente");
      }
      break;
    }
  } while (menu);

  return 0;
}

void Cadastro(Paciente lista[], int *total)
{ // Menu de Cadastro

  int opcao;
  bool menu1 = true;
  int i;

  Paciente novo_paciente;

  // menu cadastros
  do
  {
    printf("1) Realizar cadastro de paciente\n");
    printf("2) Realizar mudança no cadastro de um paciente\n");
    printf("3) Voltar ao menu principal\n\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    while (getchar() != '\n')
      ;

    switch (opcao)
    {

    case 1: // cadastro
      printf("Escreva o nome do paciente: \n");
      fgets(novo_paciente.nome, 100, stdin);                     // Escreve o nome do paciente em até 100 caractéres
      novo_paciente.nome[strcspn(novo_paciente.nome, "\n")] = 0; // Faz com que o formato fgets ignore os "/n" escritos na linha para que não apareçam no produto final

      printf("Escreva a idade do paciente: \n");
      scanf("%d", &novo_paciente.idade);

      novo_paciente.id = *total + 1; // O ID de um paciente é determinado pela sua ordem de chegada, começando por 1 e indo até 50, essa função adiciona esses numerais
      printf("Cadastrando Paciente ID: %d\n", novo_paciente.id);
      lista[*total] = novo_paciente; // Adiciona o paciente na lista, junto de seu ID para que possa ser identificado depois
      (*total)++;

      //ListaDebug(lista, *total);
      break;

    case 2: // alterar cadastro
      if (*total == 0)
      { // Caso não tenha pacientes registrados
        printf("Não há pacientes registrados.\n\n");
        break;
      }

      int id_busca;
      printf("Insira a ID do paciente: ");
      scanf("%d", &id_busca);

      while (getchar() != '\n')
        ; // Previne erro na escrita caso um valor incorreto seja detectado

      int indice_encontrado = -1; // O total de IDs válidas sempre irá ser maior ou igual a 1, mas pelo "i" sempre começar em 0 usamos essa subtração para equivaler o valor do total com o código

      for (i = 0; i < *total; i++)
      {
        if (lista[i].id == id_busca)
        { // Procura o valor da ID na Lista para checar se existe
          indice_encontrado = i;
          break;
        }
      }

      if (indice_encontrado != -1)
      {
        printf("Insira o novo nome: \n");
        fgets(lista[indice_encontrado].nome, 100, stdin);
        lista[indice_encontrado].nome[strcspn(lista[indice_encontrado].nome, "\n")] = 0;

        int idade;
        printf("Insira a nova idade: \n");
        scanf("%d", &idade);
        lista[indice_encontrado].idade = idade;
      }
      else
      {
        printf("ID não encontrada, tente novamente\n\n");
        break;
      }
      break;

    case 3: // voltar para o menu
      menu1 = false;
      break;

    default:
      if (!(opcao >= 1 || opcao <= 4))
      {
        printf("Número inválido, tente novamente\n");
      }
      break;
    }
  } while (menu1);
};

/*void ListaDebug(Paciente lista[], int total) // Função usada só para testar a funcionalidade do código
{
  int i;
  for (i = 0; i < total; i++)
  {
    printf("ID: %d, Nome: %s, Idade: %d, Temperatura: %.2f, Nível de Dor: %d\n", lista[i].id, lista[i].nome, lista[i].idade, lista[i].temperatura, lista[i].nivel_dor);
  }
};*/

void Dados(Paciente lista[], int total)
{

  int opcao;
  int i;
  bool menu = true;
  float temperatura;
  int nivel_dor;

  Paciente novo_paciente;

  do
  {
    printf("1) Registre os dados do paciente\n");
    printf("2) Atualize os dados do paciente\n");
    printf("3) Voltar ao menu principal\n\n");

    printf("Escolha uma opção: \n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1: // Determinar a temperatura do paciente e seu nível de dor

      if (total == 0)
      { // Caso não tenha pacientes registrados
        printf("Não há pacientes registrados.\n\n");
        break;
      }

      int id_busca;
      printf("Insira a ID do paciente: \n");
      scanf("%d", &id_busca);

      while (getchar() != '\n')
        ; // Previne erro na escrita caso um valor incorreto seja detectado

      int indice_encontrado = -1; // O total de IDs válidas sempre irá ser maior ou igual a 1, mas pelo "i" sempre começar em 0 usamos essa subtração para equivaler o valor do total com o código

      printf("id_busca: %d\n", id_busca);
      printf("total: %d\n", total);

      for (i = 0; i < total; i++)
      {
        if (lista[i].id == id_busca)
        { // Procura o valor da ID na Lista para checar se existe
          indice_encontrado = i;
          break;
        }
      }

      if (indice_encontrado == -1)
      {
        printf("ID não encontrada, tente novamente\n\n");
        break;
      }

      printf("Digite a temperatura do paciente: \n");
      scanf("%f", &temperatura);

      if (temperatura < 36.0 || temperatura > 40.0)
      { // Caso a temperatura seja menor que 36 °C ou maior que 40°C considera como inválido
        printf("Valor inválido, insira um número entre 36.0 e 40.0\n\n");
        break;
      }

      printf("Em uma escala de 1 a 10, qual seu nível de dor?: \n");
      scanf("%d", &nivel_dor);

      if (nivel_dor < 1 || nivel_dor > 10)
      {
        printf("Valor fora dos parâmetros, tente novamente\n\n");
        break;
      }
      
      lista[indice_encontrado].temperatura = temperatura;
      lista[indice_encontrado].nivel_dor = nivel_dor;
      lista[indice_encontrado].prioridade = Consulta(lista, lista[indice_encontrado].id, total);
      //ListaDebug(lista, total);

      break;

    case 2: // atualizar dados do paciente
      if (total == 0)
      { // Caso não tenha pacientes registrados
        printf("Não há pacientes registrados.\n\n");
        break;
      }

      printf("Insira a ID do paciente: \n");
      scanf("%d", &id_busca);

      while (getchar() != '\n')
        ; // Previne erro na escrita caso um valor incorreto seja detectado

      indice_encontrado = -1; // O total de IDs válidas sempre irá ser maior ou igual a 1, mas pelo "i" sempre começar em 0 usamos essa subtração para equivaler o valor do total com o código

      printf("id_busca: %d\n", id_busca);
      printf("total: %d\n", total);

      for (i = 0; i < total; i++)
      {
        printf("item %d: %d\n", i, lista[i].id);
        if (lista[i].id == id_busca)
        { // Procura o valor da ID na Lista para checar se existe
          indice_encontrado = i;
          break;
        }
      }

      printf("indice_encontrado: %d\n", indice_encontrado);

      if (indice_encontrado == -1)
      {
        printf("ID não encontrada, tente novamente\n\n");
        break;
      }

      printf("Digite a nova temperatura do paciente: \n");
      scanf("%f", &temperatura);

      if (temperatura < 36.0 || temperatura > 40.0)
      { // Caso a temperatura seja menor que 36 °C ou maior que 40°C considera como inválido
        printf("Valor inválido, insira um número entre 36.0 e 40.0\n\n");
        break;
      }

      printf("Em uma escala de 1 a 10, qual seu novo nível de dor?: \n");
      scanf("%d", &nivel_dor);

      if (nivel_dor < 1 || nivel_dor > 10)
      {
        printf("Valor fora dos parâmetros, tente novamente\n\n");
        break;
      }
      
      lista[indice_encontrado].temperatura = temperatura;
      lista[indice_encontrado].nivel_dor = nivel_dor;
      lista[indice_encontrado].prioridade = Consulta(lista, lista[indice_encontrado].id, total);

      break;

    case 3: // Voltar para o menu
      menu = false;
      break;

    default:
      if (!(opcao >= 1 || opcao <= 4))
      {
        printf("Número inválido, tente novamente\n");
      }
      break;
    }
  } while (menu);
};

int Consulta(Paciente lista[], int id, int total)
{
  int i;
  float temperatura;
  int nivel_dor;
  int prioridade;
  printf("Total: %d\n", total);
  
    for (i = 0; i < total; i++)
    {
      printf("ID: %d, Temperatura: %.2f, Nível de Dor: %d\n", lista[i].id, lista[i].temperatura, lista[i].nivel_dor);
      if (lista[i].id == id)
      {
        if ((lista[i].temperatura >= 39 && lista[i].temperatura <= 40) || (lista[i].nivel_dor >= 9 && lista[i].nivel_dor <= 10)){
          prioridade = 4;
        }
        else if ((lista[i].temperatura >= 38 && lista[i].temperatura < 39) || (lista[i].nivel_dor >= 7 && lista[i].nivel_dor < 9)){
          prioridade = 3;
        }
        else if (lista[i].nivel_dor >= 5 && lista[i].nivel_dor < 7){
          prioridade = 2;
        } else {
          prioridade = 1;
        }
      }
    }
    return prioridade;
}

void Estatisticas(Paciente lista[], int total)
{
  int i;
  int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

  printf("Tabela de Valores\n");
    printf("Nível 1) Prioridade Minima.\n");
    printf("Nível 2) Prioridade Baixa\n");
    printf("Nível 3) Prioridade Alta\n");
    printf("Nível 4) Emergência.\n");
  for (i = 0; i < total; i++)
  {
    
    if (lista[i].prioridade == 1){
      p1++;
    }
    
    if (lista[i].prioridade == 2){
      p2++;
    }
    if (lista[i].prioridade == 3){
      p3++;
    }
    if (lista[i].prioridade == 4){
      p4++;
    }
    printf("ID: %d, Nome: %s, Idade: %d, Temperatura: %.2f, Nível de Dor: %d, Prioridade: %d\n", lista[i].id, lista[i].nome, lista[i].idade, lista[i].temperatura, lista[i].nivel_dor, lista[i].prioridade);
  }
  printf("\nO total de pacientes em nível de Prioridade Minima é de: %d\n", p1);
  printf("\nO total de pacientes em nível de Prioridade Baixa é de: %d\n", p2);
  printf("\nO total de pacientes em nível de Prioridade Alta é de: %d\n ", p3);
  printf("\nO total de pacientes em nível de Emergência é de: %d\n", p4);
  printf("\nTotal de pacientes: %d\n", total);
};
