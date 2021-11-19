#include <iostream>
#include "list.h"
#include <memory>
#include <string>

int main()
{
  auto l = std::make_shared<node<int>>();
  l->data = 5;
  auto l0 = list_insert(l, 10);
  print_list(l0);

  auto sl = std::make_shared<node<std::string>>();
  sl->data = std::string{"Hello"};
  auto sl0 = list_insert(sl, std::string{"dere!"});
  print_list(sl0);

  std::cout << "Test list class...\n";
  
  List<double> ll;
  ll.insert(1.2);
  ll.insert(2.2);
  ll.insert(3.2); 
  ll.print();
  std::cout << "range-for-loop test\n"; 
  for (auto val : ll) 
    std::cout << val << " ";
  std::cout << "\n";

  std::cout << "Testing merge..." << '\n';
  auto a = std::make_shared<node<int>>(7);
  auto b = std::make_shared<node<int>>(4);
  a = list_insert(a, 5);
  a = list_insert(a, 2);

  b = list_insert(b, 3);
  std::cout << "list a: " << '\n';
  print_list(a);
  std::cout << "list b: " << '\n';
  print_list(b);
  std::shared_ptr<node<int>> merged_list; 
  merged_list = merge_lists(b,a);
  std::cout << "merged list: " << '\n';
  print_list(merged_list);

  std::cout << "reversed merged list: " << '\n';
  print_list(reverse_list(merged_list));
  return 0;
}


