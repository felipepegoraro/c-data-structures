#include <iostream>
#include <assert.h>
#include "./linked-list.h"
#include "./linked-list.cpp"

int main(void)
{
  List<int> *p = new List<int>("my test");

  p->add(10); assert(p->contains(10) == true);
  p->add(20); assert(p->contains(20) == true);
  p->add(30); assert(p->contains(30) == true);

  p->display();

  assert(p->remove_last());
  assert(p->contains(30) == false);

  p->add(40);
  assert(p->contains(40));

  p->display();

  assert(p->insert(50, 0));
  assert(p->get_head_value() == 50);
  assert(p->insert(60, 2));
  
  p->display();

  p->add(-1);
  assert(p->get_tail_value() == -1);

  p->display();

  assert(p->remove(2));

  p->display();
  assert(p->contains(60) == false);

  assert(p->is_empty() == false);
  p->clear();
  assert(p->is_empty());

  delete p;

  // reverse list ------------------------------------------
  List<int> *x = new List<int>("to reverse");

  x->add(1); assert(x->contains(1)); assert(x->get_value_by_index(0) == 1);
  x->add(2); assert(x->contains(2)); assert(x->get_value_by_index(1) == 2);
  x->add(3); assert(x->contains(3)); assert(x->get_value_by_index(2) == 3);

  x->display(); // 1, 2, 3
  x->reverse(); // -------
  x->display(); // 3, 2, 1

  assert(x->get_value_by_index(0) == 3);
  assert(x->get_value_by_index(1) == 2);
  assert(x->get_value_by_index(2) == 1);  

  delete x;
  // reverse list ------------------------------------------

  printf("lista encadeada funcionando corretamente\n");
  return(EXIT_SUCCESS);
}
