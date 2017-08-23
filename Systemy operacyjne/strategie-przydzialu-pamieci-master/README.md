
# Zarządzanie pamięcią - strategie przydziału pamięci - zadanie na pracownię z systemów operacyjnych

Mateusz Pater

##Wstęp
Gdy system operacyjny przydziela procesowi obszar pamięci, to zwykle może go przydzielić z jednego z wielu obszarów wolnej pamięci. Oczywiście obszar wolnej pamięci, z którego przydzielamy pamięć musi być wystarczająco duży. Istnieje kilka strategii wybierania, z którego obszaru przydzielić pamięć.

##First-fit
Wybierany jest pierwszy wolny obszar, który jest wystarczająco duży.

Jest to najprostszy spośród wszystkich algorytm jeżeli chodzi o jego implementację.
Dla każdego procesu (linia 96) przeglądamy wszystkie bloki (linia 98), a następnie wybieramy pierwszy wolny, którego wielkość spełnia potrzeby naszego procesu (linie 99-102).

## Best-fit
Wybieramy najmniejszy wolny obszar, który jest wystarczająco duży. Pomysł, który się kryje za tą strategią jest następujący: Wolny obszar jest zwykle większy niż przydzielany obszar, więc po przydzieleniu część wolnego obszaru pozostaje wolna. W przypadku strategii best-fit, taka "końcówka" jest możliwie najmniejsza. Jeśli w przyszłości nie wykorzystamy jej, to straty z powodu fragmentacji zewnętrznej będą możliwie małe.

Dla każdego procesu (linia 112) znajdujemy najmniejszy wolny obszar, którego wielkość jest wystarczająca (linie 116-128). Następnie przeglądając wszystkie bloki (linia 130) znajdujemy wolne miejsce, które możemy zagospodarować na nasz proces (linie 131-134). 



## Worst-fit
Przydzielamy pamięć zawsze z największego wolnego obszaru (oczywiście, o ile jest on wystarczająco duży). W przypadku tej strategii, część obszaru, która pozostaje wolna jest możliwie jak największa. Jest więc szansa, że będzie można ją jeszcze wykorzystać bez konieczności uzwracenia.



Odwrotnie do algorytmu Best-fit. Dla każdego procesu (linia 145) znajdujemy blok z największą ilością wolnego obszaru. (linie 150-162). Następnie przeglądając wszystkie bloki (linia 164) znajdujemy wolne miejsce, które możemy zagospodarować na nasz proces (linie 165-169). 



```bash
$ gcc main.c 
```

Uruchomienie :
```bash
$ .\a.out
```

Na wejściu powinniśmy wpisać liczbę bloków, liczbę procesów oraz pamięć kolejnych bloków i procesów biorących udział w symulacji przydziału pamięci.

## Analiza wyników
Wynikiem działania programu jest tabela ze spisem wszystkich bloków pamięci. Jeżeli blok pamięci jest pusty to kolumna PROCES ma wartość null.

Opis nagłówka tabeli:

  * BLOK - liczba porządkowa bloku pamięci,
  * PROCES - identyfikator przydzielonego procesu,
  * PAMIĘĆ PROCESU - wymagana pamięć dla danego procesu,
  * PAMIĘĆ BLOKU - dostępna pamięć bloku,
  * FRAGMENTACJA - wynik fragmentacji wewnętrznej.
  


Utracona pamięć to suma pamięci zajętej w wyniku fragmentacji wewnętrznej.


