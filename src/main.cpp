#include "fmt/core.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

int main()
{
  fmt::print("{}\n", "Hello, nlohmann and fmt\n");

  std::ifstream in_file{"../example.json"};

  json example;
  in_file >> example;

  fmt::print("example.json: {}\n", example.dump(2));

  example["new"]["key"]["value"] = {"another", "list"};
  fmt::print("Added: {}\n", example["new"]["key"]["value"].dump(2));
  fmt::print("Updated example.json: {}\n", example.dump(2));

  auto number_of_elements = example.size();
  fmt::print("JSON Elements: {}\n", number_of_elements);
  fmt::print("\"size\": {}\n", example["size"].dump(2));
  example["size"] = number_of_elements;
  fmt::print("Updated \"size\": {}\n", example["size"].dump(2));

  std::ofstream out_file{"../updated.json"};
  out_file << example.dump(2);

  return 0;
}
