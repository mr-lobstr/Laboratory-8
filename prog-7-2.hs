import Data.Char

endExpr :: String -> Int -> Int
endExpr str ind = go str ind 0
  where
    go [] _ _ = length str
    go (x:xs) i brackets
      | brackets == 0 && (x == ',' || x == ')') = i
      | x == ')' = go xs (i + 1) (brackets - 1)
      | x == '(' = go xs (i + 1) (brackets + 1)
      | otherwise = go xs (i + 1) brackets

logicFunc :: String -> Int -> Bool
logicFunc str ind
  | isLower (str !! ind) = str !! ind == 't'
  | str !! ind == '!' = not (logicFunc str (ind + 2))
  | otherwise = let isAnd = str !! ind == '&'
                    newInd = ind + 2
                in go newInd isAnd
  where
    go i isAnd
      | str !! i == ')' = not isAnd
      | otherwise = let res = logicFunc str (i + 1)
                    in if isAnd && not res
                       then False
                       else if not isAnd && res
                            then True
                            else go (endExpr str (i + 1)) isAnd

main :: IO ()
main = do
  st <- getLine
  print $ logicFunc st 0 
