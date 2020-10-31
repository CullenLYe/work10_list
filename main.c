#include <stdlib.h>
#include <stdio.h.>
#include <time.h>
#include "list.h"

int main() {

  srand(time(NULL));

  struct Pokemon *Eevee;
  struct Pokemon *Vaporeon;
  struct Pokemon *Jolteon;
  struct Pokemon *Flareon;
  struct Pokemon *Ditto;

  Eevee = new_Pokemon("Eevee   ", 133, rand()%256);
  Vaporeon = new_Pokemon("Vaporeon", 134, rand()%256);
  Jolteon = new_Pokemon("Jolteon", 135, rand()%256);
  Flareon = new_Pokemon("Flareon", 136, rand()%256);

  printf("Inserting Eeveelutions...\n");
  printf("Eeveelutions:\n");
  Eevee->poke = Vaporeon;
  Vaporeon->poke = Jolteon;
  Jolteon->poke = Flareon;
  print_list(Eevee);

  printf("\nInserting Ditto...\n");
  Ditto = insert_front(Eevee, "Ditto   ", 132, rand()%256);
  printf("Eeveelutions:\n");
  print_list(Ditto);

  printf("\nRemoving Jolteon...\nEeveelutions:\n");
  print_list(remove_node(Ditto, 135));

  printf("\nRemoving Eevee...\nEeveelutions:\n");
  print_list(remove_node(Ditto, 133));

  printf("\nRemoving Ditto...\nEeveelutions:\n");
  print_list(remove_node(Ditto, 132));

  printf("\n");
  free_list(Ditto);

  return 0;

}
