-- Zdefiniuj dziedzinę semestry z dwiema wartościami: 'zimowy' i 'letni' oraz niedopuszczalną wartością pustą. 
CREATE DOMAIN semestry as text
NOT NULL
CHECK (VALUE IN ('zimowy', 'letni'));
-- Zdefiniuj sekwencję numer_semestru i nadaj jej wartość równą pierwszej nieużywanej liczbie w kolumnie semestr_id 
-- (a raczej maksymalnej wartości użytej, by kolejne wartości generowane przez sekwencje nie kolidowały z dotychczas użytymi).

CREATE SEQUENCE my_sequence START 39;
-- baza=# select nextval('my_sequence');
--  nextval
-- ---------
--       39
-- (1 row)

-- baza=# select nextval('my_sequence');
--  nextval
-- ---------
--       40
-- (1 row)

-- Do tabeli semestr dodaj dwa nowe atrybuty:
-- 			semestr – kolumnę typu semestry; (ponieważ typ kolumny nie dopuszcza wartości pustych możesz np. 
-- 					zdefiniować nową kolumnę z niepustą wartością domyślną);
-- 			rok – kolumnę typu tekstowego opisującą rok akademicki w formacie: '2010/2011'; 
-- 					(nie musisz definiować wymaganego formatu, wystarczy, że będzie to słowo odpowiedniej długości);

ALTER table semestr add column semestr semestry DEFAULT 'zimowy';
ALTER table semestr add column rok text CHECK (char_length(rok) = 9);

-- Wypełnij kolumny semestr i rok rozbijając nazwę każdego semestru na typ semestru i rok akademicki 
-- (sprawdź w dokumentacji PostgreSQL, jakie funkcje tekstowe są dostępne). (semestr i rok możesz ustawić w oddzielnych poleceniach UPDATE:
-- ustawiając semestr możesz tylko zbadać, jakie słowo (zimowy/letni) występuje w nazwie semestru;

UPDATE semestr SET semestr = 'zimowy' WHERE nazwa like '%zimowy%';
UPDATE semestr SET semestr = 'letni' WHERE nazwa like '%letni%';

UPDATE semestr s1 SET rok = (SELECT SUBSTRING(s2.nazwa FROM '.{9}$') FROM semestr s2 where s1.semestr_id = s2.semestr_id);


-- Usuń z tabeli semestr kolumnę nazwa.
ALTER TABLE semestr DROP column nazwa;


--  Dodaj do kolumn semestr i rok wartości domyślne, które dla bieżącej daty od stycznia 
-- do czerwca (włącznie) ustawiają domyślny semestr letni i rok (x-1)/x; a dla  daty od lipca do grudnia 
-- (włącznie) - semestr zimowy i rok x/(x+1) (sprawdź w dokumentacji PostgreSQL dostępne funkcje daty i czasu). (możesz skorzystać z:
-- wyrażenia warunkowego CASE WHEN warunek1 THEN wartosc1 WHEN warunek2 THEN wartosc2... ELSE wartosc
-- funkcji EXTRACT (MONTH FROM data)
-- operatora konkatenacji: ||   )

ALTER TABLE semestr ALTER COLUMN semestr SET DEFAULT 
CASE WHEN (extract(MONTH from current_date) BETWEEN 1 AND 6) 
	THEN  'letni'
	ELSE  'zimowy'
END;

-- Załóż tabele: pracownik oraz student. Dla każdej tabeli zdefiniuj właściwe dla niej pola występujące w tabeli uzytkownik. 
-- (czyli wybierz te pola z tabeli uzytkownik, które musi mieć pracownik i te, które musi mieć student)

CREATE TABLE student (
    kod_uz integer NOT NULL PRIMARY KEY,
    imie character varying(15) NOT NULL,
    nazwisko character varying(30) NOT NULL,
    semestr smallint
);

CREATE TABLE pracownik (
    kod_uz integer NOT NULL PRIMARY KEY,
    imie character varying(15) NOT NULL,
    nazwisko character varying(30) NOT NULL
);

-- Wpisz do tabeli pracownik wszystkie osoby, które kiedykolwiek prowadziły zajęcia. 

INSERT INTO pracownik SELECT u.kod_uz, u.imie, u.nazwisko FROM uzytkownik u 
WHERE u.kod_uz IN ( SELECT g.kod_uz from grupa g );

-- Wpisz do tabeli student osoby, które kiedykolwiek uczęszczały na zajęcia. 

INSERT INTO student SELECT u.kod_uz, u.imie, u.nazwisko, u.semestr from uzytkownik u
WHERE u.kod_uz IN ( SELECT g.kod_uz from wybor g );

-- Przekieruj klucze obce wskazujące na tabelę uzytkownik tak, by wskazywały teraz odpowiednio na tabele pracownik i student.
 -- Usuń tabelę uzytkownik. (dokładniej, usuń więzy klucza obcego wskazujące na tabelę uzytkownik i utwórz klucze obce wskazujące 
 	-- odpowiednio na tabelę pracownik i student; wszystko to poleceniami ALTER TABLE nazwa_tabeli [ADD|DROP] CONSTRAINT nazwa_więzu ...);

alter table wybor DROP constraint fk_wybor_uz;
alter table wybor ADD constraint "fk_wybor_uz" FOREIGN KEY (kod_uz) REFERENCES student(kod_uz) DEFERRABLE;
alter table grupa drop constraint fk_grupa_uz;
alter table grupa add constraint "fk_grupa_uz" FOREIGN KEY (kod_uz) REFERENCES uzytkownik(kod_uz) DEFERRABLE;
drop table uzytkownik;


-- Zdefiniuj dziedzinę rodzaje_zajec tak, by nie dopuszczała wartości pustych i 
-- obejmowała wszystkie występujące w tej chwili rodzaje zajęć w wersji małej i dużej (litery). 
-- (nie musisz generować wartości dopuszczalnych w dziedzinie automatycznie - zobacz,
--  jakie występują i wpisz je w definicji dziedziny)
select distinct rodzaj_zajec from grupa;

CREATE DOMAIN rodzaje_zajec as char(1) 
NOT NULL CHECK (VALUE IN ('w', 'W', 'c', 'C', 'e', 'E', 'p', 'P', 'r', 'R', 's', 'S'));

-- Zmień tabelę grupa tak, by używała zdefiniowanej dziedziny zamiast typu char(1) w 
-- kolumnie rodzaj_zajec. (sprawdź w dokumentacji PostgreSQL komendę ALTER TABLE)

ALTER TABLE grupa ALTER column rodzaj_zajec TYPE rodzaje_zajec;

-- Zdefiniuj perspektywę obsada_zajec_view o polach: 
-- 		prac_kod - kod prowadzącego, 
-- 		prac_nazwisko - nazwisko prowadzącego, 
-- 		przed_kod - kod przedmiotu, 
-- 		przed_nazwa - nazwa przedmiotu, 
-- 		rodzaj_zajec - rodzaj zajęć, jak w grupie, 
-- 		liczba_grup - liczba grup danego rodzaju (wykł. ćw. itp.) do danego przedmiotu prowadzonych przez daną osobę, 
-- 		liczba_studentow - liczba wszystkich studentów (z powtórzeniami), którzy uczęszczali do grup tego rodzaju z 
-- 						    tego przedmiotu do tego prowadzącego. 

CREATE VIEW obsada_zajec_view
  (prac_kod, prac_nazwisko, przed_kod, przed_nazwa,
   rodzaj_zajec, liczba_grup, liczba_studentow)
AS
SELECT
   pr.kod_uz, nazwisko, p.kod_przed, p.nazwa, rodzaj_zajec,
   COUNT(DISTINCT kod_grupy), COUNT(w.kod_uz)
FROM pracownik pr JOIN
     grupa USING(kod_uz) JOIN
     wybor w USING(kod_grupy) JOIN
     przedmiot_semestr USING(kod_przed_sem) JOIN
     przedmiot p USING(kod_przed)
GROUP BY
     pr.kod_uz, nazwisko, p.kod_przed, nazwa, rodzaj_zajec;


-- Zdefiniuj tabelę obsada_zajec_tab o schemacie analogicznym, jak powyższa perspektywa. Wypełnij ją danymi.

CREATE TABLE obsada_zajec_tab (
    prac_kod integer NOT NULL,
    prac_nazwisko character varying(30) NOT NULL,
    przed_kod integer NOT NULL,
    przed_nazwa text not null,
    rodzaj_zajec rodzaje_zajec,
    liczba_grup integer NOT NULL,
    liczba_studentow integer
);


INSERT INTO obsada_zajec_tab SELECT * from obsada_zajec_view;


-- Korzystając z perspektywy znajdź dla każdego przedmiotu obowiązkowego i 
-- podstawowego osobę, która uczyła najwięcej osób tego przedmiotu.  
-- Następnie zrób to samo korzystając z tabeli i sprawdź, 
-- czy występuje widoczna różnica w czasie wykonania.


SELECT v.prac_kod, v.prac_nazwisko, v.przed_nazwa, sum(v.liczba_studentow) as sum from obsada_zajec_view v
JOIN przedmiot p  ON v.przed_kod = p.kod_przed WHERE 
p.rodzaj = 'o'
AND sum > ALL ( 
			SELECT sum(v.liczba_studentow) from obsada_zajec_view v
			JOIN przedmiot p  ON v.przed_kod = p.kod_przed WHERE 
			p.rodzaj = 'o'
			GROUP BY v.prac_kod, v.przed_nazwa
)
GROUP BY v.prac_kod, v.prac_nazwisko,v.przed_nazwa
ORDER BY sum desc;



-- W tym zadaniu bazę danych uzupełnimy o dane o praktykach zawodowych.
-- Załóż tabelę firma o atrybutach (pamiętaj o kluczach i ograniczeniach  NULL/NOT NULL):
-- kod_firmy - unikalny kod generowany przez sekwencję;
-- nazwa - pole niepuste,
-- adres - pole niepuste,
-- kontakt - pole niepuste.

CREATE table firma (
	kod_firmy serial PRIMARY key,
	nazwa text not null,
	adres text not null,
	kontakt text not null
);

-- Wpisz krotki: (SNS, Wrocław, H.Kloss); (BIT, Kraków, R.Bruner); (MIT, Berlin, J.Kos);
INSERT INTO firma (nazwa, adres, kontakt) VALUES ('SNS', 'Wrocław', 'H.Kloss');
INSERT INTO firma (nazwa, adres, kontakt) VALUES ('BIT', 'Kraków', 'R.Bruner');
INSERT INTO firma (nazwa, adres, kontakt) VALUES ('MIT', 'Berlin', 'J.Kos');


-- Załóż tabelę oferta_praktyki o atrybutach:
-- kod_oferty - automatycznie generowany unikalny klucz,
-- kod_firmy - klucz obcy do firmy;
-- semestr_id - klucz obcy do semestr;
-- liczba_miejsc - liczba dodatnia;
CREATE table oferta_praktyki (
	kod_oferty serial PRIMARY key,
	kod_firmy integer,
	semestr_id integer, 
	liczba_miejsc integer,

	CONSTRAINT con1 check (liczba_miejsc >= 0),
	CONSTRAINT fk_kodfirmy FOREIGN KEY (kod_firmy)
    REFERENCES firma(kod_firmy),
    CONSTRAINT fk_semestrid FOREIGN KEY (semestr_id)
    REFERENCES semestr(semestr_id)

);

-- Wpisz na semestr letni 2013/14 oferty: SNS (3 miejsc) i MIT (2 miejsca);
insert into semestr (semestr, rok) VALUES('letni', '2013/2014');
-- id 40
insert into oferta_praktyki (kod_firmy, semestr_id, liczba_miejsc) VALUES (1, 40, 3);
insert into oferta_praktyki (kod_firmy, semestr_id, liczba_miejsc) VALUES (3, 40, 2);

-- Załóż tabelę praktyki o atrybutach:
-- student - kod studenta,
-- opiekun - kod pracownika,
-- oferta - kod oferty.

create table praktyki (
	student integer,
	opiekun integer,
	oferta integer,

	CONSTRAINT fk_student FOREIGN KEY (student)
    REFERENCES student(kod_uz),

    CONSTRAINT fk_opiekun FOREIGN KEY (opiekun)
    REFERENCES pracownik(kod_uz),

    CONSTRAINT fk_praktyka FOREIGN KEY (oferta)
    REFERENCES oferta_praktyki(kod_oferty)
);

-- Wypełnij wszystkie wolne miejsca na praktykach studentami z semestru pomiędzy 6 i 10, 
-- którzy jeszcze nie zaliczyli praktyki.(zapytanie to możesz wykonać np. 
-- powtarzając kilka razy zapytanie, które do każdej firmy, w której jest >=1 
-- miejsce skieruje jednego studenta (i zaktualizuje liczbę miejsc);




-- Zdefiniuj perspektywę plan_zajec, która pokaże dla każdej osoby (studenta), 
-- semestru i przedmiotu termin, w jakim osoba powinna uczęszczać na zajęcia z tego 
-- przedmiotu (także do jakiej sali i kto prowadzi zajęcia).

CREATE VIEW plan_zajec 
    (student, termin, prowadzacy, sala, przedmiot, semestr, rok)
AS
    SELECT
    w.kod_uz, g.termin, p.nazwisko, g.sala, przedmiot.nazwa, s2.semestr, s2.rok
    FROM grupa g
    JOIN pracownik p using (kod_uz)
    JOIN wybor w using (kod_grupy)
    JOIN przedmiot_semestr using (kod_przed_sem)
    JOIN przedmiot using (kod_przed)
    JOIN semestr s2 using (semestr_id)
    JOIN student s ON s.kod_uz = w.kod_uz
    GROUP BY 
    w.kod_uz, g.termin, p.nazwisko, g.sala, przedmiot.nazwa, s2.semestr, s2.rok;




-- Wykorzystaj perspektywę plan_zajec, by pokazać plan zajęć konkretnego studenta (wybierz dowolnie wg kodu) w konkretnym semestrze.
select * from plan_zajec where student = 2619 AND rok = '2009/2010' and semestr = 'zimowy';

-- Wykorzystaj perspektywę plan_zajec, by pokazać plan zajęć konkretnego pracownika (wybierz dowolnie wg kodu) w konkretnym semestrze.
select distinct(przedmiot, termin) from plan_zajec where prowadzacy = 'Godowski' and semestr = 'letni';
--  nie chcemy tutaj wszystkich studentów, którzy mają zajęcia w danej sali tylko po prostu, informacja, że takowe sie odbywają
-- oczywiscie ta perspektywe mozemy zmienić, aby był id prowadzącego (aktualnie moze byc kolizja względem nazwisk)

-- Wykorzystaj perspektywę plan_zajec, by pokazać plan w konkretnej sali w konkretnym semestrze.
select distinct termin, prowadzacy, sala, przedmiot FROM plan_zajec where semestr = 'letni' AND rok = '2010/2011' AND sala = '103';

