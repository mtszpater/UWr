-- Wymagamy, by moduł zawierał tylko bezpieczne funkcje
{-# LANGUAGE Safe #-}
-- Definiujemy moduł zawierający rozwiązanie.
-- Należy zmienić nazwę modułu na {Imie}{Nazwisko} gdzie za {Imie}
-- i {Nazwisko} należy podstawić odpowiednio swoje imię i nazwisko
-- zaczynające się wielką literą oraz bez znaków diakrytycznych.
module MateuszPater (typecheck, eval) where

-- Importujemy moduły z definicją języka oraz typami potrzebnymi w zadaniu
import AST
import DataTypes
import Data.Map as Map

data LogicB = Intidzer | Boolean deriving (Eq)

data Error p = EX p String deriving (Eq)
data Environment a = Environment (Map Var a) deriving (Eq)

zip' :: [a] -> b -> [(a,b)]  

zip' [] _ = []  
zip' (x:xs) y = (x,y):zip' xs y 

typecheck :: [Var] -> Expr p -> TypeCheckResult p
typecheck list expr =
    case infer_type (Environment (Map.fromList (zip' list Intidzer))) expr of
        Right Intidzer -> Ok
        Right Boolean -> Error (getData expr) "got bool instead int"
        Left (EX p message) -> Error p message

infer_type :: Environment LogicB -> Expr p -> Either (Error p) LogicB
infer_type (Environment env) (EVar p e) = 
    case Map.lookup e env of 
        Nothing -> Left (EX p "Undefined variable")
        Just a -> 
            case a of
                Intidzer -> Right Intidzer
                Boolean -> Right Boolean

infer_type _ (EBool _ _) = Right Boolean
infer_type _ (ENum _ _) = Right Intidzer

-- UNARY OPERATIONS
infer_type env (EUnary p UNot e) =  
    case infer_type env e of 
        Right Boolean -> Right Boolean
        Right Intidzer -> Left (EX p "Error in: EUnary UNot (Int)")
        Left (EX p message) -> Left (EX p message)

infer_type env (EUnary p UNeg e) =    
    case infer_type env e of 
        Right Intidzer -> Right Intidzer
        Right Boolean -> Left (EX p "Error in: EUnary UNeg (Bool)")
        Left (EX p message) -> Left (EX p message)

-- + - * div mod = > < => <=
infer_type env (EBinary p op e1 e2) = 
    case infer_type env e1 of 
        Right Boolean -> 
            case op of
                BAnd ->
                    case infer_type env e2 of 
                    Right Intidzer -> Left (EX p "Error in: EBinary BAnd (Int#2)")
                    Left (EX p message) -> Left (EX p message)
                    Right Boolean -> Right Boolean
                BOr ->
                    case infer_type env e2 of 
                    Right Intidzer -> Left (EX p "Error in: EBinary BOr (Int#2)")
                    Left (EX p message) -> Left (EX p message)
                    Right Boolean -> Right Boolean
                BAdd -> Left (EX p "Error in: EBinary BAdd (Bool#1)")
                BSub -> Left (EX p "Error in: EBinary BSub (Bool#1)")
                BMul -> Left (EX p "Error in: EBinary BMul (Bool#1)")
                BDiv -> Left (EX p "Error in: EBinary BDiv (Bool#1)")
                BMod -> Left (EX p "Error in: EBinary BMod (Bool#1)")
                BEq -> Left (EX p "Error in: EBinary BEq (Bool#1)")
                BNeq -> Left (EX p "Error in: EBinary BNeq (Bool#1)")
                BLt -> Left (EX p "Error in: EBinary BLt (Bool#1)")
                BGt -> Left (EX p "Error in: EBinary BGt (Bool#1)")
                BLe -> Left (EX p "Error in: EBinary BLe (Bool#1)")
                BGe -> Left (EX p "Error in: EBinary BGe (Bool#1)")
        Left (EX p message) -> Left (EX p message)
        Right Intidzer -> 
            case infer_type env e2 of 
                Right Boolean -> 
                    case op of
                        BAdd -> Left (EX p "Error in: EBinary BAdd (Bool#2)")
                        BSub -> Left (EX p "Error in: EBinary BSub (Bool#2)")
                        BMul -> Left (EX p "Error in: EBinary BMul (Bool#2)")
                        BDiv -> Left (EX p "Error in: EBinary BDiv (Bool#2)")
                        BMod -> Left (EX p "Error in: EBinary BMod (Bool#2)")
                        BEq -> Left (EX p "Error in: EBinary BEq (Bool#2)")
                        BNeq -> Left (EX p "Error in: EBinary BNeq (Bool#2)")
                        BLt -> Left (EX p "Error in: EBinary BLt (Bool#2)")
                        BGt -> Left (EX p "Error in: EBinary BGt (Bool#2)")
                        BLe -> Left (EX p "Error in: EBinary BLe (Bool#2)")
                        BGe -> Left (EX p "Error in: EBinary BGe (Bool#2)")
                        BAnd -> Left (EX p "Error in: EBinary BAnd (Int#1)")
                        BOr -> Left (EX p "Error in: EBinary BOr (Int#1)")
                Left (EX p message) -> Left (EX p message)
                Right Intidzer -> 
                    case op of 
                        BAdd -> Right Intidzer
                        BSub -> Right Intidzer
                        BMul -> Right Intidzer
                        BDiv -> Right Intidzer
                        BMod -> Right Intidzer
                        BEq -> Right Boolean
                        BNeq -> Right Boolean
                        BLt -> Right Boolean
                        BGt -> Right Boolean
                        BLe -> Right Boolean
                        BGe -> Right Boolean
                        BAnd -> Left (EX p "Error in: EBinary BAnd (Int#1)")
                        BOr -> Left (EX p "Error in: EBinary BOr (Int#1)")

---- LET
infer_type (Environment env) (ELet p var e1 e2) = 

        case infer_type (Environment env) e1 of
            Left (EX p message) -> Left (EX p message)
            Right typ -> 
                case infer_type (Environment (Map.insert var typ env)) e2 of
                    Right typ2 -> Right typ2
                    Left (EX p message) -> Left (EX p message)

-- IF
infer_type env (EIf p e1 e2 e3) = 
    case infer_type env e1 of
        Right Intidzer -> Left (EX p "Error in: EIf (Int)")
        Left (EX p message) -> Left (EX p message)
        Right Boolean -> 
            case infer_type env e2 of
                Left (EX p message) -> Left (EX p message)
-- pozostale dwa mają taki sam typ jak ostateczne eazenie
                Right Boolean -> 
                    case infer_type env e3 of
                        Right Intidzer -> Left (EX p "EIf have to be bool")
                        Left (EX p message) -> Left (EX p message)
                        Right Boolean -> Right Boolean
                Right Intidzer -> 
                    case infer_type env e3 of
                        Right Boolean -> Left (EX p "Eif have to int ")
                        Left (EX p message) -> Left (EX p message)
                        Right Intidzer -> Right Intidzer

eval :: [(Var,Integer)] -> Expr p -> EvalResult
eval env e =
    case evalTmp env e [] of
        Left _ -> RuntimeError
        Right p -> Value p

evalTmp :: [(Var,Integer)] -> Expr p -> [(Var, String)] -> Either String Integer
evalTmp _ (ENum _ var) _ = Right var

evalTmp env (EVar _ e) list = 
    case Map.lookup e (Map.fromList list) of 
        Just a -> Left a
        Nothing -> 
            case Map.lookup e (Map.fromList env) of 
                Nothing -> Left "Blad"
                Just a -> Right a

evalTmp _ (EBool _ True) _ = Left "true"
evalTmp _ (EBool _ False) _ = Left "false"

-- UNARY OPERATIONS
evalTmp env (EUnary _ UNeg e) list =
    case evalTmp env e list of
        Left x -> Left x
        Right var -> Right ((-1) * var)

evalTmp env (EUnary _ UNot e) list =
    case evalTmp env e list of
        Left "true" -> Left "false"
        Left "false" -> Left "true"
        
-- IF
evalTmp env (EIf _ e1 e2 e3) list = 
    case evalTmp env e1 list of
        Left "true" -> evalTmp env e2 list
        Left "false" -> evalTmp env e3 list
        otherwise -> Left "undefined"

-- LET
evalTmp env (ELet _ var e1 e2) list = 
    case evalTmp env e1 list of
        Right var2 -> evalTmp (Map.toList (Map.insert var var2 ( Map.fromList env) )) e2 (Map.toList (Map.delete var ( Map.fromList list) ))
        Left "true" -> evalTmp env e2 (Map.toList (Map.insert var "true" ( Map.fromList list )))
        Left "false" -> evalTmp env e2 (Map.toList (Map.insert var "false" ( Map.fromList list )))
        otherwise -> Left "undefined"
        
-- AND /OR 
evalTmp env (EBinary _ BAnd e1 e2) list =
    case evalTmp env e1 list of
        Left "false" -> 
            case evalTmp env e2 list of
                Left "true" -> Left "false"
                Left "false" -> Left "false"
                otherwise -> Left "undefined"
        Left "true" -> 
            case evalTmp env e2 list of
                Left "true" -> Left "true"
                Left "false" -> Left "false"
                otherwise -> Left "undefined"

evalTmp env (EBinary _ BOr e1 e2) list =
    case evalTmp env e1 list of
        Left "true" ->  
            case evalTmp env e2 list of
                Left "false" -> Left "true"
                Left "true" -> Left "true"
                otherwise -> Left "undefined"
        Left "false" -> 
            case evalTmp env e2 list of
                Left "true" -> Left "true"
                Left "false" -> Left "false"
                otherwise -> Left "undefined"

-- == /= < > <= >= mod div 
evalTmp env (EBinary _ op e1 e2) list =
    case evalTmp env e1 list of
        Left x -> Left x
        Right var ->
            case evalTmp env e2 list of
                Left x2 -> Left x2
                Right var2 -> 
                    case op of 
                        BEq -> 
                            case var == var2 of
                                True -> Left "true"
                                False -> Left "false"
                        BNeq ->
                            case var /= var2 of
                                True -> Left "true"
                                False -> Left "false"
                        BLt ->
                            case var < var2 of
                                True -> Left "true"
                                False -> Left "false"
                        BGt ->
                            case var > var2 of
                                True -> Left "true"
                                False -> Left "false"
                        BLe ->
                            case var <= var2 of
                                True -> Left "true"
                                False -> Left "false"  
                        BGe ->
                            case var >= var2 of
                                True -> Left "true"
                                False -> Left "false"
                        BAdd -> Right ( var + var2 )
                        BSub -> Right ( var - var2 )
                        BMul -> Right ( var * var2 )
                        BDiv -> 
                            case var2 of
                                0 -> Left "Blad dzielenia przez 0"
                                otherwise -> Right ( var `div` var2 )
                        BMod ->
                            case var2 of
                                0 -> Left "Blad dzielenia przez 0"
                                otherwise -> Right ( var `mod` var2 )
