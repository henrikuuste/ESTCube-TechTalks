#include <iostream>
#include <vector>
#include <map>

template <template <typename, typename...> class ContainerType,
          typename ValueType, typename... Args>
void print_container(const ContainerType<ValueType, Args...>& c) {
  auto &last = *(--c.end());
  std::cout << "{";
  for (const auto& v : c) {
    std::cout << v << ((&v == &last) ? "" : ", ");
  }
  std::cout << "}\n";
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}

int main() {
  std::vector<int> v1{1, 2, 3, 4, 5, 6};
  std::map<std::string, int> m1{{"foo", 42}, {"bar", 84}, {"baz", 168}};

  print_container(v1);
  print_container(m1);
}