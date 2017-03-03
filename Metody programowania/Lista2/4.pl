even([]).
even([_,_|B]) :-
	even(B).

palindrom(X) :- 
	reverse(X, Y),
	X = Y.

singleton([_]).
