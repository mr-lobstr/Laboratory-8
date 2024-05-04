digitAdd :: Integer -> Integer -> Integer
digitAdd num dig
    | num >= dig = digitAdd num (dig * 10)
    | otherwise = dig + num

func :: Integer -> Integer -> Integer -> Integer -> Bool
func n sum head tail
    | head == 0 = if sum + tail == n then True else False
    | func n (sum + tail) (head `div` 10) (head `mod` 10) = True
    | func n (sum - tail) (head `div` 10) (head `mod` 10) = True
    | func n sum (head `div` 10) (digitAdd tail (head `mod` 10)) = True
    | otherwise = False

main :: IO ()
main = do
    input <- getLine
    let [n, digits] = map read $ words input
    func n 0 (digits `div` 10) (digits `mod` 10)
 
