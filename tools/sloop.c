/**
 * Library of functions pertaining to Sloop shadows. Slooping is a way
 * to simulate the built-in snooping functionality of EotL.
 *
 * @author gon
 */

// Function Declarations
protected void add_sloop_shadow( object ob, string str );
protected void dest_sloop_shadows( object ob, string str );
protected object * get_sloopee( object ob );
protected void is_slooping( object initiator, object target );
protected object * query_sloop_shadows( object ob, string param );
protected void * set_sloopee( object initiator, object target );

// Variables
protected object * slooper_shadow_ob;
protected object * sloopee_shadow_ob;

protected object * query_sloop_shadows( object ob, string str ) {
    object * shadow_ob = shadow_list( ob );
    return filter( shadow_ob, (: return ( program_name( $1 ) == $2 ); :), str );
}

protected void is_slooping( object initiator, object target ) {
    
}

protected void add_sloop_shadow( object ob, string str ) {
        object shadow = clone_object( str );
        shadow->sh_init( ob );
}

protected void dest_sloop_shadows( object ob, string str ) {
    object * arr = query_sloop_shadows( ob, str );
    destruct( arr[0] );
}