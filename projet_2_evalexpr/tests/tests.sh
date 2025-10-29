#!/bin/sh

pass=0
fail=0

run_ok() {
    input="$1"; expected="$2"; desc="$3"
    output=$(echo "$input" | ./evalexpr 2>/dev/null)
    rc=$?
    if [ "$output" = "$expected" ] && [ $rc -eq 0 ]; then
        echo "[OK]  $desc"
        pass=$((pass+1))
    else
        echo "[FAIL] $desc"
        echo "  input:    '$input'"
        echo "  expected: '$expected' (rc=0)"
        echo "  got:      '$output' (rc=$rc)"
        fail=$((fail+1))
    fi
}

run_ok_rpn() {
    input="$1"; expected="$2"; desc="$3"
    output=$(echo "$input" | ./evalexpr -rpn 2>/dev/null)
    rc=$?
    if [ "$output" = "$expected" ] && [ $rc -eq 0 ]; then
        echo "[OK]  $desc"
        pass=$((pass+1))
    else
        echo "[FAIL] $desc"
        echo "  input:    '$input' (RPN)"
        echo "  expected: '$expected' (rc=0)"
        echo "  got:      '$output' (rc=$rc)"
        fail=$((fail+1))
    fi
}

run_err() {
    input="$1"; exp_rc="$2"; desc="$3"
    output=$(echo "$input" | ./evalexpr 2>/dev/null)
    rc=$?
    if [ -z "$output" ] && [ $rc -eq $exp_rc ]; then
        echo "[OK]  $desc"
        pass=$((pass+1))
    else
        echo "[FAIL] $desc"
        echo "  input:    '$input'"
        echo "  expected: '' (rc=$exp_rc)"
        echo "  got:      '$output' (rc=$rc)"
        fail=$((fail+1))
    fi
}

run_err_rpn() {
    input="$1"; exp_rc="$2"; desc="$3"
    output=$(echo "$input" | ./evalexpr -rpn 2>/dev/null)
    rc=$?
    if [ -z "$output" ] && [ $rc -eq $exp_rc ]; then
        echo "[OK]  $desc"
        pass=$((pass+1))
    else
        echo "[FAIL] $desc"
        echo "  input:    '$input' (RPN)"
        echo "  expected: '' (rc=$exp_rc)"
        echo "  got:      '$output' (rc=$rc)"
        fail=$((fail+1))
    fi
}

run_badarg() {
    input="$1"; arg="$2"; desc="$3"
    output=$(echo "$input" | ./evalexpr "$arg" 2>/dev/null)
    rc=$?
    if [ -z "$output" ] && [ $rc -eq 4 ]; then
        echo "[OK]  $desc"
        pass=$((pass+1))
    else
        echo "[FAIL] $desc"
        echo "  arg:      $arg"
        echo "  expected: '' (rc=4)"
        echo "  got:      '$output' (rc=$rc)"
        fail=$((fail+1))
    fi
}

echo "Running evalexpr functional tests"
echo

run_ok "1+1" "2" "sn1"
run_ok "2^3^2" "512" "sn2"
run_ok "(1+2)*3" "9" "sn3"
run_ok "7%4" "3" "sn4"
run_ok "5*(2^2+3)-8/2+9%4" "32" "sn5"
run_ok "   8 +  2 * 3" "14" "snqdf"
run_ok "0+0*5^0" "0" "snqfd1"
run_ok "(2^(3^2))" "512" "snqfdgfs1"
run_ok "-5+2*10" "15" "snsfgsfg1"
run_ok "10%6*3+2^3^2" "524" "sngfssgf1"
run_ok "20000*3+5" "60005" "fsggsf"
run_ok "((((3+2))))*(1+(2*(1+1)))" "25" "sngsffgs1"
run_ok "" "" "sfgsfsgn1"

run_ok_rpn "1 1 +" "2" "qfdqfdg"
run_ok_rpn "2 3 * 1 +" "7" "sgfsfghfsgh"
run_ok_rpn "8 2 + 3 1 + *" "40" "ghfsdhfghfs"
run_ok_rpn "10 6 % 3 * 2 3 2 ^ ^ +" "524" "sfghfshfhs"
run_ok_rpn "0 5 - 2 10 * +" "15" "qerfsfgsfgh"

run_err "5/0" 3 "hgsfdsfgh"
run_err "1(+1)" 2 "qfssgdsgdf"
run_err "a+1" 1 "shfghdf"
run_err "2^-1" 3 "sgfhsfdhfsdg"

run_err_rpn "1 +" 2 "qfdgsfghsfd"
run_err_rpn "1 0 /" 3 "dgjhfjdhtg"
run_err_rpn "1 a +" 1 "dhgdhgghd"
run_err_rpn "" 0 "dghfdhgdghghdj"

run_badarg "1+1" "--toto" "dhgdgjhjhgd"

echo
echo "Summary:"
echo "  Passed: $pass"
echo "  Failed: $fail"

[ $fail -eq 0 ] && { echo "All tests passed"; exit 0; }
echo "$fail test(s) failed"; exit 1
