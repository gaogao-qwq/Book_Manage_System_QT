#include <QApplication>
#include "mainmenu.hpp"
#include "bookList.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto b1 = new BookNode(56.4, "9787519817749", "Effective Modern C++（中文版）", "Scott Meyers", "中国电力出版社");
    auto b2 = new BookNode(86.2, "9787111213826", "Java 编程思想", "Bruce Eckel", "机械工业出版社");
    auto b3 = new BookNode(67.8, "7121085119", "程序员的自我修养 : 链接、装载与库", "俞甲子 石凡 潘爱民", "电子工业出版社");
    auto b4 = new BookNode(75.7, "9787115564177", "现代C++语言核心特性解析", "谢丙堃", "人民邮电出版社");
    auto b5 = new BookNode(55.5, "9787511733696", "意识形态的崇高客体", "Slavoj Zizek", "中央编译出版社");
    auto b6 = new BookNode(56.4, "9787100156431", "存在与时间", "Martin Heidegger", "商务印书馆");
    auto b7 = new BookNode(74.3, "9787115279460", "C++ Primer Plus（第6版）中文版", "Stephen Prata", "人民邮电出版社");
    auto b8 = new BookNode(74.3, "9787115279460", "C++ Primer Plus（第6版）中文版", "Stephen Prata", "人民邮电出版社");
    auto b9 = new BookNode(259.6, "9787115585028", "On Java 中文版 基础卷+进阶卷（共2册）", "Bruce Eckel", "人民邮电出版社");
    b1->next = b2, b2->prev = b1, b2->next = b3, b3->prev = b2, b3->next = b4, b4->prev = b3,
    b4->next = b5, b5->prev = b4, b5->next = b6, b6->prev = b5, b6->next = b7, b7->prev = b6,
    b7->next = b8, b8->prev = b7, b8->next = b9, b9->prev = b8;
    auto w_mainMenu = new mainMenu(nullptr, new BookList(b1, 9));
    w_mainMenu->show();
    return QApplication::exec();
}
