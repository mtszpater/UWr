head(H, [H|_]).

last(L, H) :-
	reverse(L, L2),
	head(H, L2).

tail(T, [_|T]).

init([], [_]).
init([T|Z],[T|L]) :- 
	init(Z,L).

prefix([], _).
prefix([H|T], [H|L]) :-
	prefix(T,L).
	
suffix([], _).
suffix(L, S) :-
	append(_, L, S).