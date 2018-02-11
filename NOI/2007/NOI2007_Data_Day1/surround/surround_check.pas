{$r+,q+,s+,i+}
program surround_check;
{$MODE DELPHI}

const
        maxn = 3001;
        maxm = 101;
        s       : array[ 1.. 4, 1.. 2 ] of longint = ( ( 1, 0 ), ( 0, 1 ), ( 0, -1 ), ( -1, 0 ) );

var
        n, m, i, j, ans         : longint;
        x1, y1, x2, y2          : longint;
        inf, ouf                : string;
        map                     : array[ 0.. maxn, 0.. maxm ] of char;
        sign, use               : array[ 0.. maxn, 0.. maxm ] of boolean;
        queue                   : array[ 1.. maxn * maxm, 1.. 2 ] of longint;
        A, B                    : extended;
        h, l                    : longint;

procedure swap( var a, b : char );
var
        tmp     : char;
begin
        tmp := a;
        a := b;
        b := tmp;
end;

procedure wrong( k : longint );
begin
        case k of
                1 :
                        writeln( 'overlap' );
                2 :
                        writeln( 'outside' );
                3 :
                        writeln( 'move error' );
                4 :
                        writeln( 'not surround' );
                5 :
                        writeln( 'time not match' );
        end;

        halt;
end;

begin
        inf := paramstr( 1 );
        ouf := paramstr( 2 );

        assign( input, inf );
        reset( input );

        randomize;
        readln( n, m );
        for i := 1 to n do
                begin
                        for j := 1 to m do
                                begin
                                        read( map[ i, j ] );
                                        if map[ i, j ] = 'O' then
                                                begin
                                                        sign[ i, j ] := true;
                                                        map[ i, j ] := '.';
                                                end;
                                end;
                        readln;
                end;

        close( input );

        assign( input, ouf );
        reset( input );

        read( ans );
        while not seekeof( input ) do
                begin
                        dec( ans );
                        if ans < 0 then
                                wrong( 5 );
                        read( x1 );
                        if seekeof( input ) then
                                wrong( 5 );
                        read( y1 );
                        if seekeof( input ) then
                                wrong( 5 );
                        read( x2 );
                        if seekeof( input ) then
                                wrong( 5 );
                        read( y2 );
                        if abs( x1 - x2 ) + abs( y1 - y2 ) <> 1 then
                                wrong( 3 );
                        if ( x1 <= 0 ) or ( x1 > n ) or ( y1 <= 0 ) or ( y1 > m ) or
                           ( x2 <= 0 ) or ( x2 > n ) or ( y2 <= 0 ) or ( y2 > m ) then
                                wrong( 2 );
                        if map[ x1, y1 ] <> '#' then
                                wrong( 3 );
                        if map[ x2, y2 ] = '#' then
                                wrong( 1 );
                        swap( map[ x1, y1 ], map[ x2, y2 ] );
                end;
        if ans <> 0 then
                wrong( 5 );
        l := 0;
        h := 0;
        fillchar( use, sizeof( use ), #1 );
        for i := 1 to n do
                for j := 1 to m do
                        begin
                                if ( sign[ i, j ] ) and ( map[ i, j ] = '#' ) then
                                        wrong( 1 );
                                if ( ( i = 1 ) or ( j = 1 ) or ( i = n ) or ( j = m ) ) and ( map[ i, j ] = '.' ) then
                                        begin
                                                inc( l );
                                                queue[ l, 1 ] := i;
                                                queue[ l, 2 ] := j;
                                                use[ i, j ] := false;
                                        end;
                        end;
        while h < l do
                begin
                        inc( h );
                        if sign[ queue[ h, 1 ], queue[ h, 2 ] ] then
                                wrong( 4 );
                        for i := 1 to 4 do
                                if ( map[ queue[ h, 1 ] + s[ i, 1 ], queue[ h, 2 ] + s[ i, 2 ] ] = '.' ) and
                                   ( use[ queue[ h, 1 ] + s[ i, 1 ], queue[ h, 2 ] + s[ i, 2 ] ] ) then
                                        begin
                                                inc( l );
                                                queue[ l, 1 ] := queue[ h, 1 ] + s[ i, 1 ];
                                                queue[ l, 2 ] := queue[ h, 2 ] + s[ i, 2 ];
                                                use[ queue[ l, 1 ], queue[ l, 2 ] ] := false;
                                        end;
                end;

        close( input );

        writeln( 'yes' );
{
        for i := 1 to n do
                begin
                        for j := 1 to m do
                                begin
                                        if sign[ i, j ] then
                                                map[ i, j ] := 'O';
                                        write( map[ i, j ] );
                                end;
                        writeln;
                end;
}
end.
