-- Zadanie 1
--
-- Dla danej osoby p oznaczamy p przez L(p) liczbę różnych osób, które polubiły jakikolwiek post 
-- stworzony przez p. Dla każdej osoby p, dla której L(p) przekracza 50 wypisz id, imię, nazwisko, 
-- płeć oraz liczbę L(p). Wyniki posortuj wg L(p) malejąco. 

-- Mateusz Pater, mka

SELECT post_hascreator_person.postid, person.firstname, person.lastname, person.gender, count(*) as sum from person
JOIN post_hascreator_person ON person.id = post_hascreator_person.personid
JOIN person_likes_post ON post_hascreator_person.postid = person_likes_post.postid
group by  post_hascreator_person.postid, person.firstname, person.lastname, person.gender
having count(*) >= 50
order by sum desc;


-- Zadanie 2
--
-- Wypisz id, imię i nazwisko dla wszystkich osób, których komentarze zostały łącznie polubione
-- maksymalnie wiele razy, przy czym liczymy wyłącznie polubienia z dnia 1 grudnia 2011 i później.

-- Mateusz Pater, mka

SELECT foo.id, foo.firstname, foo.lastname FROM 
(


SELECT sum(sum) as count, id, person.firstname, person.lastname FROM 
	(SELECT comment_hascreator_person.personid as id, person_likes_comment.commentid, count(*) as sum FROM person_likes_comment
JOIN comment_hascreator_person ON comment_hascreator_person.commentid = person_likes_comment.commentid
	WHERE ( extract( year from creationdate ) > 2011) OR 
 ( extract( year from creationdate ) = 2011 AND extract( month from creationdate ) = 12)
GROUP by person_likes_comment.commentid, id) as ss
JOIN person using(id)
GROUP BY id, person.firstname, person.lastname
ORDER BY count DESC

) as foo

WHERE foo.count >= ALL 
(
SELECT sum(sum) as count FROM 
	(SELECT comment_hascreator_person.personid as id, person_likes_comment.commentid, count(*) as sum FROM person_likes_comment
JOIN comment_hascreator_person ON comment_hascreator_person.commentid = person_likes_comment.commentid
	WHERE ( extract( year from creationdate ) > 2011) OR 
 ( extract( year from creationdate ) = 2011 AND extract( month from creationdate ) = 12)
GROUP by person_likes_comment.commentid, id) as ss
GROUP BY id 
);
-- brzydko ale dziala, juz nie zdaze tego poprawic :c



-- Zadanie 2 [male wyjasnienie] TUTAJ SELECT * ABY ZOBACZYC, ZE KOMENTARZE BYLY POLUBIONE 117 RAZY 

SELECT * FROM 
(


SELECT sum(sum) as count, id, person.firstname, person.lastname FROM 
	(SELECT comment_hascreator_person.personid as id, person_likes_comment.commentid, count(*) as sum FROM person_likes_comment
JOIN comment_hascreator_person ON comment_hascreator_person.commentid = person_likes_comment.commentid
	WHERE ( extract( year from creationdate ) > 2011) OR 
 ( extract( year from creationdate ) = 2011 AND extract( month from creationdate ) = 12)
GROUP by person_likes_comment.commentid, id) as ss
JOIN person using(id)
GROUP BY id, person.firstname, person.lastname
ORDER BY count DESC

) as foo

WHERE foo.count >= ALL 
(
SELECT sum(sum) as count FROM 
	(SELECT comment_hascreator_person.personid as id, person_likes_comment.commentid, count(*) as sum FROM person_likes_comment
JOIN comment_hascreator_person ON comment_hascreator_person.commentid = person_likes_comment.commentid
	WHERE ( extract( year from creationdate ) > 2011) OR 
 ( extract( year from creationdate ) = 2011 AND extract( month from creationdate ) = 12)
GROUP by person_likes_comment.commentid, id) as ss
GROUP BY id 
);





