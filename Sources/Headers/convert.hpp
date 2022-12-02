#ifndef BOOK_MANAGE_SYSTEM_QT_CONVERT_HPP
#define BOOK_MANAGE_SYSTEM_QT_CONVERT_HPP

#include <map>
#include <string>
#include <fstream>

class Convert {
public:
    Convert() = default;
    ~Convert() = default;

public:
    // 中文转换拼音函数
    static std::string convertZhToPinyin(std::string &zh, std::map<std::string, std::string> pinyin_map);
    // 判断是否是中文函数
    static bool isZh(const char* p);
    // 从文件中获取拼音字典函数
    static int getPinYinMap(std::map<std::string, std::string> &pin_yin_map);
};

#endif //BOOK_MANAGE_SYSTEM_QT_CONVERT_HPP
