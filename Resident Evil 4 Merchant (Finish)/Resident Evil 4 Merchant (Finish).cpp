#include<iostream>
#include<stdlib.h>

// Adicionar PTAS
float ptas = 0;

// Menus
void adicionar_ptas();
void adicionar_armas();
void upgrades();
void comprar();
void vender();
int main();

// Armas do Mercador
int array_base = 3;

std::string arma_nome[99] = {"Punisher", "Red 9", "Broken Butterfly"};
float preco[99] = {20000, 14000, 28000};
float preco_original[99] = {20000, 14000, 28000};
float firepower[99][99] = {{0.9, 1.1, 1.3, 1.5, 1.7, 1.9},{1.6, 1.8, 2.0, 2.4, 2.8, 3.7},{13, 15, 17, 20, 24, 28}};
float firespeed[99][99] = {{0.47, 0.40, 0.33},{0.53, 0.47, 0.40}, {0.70}};
float reloadspeed[99][99] = {{1.70, 1.47, 0.83},{2.73, 2.20, 1.67},{3.67, 3, 2.33}};
int capacidade[99][99] = {{10, 13, 16, 20, 24, 28},{8, 10, 12, 15, 18, 22},{6, 8, 10, 12}};

float firepower_preco[99][99] = {{10000, 15000, 20000, 25000, 35000},{15000, 20000, 24000, 28000, 45000},{25000, 30000, 35000, 50000, 70000}};
float firespeed_preco[99][99] = {{10000, 20000},{10000, 15000},{0}};
float reloadspeed_preco[99][99] = {{8000, 18000},{6000, 10000},{15000, 20000}};
int capacidade_preco[99][99] = {{8000, 10000, 15000, 18000, 24000},{6000, 8000, 12000, 16000, 22000},{15000, 20000, 25000}};

int firepower_limit[99] = {5,5,5};
int firespeed_limit[99] = {2,2,0};
int reloadspeed_limit[99] = {2,2,2};
int capacidade_limit[99] = {5,5,3};

int firepower_base[99] = {0,0};
int firespeed_base[99] = {0,0};
int reloadspeed_base[99] = {0,0};
int capacidade_base[99] = {0,0};

// Armas do Player
int array_player = 0;

std::string arma_nome_player[99];
float preco_player[99];
float preco_original_player[99];
float firepower_player[99][99];
float firespeed_player[99][99];
float reloadspeed_player[99][99];
int capacidade_player[99][99];

float firepower_preco_player[99][99];
float firespeed_preco_player[99][99];
float reloadspeed_preco_player[99][99];
int capacidade_preco_player[99][99];

int firepower_limit_player[99];
int firespeed_limit_player[99];
int reloadspeed_limit_player[99];
int capacidade_limit_player[99];
 
int firepower_base_player[99];
int firespeed_base_player[99];
int reloadspeed_base_player[99];
int capacidade_base_player[99];

int pergunta()
{
    int retorno;

    std::cout << " | Is that all, stranger?, [1] - SIM [0] - NAO |\n :: ";
    std::cin >> retorno;

    std::cin.clear();
    fflush(stdin);

    return retorno;
}
void vender()
{
    system("cls");

    int chave;  

    std::cout << "     * Vender *     " << ptas << " PTAS\n\n";
    for(int aux = 0; aux < array_player; aux++)
    {
        std::cout << " " << aux + 1 << " - " << arma_nome_player[aux] << " == Preco PTAS: " << preco_player[aux] / 2 << "\n\n";
        std::cout << " Firepower Level  " << firepower_base_player[aux] + 1 << " = " << firepower_player[aux][firepower_base_player[aux]] << " Firespeed Level " << firepower_base_player[aux] + 1 << " = " << firespeed_player[aux][firespeed_base_player[aux]] << "\n";
        std::cout << " Reloadspeed Level " << reloadspeed_base_player[aux]  + 1 << " = " << reloadspeed_player[aux][reloadspeed_base_player[aux]] << " Capacidade Level " << capacidade_base_player[aux] + 1 << " = " << capacidade_player[aux][capacidade_base_player[aux]] << "\n\n";
    }
    std::cout << " Digite o numero da arma que deseja vender ou 0 para sair para o menu :: ";
    std::cin >> chave;

    std::cin.clear();
    fflush(stdin);
    
    chave -= 1;

    system("cls");
    if(chave >= array_player || chave < 0)
    {
        main();
    }
    else
    {
        if(pergunta() == 1)
        {
            ptas += preco_player[chave] / 2;

            arma_nome[array_base] = arma_nome_player[chave];
            preco[array_base] = preco_original_player[chave];
            preco_original[array_base] = preco_original_player[chave];

            firepower_base[array_base] = 0;
            firespeed_base[array_base] = 0;
            reloadspeed_base[array_base] = 0;
            capacidade_base[array_base] = 0;

            firepower_limit[array_base] = firepower_limit_player[chave];
            firespeed_limit[array_base] = firespeed_limit_player[chave];
            reloadspeed_limit[array_base] = reloadspeed_limit_player[chave];
            capacidade_limit[array_base] = capacidade_limit_player[chave];

            for(int aux = 0; aux <= firepower_limit[array_base]; aux++)
            {
                firepower[array_base][aux] = firepower_player[chave][aux];
            }

            for(int aux = 0; aux <= firespeed_limit[array_base]; aux++)
            {
                firespeed[array_base][aux] = firespeed_player[chave][aux];
            }

            for(int aux = 0; aux <= reloadspeed_limit[array_base]; aux++)
            {
                reloadspeed[array_base][aux] = reloadspeed_player[chave][aux];
            }

            for(int aux = 0; aux <= capacidade_limit[array_base]; aux++)
            {
                capacidade[array_base][aux] = capacidade_player[chave][aux];
            }
            for(int aux = 0; aux <= firepower_limit[array_base]; aux++)
            {
                firepower_preco[array_base][aux] = firepower_preco_player[chave][aux];
            }

            for(int aux = 0; aux <= firespeed_limit[array_base]; aux++)
            {
                firespeed_preco[array_base][aux] = firespeed_preco_player[chave][aux];
            }

            for(int aux = 0; aux <= reloadspeed_limit[array_base]; aux++)
            {
                reloadspeed_preco[array_base][aux] = reloadspeed_preco_player[chave][aux];
            }

            for(int aux = 0; aux <= capacidade_limit[array_base]; aux++)
            {
                capacidade_preco[array_base][aux] = capacidade_preco_player[chave][aux];
            }

            for(int troca = chave; troca < array_player; troca++)
                {
                    arma_nome_player[troca] = arma_nome_player[troca + 1];
                    preco_player[troca] = preco_player[troca + 1];
                    preco_original_player[troca] = preco_original_player[troca + 1];

                    firepower_base_player[troca] = firepower_base_player[troca + 1];
                    firespeed_base_player[troca] = firespeed_base_player[troca + 1];
                    reloadspeed_base_player[troca] = reloadspeed_base_player[troca + 1];
                    capacidade_base_player[troca] = capacidade_base_player[troca + 1];

                    firepower_limit_player[troca] = firepower_limit_player[troca + 1];
                    firespeed_limit_player[troca] = firespeed_limit_player[troca + 1];
                    reloadspeed_limit_player[troca] = reloadspeed_limit_player[troca + 1];
                    capacidade_limit_player[troca] = capacidade_limit_player[troca + 1];

                    for(int aux = 0; aux <= firepower_limit_player[troca]; aux++)
                    {
                        firepower_player[troca][aux] = firepower_player[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= firespeed_limit_player[troca]; aux++)
                    {
                        firespeed_player[troca][aux] = firespeed_player[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= reloadspeed_limit_player[troca]; aux++)
                    {
                        reloadspeed_player[troca][aux] = reloadspeed_player[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= capacidade_limit_player[troca]; aux++)
                    {
                        capacidade_player[troca][aux] = capacidade_player[troca + 1][aux];
                    }
                    
                    for(int aux = 0; aux <= firepower_limit_player[troca]; aux++)
                    {
                        firepower_preco_player[troca][aux] = firepower_preco_player[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= firespeed_limit_player[troca]; aux++)
                    {
                        firespeed_preco_player[troca][aux] = firespeed_preco_player[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= reloadspeed_limit_player[troca]; aux++)
                    {
                        reloadspeed_preco_player[troca][aux] = reloadspeed_preco_player[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= capacidade_limit_player[troca]; aux++)
                    {
                        capacidade_preco_player[troca][aux] = capacidade_preco_player[troca + 1][aux];
                    }
                }

            array_base += 1;
            array_player -= 1;

            std::cout << " | Hehe, Thank You!|\n";
            system("pause");
        }
        else
        {
        }
    }
    vender();
}
void upgrades()
{
    system("cls");

    int chave, chave_b;

    std::cout << "     * Upgrades *     " << ptas << " PTAS\n\n";
    for(int aux = 0; aux < array_player; aux++)
    {
        std::cout << " " << aux + 1 << " - " << arma_nome_player[aux] << "\n\n";
        std::cout << " Firepower Level  " << firepower_base_player[aux] + 1 << " = " << firepower_player[aux][firepower_base_player[aux]] << " Firespeed Level " << firespeed_base_player[aux] + 1 << " = " << firespeed_player[aux][firespeed_base_player[aux]] << "\n";
        std::cout << " Reloadspeed Level " << reloadspeed_base_player[aux]  + 1 << " = " << reloadspeed_player[aux][reloadspeed_base_player[aux]] << " Capacidade Level " << capacidade_base_player[aux] + 1 << " = " << capacidade_player[aux][capacidade_base_player[aux]] << "\n\n";
    }

    std::cout << " | Selecione a arma que deseja melhorar ou 0 para sair para o menu :: ";
    std::cin >> chave;

    std::cin.clear();
    fflush(stdin);

    chave -= 1;

    system("cls");
    if(chave < 0 || chave >= array_player)
    {
        main();
    }
    else
    {
        while(true)
        {
            system("cls");

            std::cout << "      * " <<arma_nome_player[chave] << " *     " << ptas << " PTAS\n\n";
            std::cout << " | 1 - Fireporwer Level " << firepower_base_player[chave] + 1 << " - " << firepower_player[chave][firepower_base_player[chave]];
            firepower_limit_player[chave] == firepower_base_player[chave] ? std::cout << "\n" : std::cout << "   >>   Level " << firepower_base_player[chave] + 2 << " - " << firepower_player[chave][firepower_base_player[chave] + 1] << " | Preco PTAS " << firepower_preco_player[chave][firepower_base_player[chave]] << '\n';

            std::cout << " | 2 - Firespeed Level " << firespeed_base_player[chave] + 1 << " - " << firespeed_player[chave][firespeed_base_player[chave]]; 
            firespeed_limit_player[chave] == firespeed_base_player[chave] ? std::cout << "\n" : std::cout << "   >>   Level " << firespeed_base_player[chave] + 2 << " - " << firespeed_player[chave][firespeed_base_player[chave] + 1] << " | Preco PTAS " << firespeed_preco_player[chave][firespeed_base_player[chave]] << '\n';

            std::cout << " | 3 - Reloadspeed Level " << reloadspeed_base_player[chave] + 1 << " - " << reloadspeed_player[chave][reloadspeed_base_player[chave]]; 
            reloadspeed_limit_player[chave] == reloadspeed_base_player[chave] ? std::cout << "\n" : std::cout << "   >>   Level " << reloadspeed_base_player[chave] + 2 << " - " << reloadspeed_player[chave][reloadspeed_base_player[chave] + 1] << " | Preco PTAS " << reloadspeed_preco_player[chave][reloadspeed_base_player[chave]] << '\n';

            std::cout << " | 4 - Capacidade Level " << capacidade_base_player[chave] + 1 << " - " << capacidade_player[chave][capacidade_base_player[chave]]; 
            capacidade_limit_player[chave] == capacidade_base_player[chave] ? std::cout << "\n" : std::cout  << "   >>   Level " << capacidade_base_player[chave] + 2 << " - " << capacidade_player[chave][capacidade_base_player[chave] + 1] << " | Preco PTAS " << capacidade_preco_player[chave][capacidade_base_player[chave]] << '\n';

            std::cout << "\n | Digite o numero do atributo que deseja melhorar ou 0 para voltar ao menu :: ";
            std::cin >> chave_b;

            std::cin.clear();
            fflush(stdin);

            system("cls");
            switch(chave_b)
            {
                case 1:
                    if(firepower_preco_player[chave][firepower_base_player[chave]] > ptas)
                    {
                        std::cout << " | Not enough cash, stranger! |\n";
                        system("pause");
                    }
                    else if(firepower_limit_player[chave] == firepower_base_player[chave])
                    {
                        std::cout << " | Voce ja upgradeou ao maximo esse atributo! |\n";
                        system("pause");
                    }
                    else
                    {
                        if(pergunta() == 1)
                        {   
                            ptas -= firepower_preco_player[chave][firepower_base_player[chave]];
                            firepower_base_player[chave] += 1;
                            preco_player[chave] += (firepower_preco_player[chave][firepower_base_player[chave]] / 2);

                            std::cout << "| Hehe, Thank you! |\n";
                            system("pause");
                        }
                        else
                        {
                        }
                    }
                break;
                case 2:
                    if(firespeed_preco_player[chave][firespeed_base_player[chave]] > ptas)
                        {
                            std::cout << " | Not enough cash, stranger! |\n";
                            system("pause");
                        }
                        else if(firespeed_limit_player[chave] == firespeed_base_player[chave])
                        {
                            std::cout << " | Voce ja upgradeou ao maximo esse atributo! |\n";
                            system("pause");
                        }
                        else
                        {
                            if(pergunta() == 1)
                            {   
                                ptas -= firespeed_preco_player[chave][firespeed_base_player[chave]];
                                firespeed_base_player[chave] += 1;
                                preco_player[chave] += (firespeed_preco_player[chave][firespeed_base_player[chave]] / 2);

                                std::cout << "| Hehe, Thank you! |\n";
                                system("pause");
                            }
                            else
                            {
                            }   
                        }
                break;
                case 3:
                    if(reloadspeed_preco_player[chave][reloadspeed_base_player[chave]] > ptas)
                        {
                            std::cout << " | Not enough cash, stranger! |\n";
                            system("pause");
                        }
                        else if(reloadspeed_limit_player[chave] == reloadspeed_base_player[chave])
                        {
                            std::cout << " | Voce ja upgradeou ao maximo esse atributo! |\n";
                            system("pause");
                        }
                        else
                        {
                            if(pergunta() == 1)
                            {   
                                ptas -= reloadspeed_preco_player[chave][reloadspeed_base_player[chave]];
                                reloadspeed_base_player[chave] += 1;
                                preco_player[chave] += (reloadspeed_preco_player[chave][reloadspeed_base_player[chave]] / 2);

                                std::cout << "| Hehe, Thank you! |\n";
                                system("pause");
                            }
                            else
                            {
                            }
                        }
                break;
                case 4:
                    if(capacidade_preco_player[chave][capacidade_base_player[chave]] > ptas)
                        {
                            std::cout << " | Not enough cash, stranger! \n";
                            system("pause");
                        }
                        else if(capacidade_limit_player[chave] == capacidade_base_player[chave])
                        {
                            std::cout << " | Voce ja upgradeou ao maximo esse atributo! |\n";
                            system("pause");
                        }
                        else
                        {
                            if(pergunta() == 1)
                            {   
                                ptas -= capacidade_preco_player[chave][capacidade_base_player[chave]];
                                capacidade_base_player[chave] += 1;
                                preco_player[chave] += (capacidade_preco_player[chave][capacidade_base_player[chave]] / 2);

                                std::cout << "| Hehe, Thank you! |\n";
                                system("pause");
                            }
                            else
                            {
                            }
                        }
                break;
                default:
                upgrades();
                break;
            }
        }
    }
}
void comprar()
{
    system("cls");

    int chave;

    std::cout << "     * Comprar Armas *     " << ptas << " PTAS\n\n";
    for(int aux = 0; aux < array_base; aux++)
    {
        std::cout << " " << aux + 1 << " - " << arma_nome[aux] << " == Preco PTAS: " << preco[aux] << "\n";
        std::cout << " | Firepower Level 1 = " << firepower[aux][0] << " Firespeed Level 1 = " << firespeed[aux][0] << "\n";
        std::cout << " | Reloadspeed Level 1 = " << reloadspeed[aux][0] << " Capacidade Level 1 = " << capacidade[aux][0] << "\n\n";
    }
    std::cout << " | Digite o numero da arma que deseja adquirir ou 0 para sair para o menu :: ";
    std::cin >> chave;

    std::cin.clear();
    fflush(stdin);
    
    chave -= 1;

    system("cls");
    if(chave >= array_base || chave < 0)
    {
        main();
    }
    else if(ptas < preco[chave])
    {
        std::cout << " | Not enough cash, stranger! |\n";
        system("pause");
    }
    else
    {
        if(pergunta() == 1)
        {
            ptas -= preco[chave];

            arma_nome_player[array_player] = arma_nome[chave];
            preco_player[array_player] = preco[chave];
            preco_original_player[array_player] = preco_original[chave];

            firepower_base_player[array_player] = firepower_base[chave];
            firespeed_base_player[array_player] = firespeed_base[chave];
            reloadspeed_base_player[array_player] = reloadspeed_base[chave];
            capacidade_base_player[array_player] = capacidade_base[chave];

            firepower_limit_player[array_player] = firepower_limit[chave];
            firespeed_limit_player[array_player] = firespeed_limit[chave];
            reloadspeed_limit_player[array_player] = reloadspeed_limit[chave];
            capacidade_limit_player[array_player] = capacidade_limit[chave];

            for(int aux = 0; aux <= firepower_limit_player[array_player]; aux++)
            {
                firepower_player[array_player][aux] = firepower[chave][aux];
            }

            for(int aux = 0; aux <= firespeed_limit_player[array_player]; aux++)
            {
                firespeed_player[array_player][aux] = firespeed[chave][aux];
            }

            for(int aux = 0; aux <= reloadspeed_limit_player[array_player]; aux++)
            {
                reloadspeed_player[array_player][aux] = reloadspeed[chave][aux];
            }

            for(int aux = 0; aux <= capacidade_limit_player[array_player]; aux++)
            {
                capacidade_player[array_player][aux] = capacidade[chave][aux];
            }
            for(int aux = 0; aux <= firepower_limit_player[array_player]; aux++)
            {
                firepower_preco_player[array_player][aux] = firepower_preco[chave][aux];
            }

            for(int aux = 0; aux <= firespeed_limit_player[array_player]; aux++)
            {
                firespeed_preco_player[array_player][aux] = firespeed_preco[chave][aux];
            }

            for(int aux = 0; aux <= reloadspeed_limit_player[array_player]; aux++)
            {
                reloadspeed_preco_player[array_player][aux] = reloadspeed_preco[chave][aux];
            }

            for(int aux = 0; aux <= capacidade_limit_player[array_player]; aux++)
            {
                capacidade_preco_player[array_player][aux] = capacidade_preco[chave][aux];
            }

                for(int troca = chave; troca < array_base; troca++)
                {
                    arma_nome[troca] = arma_nome[troca + 1];
                    preco[troca] = preco[troca + 1];
                    preco_original[troca] = preco_original[troca + 1];

                    firepower_base[troca] = firepower_base[troca + 1];
                    firespeed_base[troca] = firespeed_base[troca + 1];
                    reloadspeed_base[troca] = reloadspeed_base[troca + 1];
                    capacidade_base[troca] = capacidade_base[troca + 1];

                    firepower_limit[troca] = firepower_limit[troca + 1];
                    firespeed_limit[troca] = firespeed_limit[troca + 1];
                    reloadspeed_limit[troca] = reloadspeed_limit[troca + 1];
                    capacidade_limit[troca] = capacidade_limit[troca + 1];

                    for(int aux = 0; aux <= firepower_limit[troca]; aux++)
                    {
                        firepower[troca][aux] = firepower[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= firespeed_limit[troca]; aux++)
                    {
                        firespeed[troca][aux] = firespeed[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= reloadspeed_limit[troca]; aux++)
                    {
                        reloadspeed[troca][aux] = reloadspeed[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= capacidade_limit[troca]; aux++)
                    {
                        capacidade[troca][aux] = capacidade[troca + 1][aux];
                    }
                    
                    for(int aux = 0; aux <= firepower_limit[troca]; aux++)
                    {
                        firepower_preco[troca][aux] = firepower_preco[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= firespeed_limit[troca]; aux++)
                    {
                        firespeed_preco[troca][aux] = firespeed_preco[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= reloadspeed_limit[troca]; aux++)
                    {
                        reloadspeed_preco[troca][aux] = reloadspeed_preco[troca + 1][aux];
                    }

                    for(int aux = 0; aux <= capacidade_limit[troca]; aux++)
                    {
                        capacidade_preco[troca][aux] = capacidade_preco[troca + 1][aux];
                    }
                }

            array_base -= 1;
            array_player += 1;

            std::cout << " | Hehe, Thank You!|\n";
            system("pause");
        }
        else
        {
        }
    }
    comprar();
}
void adicionar_ptas()
{
    float add_ptas;

    system("cls");
    std::cout << "     * Adicionar PTAS *     " << ptas << " PTAS\n\n";
    std::cout << " | Digite a quantidade de PTAS que deseja adiconar ou 0 para sair :: ";
    std::cin >> add_ptas;

    std::cin.clear();
    fflush(stdin);

    system("cls");
    if(add_ptas <= 0)
    {
    }
    else
    {
        if(pergunta() == 1)
        {
            ptas += add_ptas;
            std::cout << " | Hehe, Thank You! |\n";
            system("pause");
        }
        else
        {
        }
        adicionar_ptas();
    }
    main();
}
void adicionar_armas()
{
    std::cout << "     * Adicionar Armas *\n\n";
    std::cout << " | Digite nome da arma ou 0 para sair para o menu :: ";
    std::getline(std::cin, arma_nome[array_base]);

    std::cin.clear();
    fflush(stdin);

    if(arma_nome[array_base] == "0")
    {
        main();
    }

    std::cout << " | Digite o preco da arma :: ";
    std::cin >> preco[array_base];

    std::cin.clear();
    fflush(stdin);

    preco_original[array_base] = preco[array_base];

    system("cls");

    std::cout << " | Digite quantos niveis de Firepower a arma deve ter :: ";
    std::cin >> firepower_limit[array_base];

    std::cin.clear();
    fflush(stdin);

    std::cout << " | Digite quantos niveis de Firespeed a arma deve ter :: ";
    std::cin >> firespeed_limit[array_base];

    std::cin.clear();
    fflush(stdin);

    std::cout << " | Digite quantos niveis de Reloadspeed a arma deve ter :: ";
    std::cin >> reloadspeed_limit[array_base];

    std::cin.clear();
    fflush(stdin);

    std::cout << " | Digite quantos niveis de Capacidade a arma deve ter :: ";
    std::cin >> capacidade_limit[array_base];

    std::cin.clear();
    fflush(stdin);

    firepower_limit[array_base] -= 1;
    firespeed_limit[array_base] -= 1;
    reloadspeed_limit[array_base] -= 1;
    capacidade_limit[array_base] -= 1;

    firepower_base[array_base] = 0;
    firespeed_base[array_base] = 0;
    reloadspeed_base[array_base] = 0;
    capacidade_base[array_base] = 0;

    firepower_preco[array_base][0] = 0;
    firespeed_preco[array_base][0] = 0;
    reloadspeed_preco[array_base][0] = 0;
    capacidade_preco[array_base][0] = 0;

    system("cls");
    for(int aux = 0; aux <= firepower_limit[array_base]; aux++)
    {
        std::cout << " | Digite o Firepower no Level " << aux + 1 << " :: ";
        std::cin >> firepower[array_base][aux];

        std::cin.clear();
        fflush(stdin);
        
        if(aux == 0)
        {   
            firepower_preco[array_base][aux] = 0;
            continue;
        }

        std::cout << " | Digite o preco do Upgrade no Level " << aux + 1 << " :: ";
        std::cin >> firepower_preco[array_base][aux];

        std::cin.clear();
        fflush(stdin);
    }

    system("cls");
    for(int aux = 0; aux <= firespeed_limit[array_base]; aux++)
    {
        std::cout << " | Digite o Firespeed no Level " << aux + 1 << " :: ";
        std::cin >> firespeed[array_base][aux];

        std::cin.clear();
        fflush(stdin);

        if(aux == 0)
        {
            firespeed_preco[array_base][aux] = 0;
            continue;
        }

        std::cout << " | Digite o preco do Upgrade no Level " << aux + 1 << " :: ";
        std::cin >> firespeed_preco[array_base][aux];

        std::cin.clear();
        fflush(stdin);
    }

    system("cls");
    for(int aux = 0; aux <= reloadspeed_limit[array_base]; aux++)
    {
        std::cout << " | Digite o Reloadspeed no Level " << aux + 1 << " :: ";
        std::cin >> reloadspeed[array_base][aux];

        std::cin.clear();
        fflush(stdin);

        if(aux == 0)
        {
            reloadspeed_preco[array_base][aux] = 0;
            continue;
        }

        std::cout << " | Digite o preco do Upgrade no Level " << aux + 1 << " :: ";
        std::cin >> reloadspeed_preco[array_base][aux];

        std::cin.clear();
        fflush(stdin);
    }

    system("cls");
    for(int aux = 0; aux <= capacidade_limit[array_base]; aux++)
    {
        std::cout << " | Digite o Capacidade no Level " << aux + 1 << " :: ";
        std::cin >> capacidade[array_base][aux];

        std::cin.clear();
        fflush(stdin);

        if(aux == 0)
        {
            capacidade_preco[array_base][aux] = 0;
            continue;
        }

        std::cout << " | Digite o preco do Upgrade no Level " << aux + 1 << " :: ";
        std::cin >> capacidade_preco[array_base][aux];

        std::cin.clear();
        fflush(stdin);
    }

    array_base += 1;

    system("cls");
    std::cout << " | Hehe, Thank You! |\n ";
    system("pause");

    main(); 
}
int main()
{
    int chave;

    system("cls");

    std::cout << "                  * Mercador do Resident Evil 4 *\n\n";
    std::cout << " |     1 - Vender     |        2 - Comprar         | 3 - Upgrades |\n | 4 - Adicionar PTAS | 5 - Adicionar Armas a Loja | 6 - Sair     |\n :: ";
    std::cin >> chave;

    std::cin.clear();
    fflush(stdin);

    system("cls");
    switch(chave)
    {
        case 1:
        vender();
        break;
        case 2:
        comprar();
        break;
        case 3:
        upgrades();
        break;
        case 4:
        adicionar_ptas();
        break;
        case 5:
        adicionar_armas();
        break;
        default:
        std::cout << " | Goodbye, Stranger! |\n";
        system("pause");
        exit(0); 
        break;
    }
}
