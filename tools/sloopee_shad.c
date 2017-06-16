// Sloopee Shadow (Denotes who is being Slooped)
// Gon
// 2017-04

#include  <ansi.h>

inherit AnsiTellCode;

void sh_init(object ob ) {
    shadow( ob, 1 );
    return;
}

string short() {
    return( query_shadowing(THISO)->short() )+ BOLD_GREEN" [Slooped]" NORM;
}
