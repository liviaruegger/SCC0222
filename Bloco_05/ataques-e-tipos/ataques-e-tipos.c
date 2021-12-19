#include <stdio.h>
#include <stdlib.h>

#define END -1

typedef struct attack
{
    int power;
    int type;
} attack_t;

attack_t **scan_player_attacks(int *n_player_attacks_scanned);

int main()
{
    int n_types;
    scanf("%d", &n_types);

    float attack_chart[n_types][n_types];

    for (int i = 0; i < n_types; i++)
    {
        for (int j = 0; j < n_types; j++)
            scanf(" %f", &attack_chart[i][j]);
    }

    int n_player_attacks;
    attack_t **player_atacks = scan_player_attacks(&n_player_attacks);

    int enemy_type;
    scanf(" %d", &enemy_type);

    float highest_damage = 0;
    int best_attack_type;

    // Compara os possíveis valores de dano até encontar o melhor ataque disponível.
    for (int i = 0; i < n_player_attacks; i++)
    {
        int power = player_atacks[i]->power;
        int type = player_atacks[i]->type;

        float damage = power * attack_chart[type][enemy_type];

        if (damage > highest_damage)
        {
            highest_damage = damage;
            best_attack_type = type;
        }
    }
    
    printf("O melhor ataque possui indice %d e dano %.2f\n", best_attack_type, highest_damage);

    for (int i = 0; i < n_player_attacks; i++)
        free(player_atacks[i]);
    free(player_atacks);
    
    return 0;
}

// Lê da entrada padrão uma sequência de ataques até encontrar o valor -1 (END).
// Retorna um ponteiro duplo (attack_t **) para a lista de ataques.
// Guarda no endereço passado como parâmento o número de ataques lidos.
attack_t **scan_player_attacks(int *n_player_attacks_scanned)
{   
    attack_t **player_attacks = NULL;

    int power_temp, type_temp;
    int n_player_attacks = 0;

    do
    {
        scanf(" %d", &power_temp);

        if (power_temp == END)
        {
            *n_player_attacks_scanned = n_player_attacks;

            return player_attacks;
        }
        
        scanf(" %d", &type_temp);

        player_attacks = (attack_t **) realloc(player_attacks, (n_player_attacks + 1) * sizeof(attack_t *));
        attack_t *attack = (attack_t *) malloc(sizeof(attack_t));
        player_attacks[n_player_attacks] = attack;

        player_attacks[n_player_attacks]->power = power_temp;
        player_attacks[n_player_attacks]->type = type_temp;

        n_player_attacks++;

    } while (power_temp != END);

    *n_player_attacks_scanned = n_player_attacks;

    return player_attacks;
}