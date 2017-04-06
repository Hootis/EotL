#include  <ansi.h>
inherit AnsiTellCode;
string shad;

void sh_init(object ob )
{
    string shad=" [slooped]";
    shadow( ob, 1 );
    return;
}

string short()
{
    return( query_shadowing(THISO)->short() )+ BOLD_GREEN"" + shad + "" NORM;
}
