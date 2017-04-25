-- Mateusz Pater, mka, pkt 1
ALTER TABLE person ADD PRIMARY KEY (id);
-- pkt 2
alter table  post_hascreator_person ADD constraint "fk_person_id" FOREIGN KEY (personid) REFERENCES person(id) DEFERRABLE;
-- pkt 3
alter table person add column posts int default 0;
-- pkt 4
UPDATE person SET posts = ( SELECT count(*) from post_hascreator_person p  WHERE 
p.personid = person.id GROUP BY p.personid );
UPDATE PERSON SET posts = 0 WHERE posts is NULL;
-- pkt 5 przez ten klucz z zadania 2 :c
delete from post_hascreator_person USING person WHERE person.id = personid AND person.browserused = 'Safari';
delete from person where browserused = 'Safari';
-- pkt 6
select count(*), personid from post_hascreator_person group by personid;
select count(*), personid from comment_hascreator_person group by personid;

create table posts_tmp (
personid numeric,
comments int default 0,
posts int default 0
);

INSERT INTO posts_tmp select personid, count(*) as comments from comment_hascreator_person group by personid;

UPDATE posts_tmp set posts = select count(*) as posts from post_hascreator_person WHERE post_hascreator_person.personid = posts_tmp.personid group by personid;

DELETE FROM person WHERE id IN (SELECT personid from posts_tmp WHERE comments > posts);


-- pkt 7
create table student (
personid numeric,
firstname varchar,
lastname varchar,
university varchar
);
-- pkt 8
-- musimy uzyc left, bo inaczej dostajemy 336 wierszy (zamiast 357), bo niektorzy np. nie maja rekordu w person- a w zadaniu mamy ich tez wziac pod uwage
INSERT INTO student
SELECT p.personid, p2.firstname, p2.lastname, o.name as university from person_studyat_organisation p 
LEFT JOIN person p2 ON p.personid = p2.id
LEFT JOIN organisation o ON o.id = p.organisationid;

