#include <stdio.h>
#include <stdlib.h>

#define FINISH           0
#define REGISTER_POKEMON 1
#define REGISTER_ATTACK  2
#define PRINT_POKEMON    3
#define PRINT_ATTACK     4

typedef struct status
{
    int hp;
    int attack;
    int defense;
    int sp_attack;
    int sp_defense;
    int speed;
}   status_t;

typedef struct attack
{
    char   name[20];
    int    base_power;
    float  accuracy;
    char   category;
}   attack_t;

typedef struct pokemon
{
    char     *name;
    char     *type1;
    char     *type2;
    status_t  status;
    attack_t  attacks[4];
}   pokemon_t;

char *read_string();

void register_pokemon(pokemon_t **pokedex, int n_registered);
void register_attack(pokemon_t **pokedex);
void print_pokemon(pokemon_t **pokedex);
void print_attack(pokemon_t **pokedex);

void free_pokedex(pokemon_t **pokedex, int n_registered);

int main()
{
    pokemon_t *pokedex = NULL;
    int n_registered = 0;

    int command;
    do
    {
        scanf("%d\n", &command);

        switch (command)
        {
        case REGISTER_POKEMON:
            register_pokemon(&pokedex, n_registered);
            n_registered++;
            break;
        case REGISTER_ATTACK:
            register_attack(&pokedex);
            break;
        case PRINT_POKEMON:
            print_pokemon(&pokedex);
            break;
        case PRINT_ATTACK:
            print_attack(&pokedex);
            break;
        }

    } while (command != FINISH);
    free_pokedex(&pokedex, n_registered);

    return 0;
}

// Lê e armazena uma string da entrada padrão.
// Retorna um ponteiro para essa string.
char *read_string()
{
    char *string = (char *) malloc(sizeof(char));
    int size = 0;

    do
    {
        string[size] = fgetc(stdin);
        size++;

        if (string[size - 1] != '\n')
            string = (char *) realloc(string, size + 1);

    } while (string[size - 1] != '\n');

    string[size - 1] = '\0';

    return string;
}

// Lê da entrada padrão as informações referentes a um Pokémon e o registra no Pokédex.
void register_pokemon(pokemon_t **pokedex, int n_registered)
{
    pokemon_t pokemon;

    pokemon.name  = read_string();
    pokemon.type1 = read_string();
    pokemon.type2 = read_string();

    scanf("%d\n", &pokemon.status.hp);
    scanf("%d\n", &pokemon.status.attack);
    scanf("%d\n", &pokemon.status.defense);
    scanf("%d\n", &pokemon.status.sp_attack);
    scanf("%d\n", &pokemon.status.sp_defense);
    scanf("%d\n", &pokemon.status.speed);

   *pokedex = (pokemon_t *) realloc(*pokedex, (n_registered + 1) * sizeof(pokemon_t));
   (*pokedex)[n_registered] = pokemon;
}

// Registra, para o Pokémon indicado na entrada padrão, um novo ataque,
// cujos detalhes também são recebidos da entrada padrão.
void register_attack(pokemon_t **pokedex)
{
    int pokemon_index, attack_index;
    attack_t attack;

    scanf("%d\n", &pokemon_index);
    scanf("%d\n", &attack_index);

    for (int i = 0; i < 20; i++)
    {
        scanf("%c", &attack.name[i]);
        if (attack.name[i] == '\n')
        {
            attack.name[i] = '\0';
            break;
        }
    }
    
    scanf("%d\n", &attack.base_power);
    scanf("%f\n", &attack.accuracy);
    scanf("%c\n", &attack.category);

    (*pokedex)[pokemon_index].attacks[attack_index] = attack;
}

// Imprime as informações do Pokémon cujo índice foi dado na entrada padrão.
void print_pokemon(pokemon_t **pokedex)
{
    int pokemon_index;

    scanf("%d\n", &pokemon_index);

    printf("Nome do Pokemon: %s\r\n", (*pokedex)[pokemon_index].name);
    printf("Tipo primario: %s\r\n", (*pokedex)[pokemon_index].type1);
    printf("Tipo secundario: %s\r\n", (*pokedex)[pokemon_index].type2);
    printf("Status:\r\n");
    printf("\tHP: %d\r\n", (*pokedex)[pokemon_index].status.hp);
    printf("\tAtaque: %d\r\n", (*pokedex)[pokemon_index].status.attack);
    printf("\tDefesa: %d\r\n", (*pokedex)[pokemon_index].status.defense);
    printf("\tAtaque Especial: %d\r\n", (*pokedex)[pokemon_index].status.sp_attack);
    printf("\tDefesa Especial: %d\r\n", (*pokedex)[pokemon_index].status.sp_defense);
    printf("\tVelocidade: %d\r\n\r\n", (*pokedex)[pokemon_index].status.speed);
}

// Imprime as informações do ataque cujos índices foram dados na entrada padrão.
void print_attack(pokemon_t **pokedex)
{
    int pokemon_index, attack_index;

    scanf("%d\n", &pokemon_index);
    scanf("%d\n", &attack_index);

    printf("Nome do Ataque: %s\r\n", (*pokedex)[pokemon_index].attacks[attack_index].name);
    printf("Poder base: %d\r\n", (*pokedex)[pokemon_index].attacks[attack_index].base_power);
    printf("Acuracia: %f\r\n", (*pokedex)[pokemon_index].attacks[attack_index].accuracy);
    printf("Classe: %c\r\n\r\n", (*pokedex)[pokemon_index].attacks[attack_index].category);
}

// Libera a memória utilizada pelo Pokédex.
void free_pokedex(pokemon_t **pokedex, int n_registered)
{
    for (int i = 0; i < n_registered; i++)
    {
        free((*pokedex)[i].name);
        free((*pokedex)[i].type1);
        free((*pokedex)[i].type2);
    }

    free(*pokedex);
}