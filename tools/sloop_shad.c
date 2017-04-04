inherit AnsiTellCode;
#include <ansi.h>

object me;

has_sloop_shadow() { return 1; }

void do_sloop(int time)
{
    call_out("remove_sloop_shadow", time );
}

sh_init(object who, int time)
{
    me = who;
    shadow( me, 1 );
    do_sloop(time);
}

void remove_sloop_shadow()
{
    ansi_tell(me, "You are no longer being slooped".BOLD_GREEN );
    remove_shadow( THISO );
    destruct( THISO );
}

short()
{
    return me->short() + BOLD_GREEN" [slooped]";
}
