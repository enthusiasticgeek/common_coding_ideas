#include <iostream>
#include <memory>

int main () {

  std::shared_ptr<int> foo = std::make_shared<int> (10);

  auto bar = std::make_shared<int> (20);
  std::cout << bar.use_count() << std::endl;
  auto baz = std::make_shared<int> (30);
  std::cout << baz.use_count() << std::endl;
  auto hel = std::make_shared<int> (30);
  std::cout << hel.use_count() << std::endl;
  auto som = hel;
  std::cout << som.use_count() << std::endl;
  auto tel = som;
  //note resetting the tel below only affects that but not the object
  std::cout << som.use_count() << std::endl;
  tel.reset();
  std::cout << som.use_count() << std::endl;

return 0;
}
