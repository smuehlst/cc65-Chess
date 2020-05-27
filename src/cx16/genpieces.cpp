/*
 *  genPieces.cpp
 *  cc65 Chess
 *
 *  Created by Oliver Schmidt, January 2020.
 *  Pieces designed by Frank Gebhart, 1980s.
 *  Modified for CX16 by S. Wessels, May 2020.
 *
 */

#include <fcntl.h>
#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <memory.h>

char pieces[]=
"                                " 
"                                " 
"      ****   *****   ****       " 
"      *  *   *   *   *  *       " 
"      *  *   *   *   *  *       " 
"      *  *****   *****  *       " 
"      *                 *       " 
"       *               *        " 
"        *             *         " 
"         * ********* *          " 
"         **         **          " 
"          *         *           " 
"          *         *           " 
"          *         *           " 
"          *         *           " 
"          *         *           " 
"         *           *          " 
"        *             *         " 
"        * *********** *         " 
"       *               *        " 
"      *******************       " 
"      *******************       " 
"                                " 
"                                " 
"                                " 
"                                " 
"      ****   *****   ****       " 
"      ****   *****   ****       " 
"      ****   *****   ****       " 
"      *******************       " 
"      *******************       " 
"       *****************        " 
"        ***************         " 
"         *************          " 
"         *           *          " 
"          ***********           " 
"          ***********           " 
"          ***********           " 
"          ***********           " 
"          ***********           " 
"         *************          " 
"        ***************         " 
"        ***************         " 
"       *               *        " 
"      *******************       " 
"      *******************       " 
"                                " 
"                                " 
"                                " 
"                                " 
"            *   *               " 
"           * * * *              " 
"          *    *  *             " 
"          *        *            " 
"         *          *           " 
"         *   *    * *           " 
"         *        * *           " 
"        *         ** *          " 
"       *           * *          " 
"      *              *          " 
"      *    ****      *          " 
"       *  *    *   * **         " 
"        **    *    ** *         " 
"             *      *  *        " 
"            *        * *        " 
"           *           **       " 
"          *             *       " 
"         * ************ *       " 
"         *              *       " 
"         ****************       " 
"                                " 
"                                " 
"                                " 
"                                " 
"            *   *               " 
"           * * * *              " 
"          ***** ***             " 
"          **********            " 
"         ************           " 
"         **** **** **           " 
"         ********* **           " 
"        **********  **          " 
"       ************ **          " 
"      ****************          " 
"      ****************          " 
"       ****    **** ***         " 
"        **    *****  **         " 
"             ******* ***        " 
"            ********* **        " 
"           **************       " 
"          ***************       " 
"         *              *       " 
"         ****************       " 
"         ****************       " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"              ***               " 
"             *   *              " 
"            *     *             " 
"           *   *   *            " 
"          *    *    *           " 
"          * ******* *           " 
"         *     *     *          " 
"         *     *     *          " 
"         *     *     *          " 
"          *    *    *           " 
"          *         *           " 
"           *       *            " 
"            *******             " 
"            *     *             " 
"            *     *             " 
"             *****              " 
"          *         *           " 
"        ***************         " 
"       *****************        " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"              ***               " 
"             *****              " 
"            *******             " 
"           **** ****            " 
"          ***** *****           " 
"          **       **           " 
"         ****** ******          " 
"         ****** ******          " 
"         ****** ******          " 
"          ***** *****           " 
"          ***********           " 
"           *********            " 
"            *     *             " 
"            *******             " 
"            *******             " 
"             *****              " 
"          ***********           " 
"        *             *         " 
"       *****************        " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"              ***               " 
"             *   *              " 
"        ***  *   *  ***         " 
"       *   *  * *  *   *        " 
"      *    * *   * *    *       " 
"      *   * *     * *   *       " 
"      *                 *       " 
"      *   *    *    *   *       " 
"      *   **  ***  **   *       " 
"       *   *********   *        " 
"       *    *******    *        " 
"        *             *         " 
"        *             *         " 
"        * *********** *         " 
"         *           *          " 
"         *           *          " 
"         *           *          " 
"         **         **          " 
"          ***********           " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"              ***               " 
"             *****              " 
"        ***  *****  ***         " 
"       *****  ***  *****        " 
"      ****** ***** ******       " 
"      ***** ******* *****       " 
"      *******************       " 
"      **** **** **** ****       " 
"      ****  **   **  ****       " 
"       ****         ****        " 
"       *****       *****        " 
"        ***************         " 
"        ***************         " 
"        **           **         " 
"         *************          " 
"         *************          " 
"         *************          " 
"         *************          " 
"          ***********           " 
"                                " 
"                                " 
"                                " 
"                                " 
"              ***               " 
"              * *               " 
"            *** ***             " 
"            **   **             " 
"          **  * *  **           " 
"         *  * * * *  *          " 
"        *    ** **    *         " 
"       *      * *      *        " 
"       *  *  *   *  *  *        " 
"      *  *    * *    *  *       " 
"      *  *     *     *  *       " 
"      *   *    *    *   *       " 
"       *   *       *   *        " 
"       *    *     *    *        " 
"        *             *         " 
"        *  *********  *         " 
"         *           *          " 
"         *           *          " 
"         **         **          " 
"          ***********           " 
"                                " 
"                                " 
"                                " 
"                                " 
"              ***               " 
"              * *               " 
"            *** ***             " 
"            **   **             " 
"          **  * *  **           " 
"         **** * * ****          " 
"        ******* *******         " 
"       *******   *******        " 
"       *** ** * * ** ***        " 
"      *** ****   **** ***       " 
"      *** ***** ***** ***       " 
"      **** ********* ****       " 
"       **** ******* ****        " 
"       ***** ***** *****        " 
"        ***************         " 
"        **           **         " 
"         *************          " 
"         *************          " 
"         *************          " 
"          ***********           " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"              ***               " 
"             *   *              " 
"            *     *             " 
"            *     *             " 
"            *     *             " 
"             *   *              " 
"              ***               " 
"             *   *              " 
"             *   *              " 
"            **   **             " 
"             *   *              " 
"             *   *              " 
"            *******             " 
"           *       *            " 
"          ***********           " 
"          ***********           " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"                                " 
"              ***               " 
"             *****              " 
"            *******             " 
"            *******             " 
"            *******             " 
"             *****              " 
"              ***               " 
"             *****              " 
"             *****              " 
"            *******             " 
"             *****              " 
"             *****              " 
"            *******             " 
"           *       *            " 
"          ***********           " 
"          ***********           " 
"                                " 
"                                " 
;

int main(void)
{
    int i;
    unsigned char c = 0;

    printf("const char gfxTiles[PAWN][2][384] = \n{\n");
    for(i=0; i<sizeof(pieces); i++)
    {
        if(!(i%(32*24*2)))
            printf("\t{\n");
        if(!(i%(32*24)))
            printf("\t\t{\n");
        if(!(i % 32))
            printf("\t\t\t");
        c |= (pieces[i] == '*') << (7-(i%8));
        if ((i%8) == 7)
        {
            printf("0x%02X, ", c);
            c = 0;
        }
        if(31 == (i%32))
            printf("\n");
        if((32*24) -1 == (i%(32*24)))
            printf("\t\t},\n");
        if((32*24*2) - 1 == (i%(32*24*2)))
            printf("\t},\n");
    }
    printf("};\n");
    
    return 0;
}