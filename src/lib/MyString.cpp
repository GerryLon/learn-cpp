#include "../../include/common/common.h"
#include <string.h>
#include "../../include/lib/MyString.h"

using namespace std;

ostream& operator<<(ostream &out, const MyString &s) {
    out << s.m_s;
    return out;
}

istream& operator>>(istream& in, MyString &s) {
    in >> s.m_s;
    return in;
}

MyString::MyString() {
    m_len = 0;
    m_s = new char[m_len + 1];
    if (m_s) {
        m_s[0] = '\0';
    } else {
        cerr << "MyString::MyString() err\n";
    }
}

MyString::MyString(const char *s) {
    int len = strlen(s);
    m_s = new char[len + 1];
    strcpy(m_s, s);
}

MyString::MyString(int len, char c) {
    if (len < 1) {
        return;
    }
    m_len = len;
    m_s = new char[m_len + 1];
    memset(m_s, c, len);
//    for (int i = 0; i < len; i++) {
//        m_s[i] = c;
//    }
    m_s[len] = '\0';
}

MyString::MyString(const MyString &s) {
    m_len = s.m_len;
    m_s = new char[m_len + 1];
    strcpy(m_s, s.m_s);
}

MyString::~MyString() {
    if (m_s) {
        delete []m_s;
        m_s = NULL;
    }
}

//////////////////////
// MyString s2 = "hello";
MyString& MyString::operator=(const char *s) {
    if (m_s) {
        delete []m_s;
        m_s = NULL;
    }

    m_len = strlen(s);
    m_s = new char[m_len];
    strcpy(m_s, s);

    return *this;
}

// MyString s1;
// MyString s2 = s1;
MyString& MyString::operator=(const MyString &s) {
    if (this == &s) {
        return *this;
    }
    if (m_s) {
        delete []m_s;
        m_s = NULL;
    }
    m_len = s.m_len;
    m_s = new char[m_len];
    strcpy(m_s, s.m_s);
    return *this;
}

char& MyString::operator[](int index) {
    return m_s[index];
}

//////////////////////
MyString& MyString::operator+(const char *str) {
    if (!str) {
        return *this;
    }

    char* tmp = m_s;
    m_len = strlen(tmp) + strlen(str);
    m_s = new char[m_len + 1];
    strcpy(m_s, tmp);
    strcat(m_s, str);
    delete []tmp;
    return *this;
}

MyString& MyString::operator+(const MyString &s) {
    *this = *this + s.m_s; // 利用上边的重载
    return *this;
}

MyString& MyString::operator+=(const char *str) {
    if (!str) {
        return *this;
    }
    *this = *this + str;
    return *this;
}

MyString& MyString::operator+=(const MyString &s) {
    *this = *this + s.m_s;
    return *this;
}

//////////////////////
bool MyString::operator==(const char *str) const {
    return strcmp(m_s, str) == 0;
}

bool MyString::operator==(const MyString &s) const {
    return strcmp(m_s, s.m_s) == 0;
}

bool  MyString::operator!=(const char *str) const {
    return strcmp(m_s, str) != 0;
}

bool  MyString::operator!=(const MyString &s) const {
    return strcmp(m_s, s.m_s) != 0;
}

//////////////////////
bool MyString::operator>(const char *str) const {
    return strcmp(m_s, str) > 0;
}

bool MyString::operator>(const MyString &s) const {
    return strcmp(m_s, s.m_s) > 0;
}

bool MyString::operator<(const char *str) const {
    return strcmp(m_s, str) < 0;
}

bool MyString::operator<(const MyString &s) const {
    return strcmp(m_s, s.m_s) < 0;
}
