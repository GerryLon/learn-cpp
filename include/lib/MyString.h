#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <iostream>
#include <string>

class MyString
{
    // ���� << ������
	friend std::ostream& operator<<(std::ostream &out, const MyString& str);

	// ���� >> ������
	friend std::istream& operator>>(std::istream& in, MyString& str);

    public:
        MyString();                         // �޲ι���
        MyString(const char *s);            // �вι���
        MyString(int len, char c = '\0');   // �вι���
        MyString(const MyString &s);        // ��������
        virtual ~MyString();                        // ��������

    // ����=��[]������
    public:
        MyString& operator=(const char *s);       // ��ͨ�ַ�����ֵ
        MyString& operator=(const MyString &s);   // �����֮�丳ֵ
        char & operator[](int index);

    // ���� + �����
    public:
        MyString& operator+(const char *str);
        MyString& operator+(const MyString &s);

        MyString& operator+=(const char *str);
        MyString& operator+=(const MyString &s);

    // ���� == !=
    public:
        bool operator==(const char *str) const;
        bool operator==(const MyString &s) const;

        bool operator!=(const char *str) const;
        bool operator!=(const MyString &s) const;

    // ���� < >
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
        int m_len;    // �ַ�������
        char *m_s;  // �ַ�������
};

#endif // _MYSTRING_H
