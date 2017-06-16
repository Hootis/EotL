/**
 * Library of functions pertaining to Sloop shadows. Slooping is a way
 * to simulate the built-in snooping functionality of EotL.
 *
 * @author gon
 */

#define SLOOPEE_SHAD "/usr/gon/tools/sloopee_shad"
#define SLOOPER_SHAD "/usr/gon/tools/slooper_shad"

// Function Declarations
protected void add_sloop_shadow( object ob, string str );
protected void dest_sloop_shadows( object ob, string str );
protected object * query_sloop_shadows( object ob, string str );
void add_slooper_shadow( object ob );
void add_sloopee_shadow( object ob );
void dest_slooper_shadow( object ob );
void dest_sloopee_shadow( object ob );
object find_slooper_shadow( object ob );
object find_sloopee_shadow( object ob );

/**
 * Function filters all shdow objects and returns a filtered array of shadows
 * matching either SLOOPEE_SHAD or SLOOPER_SHAD
 * @param  object ob   Object passed to check for shadow
 * @param  string str    string to match (Either SLOOPER_SHAD or SLOOPEE_SHAD)
 * @return   array of matching shadow(s)
 */
protected object * query_sloop_shadows( object ob, string str ) {
    object * shadow_ob = shadow_list( ob );
    return filter( shadow_ob, (: return ( program_name( $1 ) == $2 ); :), str );
}

/**
 * Calls query_sloop_shadows passing SLOOPER_SHAD
 * @param  object ob            Object to check for SLOOPER_SHAD
 * @return        Filtered object from query_sloop_shadows()
 */
object find_slooper_shadow( object ob ) {
    query_sloop_shadows( ob, SLOOPER_SHAD );
}

/**
 * Calls query_sloop_shadows passing SLOOPEE_SHAD
 * @param  object ob            Object to check for SLOOPEE_SHAD
 * @return        Filtered object from query_sloop_shadows()
 */
object find_sloopee_shadow( object ob ) {
    query_sloop_shadows( ob, SLOOPEE_SHAD );
} 

/**
 * Clones the shadow object (path of str) and applies it to ob
 * @param  object ob  Object that will receive shadow
 * @param  string str String that is path to shadow_object
 */
protected void add_sloop_shadow( object ob, string str ) {
        object shadow = clone_object( str );
        shadow->sh_init( ob );
}

/**
 * Queries to see if shadow(s) exist and then attempt to destroy shadow(s)
 * @param  object ob            Object to check for shadow(s)
 * @param  string str           String that is path to shadow_object
 */
protected void dest_sloop_shadows( object ob, string str ) {
    object * arr = query_sloop_shadows( ob, str );
    destruct( arr[0] );
}

/**
 * Call add_sloop_function with Slooper_shad path
 * @param object ob Object to receive shadow
 */
void add_slooper_shadow( object ob ) {
    add_sloop_shadow( ob, SLOOPER_SHAD );
}

/**
 * Call add_sloop_function with Sloopee_shad path
 * @param object ob Object to receive shadow
 */
void add_sloopee_shadow( object ob ) {
    add_sloop_shadow( ob, SLOOPEE_SHAD );
}

/**
 * Call dest_sloop_function with Slooper_shad path
 * @param  object ob            Object to remove shadow from
 */
void dest_slooper_shadow( object ob ) {
    dest_sloop_shadow( ob, SLOOPER_SHAD );
}

/**
 * Call dest_sloop_function with Sloopee_shad path
 * @param  object ob            Object to remove shadow from
  */
void dest_sloopee_shadow( object ob ) {
    dest_sloop_shadow( ob, SLOOPEE_SHAD );
}
