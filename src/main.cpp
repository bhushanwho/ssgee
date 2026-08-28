#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace {

constexpr std::string_view kVersion = "0.1.0";

constexpr std::string_view kHelpText = R"(ssgee — a static site generator

USAGE:
    ssgee <COMMAND> [OPTIONS]

COMMANDS:
    build <content> <output>      build the site from <content> into <output>
    clean <output>                remove all generated files from <output>
    help                          show this help message
    version                       show version information

OPTIONS:
    -h, --help                    show help for a command
    -v, --version                 show version and exit

EXAMPLES:
    ssgee this is awkward, this is only a scaffold

)";

constexpr std::string_view kBuildUsage =
    "USAGE:\n"
    "    ssgee build <content> <output> [OPTIONS]\n";

void printHelp() { std::cout << kHelpText; }

void printVersion() { std::cout << "ssgee " << kVersion << "\n"; }

[[noreturn]] void fail(std::string_view message, std::string_view usage) {
  std::cerr << "error: " << message << "\n\n" << usage;
  std::exit(1);
}

} // namespace

int main(int argc, char **argv) {
  std::vector<std::string_view> args(argv + 1, argv + argc);

  if (args.empty()) {
    printHelp();
    return 1;
  }

  std::string_view command = args[0];
  std::vector<std::string_view> rest(args.begin() + 1, args.end());

  if (command == "-h" || command == "--help" || command == "help") {
    printHelp();
    return 0;
  }
  if (command == "-v" || command == "--version" || command == "version") {
    printVersion();
    return 0;
  }

  // if (command == "build") {
  // }
  // if (command == "clean") {
  // }

  fail("unknown command '" + std::string(command) + "'",
       "run 'ssgee --help' to see available commands.\n");
}