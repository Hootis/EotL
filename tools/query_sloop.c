// Query if player has sloop shadow on them
// Gon
// 2017 - 04

// Declared Functions
int query_sloop();

// Find if target has sloop shadow and return 1
int query_sloop( object victim ) {
    return sizeof( filter( shadow_list( victim ), (: if(blueprint($1) == FINDO(
        "/usr/gon/tools/sloop_shad" ) ) ); :) );
}