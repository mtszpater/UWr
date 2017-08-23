:- module(mateusz_pater, [resolve/4, prove/2]).
:- op(200, fx, ~).
:- op(500, xfy, v).

% CZĘŚĆ PIERWSZA ZADANIA

resolve(Var, Clause1, Clause2, Res) :-
	set_to_list(Clause1, ListWithClause1),
	set_to_list(Clause2, ListWithClause2),
	select(Var, ListWithClause1, ListWithClause1AfterSelect),
	select(~Var, ListWithClause2, ListWithClause2AfterSelect),
	append(ListWithClause1AfterSelect, ListWithClause2AfterSelect, ClauseResult),
	sort(ClauseResult, ResTmp),
	length(ResTmp, Length),
	( Length == 0 ->  Res = [] ; clause_to_list(Res, ResTmp) ).

% CZĘŚĆ DRUGA ZADANIA

prove(List, Res) :-
	member([], List),
	Res = [([], axiom)], !.

prove(List, Res) :-
	deduce(List, Rezolwenty),
	member([[], [A, B]], Rezolwenty),
	make_tree_of_proof([[],[A,B]], Rezolwenty, PotrzebneRezolwenty),
	reverse(PotrzebneRezolwenty, OdwroconeRezolwenty),
	numbering(OdwroconeRezolwenty, PonumerowaneRezolwenty, 1),
	print_proof(OdwroconeRezolwenty, Res, PonumerowaneRezolwenty), !.
											
% PRZEPROWADZA REZOLWENTE KAŻDEGO ELEMENTU Z KAŻDYM

deduce( Clauses, Res ) :-
	clauses_to_list(Clauses, ListOfClauses),
	deduce(ListOfClauses, ListOfClauses, ListOfClauses, Res).

deduce([], Clauses, _, SortedClauses) :-
	sort(Clauses, SortedClauses).

deduce([H|T], Clauses, ClearClauses, Res) :-
	( deduce_with_one_clause(H, ClearClauses, Result) ->
		append(Result, Clauses, NewClauses),
		get_clear_clauses(Result, ClearResult),
		append(ClearClauses, ClearResult, NewClearClauses),
		append(ClearResult, T, NewT),
		remove_tautology(NewT, NewClearT),
		deduce(NewClearT, NewClauses, NewClearClauses, Res)
		;
		deduce(T, Clauses, ClearClauses, Res)
	).

% ROBI REZOLWENTĘ JEDNEJ KLAUZULI Z CAŁYM ZBIOREM

deduce_with_one_clause(Clause, Clauses, Res) :-
	deduce_with_one_clause(Clause, Clauses,Clauses, [], Res), !.

deduce_with_one_clause( _, [],_, Acc, Acc) :- !.

deduce_with_one_clause( Clause, Clauses, Clauses_tmp, Temp, Result ) :-
	sort(Clauses,SortedClauses),
	remove_tautology(SortedClauses, [X|ClearClauses]),

	( rezolwenta(X, Clause, Clauses_tmp, Res) -> 
		append([Res], Temp, NewRes),
		deduce_with_one_clause(Clause, ClearClauses, Clauses_tmp, NewRes, Result)
		;
		deduce_with_one_clause(Clause, ClearClauses, Clauses_tmp, Temp, Result)
	).

% ZWRACA REZOLWENTĘ DWÓCH KLAUZUL O ILE JEST TO TAUTOLOGIA, NADZBIOR BĄDŹ DUPLIKAT

rezolwenta(Clause1, Clause2, Clauses, Res) :-
	append(Clause1, Clause2, AllClauses),
	list_of_literals(AllClauses, Literals),
	member(Var, Literals),

	( member(Var, Clause1) -> 
		select(Var, Clause1, ListWithClause1AfterSelect),
		select(~Var, Clause2, ListWithClause2AfterSelect),
		ToAdd = [Clause1, Clause2]
		;
		select(~Var, Clause1, ListWithClause1AfterSelect),
		select(Var, Clause2, ListWithClause2AfterSelect),
		ToAdd = [Clause2, Clause1]
	),

% ŁĄCZYMY I SORTUJEMY NASZĄ REZOLWENTĘ
	append(ListWithClause1AfterSelect, ListWithClause2AfterSelect, ClauseResult),
	sort(ClauseResult, ResTmp),
	length(ResTmp, Length),

% SPRAWDZAMY CZY ZWRACANA WARTOŚĆ TO NIE JEST CZASEM TAUTOLOGIA (OUT), NADZBIOR (OUT) LUB PO PROSTU KLAUZULA PUSTA
	(Length == 0 -> 
		Res = [ [], ToAdd ], !
		;
		\+ is_tautology(ResTmp), 
		\+ subset_of_some_clauses(ResTmp, Clauses),
		Res = [ResTmp, ToAdd], !
	).

% USUWA NADZBIORY I TAUTLOGIE Z LISTY

remove_tautology(List, Res) :-
	remove_tautology(List, [], List, Res), !.

remove_tautology([], Res, _, Res) :- !.

remove_tautology([H|T], Aku, Clauses, Res) :-
	select(H, Clauses, ClausesWithoutH),
	( (is_tautology(H) ; subset_of_some_clauses(H, ClausesWithoutH) ) ->
		remove_tautology(T, Aku, Clauses, Res)
		;
		append([H], Aku, AkuWithH),
		remove_tautology(T, AkuWithH,Clauses, Res)
	).

% ZWRACA LISTĘ LITERAŁÓW Z KLAUZULI

list_of_literals(Clauses, Res) :-
	get_literals_from_clause(Clauses, Result), sort(Result, Res).

get_literals_from_clause([], []).

get_literals_from_clause([H|T], [H2|T2]) :-
	only_literal(H, H2), get_literals_from_clause(T, T2).

% ZWRACA LISTĘ KLAUZUL BEZ ICH PRZESŁANEK 

get_clear_clauses([], []).
get_clear_clauses([ [H, [_, _]] |T], [H|Z]) :-
	get_clear_clauses(T,Z).

% TRUE JEŻELI JEST TAUTOLOGIĄ

is_tautology([]).

is_tautology([H|T]) :-
	length(T, Rozmiar), Rozmiar > 0,
	( is_negative(H) -> 
		only_literal(H, Literal),
		( member(Literal, T) -> 
			is_tautology([]), !
			; is_tautology(T)

		)
		;
		( member(~H, T) -> 
			is_tautology([]), !
			; is_tautology(T)
		)
	).

% TRUE JEŻELI JEST PODZBIOREM 

subset([], _).

subset([H|T], List) :-
	member(H, List), subset(T, List).

% TRUE JEŻELI NADZBIOREM KTÓREJŚ Z KLAUZUL

subset_of_some_clauses(Clause, [H|_]) :-
	subset(H, Clause), !.

subset_of_some_clauses(Clause, [_|T]) :-
	subset_of_some_clauses(Clause, T).

% ZNAJDUJE NASTEPNEGO POTOMKA KORZENIA

descendant(Clause, List, [Clause, [A, B]]) :-
	member([Clause, [A, B]], List ), !.

descendant(Clause, _, Clause).

% PREDYKAT WYPROWADZA DRZEWO BINARNE DOWODU, POZWALA POMINĄĆ ZBĘDNE KLAUZULE W DOWODZIE

make_tree_of_proof([R, [C1, C2]], List, [[R, [C1, C2]] | Res]) :-
	descendant(C1, List, D1),
	descendant(C2, List, D2),

	( D1=[_, [_,_]] ->
	    make_tree_of_proof(D1, List, Res1)
	    ; Res1=[D1]
	),

	( D2=[_, [_,_]]  ->
	    make_tree_of_proof(D2, List, Res2)
	    ; Res2=[D2]
	),

	append(Res1, Res2, Res3),
	remove_copies(Res3, Res).

remove_copies([], []).

remove_copies([H|T], [H|L]) :-
	\+ member(H, T),
	remove_copies(T, L), !.

remove_copies([H|T], L) :-
	member(H, T),
	remove_copies(T, L).

% WYPISYWANIE DOWODU

print_proof( [], [], _ ).

print_proof( [[Clause, [A, B]]|T], [(Z, (X, ANum, BNum)) |T2], Clauses ) :-
	member(X, A), member(~X, B),
	clause_to_list(Z, Clause),
	get_number_of_clause(A, Clauses, ANum),
	get_number_of_clause(B, Clauses, BNum),
	print_proof(T, T2, Clauses), !.

print_proof( [[[], [[A], B]]|T], [([], (A, ANum, BNum)) |T2], Clauses) :-
	get_number_of_clause([A], Clauses, ANum), get_number_of_clause(B, Clauses, BNum), print_proof(T, T2, Clauses), !.

print_proof( [Clause|T], [ (Z, axiom) |T2], Clauses ) :- clause_to_list(Z, Clause), print_proof(T, T2, Clauses), !.

% NUMERUJE KLAUZULE

numbering([], [], _).
numbering([ Clause | T], [[ (Num), Clause ]|T2], Num) :- NewNum is Num + 1, numbering(T, T2, NewNum), !.

% ZWRACA NUMER DANEJ KLAUZULI

get_number_of_clause( Clause, List, Res) :- member([Res, Clause], List), !.
get_number_of_clause( Clause, List, Res) :- member([Res, [Clause, [_, _]]], List), !.

% ZWRACA LITERAŁ X BEZ NEGACJI (JEŻELI JEST Z NEGACJĄ)

only_literal(~X, X) :- !.
only_literal(X, X).

% REGUŁY DOTYCZĄCE LITERAŁÓW										   

literal(X) :- atom(X).
literal(~X) :- atom(X).
is_negative(~_).

% DOSTAJE LISTĘ [ p v t, p, [..] ] ZWRACA [ [p,t], [p], [..] ]		   

clauses_to_list([X], [L]) :-
	set_to_list(X, L), !.

clauses_to_list([H|T], [H1|T1]) :-
	set_to_list(H, H1), clauses_to_list(T, T1).

set_to_list(X, L) :-
	clause_to_list(X, L1), sort(L1, L).

clause_to_list(X, [X]) :-
	literal(X), !.

clause_to_list(X, [H|T]) :-
	first_literal(X, H), rest_of_literals(X, X1), clause_to_list(X1, T).

first_literal(C v _, C) :-
	literal(C).

rest_of_literals(C v D, D) :-
	literal(C).