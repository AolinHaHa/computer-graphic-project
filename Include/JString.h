#ifndef __JSTRING_H__
#define __JSTRING_H__

// Disable warnings about older C string functions
#pragma warning(disable : 4996)

#include <iostream>
using namespace std;

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

bool IsWhitespace(char k);
bool IsNumeric(char k);

class jstring
{
public:

    enum { DEF_STRING_LEN = 20 };

    jstring(size_t Size = DEF_STRING_LEN);
    jstring(const char *source);
    jstring(const jstring& source);
    ~jstring();

    jstring& operator=(const jstring &source);

    void erase(void) { *buffer = '\0'; }
    void resize(size_t newSize);
    void insert(const char *source, size_t location);
    void insert(const jstring &source, size_t location);
    void overwrite(const char *source, size_t location);
    void overwrite(const jstring& source, size_t location) { overwrite(source.buffer, location); }
    
    void trimLeft(void);
    void trimRight(void);
    void trim(void) { trimLeft(); trimRight(); }

    void setInputDelimiter(char *delims);
	void setInputDelimiter(const jstring& s) { setInputDelimiter(s.buffer); }

    size_t length(void) const { return ::strlen(buffer); }
    bool isEmpty(void) const { return (*buffer == '\0'); }

    jstring left(size_t count) const;
    jstring right(size_t count) const;
    jstring mid(size_t pos, size_t count) const;

    void deleteRange(int start, int nChars);

    char& operator[](size_t index);
	const char& operator[](size_t index) const;

    jstring &operator+=(const jstring& string1);
	jstring &operator+=(const long k);
	
    bool operator==(const jstring& string1) const { return (::strcmp(buffer, string1.buffer) == 0); }
    bool operator>(const jstring& string1) const { return (::strcmp(buffer, string1.buffer) > 0); }
    bool operator>=(const jstring& string1) const { return (::strcmp(buffer, string1.buffer) >= 0); }
    bool operator<(const jstring& string1) const { return (::strcmp(buffer, string1.buffer) < 0); }
    bool operator<=(const jstring& string1) const { return (::strcmp(buffer, string1.buffer) <= 0); }
    bool operator!=(const jstring& string1) const { return (::strcmp(buffer, string1.buffer) != 0); }

	int strlen(void) { return ::strlen(buffer); }
	int strspn(const jstring& s) { return ::strspn(buffer, s.buffer); }

	int strcmp(const jstring& str) const { return ::strcmp(buffer, str.buffer); }
	int strcmp(const char *str) const { return ::strcmp(buffer, str); }
	int strncmp(const jstring& str, size_t count) const { return ::strncmp(buffer, str.buffer, count); }
	int strncmp(const char *str, size_t count) const { return ::strncmp(buffer, str, count); }

	jstring& strcat(const jstring& s) 
		{ size_t resLen = length() + s.length() + 1; if (resLen > size) resize(resLen);
		  ::strcat(buffer, s.buffer); return *this; }
	jstring& strcat(const char *s) 
	{ size_t resLen = length() + ::strlen(s) + 1; if (resLen > size) resize(resLen);
		  ::strcat(buffer, s); return *this; }
	jstring& strncat(const jstring& s, size_t n) 
		{ size_t resLen = length() + n + 1; if (resLen > size) resize(resLen);
		  ::strcat(buffer, s.buffer); return *this; }
	jstring& strncat(const char *s, size_t n) 
		{ size_t resLen = length() + n + 1; if (resLen > size) resize(resLen);
		  ::strcat(buffer, s); return *this; }

    size_t Width, Precision;
    bool Right, Scientific, LeadingPlus, LeadingSpace, ShowPoint, Zeros;

    size_t width(size_t w) { size_t old = Width; Width = w; return old; }
    size_t precision(size_t p) { size_t old = Precision; Precision = p; return old; }
    bool rightJustify(bool r) { bool old = Right; Right = r; return old; }
    bool padZeros(bool z) { bool old = Zeros; Zeros = z; return old; }
    bool scientific(bool s) { bool old = Scientific; Scientific = s; return old; }
    bool leadingPlus(bool s) { bool old = LeadingPlus; LeadingPlus = s; return old; }
    bool leadingSpace(bool s) { bool old = LeadingSpace; LeadingSpace = s; return old; }
    bool showPoint(bool s) { bool old = ShowPoint; ShowPoint= s; return old; }

    jstring& operator<<(double d);
    jstring& operator<<(short k) { return(operator<<(long(k))); }
    jstring& operator<<(int k) { return(operator<<(long(k))); }
    jstring& operator<<(long k);
    jstring& operator<<(unsigned short k) { return(operator<<(unsigned long(k))); }
    jstring& operator<<(unsigned int k) { return(operator<<(unsigned long(k))); }
    jstring& operator<<(unsigned long k);
    jstring& operator<<(const char *s);
    jstring& operator<<(const char s);
    jstring& operator<<(const jstring& s);

    jstring& operator>>(double &d);
    jstring& operator>>(short &d);
    jstring& operator>>(int &d);
    jstring& operator>>(long &d);
    jstring& operator>>(unsigned short &d);
    jstring& operator>>(unsigned int &d);
    jstring& operator>>(unsigned long &d);
    jstring& operator>>(jstring& s);
    jstring& operator>>(char *s);
    jstring& operator>>(char &c);

	friend ostream& operator<<(ostream& output, const jstring& source);
    friend istream& operator>>(istream& input, jstring& dest);
    friend class TextWindow;

    jstring getNextToken(char *delims, bool procToken = true);
    jstring removeNextToken(char *delims, bool procToken = true);
    jstring getNextToken(const jstring& delims, bool procToken = true) { return getNextToken(delims.buffer, procToken); }
    jstring removeNextToken(const jstring& delims, bool procToken = true) { return(removeNextToken(delims.buffer, procToken)); }
	jstring getNextNumber(char *delims, bool procToken);
	jstring removeNextNumber(char *delims, bool procToken);
    jstring getNextNumber(const jstring& delims, bool procToken = true) { return getNextNumber(delims.buffer, procToken); }
    jstring removeNextNumber(const jstring& delims, bool procToken = true) { return(removeNextNumber(delims.buffer, procToken)); }
    bool moreTokens(void) { return (*nextToken != '\0'); }
    void resetTokens(void);

	char *getBuffer(void) { return buffer; }
	const char *getConstBuffer(void) const { return buffer; }

private:

    enum { MAX_DELIM_LENGTH = 255 };

    static char inputDelimiter[MAX_DELIM_LENGTH + 1];
	static char numberDelimiter[MAX_DELIM_LENGTH + 1];
    static size_t delimCount;
    static bool initialized;

    size_t size; // size of buffer
    char *buffer;

    char *nextToken;

    void setup(void);
    void makeFormatString(char *format);
};

jstring operator+(const jstring &string1, const jstring &string2);
jstring operator+(const jstring &string1, const long k);

#endif