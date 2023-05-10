#include <stdio.h> //comunica��o com o usuario
#include <stdlib.h> // aloca��o de mem�ria
#include <locale.h> // aloca��es de texto por regi�o
#include <string.h> // strings

// Fun��es

int registro() // resgistro
{
	//variaveis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese"); // seleciona a linguagem
		
	printf("\nVoc� escolheu a op��o REGISTRAR NOMES! \n"); // coleta de informa��es 
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

	printf("\nVoc� escolheu a op��o CONSULTAR NOMES! \n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("N�o foi poss�vel consultar! CPF n�o localizado.\n");		
	}
	

	while ( fgets(consulta, 200, file) != NULL) // pega as informa��es do arquivo
	{
		printf("Essas s�o as informa��es: \n");
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
	
	printf("\nVoc� escolheu a op��o DELETAR NOMES! \n");
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("Usuario n�o encontrado!\n");
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
	
	printf("	Cart�rio da EBAC	\n\n");
	printf("Login de Admim \n\n Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if (comparacao == 0)
	{
		
		
		//la�o
		for (laco =1; laco= 1;)
		{
			setlocale(LC_ALL, "Portuguese");
			
			//limpa tela
			system("cls");		
			
			//Menu
			printf("	Cart�rio da EBAC	\n\n");
			printf("   Escolha uma das op��es abaixo: \n\n");
			
			//Limguagem
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar   Nomes\n");
			printf("\t4 - Sair do Sistema\n");
			printf("	Op��o: ");
			
			// Defini��es dps valores
			scanf("%d", &opcao);
		
			//Limpa a tela
			system("cls");
			
			// Tomada de decis�o
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
				 printf("\n\tOp��o n�o d�sponivel! \n");
				 system("pause");
				 break;
			}
			
		}
	}
	else
		printf("Senha incorreta!");
}

