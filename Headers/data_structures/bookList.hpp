#ifndef BOOK_MANAGE_SYSTEM_QT_BOOKLIST_HPP
#define BOOK_MANAGE_SYSTEM_QT_BOOKLIST_HPP

#include <string>
#include <utility>

// 这里用的还是自己写的双链表而不是 QT 自带的 map_node，方便不熟悉 QT 的人也能读懂
class BookNode {
public:
    float price;
    std::string ISBN;
    std::string book;
    std::string author;
    std::string press;

    BookNode *next;
    BookNode *prev;

public:
    // 构造函数
    explicit BookNode(
        float _price = 0.0, std::string ISBN = "",
        std::string _book = "", std::string _author = "", std::string _press = "",
        BookNode *_next = nullptr, BookNode *_prev = nullptr
    ) :
            price(_price), ISBN(std::move(ISBN)), book(std::move(_book)),
            author(std::move(_author)), press(std::move(_press)), next(_next), prev(_prev) {};
    // 析构函数
    ~BookNode() = default;
};

class BookList {
public:
    BookNode *head;
    int size;

public:
    // 构造函数
    explicit BookList(BookNode *h = nullptr, int s = 0) : head(h), size(s) {};
    // 析构函数
    ~BookList() = default;
};


#endif //BOOK_MANAGE_SYSTEM_QT_BOOKLIST_HPP
