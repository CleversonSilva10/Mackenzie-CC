
-- Nome: Cleverson Pereira da Silva - TIA: 32198531
-- Professor: Antonio Luiz Basile
-- Turma: [05N]

seg :: [Char] -> Maybe Char
seg [] = Nothing
seg [_] = Nothing
seg (_:x:_) = Just x

main :: IO()
main = do
    let string = "abcdefgh"
    let x = seg string
    print x