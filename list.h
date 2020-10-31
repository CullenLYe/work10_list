#ifndef POKEMON_STRUCT_H
#define POKEMON_STRUCT_H

struct Pokemon {
  char name[256];
  int pokedex;
  int friendship;
  struct Pokemon *poke;
};

struct Pokemon *new_Pokemon(char *n, int i, int f);
struct Pokemon *insert_front(struct Pokemon *node, char *n, int i, int f);
struct Pokemon *free_list(struct Pokemon *node);
struct Pokemon *free_Pokemon(struct Pokemon *pp);
struct Pokemon *remove_node(struct Pokemon *front, int dex);
void print_Pokemon(struct Pokemon *p);
void print_list(struct Pokemon *node);

#endif
