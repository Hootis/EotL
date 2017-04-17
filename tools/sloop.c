// Sloop
// Gon
// April 2017

#include  <ansi.h>
inherit AnsiTellCode;

#define SloopUsage  StdUsage("[name]")
object slooper, slooped;

static int Sloop( string arg)
{
    
    if( !Arg )
    {
        return( write( "No, dummie. It's sloop <person's name>.\n" ) );
    }
    if( Arg == PRNAME )
    {
        return( write( "Hey! What's the point of slooping yourself?\n" ) );
    }
    UserData = GetPWNam( GetEUid( geteuid( this_object() ) ) );
    if( OrdLevel( UserData[ 2 ] ) < OrdLevel( Wizard ) )
    {
        write( this_verb() + ": You don't have permission to sloop that person.\n" );
        return 1;
    }
    User = find_anyone( arg[ 0 ] );
    sscanf( arg[ 0 ], "FTP-%s", arg[ 0 ] );
    if( !User )
    {

    }
} //end sloop() 

borrowed Bannor's find_anyone() function
object find_anyone( string who )
/* Function written by Bannor 2/93.
 *
 * use users[] to do a find_player()
 */
{
    object *list, ob;
    int i, listsize;
    string euid;
 
 
    list = users();
    listsize = sizeof( list );
    i=0;
    ob = 0;
    while( i < listsize ) {
        if( list[ i ] ) {
            euid = list[ i ]->query_real_name();
            if( euid == who ) {
                ob = list[ i ];
                break;
            }
        }
        i++;
    }
    if( !ob )
        ob=find_player( who );
    return ob;
} /* find_anyone() */
