#ifndef BOOK_MANAGE_SYSTEM_QT_PINYINMAPPARSER_HPP
#define BOOK_MANAGE_SYSTEM_QT_PINYINMAPPARSER_HPP

#include <map>
#include <string>
#include <fstream>

using namespace std;
class PinyinMapParser {
public:
    // 构造函数
    PinyinMapParser() = default;
    // 析构函数
    ~PinyinMapParser() = default;

public:
    // 从文件中获取拼音字典
    static int GetPinYinMap(string& path, map<string, string>& pin_yin_map);
};

#endif //BOOK_MANAGE_SYSTEM_QT_PINYINMAPPARSER_HPP
