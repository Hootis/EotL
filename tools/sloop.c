// Sloop Shadow
// Gon
// April 2017

#include  <ansi.h>
inherit AnsiTellCode;

#define SloopUsage  StdUsage("[name]")

static int Sloop( string *Args, string Opts, string BadOpts)
{
    string *UserData;
    object User;
    int lev;

    if( BadOpts != "" || sizeof( Args ) > 1 )
        throw( SloopUsage );

    if( !sizeof( Args ) )
    }
        sloop( this_object() );
        return 1;
    }

    UserData = GetPWNam( GetEUid( geteuid( this_object() ) ) );
    if( OrdLevel( UserData[ 2 ] ) < OrdLevel( Wizard ) )
    {
        write( this_verb() + ": Permission denied.\n" );
        return 1;
    }
    User = find_anyone( Args[ 0 ] );
    sscanf( Args[ 0 ], "FTP-%s", Args[ 0 ] );
    if( !User )
    {
        write( this_verb() + ": No such player.\n" );
    }
    else
    {
        if( geteuid(THISO) != geteuid( User ) &&
            ( lev = GetOrdLevel( THISO ) ) <= GetOrdLevel( User )
        {
            write( this_verb() + ": Permission denied.\n" );
        }
        else
        {
            if( lev == OrdLevel( Wizard ) )
                tell_object( User, CAP( getuid() )+
                    " started slooping you.\n" );
                sloop( this_object(), User );
        }
    }
    return 1;
} /*end sloop() */

// borrowed Bannor's find_anyone() function
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
