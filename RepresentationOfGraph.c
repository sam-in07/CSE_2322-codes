#include<stdio.h>
int a[ 20 ][ 20 ];

main()
{
    int n, i, s, ch, j;
    char c, dummy;
    printf( "ENTER THE NUMBER VERTICES " );
    scanf( "%d", &n );

    for ( i = 1;i <= n;i++ )
        {
            for ( j = 1;j <= n;j++ )
                {
                    printf( "ENTER 1 IF %d HAS A EDGE WITH %d ELSE 0 ", i, j );
                    scanf( "%d", &a[ i ][ j ] );
                }
        }

    printf( "THE ADJACENCY MATRIX IS\n" );

    for ( i = 1;i <= n;i++ )
        {
            for ( j = 1;j <= n;j++ )
                {
                    printf( " %d", a[ i ][ j ] );
                }

            printf( "\n" );
        }
  }


