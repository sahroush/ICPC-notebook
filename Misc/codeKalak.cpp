freopen("input.txt", "r", stdin);
int main(int argc, char* argv[]) {
    // Print each argument
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
}