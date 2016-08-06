// RUN: grep -Ev "// *[A-Z0-9-]+:" %s | grep -Ev "^//$" \
// RUN:   | clang-format -style="{BasedOnStyle: LLVM, IndentWidth: 4, \
// RUN:                           ColumnLimit: 40}" \
// RUN:   | FileCheck -strict-whitespace -check-prefix=CHECK1 %s
//
// RUN: grep -Ev "// *[A-Z0-9-]+:" %s | grep -Ev "^//$" \
// RUN:   | clang-format -style="{BasedOnStyle: LLVM, IndentWidth: 4, \
// RUN:                           ColumnLimit: 40, BreakBeforeBraces: Custom, \
// RUN:                           BraceWrapping: { \
// RUN:                               AfterMultilineControlStatement: true}}" \
// RUN:   | FileCheck -strict-whitespace -check-prefix=CHECK2 %s
//
/**/
if (short_condition) { some_code(1); some_code(2); }
/**/
if (long_condition + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) { some_code(3); some_code(4); }
/**/
switch (short_condition) { case 1: break; }
/**/
switch (long_condition + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) { case 1: break; }
/**/
while (short_condition) { i++; j++; }
/**/
while (long_condition + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) { i++; j++; }
/**/
for (i = 0; short_condition; i ++) { j++; k++; }
/**/
for (i = 0; long_condition + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8; i ++) { j++; k++; }
// CHECK1: /**/
// CHECK1-NEXT: if (short_condition) {
// CHECK1-NEXT:     some_code(1);
// CHECK1-NEXT:     some_code(2);
// CHECK1-NEXT: }
// CHECK1-NEXT: /**/
// CHECK1-NEXT: if (long_condition + 1 + 2 + 3 + 4 + 5 +
// CHECK1-NEXT:     6 + 7 + 8) {
// CHECK1-NEXT:     some_code(3);
// CHECK1-NEXT:     some_code(4);
// CHECK1-NEXT: }
// CHECK1-NEXT: /**/
// CHECK1-NEXT: switch (short_condition) {
// CHECK1-NEXT: case 1:
// CHECK1-NEXT:     break;
// CHECK1-NEXT: }
// CHECK1-NEXT: /**/
// CHECK1-NEXT: switch (long_condition + 1 + 2 + 3 + 4 +
// CHECK1-NEXT:         5 + 6 + 7 + 8) {
// CHECK1-NEXT: case 1:
// CHECK1-NEXT:     break;
// CHECK1-NEXT: }
// CHECK1-NEXT: /**/
// CHECK1-NEXT: while (short_condition) {
// CHECK1-NEXT:     i++;
// CHECK1-NEXT:     j++;
// CHECK1-NEXT: }
// CHECK1-NEXT: /**/
// CHECK1-NEXT: while (long_condition + 1 + 2 + 3 + 4 +
// CHECK1-NEXT:        5 + 6 + 7 + 8) {
// CHECK1-NEXT:     i++;
// CHECK1-NEXT:     j++;
// CHECK1-NEXT: }
// CHECK1-NEXT: /**/
// CHECK1-NEXT: for (i = 0; short_condition; i++) {
// CHECK1-NEXT:     j++;
// CHECK1-NEXT:     k++;
// CHECK1-NEXT: }
// CHECK1-NEXT: /**/
// CHECK1-NEXT: for (i = 0; long_condition + 1 + 2 + 3 +
// CHECK1-NEXT:             4 + 5 + 6 + 7 + 8;
// CHECK1-NEXT:      i++) {
// CHECK1-NEXT:     j++;
// CHECK1-NEXT:     k++;
// CHECK1-NEXT: }
//
// CHECK2: /**/
// CHECK2-NEXT: if (short_condition) {
// CHECK2-NEXT:     some_code(1);
// CHECK2-NEXT:     some_code(2);
// CHECK2-NEXT: }
// CHECK2-NEXT: /**/
// CHECK2-NEXT: if (long_condition + 1 + 2 + 3 + 4 + 5 +
// CHECK2-NEXT:     6 + 7 + 8)
// CHECK2-NEXT: {
// CHECK2-NEXT:     some_code(3);
// CHECK2-NEXT:     some_code(4);
// CHECK2-NEXT: }
// CHECK2-NEXT: /**/
// CHECK2-NEXT: switch (short_condition) {
// CHECK2-NEXT: case 1:
// CHECK2-NEXT:     break;
// CHECK2-NEXT: }
// CHECK2-NEXT: /**/
// CHECK2-NEXT: switch (long_condition + 1 + 2 + 3 + 4 +
// CHECK2-NEXT:         5 + 6 + 7 + 8)
// CHECK2-NEXT: {
// CHECK2-NEXT: case 1:
// CHECK2-NEXT:     break;
// CHECK2-NEXT: }
// CHECK2-NEXT: /**/
// CHECK2-NEXT: while (short_condition) {
// CHECK2-NEXT:     i++;
// CHECK2-NEXT:     j++;
// CHECK2-NEXT: }
// CHECK2-NEXT: /**/
// CHECK2-NEXT: while (long_condition + 1 + 2 + 3 + 4 +
// CHECK2-NEXT:        5 + 6 + 7 + 8)
// CHECK2-NEXT: {
// CHECK2-NEXT:     i++;
// CHECK2-NEXT:     j++;
// CHECK2-NEXT: }
// CHECK2-NEXT: /**/
// CHECK2-NEXT: for (i = 0; short_condition; i++) {
// CHECK2-NEXT:     j++;
// CHECK2-NEXT:     k++;
// CHECK2-NEXT: }
// CHECK2-NEXT: /**/
// CHECK2-NEXT: for (i = 0; long_condition + 1 + 2 + 3 +
// CHECK2-NEXT:             4 + 5 + 6 + 7 + 8;
// CHECK2-NEXT:      i++)
// CHECK2-NEXT: {
// CHECK2-NEXT:     j++;
// CHECK2-NEXT:     k++;
// CHECK2-NEXT: }
