#include <limits.h>

inline bool is_num(char s) {
    return s >= '0' && s <= '9';
}

int myAtoi(char* s) {
    long long res = 0;
    bool is_negative = false;

    if (!s || strlen(s) == 0) {
        return res;
    }

    while (*s == ' ') {
        s++;
    }

    if (*s == '-') {
        is_negative = true;
        s++;

        if (!is_num(*s)) {
            return res;
        }
    }

    if (*s == '+') {
        s++;

        if (!is_num(*s)) {
            return res;
        }
    }

    long long temp = res;

    while (is_num(*s)) {
        temp = res * 10;
        temp = temp + (*s - '0');
        
        if (temp > INT_MAX) {
            res = is_negative ? INT_MIN : INT_MAX;
            return res;
        }
        
        res = temp;
        s++;
    }

    if (is_negative) {
        return res * -1;
    }

    return res;
}