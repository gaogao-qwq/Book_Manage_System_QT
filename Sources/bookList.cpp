#include <string>
#include <utility>
#include "bookList.hpp"

BookNode::BookNode(
        float _price, std::string ISBN,
        std::string _book, std::string _author, std::string _press,
        BookNode *_next, BookNode *_prev
) :
        price(_price), ISBN(std::move(ISBN)), book(std::move(_book)),
        author(std::move(_author)), press(std::move(_press)), next(_next), prev(_prev) {}

BookList::BookList(BookNode *h, int s) : head(h), size(s) {}
