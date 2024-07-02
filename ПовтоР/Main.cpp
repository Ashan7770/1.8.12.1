#include <fstream>
#include <iostream>
#include <filesystem>
#include "Header.h"
#include "Header1.h"
namespace fs = std::filesystem;
void setFilePermissions(const std::string& filePath)
{
    fs::permissions(filePath,
        fs::perms::owner_read | fs::perms::owner_write,
        fs::perm_options::replace);
}
int main() {
    std::system("chcp 1251");
    std::string aq = "users.txt", aw = "messages.txt";
    std::fstream user_file(aq, std::ios::in | std::ios::out);
    if (!user_file) {

        user_file.open(aq, std::ios::in | std::ios::out | std::ios::trunc);
    }

    std::fstream message_file(aw, std::ios::in | std::ios::out);
    if (!message_file) {

        message_file.open(aw, std::ios::in | std::ios::out | std::ios::trunc);
    }

    if (!user_file && !message_file) {

        std::cout << "Файла нет!" << std::endl;
    }
    else {

        std::string __text, __sender, __receiver;
        std::cout << "Ввод текста:" << std::endl;
        std::cin >> __text;
        std::cout << "Отправитель?" << std::endl;
        std::cin >> __sender;
        std::cout << "Получатель" << std::endl;
        std::cin >> __receiver;
        std::cout << "" << std::endl;



        User user(__text, __sender, __receiver);
        Message message("Helloi", "Alexi", "Bobi");


        setFilePermissions(aq);
        setFilePermissions(aw);

        user_file << user << std::endl;


        message_file << message << std::endl;


        user_file.seekg(0, std::ios_base::beg);
        message_file.seekg(0, std::ios_base::beg);


        User readUser;
        user_file >> readUser;
        std::cout << "User: " << readUser << std::endl;


        Message readMessage;
        message_file >> readMessage;
        std::cout << "Message: " << readMessage << std::endl;

        user_file.close();
        message_file.close();
    }

    return 0;
}