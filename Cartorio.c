#include <stdio.h> //comunicação com o usuario
#include <stdlib.h> // alocação de memória
#include <locale.h> // alocações de texto por região
#include <string.h> // strings

// Funções

int registro() // resgistro
{
	//variaveis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese"); // seleciona a linguagem
		
	printf("\nVocê escolheu a opção REGISTRAR NOMES! \n"); // coleta de informações 
	printf("Digite o CPF a ser registrado: ");
	scanf("%s", cpf); // %s = strings
	
	strcpy(arquivo, cpf); // copia o conteudo das strings

	FILE *file; // cria o arquivo
	file = fopen (arquivo, "w"); // w - write
	fprintf(file, "CPF: " ); // altera o conteudo
	fprintf(file, cpf);
	fclose(file); // fecha
	
	
	printf("Digite o nome a ser Registrado: ");
	scanf("%s", nome);
	
	file = fopen (arquivo, "a"); // a - att
	fprintf(file, " - NOME: ");
	fprintf(file, nome);
	fclose(file);
		
	printf("Digite o sobrenome a ser registrado: ");
	scanf("%s", sobrenome);
		
	file = fopen (arquivo, "a");
	fprintf(file, " - SOBRENOME: ");
	fprintf(file, sobrenome);	
	fclose(file);
	
	printf("Digite o cargo do registrado: ");
	scanf("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file," - CARGO: ");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");	
}

int consulta() // consulta
{
	// variaveis
	char cpf[40];
	char consulta[200];
	
	setlocale(LC_ALL, "Portuguese");

	printf("\nVocê escolheu a opção CONSULTAR NOMES! \n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Não foi possível consultar! CPF não localizado.\n");		
	}
	

	while ( fgets(consulta, 200, file) != NULL) // pega as informações do arquivo
	{
		printf("Essas são as informações: \n");
		printf("%s", consulta);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");		
}

int deletar() // deletar
{
	// variaveis
	char cpf[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\nVocê escolheu a opção DELETAR NOMES! \n");
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("Usuario não encontrado!\n");
	}
	else 
	{
		printf("Usuario deletado com sucesso!\n");
	}
	
	fclose(file);
	
	remove(cpf); // deleta o arquivo
	
	system("pause");	
	
}

int main()
{
	//variaveis
	int opcao = 0;
	int laco = 1;
	char senhadigitada[10] = "a";
	int comparacao = 0;
	
	printf("	Cartório da EBAC	\n\n");
	printf("Login de Admim \n\n Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if (comparacao == 0)
	{
		
		
		//laço
		for (laco =1; laco= 1;)
		{
			setlocale(LC_ALL, "Portuguese");
			
			//limpa tela
			system("cls");		
			
			//Menu
			printf("	Cartório da EBAC	\n\n");
			printf("   Escolha uma das opções abaixo: \n\n");
			
			//Limguagem
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar   Nomes\n");
			printf("\t4 - Sair do Sistema\n");
			printf("	Opção: ");
			
			// Definições dps valores
			scanf("%d", &opcao);
		
			//Limpa a tela
			system("cls");
			
			// Tomada de decisão
			switch(opcao)
			{
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;				
				
				case 4:
				printf("Obrigado por utlizar nosso sistema!");
				return 0;
				break;
				
				default:
				 printf("\n\tOpção não dísponivel! \n");
				 system("pause");
				 break;
			}
			
		}
	}
	else
		printf("Senha incorreta!");
}

