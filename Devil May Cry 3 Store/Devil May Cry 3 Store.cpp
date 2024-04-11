		#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

// Outros
int lista, blue_orbs = 14, purple_orbs = 3;
char weapons[10][20] = {{"Rebelion"}, {"Cerberus"}, {"Agni&Rudra"}, {"Nevan"}, {"Beowulf"}};
char guns[10][20] = {{"Ebony&Ivory"}, {"Shotgun"}, {"Artemis"}, {"Spiral"}, {"KalinaAnn"}};

// Menu
int chave;

// Inserir Red Orbs
float red_orbs, soma;

// Style Menu
int select_style = 1, select, chave_a = false;

// Equip Menu
int escolha_f = 0, escolha_s = 1, escolha_ff = 0, escolha_ss = 1, slot, selecionar_e, verifica_f, verifica_s;

// Guns
float custo_guns[5] = {5000, 10000, 10000, 7500, 5000};
int nivel_guns[5] = {1, 1, 1, 1, 1}, selecionar_g;

// Itens Menu
float custo_itens[7] = {250, 1000, 700, 10000, 5000, 3000, 10000};
int inventario[7] = {0, 0, 0, 0, 8, 0, 0}, selecionar_i;

// Action
int chave_b, chave_c, escolha;

int level_rebelion[3] = {0, 0, 0};
int limite_rebelion[3] = {2, 1, 1};
float preco_rebelion[3] = {2500, 10000, 20000};
char rebelion_ups[3][20] = {{"Stinger"}, {"Drive"}, {"Air-Hike"}};
char rebelion_ups_pos[1][20] = {{"Stinger:Level-2"}};

int level_cerberus[2] = {0, 0};
int limite_cerberus[2] = {1, 1};
float preco_cerberus[2] = {15000, 7500};
char cerberus_ups[2][20] = {{"Revolver:Level-2"}, {"Windmill"}};

int level_agni_rudra[3] = {0, 0, 0};
int limite_agni_rudra[3] = {2, 1, 1};
float preco_agni_rudra[3] = {10000, 7500, 20000};
char agni_rudra_ups[3][20] = {{"Jet-Stream:Level-2"}, {"Whirlwind"}, {"Air-Hike"}};
char agni_rudra_ups_pos[1][20] = {{"Jet-Stream:Level-3"}};

int level_nevan[4] = {0, 0, 0, 0};
int limite_nevan[4] = {2, 1, 1, 1};
float preco_nevan[4] = {7500, 10000, 10000, 20000};
char nevan_ups[4][30] = {{"Reverb-Shock"}, {"Bad-Rift:Level-2"}, {"Air-Raid"}, {"Volume-Up"}};
char nevan_ups_pos[1][30] = {{"Reverb-Shock:Level-2"}};

int level_beowulf[3] = {0, 0, 0};
int limite_beowulf[3] = {2, 1, 1};
float preco_beowulf[3] = {7500, 10000, 20000};
char beowulf_ups[3][20] = {{"Beast-Uppercut"}, {"Straight:Level-2"}, {"Air-Hike"}};
char beowulf_ups_pos[1][20] = {{"Rising-Dragon"}};

void menu();
void equip_menu();

int pergunta()
{
	int opcao;
	
	printf(" Will you use red orbs to buy this item?\n [1] YES\n [2] NO\n Digite: ");
	cin >> opcao;
	
	return opcao;
}
void style_menu()
{
	while(chave_a == false)
	{
		system("cls");
		printf(" -------\n| Style |\n -------\n");
		printf(" 1 -- Trickster"); if(select_style == 1){printf(" - Selecionado");};
		printf("\n 2 -- Swordmaster"); if(select_style == 2){printf(" - Selecionado");};
		printf("\n 3 -- Gunslinger");  if(select_style == 3){printf(" - Selecionado");}; 
		printf("\n 4 -- Royalguard");  if(select_style == 4){printf(" - Selecionado");};
		printf("\n 5 -- Quicksilver"); if(select_style == 5){printf(" - Selecionado");};
		printf("\n 6 -- Dopplegangar");  if(select_style == 6){printf(" - Selecionado");};
		printf("\n 7 == Sair");
		printf("\n\nDigite o numero do style que deseja equipar: ");
		cin >> select;
		
		if(select > 0 && select <= 6)
		{
			select_style = select;
		}
		else
		{
			chave_a = true;
		}
	}
	chave_a = false;
	menu();
}

void equip_menu_guns()
{
	while(slot != 4)
	{
		system("cls");
		printf(" ------------\n| Equip Menu |\n ------------\n");
		printf(" [1] Slot: %s\n [2] Slot: %s\n 3 -- Trocar para as Devil Arms\n 4 -- Sair\n\n Digite o numero que deseja alterar: ", guns[escolha_ff], guns[escolha_ss]);
		cin >> slot;
		
		if(slot == 1)
		{
			system("cls");
			for(lista = 0; lista < 5; lista++)
			{
				printf(" %d -- %s\n", lista, guns[lista]);	
			}
			
			printf("\n Digite o nuemro da arma que deseja trocar: ");
			cin >> selecionar_e;
			
			verifica_f = selecionar_e;
			
			if(selecionar_e == escolha_ff || verifica_f == escolha_ss)
			{
				system("cls");
				printf(" Voce nao pode trocar pela mesma arma dento dos slots '-'\n");
				system("pause");
			}
			else
			{
				escolha_ff = selecionar_e;
			}
		}
		else if(slot == 2)
		{
			system("cls");
			for(lista = 0; lista < 5; lista++)
			{
				printf(" %d -- %s\n", lista, guns[lista]);	
			}
			
			printf("\n Digite o nuemro da arma que deseja trocar: ");
			cin >> selecionar_e;
			
			verifica_s = selecionar_e;
			
			if(selecionar_e == escolha_ss || verifica_s == escolha_ff)
			{
				system("cls");
				printf(" Voce nao pode trocar pela mesma arma dento dos slots '-'\n");
				system("pause");
			}
			else
			{
				escolha_ss = selecionar_e;
			}
		}
		else if(slot == 3)
		{
			equip_menu();
		}
		else
		{
			slot = 0;
			menu();
		}
	}
}
void equip_menu()
{
	while(slot != 4)
	{
		system("cls");
		printf(" ------------\n| Equip Menu |\n ------------\n");
		printf(" [1] Slot: %s\n [2] Slot: %s\n 3 -- Trocar para as armas\n 4 -- Sair\n\n Digite o numero que deseja alterar: ", weapons[escolha_f], weapons[escolha_s]);
		cin >> slot;
		
		if(slot == 1)
		{
			system("cls");
			for(lista = 0; lista < 5; lista++)
			{
				printf(" %d -- %s\n", lista, weapons[lista]);	
			}
			
			printf("\n Digite o nuemro da arma que deseja trocar: ");
			cin >> selecionar_e;
			
			verifica_f = selecionar_e;
			
			if(selecionar_e == escolha_f || verifica_f == escolha_s)
			{
				system("cls");
				printf(" Voce nao pode trocar pela mesma arma dento dos slots '-'\n");
				system("pause");
			}
			else
			{
				escolha_f = selecionar_e;
			}
		}
		else if(slot == 2)
		{
			system("cls");
			for(lista = 0; lista < 5; lista++)
			{
				printf(" %d -- %s\n", lista, weapons[lista]);	
			}
			
			printf("\n Digite o nuemro da arma que deseja trocar: ");
			cin >> selecionar_e;
			
			verifica_s = selecionar_e;
			
			if(selecionar_e == escolha_s || verifica_s == escolha_f)
			{
				system("cls");
				printf(" Voce nao pode trocar pela mesma arma dento dos slots '-'\n");
				system("pause");
			}
			else
			{
				escolha_s = selecionar_e;
			}
		}
		else if(slot == 3)
		{
			equip_menu_guns();
		}
		else
		{
			slot = 0;
			menu();
		}
	}
}

void item_menu()
{
	while(selecionar_i <= 6)
	{
		system("cls");
	    printf(" HP: ");
	    for(lista = 0; lista < blue_orbs; lista++)
		{
			if(lista == 10)
			{
				printf("\n     ");
			}
			printf("-");
		}
		printf("\n DT: ");
	 	for(lista = 0; lista < purple_orbs; lista++)
		{
			printf("*");
		}
		printf("\n -------\n| Itens |		| %.0f Red Orbs |\n -------\n", red_orbs);
		printf(" 0 -- Vital Star S - %.0f Red Orbs - %d/30 No inventario\n", custo_itens[0], inventario[0]);
		printf(" 1 -- Vital Star L - %.0f Red Orbs - %d/30 No inventario\n", custo_itens[1], inventario[1]);
		printf(" 2 -- Devil Star - %.0f Red Orbs - %d/30 No inventario\n", custo_itens[2], inventario[2]);
		printf(" 3 -- Holy Water - %.0f Red Orbs - %d/3 No inventario\n", custo_itens[3], inventario[3]);
		printf(" 4 -- Blue Orb - %.0f Red Orbs - %d/14 No inventario\n", custo_itens[4], inventario[4]);
		printf(" 5 -- Purple Orb - %.0f Red Orbs - %d/7 No inventario\n", custo_itens[5], inventario[5]);
		printf(" 6 -- Golden Orb - %.0f Red Orbs - %d/3 No inventario\n", custo_itens[6], inventario[6]);
		printf(" 7 == Sair\n");
		printf("\n Digite o numero do item que quer adicionar: ");
		cin >> selecionar_i;
		
		if(selecionar_i <= 2)
		{
			if(pergunta() == 1)
			{
				if(inventario[selecionar_i] >= 30)
				{
					system("cls");
					printf("Voce ja comprou a quantidade maximo desse item'-'\n");
					system("pause");
				}	
				else if(custo_itens[selecionar_i] > red_orbs)
				{
					system("cls");
					printf("Voce nao possui Red Orbs o suficiente '-'\n");
					system("pause");
				}
				else
				{
					if(inventario[selecionar_i] >= 5)
					{
						red_orbs = red_orbs - custo_itens[selecionar_i];
						inventario[selecionar_i]++;
						
						if(inventario[selecionar_i] >= 30)
						{
							custo_itens[selecionar_i] = 0;
						}
						else
						{
						
						}
					}
					else
					{
						red_orbs = red_orbs - custo_itens[selecionar_i];
						custo_itens[selecionar_i] = custo_itens[selecionar_i] * 2.0;
						inventario[selecionar_i]++;
					}
				}
			}
		}
		else if(selecionar_i == 3 || selecionar_i == 6)
		{
			if(pergunta() == 1)
			{
				if(inventario[selecionar_i] >= 3)
				{
					system("cls");
					printf("Voce ja comprou a quantidade maximo desse item'-'\n");
					system("pause");
				}	
				else if(custo_itens[selecionar_i] > red_orbs)
				{
					system("cls");
					printf("Voce nao possui Red Orbs o suficiente '-'\n");
					system("pause");
				}
				else
				{
					red_orbs = red_orbs - custo_itens[selecionar_i];
					custo_itens[selecionar_i] = custo_itens[selecionar_i] + 10000;
					inventario[selecionar_i]++;
					
					if(inventario[selecionar_i] >= 3)
					{
						custo_itens[selecionar_i] = 0;
					}
					else
					{
						
					}
				}
			}
		}
		else if(selecionar_i == 4)
		{
			if(pergunta() == 1)
			{
				if(inventario[selecionar_i] >= 14)
				{
					system("cls");
					printf("Voce ja comprou a quantidade maximo desse item'-'\n");
					system("pause");
				}	
				else if(custo_itens[selecionar_i] > red_orbs)
				{
					system("cls");
					printf("Voce nao possui Red Orbs o suficiente '-'\n");
					system("pause");
				}
				else
				{
					blue_orbs++;
					red_orbs = red_orbs - custo_itens[selecionar_i];
					custo_itens[selecionar_i] = custo_itens[selecionar_i] + 5000;
					inventario[selecionar_i]++;
					
					if(inventario[selecionar_i] >= 14)
					{
						custo_itens[selecionar_i] = 0;
					}
					else
					{
						
					}
				}
			}
		}
		else if(selecionar_i == 5)
		{
			if(pergunta() == 1)
			{
				if(inventario[selecionar_i] >= 7)
				{
					system("cls");
					printf("Voce ja comprou a quantidade maximo desse item'-'\n");
					system("pause");
				}	
				else if(custo_itens[selecionar_i] > red_orbs)
				{
					system("cls");
					printf("Voce nao possui Red Orbs o suficiente '-'\n");
					system("pause");
				}
				else
				{
					purple_orbs++;
					red_orbs = red_orbs - custo_itens[selecionar_i];
					custo_itens[selecionar_i] = custo_itens[selecionar_i] + 3000;
					inventario[selecionar_i]++;
					
					if(inventario[selecionar_i] >= 7)
					{
							custo_itens[selecionar_i] = 0;
					}
					else
					{
						
					}
				}
			}
		}
	}
	selecionar_i = 0;
	menu();
}

void action_menu()
{
	while(escolha != 5)
	{
		system("cls");
		chave_c = false;
		printf(" --------\n| Action |\n --------");
		for(lista = 0; lista < 5; lista++)
		{
			printf("\n %d -- %s", lista, weapons[lista]);
		}
		printf("\n 5 == Sair\n");
		printf("\n Digite o numero da Devil Arm que deseja melhorar: ");
		cin >> escolha;

		if(escolha == 0)
		{
			while(chave_c == false)
			{
				system("cls");
				printf("	Rebelion	| %.0f Red Orbs |\n\n", red_orbs);
				printf(" 0 -- %s - Preco: %.0f\n", rebelion_ups[0], preco_rebelion[0]);
				printf(" 1 -- %s - Preco: %.0f\n", rebelion_ups[1], preco_rebelion[1]);
				printf(" 2 -- %s - Preco: %.0f\n", rebelion_ups[2], preco_rebelion[2]);
				printf(" 3 == Sair\n\n");
				printf(" Digite o numero do upgrade que deseja adquirir: ");
				cin >> chave_b;
				
				if(chave_b > 2 || chave_b < 0)
				{
					chave_c = true;
				}
				else if(pergunta() == 1)
				{
					if(preco_rebelion[chave_b] > red_orbs)
					{
						system("cls");
						printf("Voce nao possui Red Orbs o suficiente '-'\n");
						system("pause");
					}
					else
					{
						if(chave_b == 0 && level_rebelion[chave_b] < 1)
						{
							strcpy(rebelion_ups[chave_b], rebelion_ups_pos[chave_b]);
							red_orbs = red_orbs - preco_rebelion[chave_b];
							preco_rebelion[chave_b] = 10000;
							level_rebelion[chave_b]++;
						}
						else if(level_rebelion[chave_b] >= limite_rebelion[chave_b])
						{
							system("cls");
							printf("Voce ja melhorou essa arma ao maximo '-'\n");
							system("pause");
						}
						else
						{
							red_orbs = red_orbs - preco_rebelion[chave_b];
							level_rebelion[chave_b]++;
							preco_rebelion[chave_b] = 0;
						}
						
					}
				}
			}
		}
		else if(escolha == 1)
		{
			while(chave_c == false)
			{
				system("cls");
				printf("	Cerberus	| %.0f Red Orbs |\n\n", red_orbs);
				printf(" 0 -- %s - Preco: %.0f\n", cerberus_ups[0], preco_cerberus[0]);
				printf(" 1 -- %s - Preco: %.0f\n", cerberus_ups[1], preco_cerberus[1]);
				printf(" 2 == Sair\n\n");
				printf(" Digite o numero do upgrade que deseja adquirir: ");
				cin >> chave_b;

				if(chave_b > 1 || chave_b < 0)
				{
					chave_c = true;
				}
				else if(pergunta() == 1)
				{
					if(preco_cerberus[chave_b] > red_orbs)
					{
						system("cls");
						printf("Voce nao possui Red Orbs o suficiente '-'\n");
						system("pause");
					}
					else
					{
						if(level_cerberus[chave_b] >= limite_cerberus[chave_b])
						{
							system("cls");
							printf("Voce ja melhorou essa arma ao maximo '-'\n");
							system("pause");
						}
						else
						{
							red_orbs = red_orbs - preco_cerberus[chave_b];
							level_cerberus[chave_b]++;
							preco_cerberus[chave_b] = 0;
						}
						
					}
				}
			}
		}
		else if(escolha == 2)
		{
			while(chave_c == false)
			{
				system("cls");
				printf("	Agni & Rudra	| %.0f Red Orbs |\n\n", red_orbs);
				printf(" 0 -- %s - Preco: %.0f\n", agni_rudra_ups[0], preco_agni_rudra[0]);
				printf(" 1 -- %s - Preco: %.0f\n", agni_rudra_ups[1], preco_agni_rudra[1]);
				printf(" 2 -- %s - Preco: %.0f\n", agni_rudra_ups[2], preco_agni_rudra[2]);
				printf(" 3 == Sair\n\n");
				printf(" Digite o numero do upgrade que deseja adquirir: ");
				cin >> chave_b;

				if(chave_b > 2 || chave_b < 0)
				{
					chave_c = true;
				}
				else if(pergunta() == 1)
				{
					if(preco_agni_rudra[chave_b] > red_orbs)
					{
						system("cls");
						printf("Voce nao possui Red Orbs o suficiente '-'\n");
						system("pause");
					}
					else
					{
						if(chave_b == 0 && level_agni_rudra[chave_b] < 1)
						{
							strcpy(agni_rudra_ups[chave_b], agni_rudra_ups_pos[chave_b]);
							red_orbs = red_orbs - preco_agni_rudra[chave_b];
							preco_agni_rudra[chave_b] = 15000;
							level_agni_rudra[chave_b]++;
						}
						else if(level_agni_rudra[chave_b] == limite_agni_rudra[chave_b])
						{
							system("cls");
							printf("Voce ja melhorou essa arma ao maximo '-'\n");
							system("pause");
						}
						else
						{
							red_orbs = red_orbs - preco_agni_rudra[chave_b];
							level_agni_rudra[chave_b]++;
							preco_agni_rudra[chave_b] = 0;
						}
						
					}
				}
			}
		}
		else if(escolha == 3)
		{
			while(chave_c == false)
			{
				system("cls");
				printf("	Nevan	| %.0f Red Orbs |\n\n", red_orbs);
				printf(" 0 -- %s - Preco: %.0f\n", nevan_ups[0], preco_nevan[0]);
				printf(" 1 -- %s - Preco: %.0f\n", nevan_ups[1], preco_nevan[1]);
				printf(" 2 -- %s - Preco: %.0f\n", nevan_ups[2], preco_nevan[2]);
				printf(" 3 -- %s - Preco: %.0f\n", nevan_ups[3], preco_nevan[3]);
				printf(" 4 == Sair\n\n");
				printf(" Digite o numero do upgrade que deseja adquirir: ");
				cin >> chave_b;

				if(chave_b > 3 || chave_b < 0)
				{
					chave_c = true;
				}
				else if(pergunta() == 1)
				{
					if(preco_nevan[chave_b] > red_orbs)
					{
						system("cls");
						printf("Voce nao possui Red Orbs o suficiente '-'\n");
						system("pause");
					}
					else
					{
						if(chave_b == 0 && level_nevan[chave_b] < 1)
						{
							strcpy(nevan_ups[chave_b], nevan_ups_pos[chave_b]);
							red_orbs = red_orbs - preco_nevan[chave_b];
							preco_nevan[chave_b] = 15000;
							level_nevan[chave_b]++;
						}
						else if(level_nevan[chave_b] >= limite_nevan[chave_b])
						{
							system("cls");
							printf("Voce ja melhorou essa arma ao maximo '-'\n");
							system("pause");
						}
						else
						{
							red_orbs = red_orbs - preco_nevan[chave_b];
							level_nevan[chave_b]++;
							preco_nevan[chave_b] = 0;
						}
						
					}
				}
			}
		}
		else if(escolha == 4)
		{
			while(chave_c == false)
			{
				system("cls");
				printf("	Beowulf		| %.0f Red Orbs |\n\n", red_orbs);
				printf(" 0 -- %s - Preco: %.0f\n", beowulf_ups[0], preco_beowulf[0]);
				printf(" 1 -- %s - Preco: %.0f\n", beowulf_ups[1], preco_beowulf[1]);
				printf(" 2 -- %s - Preco: %.0f\n", beowulf_ups[2], preco_beowulf[2]);
				printf(" 3 == Sair\n\n");
				printf(" Digite o numero do upgrade que deseja adquirir: ");
				cin >> chave_b;

				if(chave_b > 2 || chave_b < 0)
				{
					chave_c = true;
				}
				else if(pergunta() == 1)
				{
					if(preco_beowulf[chave_b] > red_orbs)
					{
						system("cls");
						printf("Voce nao possui Red Orbs o suficiente '-'\n");
						system("pause");
					}
					else
					{
						if(chave_b == 0 && level_beowulf[chave_b] < 1)
						{
							strcpy(beowulf_ups[chave_b], beowulf_ups_pos[chave_b]);
							red_orbs = red_orbs - preco_beowulf[chave_b];
							preco_beowulf[chave_b] = 15000;
							level_beowulf[chave_b]++;
						}
						else if(level_beowulf[chave_b] == limite_beowulf[chave_b])
						{	
							system("cls");
							printf("Voce ja melhorou essa arma ao maximo '-'\n");
							system("pause");
						}
						else
						{
							red_orbs = red_orbs - preco_beowulf[chave_b];
							level_beowulf[chave_b]++;
							preco_beowulf[chave_b] = 0;
						}
						
					}
				}
			}
		}
		else
		{
			
		}
	}
	escolha = 0;
	menu();
}
void guns_menu()
{
	while(selecionar_g <= 4)
	{
		system("cls");
		printf(" ------\n| Guns |		| %.0f Red Orbs |\n ------", red_orbs);
		for(lista = 0; lista < 5; lista++)
		{
			printf("\n %d -- %s - Nv %d", lista, guns[lista], nivel_guns[lista]);
			if(nivel_guns[lista] < 3)
			{
				printf(" - %.0f Custo de Upgrade", custo_guns[lista]);	
			}
		}
		printf("\n 5 == Sair\n\n Digite o numero da arma que deseja melhorar: ");
		cin >> selecionar_g;
		
		if(selecionar_g >= 5 || selecionar_g < 0)
		{
			selecionar_g = 0;
			menu();
		}
		else if(pergunta() == 1)
		{
			if(custo_guns[selecionar_g] > red_orbs)
			{
				system("cls");
				printf("Voce nao possui Red Orbs o suficiente '-'\n");
				system("pause");
			}
			else if(nivel_guns[selecionar_g] == 3)
			{
				system("cls");
				printf("Voce ja melhorou essa arma ao maximo '-'\n");
				system("pause");
			}
			else
			{
				red_orbs = red_orbs - custo_guns[selecionar_g];
				custo_guns[selecionar_g] = custo_guns[selecionar_g] * 2;
				nivel_guns[selecionar_g]++;
			}
		}
	}
}

void inserir_orbs()
{
	system("cls");
	printf(" ------------------\n| Inserir Red Orbs |		| %.0f Red Orbs |\n ------------------\n", red_orbs);
	printf("\n Digite a quantidade de Red Orbs voce dejesa inserir: ");
	cin >> soma;
	
	if(soma <= 0)
	{
		system("cls");
		printf(" Ta maluco?\n");
		system("pause");
	}
	else
	{
		red_orbs = 	red_orbs + soma;
		
		system("cls");
		printf(" Red Obrs inserido UwU\n");
		system("pause");
	}
	menu();
}
void menu()
{
    system("cls");
    printf(" HP: ");
    for(lista = 0; lista < blue_orbs; lista++)
	{
		if(lista == 10)
		{
			printf("\n     ");
		}
		printf("-");
		
	}
	printf("\n DT: ");
 	for(lista = 0; lista < purple_orbs; lista++)
	{
		printf("*");
	}
    printf("\n -------------------------\n| Loja do Devil May Cry 3 | \n -------------------------");
    printf("\n 1 -- Style\n 2 -- Equip\n 3 -- Item\n 4 -- Action\n 5 -- Guns\n 6 -- Inserir Red Orbs\n 7 == Exit\n\n Digite: ");
    cin >> chave;
    
    switch(chave)
    {
    	case 1:
    	style_menu();
    	break;
    	case 2:
    	equip_menu();
    	break;
    	case 3:
    	item_menu();
    	break;
    	case 4:
    	action_menu();
    	break;
    	case 5:
    	guns_menu();
    	break;
    	case 6:
    	inserir_orbs();
    	break;
    	default:
    	system("cls");
    	break;
	}
}

int main()
{
	menu();
}