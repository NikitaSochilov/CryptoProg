#include <iostream>
#include <fstream>
#include <cryptlib.h>
#include <sha.h>
#include <hex.h>

using namespace CryptoPP;

std::string hashFile(const std::string& filename) {
    SHA256 hash;
    FileSource fileSource(filename.c_str(), true);
    HashFilter filter(hash, new HexEncoder(new StringSink(result)));
    fileSource.Attach(filter);
    fileSource.PumpAll();
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: hash_program <filename>\n";
        return 1;
    }
    std::string result = hashFile(argv[1]);
    std::cout << "Hash: " << result << std::endl;
    return 0;
}
