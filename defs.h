#ifndef DEFS_H
#define DEFS_H

typedef unsigned long long U64;

#define NAME "suboChess 1.0"
#define BRD_SQ_NUM 120

// Piece enumeration
enum { EMPTY, wP, wN, wR, wQ, wK, bP, bN, bR, bQ, bK };

// File enumeration (columns on the chessboard)
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };

// Rank enumeration (rows on the chessboard)
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

// Side enumeration
enum { BLACK, WHITE, BOTH };

// Square enumeration
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

// Boolean values
enum { FALSE, TRUE };

// Board structure
typedef struct {
    int pieces[BRD_SQ_NUM]; // Array to store pieces on the board
    U64 pawns[3];           // Pawn bitboards for WHITE, BLACK, and BOTH
    int KingSq[2];          // Squares of the kings for WHITE and BLACK

    int side;               // Current side to move (WHITE or BLACK)
    int enPas;              // En passant square (-1 if none)
    int fiftyMove;          // Fifty-move rule counter

    int ply;                // Half-move counter for search depth
    int hisPly;             // Total half-move counter in the game

    U64 posKey;             // Unique position key (Zobrist hashing)

    int pceNum[13];         // Number of each piece type
    int bigPce[3];          // Count of non-pawn pieces for WHITE, BLACK, and BOTH
    int majPce[3];          // Count of major pieces (rooks and queens) for WHITE, BLACK, and BOTH
    int minPce[3];          // Count of minor pieces (knights and bishops) for WHITE, BLACK, and BOTH
} Board;

#endif
