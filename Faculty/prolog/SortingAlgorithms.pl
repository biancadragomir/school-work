%inOrder(list)
%inOrder(i)
inOrder([]).
inOrder([_]).
inOrder([A,B|T]):- A=<B, inOrder([B|T]).

%permutation sort: a really inefficient algorithm

permt(L,[H|T]):- append(V, [H|U], L), append(V, U, R1), permt(R1, T).

%naiveSort(list, list).
%naiveSort(i,o).
naiveSort([],[]).
naiveSort(L1, L2):- permt(L1, L2), inOrder(L2).

%bubble sort
%bubbleSort(list,list).
%bubbleSort(i,o).
bubbleSort(L,L):- inOrder(L).
bubbleSort(L1,L2):- append(X, [A,B|Y], L1), A>B,
                    append(X, [B,A|Y], T),
                    bubbleSort(T, L2).

%merge sort
%split(L:list, L1: list, L2:list).
%split(i,o,o)
split([],[],[]).
split([A], [A], []).
split([A,B|T], [A|T1], [B|T2]):-
             split(T, T1,T2).

merge([],L,L).
merge(L,[],L).
merge([A|T1],[B|T2], [A|L2]):-
    A=<B, merge(T1, [B|T2], L2).
merge([A|T1], [B|T2], [B|L2]):-
    A>B, merge([A|T1], T2, L2).

mergeSort([],[]).
mergeSort([A],[A]).
mergeSort(L1,L2):- split(L1, P1, P2),
    mergeSort(P1, S1),
    mergeSort(P2, S2),
    merge(S1,S2,L2).
