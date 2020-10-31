#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Create a new Pokemon.
struct Pokemon *new_Pokemon(char *n, int i, int f) {
  struct Pokemon *np = malloc(sizeof(struct Pokemon));
  strncpy(np->name, n, sizeof(np->name)-1);
  np->pokedex = i;
  np->friendship = f;
  np->poke = NULL;
  return np;
}

// Free an entire linked list of Pokemon.
struct Pokemon *free_list(struct Pokemon *node) {
  printf("Freeing List...\n");
  struct Pokemon *currentpoke, *nextpoke;
  currentpoke = node;
  while (currentpoke!=NULL) {
    nextpoke = currentpoke->poke;
    free(currentpoke);
    currentpoke = nextpoke;
  }
  node = NULL;
  return node;
}

// Free an individual Pokemon.
struct Pokemon *free_Pokemon(struct Pokemon *pp) {
  free(pp);
  return NULL;
}

// Create a new Pokemon and insert it in front of another one in a linked list.
struct Pokemon *insert_front(struct Pokemon *node, char *n, int i, int f) {
  struct Pokemon *np = new_Pokemon(n, i, f);
  np->poke = node;
  return np;
}

// Remove the Pokemon that matches the Pokedex number from a linked list.
struct Pokemon *remove_node(struct Pokemon *front, int dex) {
  if (front->pokedex == dex) {
    struct Pokemon *temp = front->poke;
    free_Pokemon(front);
    return temp;
  }
  else {
    struct Pokemon *currentpoke, *prevpoke;
    currentpoke = front;
    while (currentpoke) {
      if (currentpoke->pokedex == dex) {
        prevpoke->poke = currentpoke->poke;
        free_Pokemon(currentpoke);
        break;
      }
      prevpoke = currentpoke;
      currentpoke = currentpoke->poke;
    }
  }
  return front;
}

void print_Pokemon(struct Pokemon *p) {
  printf("Pokemon: %s\tPokedex: #%d\tFriendship Level: %d\n", p->name, p->pokedex, p->friendship);
}

void print_list(struct Pokemon *node) {
  while (node!=NULL) {
    print_Pokemon(node);
    node = node->poke;
  }
}
