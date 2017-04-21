// Mystical Sphere of Slooping
// Gon
// 2017-04

inherit NewThingCode;
inherit AnsiTellCode;

#include <ansi.h>

#define SLOOPEE "/usr/gon/tools/sloopee_shad"
#define SLOOPER "/usr/gon/tools/slooper_shad"

// Functions
void do_sloop();
int do_touch();
int do_gaze();

void extra_create() {
    set_short( "A Glowing Sphere" );
    set_ids( ({"a glowing sphere", "glowing sphere", "sphere", 
        "a sphere" }) );
    set_long( "The sphere is glowing a deep purple that "
        "seems to pulse rhythmically, almost as if the object "
        "was taking breath. The surface appears to be smooth "
        "and without any marks. It makes you slightly uneasy "
        "as you look upon it, almost as if it was aware of your "
        "presence..." );
    set_gettable( 0 );
}

extra_init() {
    add_action( "do_sloop", "sloop" );
    add_action( "do_gaze", "gaze" );
    add_action( "do_touch", "touch" );
}

// Apply Slooper and Sloopee shadows, respectively
void do_sloop( string sloopee ) {
    object slooper = THISP;
    object shad, shadtwo;

    if ( !sloopee ) {
        ansi_tell( slooper, "What do you want to sloop?", BOLD_PURPLE );
    }
    else if ( IsWizard( slooper ) {
        if ( GetOrdLevel ( slooper ) <= GetOrdLevel( FINDP( sloopee ) ) {
            ansi_tell( slooper, "You have not the power to sloop "
             + capitalize( FINDP( sloopee) ), BOLD_PURPLE );
        }
        else {
            ansi_tell( FINDP( to_string( slooper) ), "Wubba Lubba Dub Dub, it's a sloop-a-doop, "
                "scoobily-doop-dup", BOLD_PURPLE);
            shad = clone_object( SLOOPER );
            shad -> sh_init( slooper );
            shadtwo = clone_object( SLOOPEE );
            shadtwo -> sh_init( sloopee );
            ansi_tell( FINDP( to_string( sloopee ) ), capitalize( slooper ) + " has taken a special "
                "interest in you." );
        }
    }
}

// Touching the sphere
int do_touch( string str ) {

}

// Gazing into the Sphere
int do_gaze( string str ) {

}