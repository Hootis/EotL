/**
 * Library of functions pertaining to Sloop shadows. Slooping is a way
 * to simulate the built-in snooping functionality of EotL.
 *
 * @author gon
 * 2017-05
 */

inherit AnsiTellCode;

#include <ansi.h>

#define SLOOPER_SHADOW "/usr/gon/tools/slooper_shad"
#define SLOOPEE_SHADOW "/usr/gon/tools/sloopee_shad"

/**
 * Function Declarations
 */
void add_sloopee_shadow( object ob );
void add_slooper_shadow( object ob );
void dest_sloopee_shadow( object ob );
void dest_slooper_shadow( object ob );
object * find_sloopee_shadow( object ob );
object * find_slooper_shadow( object ob );

/**
 * When function is called, adds SLOOPEE_SHADOW to object ob.
 * @param  object ob object to add SLOOPEE_SHADOW
 */
void add_sloopee_shadow( object ob ) {
    object shadow = clone_object( SLOOPEE_SHADOW );
    shadow->sh_init( ob );
}

/**
 * When function is called, adds SLOOPER_SHADOW to object ob.
 * @param  object ob object to add SLOOPER_SHADOW
 */
void add_slooper_shadow( object ob ) {
    object shadow = clone_object( SLOOPER_SHADOW );
    shadow->sh_init( ob );
}

/**
 * When function is called, uses find_sloopee_shadow() and if that
 * returns ! 0, dests the shadow object returned from the array.
 * @param  object ob            object that holds the shadow if find_sloopee_shadow returns non zero.
 */
void dest_sloopee_shadow( object ob ) {
    object * arr = find_sloopee_shadow( ob );
    remove_shadow( arr[0] );
}

/**
 * When function is called, uses find_slooper_shadow() and if that
 * returns ! 0, dests the shadow object returned from the array.
 * @param  object ob            object that holds the shadow if find_slooper_shadow returns non zero.
 */
void dest_slooper_shadow( object ob ) {
    object * arr = find_slooper_shadow( ob );
    remove_shadow( arr[0] );
}

/**
 * Function stores shadow_list in an array variable, then filters it to look for SLOOPEE_SHAD from
 * the blueprint, "/usr/gon/tools/sloopee_shad".
 * @param  object ob    object passed to list shadows and then filter
 * @return       returns filtered array if SLOOPEE_SHAD present, 0 if not
 */
object * find_sloopee_shadow( object ob ) {
    object *str_shadows = shadow_list( ob );
    return filter( str_shadows, (: if ( program_name( $1 ) == SLOOPEE_SHADOW ) return 1; :) ); 
}

/**
 * Function stores shadow_list in an array variable, then filters it to look for SLOOPER_SHAD from
 * the blueprint, "/usr/gon/tools/slooper_shad".
 * @param  object ob    object passed to list shadows and then filter
 * @return       returns filtered array if SLOOPER_SHAD present, 0 if not
 */
object * find_slooper_shadow( object ob  ) {
    object *str_shadows = shadow_list( ob );
    return filter( str_shadows, (: if ( program_name( $1 ) == SLOOPER_SHADOW ) return 1; :) ); 
}