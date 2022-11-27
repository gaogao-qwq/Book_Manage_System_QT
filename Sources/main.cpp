#include <QApplication>
#include "main_menu.hpp"
#include "bookList.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto b1 = new BookNode(23, "0987", "1986", "Apple", "Apple Inc.");
    auto b2 = new BookNode(32, "4390", "We", "Charlie", "Charlie Inc.");
    auto b3 = new BookNode(10, "4456", "Beautiful New World", "Braval", "Braval Inc.");
    b1->next = b2, b2->prev = b1, b2->next = b3, b3->prev = b2;
    auto w_mainMenu = new Main_Menu(
        nullptr, new BookList(b1, 3));
    w_mainMenu->show();
    return QApplication::exec();
}
