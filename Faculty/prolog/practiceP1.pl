%11.
%a. Write a predicate to substitute an element from a list with another element in the list.
%b. Write a predicate to create the sublist (lm, …, ln) from the list (l1,…, lk).
%

subst([],_,_,[]).
subst([H|T],E,V,[E|Acc]):- H=:=V, subst(T,E,V,Acc).
subst([H|T],E,V,[H|Acc]):- H=\=V, subst(T,E,V,Acc).


crt([],_,_,_,[]).

crt([H|T],P1,P2, Curr, [H|Acc]):- P1=<Curr, Curr=<P2,  Curr1 is Curr+1,
                                  crt(T, P1,P2,Curr1, Acc).
crt([_|T],P1,P2,Curr,Acc):- P1>Curr, Curr1 is Curr+1, crt(T,P1,P2,Curr1,Acc).
crt([_|T],P1,P2,Curr,Acc):- P2<Curr, Curr1 is Curr+1, crt(T,P1,P2,Curr1,Acc).


%12.
% a. Write a predicate to substitute in a list a value with all the
% elements of another list.
%b. Remove the n-th element of a list.

sbt([],_,_,[]).
sbt([H|T], L, V, [L|Acc]):- H=:=V, sbt(T,L,V,Acc).
sbt([H|T], L, V, [H|Acc]):-H=\=V, sbt(T,L,V,Acc).

rmv([],_,_,[]).
rmv([_|T], Curr, P, Acc):- Curr=:=P, Curr1 is Curr+1, rmv(T, Curr1, P, Acc).
rmv([H|T],Curr,P, [H|Acc]):- Curr=\=P, Curr1 is Curr+1, rmv(T, Curr1, P, Acc).

%13.
%
% a. Transform a list in a set, in the order of the last occurrences of
% elements. Eg.: [1,2,3,1,2] is transformed in
%[3,1,2].
% b. Define a predicate to determine the greatest common divisor of all
% numbers in a list.

lset([], []).
lset([H|T], [H|Acc]):- not(member(H,T)), lset(T, Acc).
lset([H|T], Acc):- member(H,T), lset(T, Acc).


cmmdc(0,X,X):-!.
cmmdc(X,0,X):-!.
cmmdc(X,X,X):-!.
cmmdc(X,Y,R):-X>Y, R1 is X mod Y, cmmdc(R1,Y,R).
cmmdc(X,Y,R):-Y>X, R1 is Y mod X, cmmdc(R1,X,R).




%10.
% a. Define a predicate to test if a list of an integer elements has a
% "valley" aspect (a set has a "valley" aspect if elements decreases up
% to a certain point, and then increases.
%eg: 10 8 6 9 11 13 – has a “valley” aspect
%b. Calculate the alternate sum of list’s elements (l1 - l2 + l3 ...).



%MOUNTAIN LIST
mtn([],1).
mtn([_],1).
mtn([H1,H2|T],0):- H1<H2, mtn([H2|T], 0).
mtn([H1,H2|T],0):- H1>=H2, mtn([H2|T], 1).
mtn([H1,H2|T],1) :-H1>H2, mtn([H2|T], 1).

mainMtn([H1,H2|T]):-H1<H2, mtn([H2|T],0).

%10a

valley([],1).
valley([_], 1).
valley([H1,H2|T], 0):- H1 >H2, valley([H2|T], 0).
valley([H1, H2|T], 0):-H1=<H2, valley([H2|T],1).
valley([H1,H2|T], 1):-H1<H2, valley([H2|T], 1).

mainVly([H1,H2|T]):-H1>H2, valley([H2|T],0).

%10

alts(L,R):-alts(L,1,R).
alts([],_,0).
alts([H|T], Curr, Tot):- Curr mod 2 =:= 0,
    Curr1 is Curr+1,alts(T,Curr1,Tot1), Tot is Tot1-H.
alts([H|T], Curr, Tot):- Curr mod 2 =\= 0,
    Curr1 is Curr+1,alts(T, Curr1, Tot1), Tot is Tot1+H.

altSum(L,S):-altSum(L,1,S).
altSum([],_,0).
altSum([H|T],P,S):- P mod 2 =\= 0, %p represents the current position in the list
				P1 is P+1,
				altSum(T,P1,S1),
				S is S1+H.
altSum([H|T],P,S):- P mod 2 =:= 0,
				P1 is P+1,
				altSum(T,P1,S1),
				S is S1-H.
%14.
% a. Write a predicate to test equality of two sets without using the set
% difference.
%b. Write a predicate to select the n-th element of a given list.

%a

eqsets([],[]).
eqsets([H1|T1],[H2|T2]):-H1=:=H2,eqsets(T1,T2).
eqsets([H1|_],[H2|_]) :- H1=\=H2,false.

%b

nthel([],_,_,[]).
nthel([_|T], Curr, Pos, Acc):- Curr =\=Pos, Curr1 is Curr+1,
                               nthel(T,Curr1,Pos,Acc).
nthel([H|T], Curr, Pos, [H|Acc]):- Curr=:=Pos, Curr1 is Curr+1,
                                   nthel(T,Curr1,Pos,Acc).

%4a - set difference
%b- add 1 after every even elem of a list
setsDiff([],_,[]).
setsDiff([H1|T1],L, Acc):- member(H1,L),setsDiff(T1,L,Acc).
setsDiff([H1|T1], L, [H1|Acc]):-not(member(H1,L)), setsDiff(T1,L,Acc).

%b

addOne([],[]).
addOne([H|T],[H,1|Acc]):-H mod 2 =:= 0, addOne(T, Acc).
addOne([H|T], [H|Acc]):- H mod 2 =\= 0, addOne(T, Acc).


%15.
% a. Write a predicate to transform a list in a set, considering the
% first occurrence.
%Eg: [1,2,3,1,2] is transform in [1,2,3].
% b. Write a predicate to decompose a list in a list respecting the
% following: [list of even numbers list of odd
% numbers] and also return the number of even numbers and the numbers of
% odd numbers.

listToSet(L,R):-listToSet(L, [], R).
listToSet([],Acc,Acc).
listToSet([H|T], Acc, R):- member(H,Acc), listToSet(T,Acc,R).
listToSet([H|T], Acc, R):-listToSet(T,[H|Acc],R).

mainlts(L,R):- reverse(R, R1), listToSet(L, R1).

%b

decomp([],[], [],_,_).

decomp([H|T], E, O, Ne, No):- H mod 2 =:=0,
                                  Ne1 is Ne+1,
                                  decomp(T,[H|E],O,Ne1,No).
decomp([H|T], E, O, Ne, No):- H mod 2 =\= 0,
                                  No1 is No+1,
                                  decomp(T,E,[H|O],Ne,No1).

deven([],[]).
deven([H|T], [H|Acc]):- H mod 2 =:= 0, deven(T,Acc).
deven([H|T], Acc):- H mod 2 =\= 0, deven(T,Acc).

dodd([],[]).
dodd([H|T], [H|Acc]):- H mod 2 =\=0, dodd(T, Acc).
dodd([H|T], Acc):-H mod 2 =:= 0, dodd(T, Acc).

nreven([],0).
nreven([H|T],Nr):-H mod 2=:=0,nreven(T, Nr1), Nr is Nr1+1.
nreven([H|T],Nr):-H mod 2=\=0, nreven(T,Nr).

nrodd([],0).
nrodd([H|T],Nr):-H mod 2=\=0, nrodd(T,Nr1), Nr is Nr1+1.
nrodd([H|T],Nr):-H mod 2=:= 0, nrodd(T,Nr).

dcmmain(L, EL, OL, NRE, NRO):-deven(L,EL), dodd(L,OL), nreven(L,NRE), nrodd(L,NRO).


%9.
%a. Insert an element on the position n in a list.
% b. Define a predicate to determine the greatest common divisor of all
% numbers from a list.

%A

%insn([],_,[],_,_).
insn([H|T],E,[H|Acc],Curr,Pos):-Curr =:= Pos, insn(T,E,Acc,Curr1,Pos),Curr is Curr1-1.
insn([H|T],E,[E,H|Acc],Curr,Pos):-Curr=\=Pos, insn(T,E,Acc,Curr1,Pos),Curr is Curr1-1.


addinl([],_,[]).
addinl([H|T],E,[H,E|Acc]):-addinl(T,E,Acc).

lenlist([],0).
lenlist([_|T],R):-lenlist(T,R1), R is R1+1.

ins(Val,[H|List],Pos,[H|Res]):-Pos>1,!, Pos1 is Pos - 1, ins(Val,List,Pos1,Res).
ins(Val, List, 1, [Val|List]).



insrt([H|T],P,[H|Rez],E):-P>1,!, P1 is P-1, insrt(T,P1,Rez,E).
insrt(L,1,[E|L],E).

%B???
%

%8.
% a. Write a predicate to determine if a list has even numbers of
% elements without counting the elements from the list.
% b. Write a predicate to delete first occurrence of the minimum number
% from a list.

%A

evn([]):-true.
evn([_]):-false.
evn([_,_|T]):-evn(T).

%b

minim([H],H).
minim([H1,H2|T],M):- H1=<H2, minim([H1|T],M).
minim([H1, H2|T],M):- H1>H2, minim([H2|T],M).

delel([],_,[],_).
delel([H|T],E,Acc,0):- H=:=E, delel(T,E,Acc,1).
delel([H|T],E,[H|Acc],0):- H=\=E, delel(T,E,Acc,0).
delel([H|T],E,[H|Acc],1):- delel(T,E,Acc,1).

delmin(L,R):-minim(L,E),delel(L,E,R,0).


%3.
%a. Define a predicate to remove from a list all repetitive elements.
%Eg.: l=[1,2,1,4,1,3,4] => l=[2,3])
% b. Remove all occurrence of a maximum value from a list on integer
% numbers.
%
%
%below not working%%%%%%%%%%%%%%%%%
rep(L,R):-rep(L,R,[]).
rep([],_,_).
rep([H|T],Acc, [H|Rep]):-member(H,T), rep(T,Acc,Rep).
rep([H|T],Acc, Rep):-member(H,Rep), rep(T,Acc,Rep).
rep([H|T],[H|Acc],Rep):-not(member(H,T)),not(member(H,Rep)),rep(T,Acc,Rep).
%above not workng%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%list to set
lts([],[],[]).
lts([H|T], [H|Acc],Ew):-not(member(H,T)),lts(T,Acc,Ew).
lts([H|T], Acc,[H|Ew]):-member(H,T),lts(T,Acc,Ew).

lts2(L,R,Dup1):- lts(L,R,Dup), listToSet(Dup,Dup1).

%idk 3a
%
%
%3b
%
maxm([H],H).
maxm([H1,H2|T], M):-H1>=H2, maxm([H1|T], M).
maxm([H1,H2|T], M):-H2>H1, maxm([H2|T], M).

rmvmax([],[]).
rmvmax([H|T], Acc):- maxm([H|T],H), rmvmax(T, Acc).
rmvmax([H|T], [H|Acc]):-not(maxm([H|T],H)), rmvmax(T,Acc).

%2.
% a. Write a predicate to remove all occurrences of a certain atom from a
% list.
% b. Define a predicate to produce a list of pairs (atom n) from an
% initial list of atoms. In this initial list atom has n occurrences.
% Eg.: numberatom([1, 2, 1, 2, 1, 3, 1], X) => X = [[1, 4], [2, 2], [3,
% 1]].


rmvfct([],[],_).
rmvfct([H|T], [H|Acc], E):- H=\=E,rmvfct(T, Acc, E).
rmvfct([H|T], Acc, E):- H=:=E,rmvfct(T, Acc, E).

%b
%
nroccr([],_,0).
nroccr([H|T],E,Nr):-H=:=E,nroccr(T,E,Nr1), Nr is Nr1+1.
nroccr([H|T],E,Nr):-H=\=E,nroccr(T,E,Nr).


