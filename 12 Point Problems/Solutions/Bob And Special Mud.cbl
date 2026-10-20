IDENTIFICATION DIVISION.
       PROGRAM-ID. BOBANDSHIT.

       ENVIRONMENT DIVISION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01  WSR        PIC 999 VALUE 0.
       01  WSC        PIC 999 VALUE 0.
       01  WSI           PIC 999 VALUE 0.
       01  WSJ           PIC 999 VALUE 0.
       01  WSL        PIC X(500) VALUE SPACES.
       01  WSINF         PIC 9(12) VALUE 999999999999.
       01  WSTE        PIC 9(12) VALUE 0.
       01  WSM         PIC 9(12) VALUE 0.
       01  WSCH     PIC 9 VALUE 0.
       01  WSPA        PIC 9(6) VALUE 0.
       01  WSIDX         PIC 9(6) VALUE 0.
       01  WSIDX2        PIC 9(6) VALUE 0.
       01  WSMI      PIC 9(6) VALUE 0.
       01  WSRES      PIC Z(11)9 VALUE 0.
       01  WSDI       PIC 9 VALUE 0.

       01  GRID-TABLE.
           05  GRID-ENTRY OCCURS 90000 TIMES PIC 9.

       01  DP-TABLE.
           05  DP-ENTRY   OCCURS 90000 TIMES PIC 9(12).

       PROCEDURE DIVISION.
       MAIN-PARA.
           ACCEPT WSR
           ACCEPT WSC
           COMPUTE WSMI = WSR * WSC

           PERFORM VARYING WSI FROM 1 BY 1
               UNTIL WSI > WSR
               ACCEPT WSL
               PERFORM VARYING WSJ FROM 1 BY 1
                   UNTIL WSJ > WSC
                   MOVE WSL(WSJ:1) TO WSDI
                   COMPUTE WSIDX = (WSI - 1) * WSC + WSJ
                   MOVE WSDI TO GRID-ENTRY(WSIDX)
               END-PERFORM
           END-PERFORM

           PERFORM VARYING WSIDX FROM 1 BY 1
               UNTIL WSIDX > WSMI
               MOVE WSINF TO DP-ENTRY(WSIDX)
           END-PERFORM

           MOVE GRID-ENTRY(1) TO DP-ENTRY(1)

           PERFORM VARYING WSPA FROM 1 BY 1
               UNTIL WSPA > WSMI
               MOVE 0 TO WSCH
               PERFORM VARYING WSI FROM 1 BY 1
                   UNTIL WSI > WSR
                   PERFORM VARYING WSJ FROM 1 BY 1
                       UNTIL WSJ > WSC
                       COMPUTE WSIDX = (WSI - 1) * WSC + WSJ
                       MOVE WSINF TO WSM

                       IF WSI > 1
                           COMPUTE WSIDX2 = (WSI - 2) * WSC
                               + WSJ
                           IF DP-ENTRY(WSIDX2) < WSINF
                               COMPUTE WSTE = DP-ENTRY(WSIDX2)
                                   + GRID-ENTRY(WSIDX)
                               IF WSTE < WSM
                                   MOVE WSTE TO WSM
                               END-IF
                           END-IF
                       END-IF

                       IF WSI < WSR
                           COMPUTE WSIDX2 = WSI * WSC + WSJ
                           IF DP-ENTRY(WSIDX2) < WSINF
                               COMPUTE WSTE = DP-ENTRY(WSIDX2)
                                   + GRID-ENTRY(WSIDX)
                               IF WSTE < WSM
                                   MOVE WSTE TO WSM
                               END-IF
                           END-IF
                       END-IF

                       IF WSJ > 1
                           COMPUTE WSIDX2 = (WSI - 1) * WSC
                               + WSJ - 1
                           IF DP-ENTRY(WSIDX2) < WSINF
                               COMPUTE WSTE = DP-ENTRY(WSIDX2)
                                   + GRID-ENTRY(WSIDX)
                               IF WSTE < WSM
                                   MOVE WSTE TO WSM
                               END-IF
                           END-IF
                       END-IF

                       IF WSJ < WSC
                           COMPUTE WSIDX2 = (WSI - 1) * WSC
                               + WSJ + 1
                           IF DP-ENTRY(WSIDX2) < WSINF
                               COMPUTE WSTE = DP-ENTRY(WSIDX2)
                                   + GRID-ENTRY(WSIDX)
                               IF WSTE < WSM
                                   MOVE WSTE TO WSM
                               END-IF
                           END-IF
                       END-IF

                       IF WSI = 1 AND WSJ = 1
                           MOVE GRID-ENTRY(1) TO WSM
                       END-IF

                       IF WSM < DP-ENTRY(WSIDX)
                           MOVE WSM TO DP-ENTRY(WSIDX)
                           MOVE 1 TO WSCH
                       END-IF
                   END-PERFORM
               END-PERFORM
               IF WSCH = 0
                   ADD WSMI TO WSPA
               END-IF
           END-PERFORM

           COMPUTE WSIDX = (WSR - 1) * WSC + WSC
           MOVE DP-ENTRY(WSIDX) TO WSRES
           DISPLAY FUNCTION TRIM(WSRES)

           STOP RUN.
