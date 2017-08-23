%	METODY PROGRAMOWANIA 2017 
%	UNIWERSYTET WROCŁAWSKI 
%	MATEUSZ PATER
% 	Definiujemy moduł zawierający rozwiązanie.
% 	Należy zmienić nazwę modułu na {imie}_{nazwisko} gdzie za
% 	{imie} i {nazwisko} należy podstawić odpowiednio swoje imię
% 	i nazwisko bez znaków diakrytycznych


:- module(mateusz_pater, [solve/2]).
:- op(200, fx, ~).
:- op(500, xfy, v).

%
%	PREDYKAT ZWRACAJĄCY WARTOŚCIOWANIA DLA LISTY KLAUZUL 					
%

solve([], []).

solve(Clauses, Solution) :-
 	zamien_klauzule_na_listy(Clauses, ListaKlauzul),
	sort(ListaKlauzul,L),
	rozwiazanie(L, Solution, [], L),
	\+ wykluczajace_sie(_, Solution).

%
%	PREDYKAT GENERUJACY CALE ROZWIAZANIE 									
%

rozwiazanie([], X, X, []) :- !.
rozwiazanie([[]|_], _, _, _) :- !.

rozwiazanie([], Res, Acc, Z) :-
	rozwiazanie(Z, Res, Acc, Z).

rozwiazanie([H|T], Res, Acc, List) :-
	ustalWartosciowania(H, Acc, NewAcc),
	select(H, List, NewList),
	rozwiazanie(T, Res, NewAcc, NewList).

%
%	GENERUJE WARTOSCIOWANIA DLA KLAUZUL 							
%

ustalWartosciowania([], Wartosciowania, Wartosciowania).
ustalWartosciowania(Lista, Wartosciowania, Res) :-
	wartosciowaniaDoListyLiteralow(Wartosciowania, NoweWartosciowania),
	usun_liste(Lista, NoweWartosciowania, ListaPoUsunieciu),
	ustalWartosciowania(ListaPoUsunieciu, Wartosciowania, Res, Lista).


ustalWartosciowania([], Wartosciowania, Wartosciowania, Acc) :-
	czy_lista_spelniona_dla_wartosciowan(Acc, Wartosciowania).


ustalWartosciowania([H|L], Wartosciowania, Res, Acc) :-
	( czy_jest_wartosciowanie(H, Wartosciowania, _) ->	
		ustalWartosciowania(L, Wartosciowania, Res, Acc)
		; 
		dodajWartosciowanieDlaLiteraluWKlauzuli(H, X),
		ustalWartosciowania(L, [X|Wartosciowania], Res, Acc)

	).


%	SPRAWDZA CZY DLA DANYCH:						   					   
%	X = [p,z,t] WARTOSCIOWANIA = [ (p,t), (z,t) .. ] 					   
%	SPELNIONA JEST KLAUZULA 						   					   


czy_lista_spelniona_dla_wartosciowan([], _).
czy_lista_spelniona_dla_wartosciowan([X], Wartosciowania) :-
	czy_jest_wartosciowanie(X, Wartosciowania, t).

czy_lista_spelniona_dla_wartosciowan([L|T], Wartosciowania) :-
	length([L|T], Len),
	Len > 1,

	( czy_jest_wartosciowanie(L, Wartosciowania, t)  ->
		czy_lista_spelniona_dla_wartosciowan([], Wartosciowania);
		czy_lista_spelniona_dla_wartosciowan(T, Wartosciowania)
	).

%
%	SPRAWDZA CZY ISTNIEJE JUŻ WARTOŚCIOWANIE DLA DANEGO LITERAŁU 		   
%

czy_jest_wartosciowanie(Lit, List, X) :-
	member((Lit, X), List).

czy_jest_wartosciowanie(~Lit, List, R) :-
	member((Lit, X), List),
	( X == f  ->
		R = t;
		R = f 
	).

%
%	SPRAWDZA CZY WARTOŚCIOWANIA WZAJEMNIE SIĘ NIE WYKLUCZAJĄ	 		   
%

wykluczajace_sie(Lit, Lista) :-
	czy_jest_wartosciowanie(Lit, Lista, f),
	czy_jest_wartosciowanie(Lit, Lista, t).

%
%	DOSTAJE LITERAŁY Z WARTOŚCIĄ, A ZWRACA LISTĘ LITERAŁÓW 			   
%

wartosciowaniaDoListyLiteralow([], []).
wartosciowaniaDoListyLiteralow([(H, _)|L], [H|Literaly]) :-
	wartosciowaniaDoListyLiteralow(L, Literaly).
	
%
%	PREDYKATY PRZYPISUJĄ WARTOŚCIOWANIA DANYM LITERAŁOM 				   
%

dodajWartosciowanieDlaLiteralu(~X,(X,f)) :- !.
dodajWartosciowanieDlaLiteralu(X,(X,t)) :- !.

dodajWartosciowanieDlaLiteraluWKlauzuli(~X,(X,f)).
dodajWartosciowanieDlaLiteraluWKlauzuli(~X,(X,t)).

dodajWartosciowanieDlaLiteraluWKlauzuli(X,(X,f)) :-
  	\+ jestNegatywny(X).
dodajWartosciowanieDlaLiteraluWKlauzuli(X,(X,t)) :-
   	\+ jestNegatywny(X).

%
%	USUWA PODLISTĘ LISTY 												   
%

usun_liste([], _, []).
usun_liste([H|T], List2, Res) :-
	member(H, List2), 
	!, 
	usun_liste(T, List2, Res). 

usun_liste([H|T], List2, [H|Res]) :-
	usun_liste(T, List2, Res).

%
%	REGUŁY DOTYCZĄCE LITERAŁÓW										   
%

jestNegatywny(~_).

literal(X) :-
	atom(X).
literal(~X) :- 
	atom(X).

%
%	DOSTAJE LISTĘ [ p v t, p, [..] ] ZWRACA [ [p,t], [p], [..] ]		   
%

zamien_klauzule_na_listy([X], [L]) :-
	zbior_do_listy(X, L), 
	!.

zamien_klauzule_na_listy([H|T], [H1|T1]) :-
	zbior_do_listy(H, H1), 
	zamien_klauzule_na_listy(T, T1).

zbior_do_listy(X, L) :-
	klauzula_do_listy(X, L1), 
	sort(L1, L).

klauzula_do_listy(X, [X]) :-
	literal(X), !.

klauzula_do_listy(X, [H|T]) :-
	pierwszy_literal(X, H), 
	reszta_literalow(X, X1), 
	klauzula_do_listy(X1, T).

pierwszy_literal(C v _, C) :-
	literal(C).

reszta_literalow(C v D, D) :-
	literal(C).
