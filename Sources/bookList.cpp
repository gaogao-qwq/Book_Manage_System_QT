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

BookNode *BookList::sortByPrice(BookNode *h) {
    // 分割递归终止条件
    if(h == nullptr || h->next == nullptr) return h;
    // 定义并初始化快慢指针
    auto fast = h->next, slow = h;
    while(fast != nullptr && fast->next != nullptr) {
        // 慢指针一次移动一个结点
        slow = slow->next;
        // 快指针一次移动两个结点
        fast = fast->next->next;
    }
    // 循环结束后快指针指向链表尾部 nullptr，慢指针指向链表中间结点的前驱结点。
    // 用 tmp 缓存中间结点，然后从中间分割链表。
    auto tmp = slow->next;
    slow->next = nullptr;
    auto left = sortByPrice(h);
    auto right = sortByPrice(tmp);

    // 合并递归
    auto _h = new BookNode();
    auto res = _h;
    while(left != nullptr && right != nullptr) {
        if(left->price < right->price) {
            _h->next = left;
            left = left->next;
        } else {
            _h->next = right;
            right = right->next;
        }
        _h = _h->next;
    }
    _h->next = (left != nullptr) ? left : right;
    return res->next;
}
