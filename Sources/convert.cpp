#include "convert.hpp"

std::string Convert::convertZhToPinyin(std::string &zh, std::unordered_map<std::string, std::string> pinyin_map) {
    std::string convert_str;
    // 逐个字符检查
    for (size_t i = 0; i < zh.length(); ++i) {
        try {
            std::string tmp_str;
            const char *p = &zh.at(i);
            // 中文占用三个字节，utf8 中三字节编码第一个字节前四位是 1110
            if ((*p & 0xF0) == 0xE0 && isZh(p)) {
                tmp_str.append(&zh.at(i), 3);
                // 从字典里找对应的拼音
                if (pinyin_map.find(tmp_str) != pinyin_map.end())
                    convert_str.append(pinyin_map[tmp_str]);
                else
                    convert_str.append(tmp_str);
                i += 2;
            }
            else
                convert_str.append(p, 1);
        }
        catch (...) {
            return convert_str;
        }
    }
    return convert_str;
}

bool Convert::isZh(const char* p) {
    if (p == nullptr) return false;

    // 中文unicode编码范围是 0X4E00~0X9FA5，即 utf8 范围 0xe4b880 ~ 0xe9baa5
    if ((*p & 0xF0) == 0xE0) {
        if (*(p + 1) == '\0' || *(p + 2) == '\0')
            return false;

        unsigned char v = *p;
        unsigned char v1 = *(p + 1);
        unsigned char v2 = *(p + 2);

        if ((v1 & 0xC0) != 0x80 || (v2 & 0xC0) != 0x80)
            return false;
        if (v < 0xE4)
            return false;
        if (v == 0xE4 && v1 < 0xB8)
            return false;
        if (v == 0xE4 && v1 == 0xB8 && v2 < 0x80)
            return false;
        if (v > 0xE9)
            return false;
        if (v == 0xE9 && v1 > 0xBE)
            return false;
        if (v == 0xE9 && v1 == 0xBE && v2 > 0xB5)
            return false;

        p += 3;
        return true;
    }
    return false;
}

int Convert::getPinYinMap(std::unordered_map<std::string, std::string> &pin_yin_map) {
    QFile file(":/lib/lib/pinyin.txt");
    if (!file.open(QIODevice::ReadOnly))
        return -1;

    // 读取拼音字库文件
    QTextStream in(&file);

    while (!in.atEnd()) {
        std::string tmp_pinyin;
        QString tmp;

        // 每次读取一行，拼音文件格式：王=wang1,wang2，数字表示声调
        in >> tmp;
        tmp_pinyin = tmp.toStdString();
        if (tmp_pinyin.find('=') != std::string::npos) {
            std::string zh, pinyin;
            size_t i = tmp_pinyin.find_first_of('=');

            if (i != std::string::npos && i != tmp_pinyin.size() - 1) {
                // 多音字只取第一个发音
                zh.assign(tmp_pinyin, 0, i);
                pinyin.assign(tmp_pinyin, i + 1, tmp_pinyin.size() - i - 1);

                // 去掉拼音末尾声调
                if (pinyin.find(',') != std::string::npos) {
                    size_t j = pinyin.find(',');
                    pinyin.assign(pinyin, 0, j - 1);
                }
                else
                    pinyin.assign(pinyin.begin(), pinyin.end() - 1);
                // 取出来后放到 map 里
                pin_yin_map[zh] = pinyin;
            }
        }
    }
    file.close();
    return 0;
}
