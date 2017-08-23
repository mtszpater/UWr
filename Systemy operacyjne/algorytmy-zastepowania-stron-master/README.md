# Algorytmy zastępowania stron - zadanie na pracownię z Systemów Operacyjnych



Mateusz Pater

Systemy Operacyjne

## Stronicowanie na żądanie

Stronicowanie na żądanie jest najczęstszym sposobem implementacji pamięci wirtualnej. W skrócie można go określić jako sprowadzanie strony do pamięci operacyjnej tylko wtedy, gdy jest ona potrzebna. Nazywa się to także procedurą leniwej wymiany. Takie rozwiązanie zmniejsza liczbę wykonywanych operacji wejścia/wyjścia i zapotrzebowanie na pamięć operacyjną, ponieważ nie sprowadza się niepotrzebnych stron (pojedyncze wywołanie dużego wielofunkcyjnego programu może wymagać sprowadzenia jedynie niewielkiej części jego kodu). Dzięki temu zmniejsza się czas reakcji systemu. Można też obsłużyć większą liczbę użytkowników.


Gdy proces odwołuje się do pamięci, mogą zajść trzy sytuacje:

* odwołanie jest niepoprawne,
* odwołanie jest poprawne i strona jest w pamięci, oraz
* odwołanie jest poprawne, ale strony nie ma w pamięci.

W pierwszym przypadku zlecenie jest odrzucane, w drugim jest po prostu obsługiwane, a w trzecim musi dodatkowo obejmować sprowadzanie żądanej strony z dysku do pamięci.\\

Oto czynności wykonywane w trakcie obsługi braku strony:

* Sprawdzenie wewnętrznej tablicy (zwykle znajduje się ona w bloku kontrolnym procesu), aby stwierdzić, czy odwołanie do pamięci było poprawne.
* Znalezienie wolnej ramki w pamięci fizycznej.
* Sprowadzanie brakującej strony z dysku.
* Aktualizacja tablicy stron (wstawienie numeru ramki i ustawienie bitu poprawności na 1).
* Wznowienie instrukcji przerwanej przez wystąpienie braku strony (teraz żądana strona jest już dostępna w pamięci).


Może się jednak tak zdarzyć, że nie ma wolnej ramki w pamięci. Należy wówczas znaleźć jakąś nieużywaną ramkę i przenieść ją na dysk (jeżeli oczywiście na dysku nie ma już jej wiernej kopii). Tym zajmuje się algorytm zastępowania stron. Należy go oczywiście tak opracować, żeby liczba zastępowanych stron była jak najmniejsza.


#Algorytmy zastępowania stron
Gdy wystąpi brak strony a nie będzie już wolnych ramek, trzeba wybrać jedną z ramek i zastąpić obecną w niej stronę żądaną stroną. Dzięki zastępowaniu stron pamięć logiczna może być większa niż pamięć fizyczna.


Zastępowanie strony obejmuje następujące czynności:

* Znalezienie położenia żądanej strony na dysku.
* Znalezienie strony-ofiary, która ma być usunięta z pamięci.
* Zapisanie ofiary na dysk -- o ile na dysku nie ma jej wiernej kopii.
* Oznaczenie w tablicy stron odwołania do ofiary jako niepoprawnego.
* Wczytanie żądanej strony do zwolnionej ramki.
* Oznaczenie w tablicy stron odwołania żądanej strony jako poprawnego.


Punkt drugi mówi o znalezieniu strony-ofiary, tą czynnością zajmują się algorytmy zastępowania stron. Jest to jedyne miejsce, gdzie wybór odpowiedniego algorytmu w systemie operacyjnym może wpłynąć na efektywność pamięci wirtualnej. Istnieje wiele takich algorytmów. Najważniejszym kryterium oceny będzie liczba braków stron. Im jest ona mniejsza, tym algorytm lepszy.

W dalszych rozdziałach sprawdzimy jak algorytmy radzą sobie z następującym ciągiem odwołań do stron:  1 , 2 , 3 , 4 , 1 , 2 , 5 , 1 , 2 , 3 ,  4 , 5  

##Algorytm optymalny

Ofiarą staje się strona, która będzie używana najpóźniej. Jest to tylko algorytm najlepszy, ale niestety tylko teoretyczny. 
Nie ma możliwości zaimplementowania go w praktyce. 
Nie da się przecież przewidzieć przyszłych odwołań do pamięci. Służy on do oceny jakości innych algorytmów.

Algorytm dla naszego ciągu odwołań do stron 1 , 2 , 3 , 4 , 1 , 2 , 5 , 1 , 2 , 3 ,  4 , 5   daje wynik łącznie 6 zmian stron. Do tego wyniku będziemy 
porównywać pozostałe algorytmy.


## First-In-First-Out (FIFO)
Strony znajdujące się w pamięci fizycznej tworzą kolejkę FIFO. Każda nowa strona jest wrzucania na koniec kolejki, a ofiarą staję się pierwsza strona na początku kolejki.
Zaletą tego algorytmu jest prosta implementacja.


Jak widać wynikiem jest liczba 9 zmian stron. Jest to wynik zdecydowanie gorszy niż ten z algorytmu optymalnego.

A co jeśli ramek będzie więcej? Ta liczba wzrasta. 

## Least Recently Used (LRU)

Ofiarą staje się strona, która nie była używana od dłuższego czasu. Jest to algorytm bazujący na pomyśle z algorytmu optymalnego tyle, że zamiast przyszłość
bierze pod uwagę przeszłość. 

Wynik 8 braków stron jest już istotnie lepszy od otrzymanego z użyciem algorytmu FIFO.

##Algorytmy zliczające
Oba algorytmy polegają na zliczaniu liczby odwołań do każdej strony. Nie są one zbyt popularne z powodu kłopotliwej implementacji.

###Least Frequently Used (LFU)
W przypadku LFU ofiarą staje się strona z najmniejszą liczbą odwołań. Zakładamy, że nie są to zbyt aktywnie użytkowane strony zatem należy usunąć je z pamięci.


###Most Frequently Used (MFU)
W drugim przypadku sprawa jest odwrotna. Zakładamy, że strony o małych licznikach odwołań zostały właśnie załadowane i wkrótce będą jeszcze używane zatem
ofiara staje się strona z największą liczbą odwołań.




## Program do symulacji 

W programie powinniśmy wybrać ilość ramek oraz uzupełnić tablicę odwołań. Następnie możemy wybrać jeden z pięciu zdefiniowanych algorytmów.


```bash
  $ gcc main.c -std=c99 
```
 Uruchomienie :
```bash
  $ .\a.out
```




![alt_tag](http://i.imgur.com/MGncl3b.png)
