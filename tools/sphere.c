// Mystical Sphere of Slooping
// Gon
// 2017-04

inherit NewThingCode;
inherit AnsiTellCode;

#include <ansi.h>

#define SLOOPEE_SHAD "/usr/gon/tools/sloopee_shad"
#define SLOOPER_SHAD "/usr/gon/tools/slooper_shad"

// Functions
object * find_slooper_shadow( object ob );
object * find_sloopee_shadow( object ob );
void add_slooper_shadow( object ob );
void add_sloopee_shadow( object ob );
void dest_slooper_shadow( object ob );
void dest_sloopee_shadow( object ob );
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

/**
 * Adds sloop action to player actions. Slooping a target successfully
 * will add the Slooper shadow to actor and the Sloopee shadow to
 * victim. If the victim is already being slooped, it will instead remove
 * the shadow.
 * @param  {String} arg           Victim
 * @return {Int}        
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
    if ( find_slooper_shadow( slooper ) && ! find_sloopee_shadow( sloopee ) ) {
        ansi_tell( sloopee, sprintf( "%s has taken a special interest in "
            "you.",slooper->query_name() ), BOLD_PURPLE );
        add_sloopee_shadow( sloopee );
    return 1;
    }
    if ( find_slooper_shadow( slooper ) && find_sloopee_shadow( sloopee ) ) {

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

/**
 *  Function finds and returns the sloop shadow based on the
 *  string passed.
 *  @param {String} sloop_type : valid values either "slooper" or "slooped"
 *  @param {Object} ob :  player object to test for shadows
 *  @return {Object} : returns the shadow object
 */

object * find_slooper_shadow( object ob  ) {
    object *str_shadows = shadow_list( ob );
    return filter( str_shadows, (: if ( program_name( $1 ) == SLOOPER_SHAD) return 1; :) ); 
}

object * find_sloopee_shadow( object ob ) {
    object *str_shadows = shadow_list( ob );
    return filter( str_shadows, (: if ( program_name( $1 ) == SLOOPEE_SHAD) return 1; :) ); 
}

void add_slooper_shadow( object ob ) {
    object shadow = clone_object( SLOOPER_SHAD );
    shadow->sh_init( ob );
}

void add_slooped_shadow( object ob ) {
    object shadow = clone_object( SLOOPEE_SHAD );
    shadow->sh_int( ob );
}
