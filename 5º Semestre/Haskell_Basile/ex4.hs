
-- Nome: Cleverson Pereira da Silva - TIA: 32198531
-- Professor: Antonio Luiz Basile
-- Turma: [05N]

penult :: [Char] -> Maybe Char
penult [] = Nothing
penult [_] = Nothing
penult xs = Just(last(init xs))

main :: IO ()
main = do
    let charList = "abcdefgh"
    case penult charList of
        Nothing -> putStrLn "Sem penultimo elemento"
        Just p -> putStrLn [p]
