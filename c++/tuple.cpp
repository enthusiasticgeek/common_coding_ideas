#include <tuple>
#include <iostream>
int main(int argc, char* argv[])
{
auto triple1 = std::make_tuple(5, 6, 7);
std::tuple<int,int,int> triple = std::make_tuple(5, 6, 7);
std::cout << "Tuple elements = " <<  std::tuple_size<decltype(t)>::value;
std::cout << std::get<0>(triple);
std::cout << std::get<1>(triple);
return 0;
}
