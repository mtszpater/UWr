perm([], []).

perm(P, [X|L]) :-
	select(X, P, Y),
	perm(Y, L).