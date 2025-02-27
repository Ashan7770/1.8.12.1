#include "Header1.h"

Message::Message(const std::string& text, const std::string& sender, const std::string& receiver)
    : _text(text), _sender(sender), _receiver(receiver) {}

std::fstream& operator >>(std::fstream& is, Message& obj) {
    is >> obj._text;
    is >> obj._sender;
    is >> obj._receiver;
    return is;
}

std::ostream& operator <<(std::ostream& os, const Message& obj) {
    os << obj._text;
    os << ' ';
    os << obj._sender;
    os << ' ';
    os << obj._receiver;
    return os;
}