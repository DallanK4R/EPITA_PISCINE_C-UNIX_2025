#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/tinyprintf.h"

TestSuite(tprt);

Test(tprt, literal_only, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    int expected = sprintf(a, "hello world");
    int i = tinyprintf("hello world");
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, empty_format, .init = cr_redirect_stdout)
{
    int i = tinyprintf("");
    fflush(NULL);
    cr_expect(eq(int, i, 0));
    cr_expect_stdout_eq_str("");
}

Test(tprt, percent_literal, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    int expected = sprintf(a, "100%% ok");
    int i = tinyprintf("100%% ok");
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, percent_runs, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    int expected = sprintf(a, "%%%% %% %% %%");
    int i = tinyprintf("%%%% %% %% %%");
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, string_basic, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    int expected = sprintf(a, "hi %s!", "there");
    int i = tinyprintf("hi %s!", "there");
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, string_null, .init = cr_redirect_stdout)
{
    const char *exp = "(null)";
    int i = tinyprintf("%s", (char *)NULL);
    fflush(NULL);
    cr_expect(eq(int, i, (int)strlen(exp)));
    cr_expect_stdout_eq_str(exp);
}

Test(tprt, string_empty, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    int expected = sprintf(a, "%s", "");
    int i = tinyprintf("%s", "");
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, char_basic, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    int expected = sprintf(a, "%c", 'A');
    int i = tinyprintf("%c", 'A');
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, int_positive, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    int expected = sprintf(a, "%d", 12345);
    int i = tinyprintf("%d", 12345);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, int_negative, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    int expected = sprintf(a, "%d", -6789);
    int i = tinyprintf("%d", -6789);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, int_zero, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    int expected = sprintf(a, "%d", 0);
    int i = tinyprintf("%d", 0);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, uint_basic, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    unsigned x = 42;
    int expected = sprintf(a, "%u", x);
    int i = tinyprintf("%u", x);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, uint_zero, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    unsigned x = 0;
    int expected = sprintf(a, "%u", x);
    int i = tinyprintf("%u", x);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, uint_max32, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    unsigned x = UINT_MAX;
    int expected = sprintf(a, "%u", x);
    int i = tinyprintf("%u", x);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, octal_basic, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    unsigned x = 42;
    int expected = sprintf(a, "%o", x);
    int i = tinyprintf("%o", x);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, octal_zero, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    unsigned x = 0;
    int expected = sprintf(a, "%o", x);
    int i = tinyprintf("%o", x);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, hex_lower_basic, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    unsigned x = 255;
    int expected = sprintf(a, "%x", x);
    int i = tinyprintf("%x", x);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, hex_zero, .init = cr_redirect_stdout)
{
    char *a = malloc(64);
    unsigned x = 0;
    int expected = sprintf(a, "%x", x);
    int i = tinyprintf("%x", x);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, unknown_directive_copied, .init = cr_redirect_stdout)
{
    const char *exp = "Good morning ACU! %t Tinyprintf is cool";
    int i = tinyprintf("Good morning ACU! %t Tinyprintf is cool", 12);
    fflush(NULL);
    cr_expect(eq(int, i, (int)strlen(exp)));
    cr_expect_stdout_eq_str(exp);
}

Test(tprt, unknown_then_valid, .init = cr_redirect_stdout)
{
    const char *exp = "X %t Y 7 Z";
    int i = tinyprintf("X %t Y %d Z", 7);
    fflush(NULL);
    cr_expect(eq(int, i, (int)strlen(exp)));
    cr_expect_stdout_eq_str(exp);
}

Test(tprt, many_directives_back_to_back, .init = cr_redirect_stdout)
{
    char *a = malloc(256);
    int expected = sprintf(a, "%d%u%o%x%s%c%%", -12, 34u, 34u, 255u, "ok", 'Z');
    int i = tinyprintf("%d%u%o%x%s%c%%", -12, 34u, 34u, 255u, "ok", 'Z');
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}

Test(tprt, extra_arguments_ignored, .init = cr_redirect_stdout)
{
    int i = tinyprintf("hello", 1, 2, 3);
    fflush(NULL);
    cr_expect(eq(int, i, 5));
    cr_expect_stdout_eq_str("hello");
}

Test(tprt, long_string, .init = cr_redirect_stdout)
{
    char buf[1024];
    char *a = malloc(1100);
    memset(buf, 'A', 1000);
    buf[1000] = '\0';
    int expected = sprintf(a, "%s", buf);
    int i = tinyprintf("%s", buf);
    fflush(NULL);
    cr_expect(eq(int, i, expected));
    cr_expect_stdout_eq_str(a);
    free(a);
}
