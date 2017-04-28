// Mystical Sphere of Slooping
// Gon
// 2017-04

inherit NewThingCode;
inherit AnsiTellCode;

#include <ansi.h>

#define SLOOPEE_SHAD "/usr/gon/tools/sloopee_shad"
#define SLOOPER_SHAD "/usr/gon/tools/slooper_shad"

// Functions
int query_sloop();
int do_sloop();
int do_touch();
int do_gaze();

void extra_create() {
    set_short( "A Glowing Sphere" );
    set_ids( ({"a glowing sphere", "glowing sphere", "sphere", 
        "a sphere" }) );
    set_long( "The sphere is glowing a deep purple that "
        "seems to pulse rhythmically, almost as if the object "
        "was breathing. The surface appears to be smooth "
        "and without any marks. It makes you slightly uneasy "
        "as you look upon it, almost as if it were aware of your "
        "presence..." );
    set_gettable( 0 );
}

extra_init() {
    add_action( "do_sloop", "sloop" );
    add_action( "do_gaze", "gaze" );
    add_action( "do_touch", "touch" );
}

// Apply Slooper and Sloopee shadows, respectively
int do_sloop( string arg ) {
    if ( !arg ) {
        return notify_fail( "What do you want to sloop?" );
    }
    object slooper = THISP;
    if ( !IsWizard( slooper ) ) {
        return notify_fail( "You cannot summon the power needed." );
    }
    object sloopee = FINDP ( arg );
    if ( !sloopee ) {
        return notify_fail( "You can only sloop a player." );
    }
    if ( slooper == sloopee ) {
        return notify_fail( "Your head begins to spin and you quickly look away "
            "from the sphere. Maybe you shouldn't try slooping yourself?" );
    }
    if ( GetOrdLevel( slooper ) <= GetOrdLevel( sloopee ) ) {
        ansi_tell( slooper, sprintf("You have not the power to sloop %s" 
                ,FINDP( arg )->query_name() ), BOLD_PURPLE );
        return 1;
    }
    else {
        object slooper_name, slooped_name;
        ansi_tell( slooper, "Wubba Lubba Dub Dub! It's a sloop-a-doop, "
            "scoobily-doop-dup.", BOLD_PURPLE );
        slooper_name = clone_object( SLOOPER_SHAD );
        slooper_name-> sh_init( slooper );
        slooped_name = clone_object( SLOOPEE_SHAD );
        slooped_name-> sh_init( sloopee );
        ansi_tell( sloopee, sprintf( "%s has taken a special interest in "
                "you.",slooper->query_name() ), BOLD_PURPLE );
        return 1;
    }
}    

// Touching the sphere
int do_touch( string str ) {

}

// Gazing into the Sphere
int do_gaze( string str ) {

}
