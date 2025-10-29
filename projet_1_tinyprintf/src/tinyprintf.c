#include "tinyprintf.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int slen(const char *t) {
  int k = 0;
  while (t[k] != '\0')
    k++;
  return k;
}

static void reverse_span(char *s, int start, int len) {
  int i = 0;
  int j = len - 1;

  while (i < j) {
    char tmp = s[start + i];
    s[start + i] = s[start + j];
    s[start + j] = tmp;
    i++;
    j--;
  }
}

char *mu(unsigned int n, char *s, const char *base) {
  int len = slen(base);
  int i = 0;
  if (n == 0) {
    s[i++] = base[0];
  } else {
    unsigned int k = (unsigned int)len;
    while (n > 0) {
      s[i++] = base[n % k];
      n /= k;
    }
  }
  reverse_span(s, 0, i);
  s[i] = '\0';
  return s;
}

char *myb(int n, char *s, const char *base) {
  int len = slen(base);
  long long v = n;
  int neg = 0;

  if (len == 10 && v < 0) {
    neg = 1;
    v = -v;
  }

  int i = 0;
  if (neg)
    i = 1;

  if (v == 0) {
    s[i] = base[0];
    i++;
  } else {
    int k = len;
    while (v > 0) {
      int d = (int)(v % k);
      s[i] = base[d];
      i++;
      v /= k;
    }
  }

  if (neg)
    s[0] = '-';

  reverse_span(s, neg, i - neg);
  s[i] = '\0';
  return s;
}

int *pstr(char *s, int *cpt) {
  if (!s)
    s = "(null)";
  int i = 0;
  while (s[i]) {
    putchar(s[i]);
    i++;
  }
  *cpt += i;
  return cpt;
}

int *printchar(char s, int *cpt) {
  putchar(s);
  *cpt += 1;
  return cpt;
}

int finalreturn(int *cpt) {
  int k = *cpt;
  free(cpt);
  return k;
}

int *earlyf() {
  int *k = malloc(sizeof(int));
  *k = 0;
  return k;
}

int tinyprintf(const char *format, ...) {
  int *cpt = earlyf();
  va_list ap;
  int i = 0;
  va_start(ap, format);
  while (format[i]) {
    if (format[i] != '%')
      printchar(format[i], cpt);
    else {
      char *s = malloc(sizeof(char) * 15);
      switch (format[i + 1]) {
      case '%':
        printchar('%', cpt);
        break;
      case 'd':
        pstr(myb(va_arg(ap, int), s, "0123456789"), cpt);
        break;
      case 'u':
        pstr(mu(va_arg(ap, unsigned int), s, "0123456789"), cpt);
        break;
      case 's':
        pstr(va_arg(ap, char *), cpt);
        break;
      case 'c':
        printchar(va_arg(ap, int), cpt);
        break;
      case 'o':
        pstr(mu(va_arg(ap, unsigned int), s, "01234567"), cpt);
        break;
      case 'x':
        pstr(mu(va_arg(ap, unsigned int), s, "0123456789abcdef"), cpt);
        break;
      default:
        printchar(format[i], cpt);
        i--;
      }
      i++;
      free(s);
    }
    i++;
  }
  va_end(ap);
  return finalreturn(cpt);
}
