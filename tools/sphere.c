// Mystical Sphere of Slooping
// Gon
// 2017-04

inherit NewThingCode;
inherit AnsiTellCode;
inherit "/usr/gon/tools/sloop";

#include <ansi.h>

// Functions
int do_sloop( string arg );
int do_touch( string str );
int do_gaze( string str );

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

/**
 * Adds sloop action to player actions. Slooping a target successfully
 * will add the Slooper shadow to actor and the Sloopee shadow to
 * victim. If the victim is already being slooped, it will instead remove
 * the shadow.
 * @param  arg           Victim
 * @return int        
 */
int do_sloop( string arg ) {
    if ( !arg ) {
        return notify_fail( "What do you want to sloop?\n" );
    }
    object slooper = THISP;
    if ( !IsWizard( slooper ) ) {
        return notify_fail( "You cannot summon the power needed.\n" );
    }
    object sloopee = FINDP( arg );
    if ( !sloopee ) {
        return notify_fail( "You can only sloop a player.\n" );
    }
    if ( slooper == sloopee ) {
        return notify_fail( "Your head begins to spin and you quickly look away "
            "from the sphere. Maybe you shouldn't try slooping yourself?\n" );
    }
    if ( GetOrdLevel( slooper ) <= GetOrdLevel( sloopee ) ) {
        ansi_tell( slooper, sprintf("You have not the power to sloop %s" 
                ,FINDP( arg )->query_name() ), BOLD_PURPLE );
        return 1;
    }
    // If already slooping victim, instead remove both shadows
    if ( sizeof( find_slooper_shadow( slooper ) ) && sizeof( find_sloopee_shadow( sloopee ) ) ) {
        ansi_tell( slooper, sprintf( "You stop slooping %s", sloopee->query_name() ), BOLD_PURPLE );
        dest_slooper_shadow( slooper );
        ansi_tell( sloopee, sprintf( "You feel %s's attention leave you.", slooper->query_name() ),
            BOLD_PURPLE );
        dest_sloopee_shadow( sloopee );
        return 1;
    }
    // initiator has slooper shadow already (add only sloopee shadow )
    if ( sizeof( find_slooper_shadow( slooper ) ) && ! sizeof( find_sloopee_shadow( sloopee ) ) ) {
        ansi_tell( slooper, "Wubba Lubba Dub Dub! It's a sloop-a-doop, "
            "scoobily-doop-dup.", BOLD_PURPLE );
        ansi_tell( sloopee, sprintf( "%s has taken a special interest in "
            "you.",slooper->query_name() ), BOLD_PURPLE );
        add_sloopee_shadow( sloopee );
        return 1;
    }
    // Victim has sloopee shadow already (add only slooper shadow )
    if ( ! sizeof( find_slooper_shadow( slooper ) ) && sizeof( find_sloopee_shadow( sloopee ) ) ) {
        ansi_tell( slooper, "Wubba Lubba Dub Dub! It's a sloop-a-doop, "
            "scoobily-doop-dup.", BOLD_PURPLE );
        add_slooper_shadow( slooper );
        ansi_tell( sloopee, sprintf( "%s has taken a special interest in "
            "you.",slooper->query_name() ), BOLD_PURPLE );
        return 1;
    }
    ansi_tell( slooper, "Wubba Lubba Dub Dub! It's a sloop-a-doop, "
        "scoobily-doop-dup.", BOLD_PURPLE );
    add_slooper_shadow( slooper );
    ansi_tell( sloopee, sprintf( "%s has taken a special interest in "
            "you.",slooper->query_name() ), BOLD_PURPLE );
    add_sloopee_shadow( sloopee );
    return 1;
}    

// Touching the sphere
int do_touch( string str ) {

}

// Gazing into the Sphere
int do_gaze( string str ) {

}
