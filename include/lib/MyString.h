#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <iostream>
#include <string>

class MyString
{
    // 重载 << 操作符
	friend std::ostream& operator<<(std::ostream &out, const MyString& str);

	// 重载 >> 操作符
	friend std::istream& operator>>(std::istream& in, MyString& str);

    public:
        MyString();                         // 无参构造
        MyString(const char *s);            // 有参构造
        MyString(int len, char c = '\0');   // 有参构造
        MyString(const MyString &s);        // 拷贝构造
        virtual ~MyString();                        // 析构函数

    // 重载=、[]操作符
    public:
        MyString& operator=(const char *s);       // 普通字符串赋值
        MyString& operator=(const MyString &s);   // 类对象之间赋值
        char & operator[](int index);

    // 重载 + 运算符
    public:
        MyString& operator+(const char *str);
        MyString& operator+(const MyString &s);

        MyString& operator+=(const char *str);
        MyString& operator+=(const MyString &s);

    // 重载 == !=
    public:
        bool operator==(const char *str) const;
        bool operator==(const MyString &s) const;

        bool operator!=(const char *str) const;
        bool operator!=(const MyString &s) const;

    // 重载 < >
    public:
        bool operator>(const char *str) const;
        bool operator>(const MyString &s) const;

        bool operator<(const char *str) const;
        bool operator<(const MyString &s) const;

public:
	const char *str() {
        return this->m_s;
	}

	int length() {
		return this->m_len;
	}

	bool empty() {
        return this->m_len == 0;
	}

    protected:

    private:
        int m_len;    // 字符串长度
        char *m_s;  // 字符串数据
};

#endif // _MYSTRING_H
