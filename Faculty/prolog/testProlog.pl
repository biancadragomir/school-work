%maximf(i,o).
%maximf(L:list, H:integer).
maximf([H],H).
maximf([H1,H2|T],M):- H1>=H2, maximf([H1|T],M).
maximf([H1, H2|T],M):- H1<H2, maximf([H2|T],M).

% delmaxi will delete the maximum element from the list, given as
% parameter
% delmaxi(L:list, E:integer, L1:list).
% delmaxi(i,i,o).
delmaxi([],_,[]).
delmaxi([H|T], E, Acc):- H=:=E, delmaxi(T,E,Acc).
delmaxi([H|T], E, [H|Acc]):- H=\=E, delmaxi(T,E,Acc).

%so r will be L but without the maximum element
%apelmaxi(L:list, R:list).
%apelmaxi(i, o).
apelmaxi(L, R):- maximf(L, M),delmaxi(L, M, R).

%listapoz(L:list, L1: list, P:integer).
%listapoz(i,o,i).
listapoz([], [],_).
listapoz([H|T], [P|Acc], P):- maximf([H|T], H), P1 is P+1, listapoz(T, Acc, P1).
listapoz([H|T], Acc, P):-not(maximf([H|T], H)), P1 is P+1, listapoz(T, Acc, P1).

%apellp(L:list, R:list)
%apellp(i,o).
apellp(L, R):-listapoz(L, R, 1).

%fctmainf(L:list, L1: list, L2: list)
%fctmainf(i,o,o).
fctmainf(L, L1,L2):- apellp(L, L1), apelmaxi(L, L2).

testmainf():-fctmainf([5,1,5], [1,3], [1]).
