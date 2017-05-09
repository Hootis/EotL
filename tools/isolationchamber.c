// Gon
// 2017-04

inherit RoomPlusCode;

#include <ansi.h>

#define SLOOP_FUNCTIONS "/usr/gon/tools/sphere"

void extra_create() {

    set( "short", "Inside the Isolation Chamber" ); 
    set ( "ansi_short" , BOLD_BLACK "Inside the Isolation Chamber" );
    set( "day_long" , "The interior of the chamber is bright enough "
        "to see clearly, but has the feel of candle-light. There are no "
        "obvious sources of light. The dark walls are covered with "
         "sound dampeners, and there isn't much of an echo. The "
         "room is fairly large with plush carpet and several large, "
         "comfortable chairs. A well-stocked bar service stands off to "
         "one side with all the accoutrements one would need to "
         "make a refreshing drink. This looks like a good place to have "
         "a private conversation. There is a huge wheel on the door "
         "that looks like it could be used to secure the door.");
    set( "day_light" , PART_LIT );
    set( "night_light" , PART_LIT );
    set( InsideP, 1 );
    set( "exits" , ( [ "lab" : "/usr/gon/workroom.c", ] ) );
    set( "descs", ([
        "door": "You see a large wheel that looks like it operates the "
            "locking mechanism",
        ({"floor", "carpet", "plush carpet" }): "The carpet is a medium "
            "grey that gives the room a very monochromatic feel. The "
            "padding is perhaps a little too thick as your feet seem to "
            "sink into the carpet as you walk.",
        ({"bar", "minibar", "drinks" }): "There are numerous bottles "
            "and decanters, as well as glasses and a small box that "
            "no doubt contains ice. Just about any drink that you could "
        ]));
}

void enter_signal( object item, object oldenv, object mover, int pass ) {
     if ( objectp( item ) )
    {
       tell_object( item, strformat( "You feel a release of pressure "
            "as you enter the isolation chamber. All other sounds seem "
            "to diminish and the outside world seems to fade away.") );
       if ( sizeof( SLOOP_FUNCTIONS->find_sloopee_shadow( item ) ) ) {
            SLOOP_FUNCTIONS->dest_sloopee_shadow( item );
       }
    }
}
