-- Zadanie 1
-- 
-- Wypisz ile jest wszystkich kobiet, które spełniają jednocześnie następujące warunki:
--		używają przeglądarki Firefox
-- 		urodziły się w styczniu
--		mają mniej niż 30 lat (na dziś)

-- Mateusz Pater, mka

-- nie dalem count, bo jest ich malo wiec widac ile :D
SELECT * from person
WHERE browserused = 'Firefox'
AND gender = 'female'
AND extract(year from now()) - extract(year from birthday) < 30
AND extract(month from birthday) = 1
ORDER BY birthday desc;



-- Zadanie 2
--
-- Wypisz imiona i nazwiska osób, które napisały jakiegoś posta oraz jakiś komentarz. Interesują 
-- nas wyłącznie osoby z nazwiskami na literę E. Zadbaj aby wyniki się nie powtarzały oraz były 
-- posortowane alfabetycznie: w pierwszej kolejności wg nazwiska, w drugiej wg imion.

-- Mateusz Pater, mka

SELECT distinct firstname, lastname from person 
WHERE id IN ( SELECT personid from post_hascreator_person )
AND id IN ( SELECT personid from comment_hascreator_person )
AND lastname like 'E%'
ORDER by lastname, firstname ASC;

-- Zadanie 3
-- 
-- Wypisz imiona i nazwiska osób, które napisały jakiegoś posta oraz komentarz będący odpowiedzią na
-- tego posta. Jak poprzednio interesują nas wyłącznie osoby z nazwiskami na literę E.

-- Mateusz Pater, mka

SELECT distinct firstname, lastname from person 
WHERE id IN (
	SELECT personid from comment_hascreator_person
	JOIN comment_replyof_post ON comment_hascreator_person.commentid = comment_replyof_post.commentid
	WHERE comment_replyof_post.postid IN ( 
						SELECT postid FROM post_hascreator_person 
						WHERE personid = comment_hascreator_person.personid
						)	
)
AND lastname like 'E%';


-- Zadanie 4
-- 
-- Wypisz imiona i nazwiska osób, które nie polubiły żadnego komentarza. Zadbaj aby wyniki się nie 
-- powtarzały oraz były posorotwane alfabetycznie: w pierwszej kolejności wg nazwisk, w drugiej wg imion.
-- Mateusz Pater, mka

SELECT firstname, lastname from person
WHERE id NOT IN ( SELECT personid from person_likes_comment )
ORDER by lastname, firstname ASC;
