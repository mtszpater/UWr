-- Wymagamy, by moduł zawierał tylko bezpieczne funkcje
{-# LANGUAGE Safe #-}
-- Definiujemy moduł zawierający testy.
-- Należy zmienić nazwę modułu na {Imie}{Nazwisko}Tests gdzie za {Imie}
-- i {Nazwisko} należy podstawić odpowiednio swoje imię i nazwisko
-- zaczynające się wielką literą oraz bez znaków diakrytycznych.
module MateuszPaterTests(tests) where

-- Importujemy moduł zawierający typy danych potrzebne w zadaniu
import DataTypes

-- Lista testów do zadania
-- Należy uzupełnić jej definicję swoimi testami
tests :: [Test]
tests =
  [ 
  Test "undefVar" (SrcString "x") TypeError
  , Test "zlyTypOperacji1" (SrcString "true*1") TypeError
  , Test "divcv"    (SrcString "3 div 0=0")     TypeError
  , Test "zlyTypOperacji2" (SrcString "false*1") TypeError
  , Test "zlyTypOperacji3" (SrcString "1*true") TypeError
  , Test "zlyTypOperacji4" (SrcString "1*false") TypeError
  , Test "zlyTypOperacji5" (SrcString "true + false") TypeError
  , Test "zlyTypOperacji6" (SrcString "true mod false") TypeError
  , Test "zlyTypOperacji7" (SrcString "true div false") TypeError
  , Test "zlyTypOperacji8" (SrcString "0 div false") TypeError
  , Test "zlyTypOperacji9" (SrcString "0 mod false") TypeError
  , Test "zlyTypOperacji10" (SrcString "false div 5") TypeError
  , Test "zlyTypOperacji11" (SrcString "true mod 5") TypeError

  , Test "zlyTypUnarny1" (SrcString "-true") TypeError
  , Test "zlyTypUnarny2" (SrcString "-false") TypeError
  , Test "zleNegowanie1" (SrcString "not 5") TypeError

  , Test "if1" (SrcString "if true then false else false") TypeError
  , Test "if2" (SrcString "if true then 1 else false") TypeError
  , Test "if3" (SrcString "if 5 then 1 else 1") TypeError
  , Test "if4" (SrcString "if true then false else 3") TypeError

  , Test "or1" (SrcString "3 or 5") TypeError
  , Test "or2" (SrcString "3 or false") TypeError
  , Test "or3" (SrcString "true or 2") TypeError

  , Test "and1" (SrcString "3 and 5") TypeError
  , Test "and2" (SrcString "3 and false") TypeError
  , Test "and3" (SrcString "true and 2") TypeError

  , Test "eq1" (SrcString "true > false") TypeError
  , Test "eq2" (SrcString "true > 0") TypeError
  , Test "eq3" (SrcString "true = false") TypeError
  , Test "eq4" (SrcString "true > false") TypeError
  , Test "eq5" (SrcString "true > 0") TypeError
  , Test "eq6" (SrcString "true <> false") TypeError
  , Test "eq7" (SrcString "true < 0") TypeError
  , Test "eq8" (SrcString "true < false") TypeError
  , Test "eq9" (SrcString "true <= false") TypeError
  , Test "eq10" (SrcString "true >= 0") TypeError

  , Test "let1" (SrcString "let x = true in false") TypeError
  , Test "let1" (SrcString "let x = 5 in false") TypeError
  , Test "let2" (SrcString "input x in let x = 3 in true+x") TypeError
  , Test "let3" (SrcString "input x in let x = 4 in true+false") TypeError
  , Test "let4" (SrcString "input x in let x = true in 4+x") TypeError
  , Test "let5" (SrcString "input x in let x = x+0 in 4+x") (Eval [2] (Value 6))

  , Test "dodawanie"   (SrcString "input x in x + 1") (Eval [42] (Value 43))
  , Test "odejmowanie" (SrcString "input x in x - 1") (Eval [42] (Value 41))
  , Test "mnozenie" (SrcString "input x in x * 2") (Eval [42] (Value 84))
  , Test "dzielenie" (SrcString "input x in x div 5") (Eval [10] (Value 2))
  , Test "modulo" (SrcString "input x in x mod 2") (Eval [3] (Value 1))
  , Test "if5" (SrcString "input x in if x > 0 then 5 else 3") (Eval [1] (Value 5))
  , Test "div0" (SrcString "input x in 1 div x") (Eval [0] (RuntimeError))
  , Test "program1" (SrcString "input x in if true then let x = x+0 in x + 3 else let x = x+0 in x + 3") (Eval [5] (Value 8))
  , Test "program2" (SrcString "input x in if false then let x = x+0 in x + 3 else let x = x+0 in x + 1") (Eval [5] (Value 6))

  , Test "xx" (SrcString "let x = false in if x and true then 42 else 5") (Eval [] (Value 5))
  , Test "xx2" (SrcString "let x = true in if x and true then 42 else 5") (Eval [] (Value 42))
  , Test "xx3" (SrcString "let x = false in if x or false then 42 else 5") (Eval [] (Value 5))
  , Test "xx4" (SrcString "let x = true in if x or false then 42 else 5") (Eval [] (Value 42))
  , Test "xx5" (SrcString "let x = 5 in if x < 3 then 42 else 5") (Eval [] (Value 5))


  ]

