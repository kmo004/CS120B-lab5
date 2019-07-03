# Test file for CS120B-Lab3


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


test "PINA: 0x0E => PORTC: 8, state = PLUS"
set state = START
setPINA 0x0E
continue 2
expectPORTC 0x08
expect state PLUS
check results

test "PINA: 0x0E => PORTC: 9, state = PLUS"
set state = START
setPINA 0x0E
continue 2
expectPORTC 0x09
expect state PLUS
check results

test "PINA: 0x0E => PORTC: 9, state = PLUS (PAST MAX VALUE)"
set state = START
setPINA 0x0E
continue 2
expectPORTC 0x09
expect state PLUS
check results

test "PINA: 0x0E => PORTC: 8, state = MINUS"
set state = START
setPINA 0x0D
continue 2
expectPORTC 0x08
expect state MINUS
check results

test "PINA: 0x0E => PORTC: 7, state = MINUS"
set state = START
setPINA 0x0D
continue 2
expectPORTC 0x07
expect state MINUS
check results

test "PINA: 0x0E => PORTC: 6, state = MINUS"
set state = START
setPINA 0x0D
continue 2
expectPORTC 0x06
expect state MINUS
check results

test "PINA: 0x0E => PORTC: 7, state = PLUS"
set state = START
setPINA 0x0E
continue 2
expectPORTC 0x07
expect state PLUS
check results

test "PINA: 0x0E => PORTC: 7, state = RESET"
set state = START
setPINA 0x00
continue 2
expectPORTC 0x00
expect state RESET
check results

test "PINA: 0x0E => PORTC: 0, state = MINUS (PAST MIN VALUE)"
set state = START
setPINA 0x0D
continue 2
expectPORTC 0x00
expect state MINUS
check results












# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
