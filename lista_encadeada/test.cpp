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

  p->remove_last();
  assert(p->contains(30) == false);

  p->add(40);
  assert(p->contains(40) == true);

  p->display();

  p->insert(99, 0); assert(p->get_head_value() == 99);
  p->insert(88, 2); 
  
  p->display();

  p->add(-1);
  assert(p->get_tail_value() == -1);

  p->display();

  p->remove(2);

  p->display();
  assert(p->contains(88) == false);

  assert(p->is_empty() == false);
  p->clear();
  assert(p->is_empty() == true);

  delete p;
  return(EXIT_SUCCESS);
}
